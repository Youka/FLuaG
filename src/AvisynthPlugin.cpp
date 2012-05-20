#include "AvisynthPlugin.h"
#include "seh_exc.h"

//Register filter
extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit2(IScriptEnvironment* env) {
	env->AddFunction("FLuaG", "c[video]s[audio]s[onscreen]b[samples32]b[userdata]s", AvisynthPlugin::Create, 0);
	return "FLuaG: Video editing via Lua";
}

AVSValue __cdecl AvisynthPlugin::Create(AVSValue args, void* user_data, IScriptEnvironment* env) {
	PClip child = args[0].AsClip();
	const char *video_file = args[1].AsString(0);
	const char *audio_file = args[2].AsString(0);
	bool onscreen = args[3].AsBool(false);
	bool audio32 = args[4].AsBool(false);
	const char *userdata_str = args[5].AsString(0);

	if(!video_file && !audio_file)
		env->ThrowError("Non audio or video script!");
	try{
		if(audio_file){
			if(audio32)
				child = env->Invoke("ConvertAudioTo32bit", child).AsClip();
			else
				child = env->Invoke("ConvertAudioTo16bit", child).AsClip();
		}
		if(video_file)
			child = env->Invoke("ConvertToRGB32", child).AsClip();
	}catch(IScriptEnvironment::NotFound){
		env->ThrowError("Cannot convert audio or video!");
	}

	return new AvisynthPlugin(child, env, video_file, audio_file, onscreen, audio32, userdata_str);
}

//Plugin ctor & dtor
AvisynthPlugin::AvisynthPlugin(PClip _child, IScriptEnvironment* env, const char *video_file, const char *audio_file, bool onscreen, bool audio32, const char *userdata_str) : GenericVideoFilter(_child){
	if(video_file && vi.HasVideo() && !vi.IsRGB32())
		env->ThrowError("RBG32 color format expected!");
	if(audio_file && vi.HasAudio() && !(vi.IsSampleType(SAMPLE_INT16) || vi.IsSampleType(SAMPLE_INT32)))
		env->ThrowError("S16 or S32 sample format expected!");

	try{
		userdata = new void*[2];
		userdata[0] =(void*)userdata_str;
		userdata[1] = env;

		proc = new FLuaG(video_file, vi.width, vi.height, 1 / ((double)vi.fps_denominator / vi.fps_numerator), vi.num_frames, onscreen,
									audio_file, vi.nchannels, vi.audio_samples_per_second, vi.num_audio_samples, audio32,
									userdata);
	}
	catch(const char* e){
		env->ThrowError(e);
	}
}

AvisynthPlugin::~AvisynthPlugin(){
	delete(proc);
	delete(userdata);
}

//Getter methods / editing
//AUDIO
void __stdcall AvisynthPlugin::GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env)
{
	child->GetAudio(buf, start, count, env);

	try{
			_se_translator_function se_prev_func = _set_se_translator(se_trans);
			proc->run_audio(start, count, buf);
			_set_se_translator(se_prev_func);
	}
	catch (const char* e){
		if(MessageBoxA(0, e, "FLUAG AUDIO ERROR", MB_OKCANCEL | MB_ICONWARNING) == IDCANCEL)
			env->ThrowError(e);
	}
	catch(unsigned int code){
		SEH_CASE
	}
}
//VIDEO
PVideoFrame __stdcall AvisynthPlugin::GetFrame(int n, IScriptEnvironment* env) {
	PVideoFrame src = child->GetFrame(n, env);
	env->MakeWritable(&src);

	try{
			_se_translator_function se_prev_func = _set_se_translator(se_trans);
			proc->run_video(n, src->GetPitch(), src->GetReadPtr(), src->GetWritePtr());
			_set_se_translator(se_prev_func);
	}
	catch (const char* e){
		if(MessageBoxA(0, e, "FLUAG VIDEO ERROR", MB_OKCANCEL | MB_ICONWARNING) == IDCANCEL)
			env->ThrowError(e);
	}
	catch(unsigned int code){
		SEH_CASE
	}

	return src;
}