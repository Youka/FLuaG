#include "LuaAudio.h"

DEF_HEAD(LoadSamples, 0)
	lua_createtable(L, LuaAudio::samples.count * LuaAudio::info.channels, 0);
	if(LuaAudio::info.audio32){
		signed long *data = (signed long*)LuaAudio::samples.buf;
		for(unsigned int i = 0; i < LuaAudio::samples.count * LuaAudio::info.channels; i++){
			lua_pushnumber(L, *data++);
			lua_rawseti(L, -2, i+1);
		}
	}else{
		signed short *data = (signed short*)LuaAudio::samples.buf;
		for(unsigned int i = 0; i < LuaAudio::samples.count * LuaAudio::info.channels; i++){
			lua_pushnumber(L, *data++);
			lua_rawseti(L, -2, i+1);
		}
	}

	return 1;
DEF_TAIL
DEF_HEAD(SaveSamples, 1)
	if(LuaAudio::info.audio32){
		LuaArray<signed long> data(L);
		data.get(1);
		if(lua_objlen(L,1) != LuaAudio::samples.count * LuaAudio::info.channels)
			error_msg(L, "wrong table size");
		memcpy(LuaAudio::samples.buf, data, LuaAudio::samples.count * LuaAudio::info.channels * sizeof(signed long));
	}else{
		LuaArray<signed short> data(L);
		data.get(1);
		if(lua_objlen(L,1) != LuaAudio::samples.count * LuaAudio::info.channels)
			error_msg(L, "wrong table size");
		memcpy(LuaAudio::samples.buf, data, LuaAudio::samples.count * LuaAudio::info.channels * sizeof(signed short));
	}
DEF_TAIL

void LuaAudio::register_audio_access(lua_State *L){
	lua_pushnumber(L, LuaAudio::info.channels);
	lua_setglobal(L, "AUDIO_CHANNELS");
	lua_pushnumber(L, LuaAudio::info.sample_rate);
	lua_setglobal(L, "AUDIO_SAMPLE_RATE");
	lua_pushnumber(L, LuaAudio::info.nsamples);
	lua_setglobal(L, "AUDIO_SAMPLES");
	REGISTER_FUNC(LoadSamples);
	REGISTER_FUNC(SaveSamples);
}