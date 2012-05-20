#pragma once

#include <windows.h>
#include <avisynth.h>
#include "FLuaG.h"

class AvisynthPlugin : public GenericVideoFilter{
public:
	static AVSValue __cdecl Create(AVSValue, void* , IScriptEnvironment*);
	AvisynthPlugin(PClip _child, IScriptEnvironment* env, const char *video_file, const char *audio_file, bool onscreen, bool audio32, const char *userdata);
	~AvisynthPlugin();

	PVideoFrame __stdcall GetFrame(int, IScriptEnvironment*);
	void __stdcall GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env);

private:
    FLuaG *proc;
	void **userdata;
};

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit2(IScriptEnvironment*);
