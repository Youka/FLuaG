#include "env.h"
#include <windows.h>
#include <avisynth.h>

#define LUACLIP	 "LuaClip"
void **userdata_avs;

void swap_red_blue(void *p, unsigned long plen){
	__asm
	{
			mov ebx, p
			mov ecx, plen
			cmp ecx, 0
			jz Finished
		NextPixel:
			mov al, [ebx+0]
			mov ah, [ebx+2]
			mov [ebx+2],al
			mov [ebx+0],ah
			add ebx, 4
			loop NextPixel
		Finished:
	}
}

DEF_HEAD(GetClipInfo, 1)
	PClip *clip = (PClip*)luaL_checkuserdata(L, 1, LUACLIP);
	VideoInfo info =  (*clip)->GetVideoInfo();

	lua_createtable(L, 0, 7);
	lua_pushnumber(L, info.width);
	lua_setfield(L, -2, "width");
	lua_pushnumber(L, info.height);
	lua_setfield(L, -2, "height");
	lua_pushnumber(L, 1 / ((double)info.fps_denominator / info.fps_numerator));
	lua_setfield(L, -2, "fps");
	lua_pushnumber(L, info.num_frames);
	lua_setfield(L, -2, "frames");
	lua_pushnumber(L, info.audio_samples_per_second);
	lua_setfield(L, -2, "sample_rate");
	lua_pushnumber(L, info.num_audio_samples);
	lua_setfield(L, -2, "samples");
	lua_pushnumber(L, info.nchannels);
	lua_setfield(L, -2, "channels");

	return 1;
DEF_TAIL
DEF_HEAD(LoadClipFrame, 2)
	PClip *clip = (PClip*)luaL_checkuserdata(L, 1, LUACLIP);
	VideoInfo info =  (*clip)->GetVideoInfo();
	unsigned int n = luaL_checknumber(L, 2);

	if(info.HasVideo() && n >= 0 && n < info.num_frames){
		PVideoFrame f = (*clip)->GetFrame(n, (IScriptEnvironment*)userdata_avs[1]);
		int pitch = f->GetPitch();
		const BYTE *src = f->GetReadPtr();

		BYTE *pixelbuf = new BYTE[info.width * info.height * 4];
		for(unsigned int y = 0; y < info.height; y++)
			memcpy(pixelbuf + y * info.width * 4, src + y * pitch, info.width * 4);

		swap_red_blue(pixelbuf, info.width * info.height);

		lua_createtable(L, info.width * info.height * 4, 0);
		BYTE *data = pixelbuf;
		for(unsigned long i = 0; i < info.width * info.height * 4; i++){
			lua_pushnumber(L, *data++);
			lua_rawseti(L, -2, i+1);
		}

		delete(pixelbuf);
		return 1;
	}else
		error_msg(L, "Frame index must be in video stream range!");
DEF_TAIL
DEF_HEAD(LoadClipSamples, 3)
	PClip *clip = (PClip*)luaL_checkuserdata(L, 1, LUACLIP);
	VideoInfo info =  (*clip)->GetVideoInfo();
	__int64 start = luaL_checknumber(L, 2);
	__int64 count = luaL_checknumber(L, 3);

	if(info.HasAudio() && start >= 0 && start+count < info.num_audio_samples && count > 0){
		signed short *buf = new signed short[count *  info.nchannels];
		(*clip)->GetAudio(buf, start, count, (IScriptEnvironment*)userdata_avs[1]);

		lua_createtable(L, count *  info.nchannels, 0);
		signed short *data = buf;
		for(unsigned int i = 0; i < count *  info.nchannels; i++){
			lua_pushnumber(L, *data++);
			lua_rawseti(L, -2, i+1);
		}

		delete(buf);
		return 1;
	}else
		error_msg(L, "Sample start and count must be in audio stream range!");
DEF_TAIL

inline void register_meta_avs(lua_State *L){
	luaL_newmetatable(L, LUACLIP);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
}
inline void register_funcs_avs(lua_State *L){
	luaL_newmetatable(L, LUACLIP);
	lua_pushcfunction(L, l_GetClipInfo);
    lua_setfield(L, -2, "Info");
	lua_pushcfunction(L, l_LoadClipFrame);
    lua_setfield(L, -2, "LoadFrame");
	lua_pushcfunction(L, l_LoadClipSamples);
    lua_setfield(L, -2, "LoadSamples");
}

void register_avs(lua_State *L){
	register_meta_avs(L);
	register_funcs_avs(L);
	
	lua_newtable(L);
	size_t n = 0;

	if(userdata_avs[0]){
		IScriptEnvironment *env = (IScriptEnvironment*)userdata_avs[1];
		char *token = strtok((char*)userdata_avs[0], " ");
		while(token != NULL){
			AVSValue val = env->GetVar(token);
			if(val.IsBool()){
				lua_pushboolean(L, val.AsBool());
				lua_rawseti(L, -2, ++n);
			}else if(val.IsClip()){
				PClip *clip = lua_createuserdata<PClip>(L, LUACLIP);
				try{
					*clip = env->Invoke("ConvertAudioTo16bit", env->Invoke("ConvertToRGB32", val)).AsClip();
				}catch(IScriptEnvironment::NotFound){
					throw "Cannot convert audio or video!";
				}
				lua_rawseti(L, -2, ++n);
			}else if(val.IsFloat()){
				lua_pushnumber(L, val.AsFloat());
				lua_rawseti(L, -2, ++n);
			}else if(val.IsString()){
				lua_pushstring(L, val.AsString());
				lua_rawseti(L, -2, ++n);
			}else
				throw "Userdata contains undefined variable names!";
			token = strtok(NULL, " ");
		}
	}

	lua_setglobal(L, "USERDATA");
}