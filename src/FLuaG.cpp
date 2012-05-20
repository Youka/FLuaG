#include "FLuaG.h"

//FLuaG ctor & dtor
FLuaG::FLuaG(const char *video_file, unsigned int width, unsigned int height, double fps, unsigned long int nframes, bool onscreen,
				const char *audio_file, unsigned char channels, unsigned int sample_rate, unsigned long int nsamples, bool audio32,
				void **userdata){
	userdata_avs = userdata;

	if(video_file && (width != 0)){
		vid_proc = new LuaVideo(width, height, fps, nframes, onscreen);
		vid_proc->dofile(video_file);
	}else
		vid_proc = NULL;

	if(audio_file && (channels != 0)){
		aud_proc =new LuaAudio(channels, sample_rate, nsamples, audio32);
		aud_proc->dofile(audio_file);
	}else
		aud_proc = NULL;
}

FLuaG::~FLuaG(){
	if(aud_proc)
		delete(aud_proc);
	if(vid_proc)
		delete(vid_proc);
}

//Run frame
void FLuaG::run_video(int n, int pitch, const unsigned char *src, unsigned char *dst){
	if(vid_proc)
		vid_proc->run_frame(n, pitch, src, dst);
}

void FLuaG::run_audio(__int64 start, __int64 count, void *buf){
	if(aud_proc)
		aud_proc->run_samples(start, count, buf);
}