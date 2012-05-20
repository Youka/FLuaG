#pragma once

#include "LuaVideo.h"
#include "LuaAudio.h"

class FLuaG
{
public:
	FLuaG(const char *video_file, unsigned int width, unsigned int height, double fps, unsigned long int nframes, bool onscreen,
				const char *audio_file, unsigned char channels, unsigned int sample_rate, unsigned long int nsamples, bool audio32,
				void **userdata);
	~FLuaG();

	void run_video(int n, int pitch, const unsigned char *src, unsigned char *dst);
	void run_audio(__int64 start, __int64 count, void *buf);

private:
	LuaVideo *vid_proc;
	LuaAudio *aud_proc;
};