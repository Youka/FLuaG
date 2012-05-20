#include "LuaAudio.h"

AInfo LuaAudio::info = {0, 0, 0, false};
LuaAudio::LuaAudio(unsigned char channels, unsigned int sample_rate, unsigned long int nsamples, bool audio32)
{
	//Set meta data
	info.channels = channels;
	info.sample_rate = sample_rate;
	info.nsamples = nsamples;
	info.audio32 = audio32;
	//Register functions
	register_audio_access(L);
	register_avs(L);
}

SmpInfo LuaAudio::samples = {0, 0, 0};
void LuaAudio::run_samples(__int64 start, __int64 count, void *buf){
	//Set sample data
	samples.start = start;
	samples.count = count;
	samples.buf = buf;
	//Run framework
	lua_getfield(L, LUA_GLOBALSINDEX, "GetSamples");
	if(lua_isfunction(L,-1)){
		lua_pushnumber(L, start);
		lua_pushnumber(L, (double)start / info.sample_rate * 1000);
		lua_pushnumber(L, count);
		if(lua_pcall(L, 3, 0, 0))
			throw lua_tostring(L,-1);
		lua_gc(L, LUA_GCCOLLECT, 0);
	}else
		lua_pop(L,-1);
}