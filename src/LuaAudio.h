#pragma once

#include "Lua.h"

typedef struct{
	unsigned char channels;
	unsigned int sample_rate;
	unsigned long int nsamples;
	bool audio32;
}AInfo;
typedef struct{
	__int64 start, count;
	void *buf;
}SmpInfo;

class LuaAudio : public Lua
{
public:
	LuaAudio(unsigned char channels, unsigned int sample_rate, unsigned long int nsamples, bool audio32);
	void run_samples(__int64 start, __int64 count, void *buf);

	static AInfo info; static SmpInfo samples;
private:
	void register_audio_access(lua_State *L);	//Lua functions for audio information access
};
