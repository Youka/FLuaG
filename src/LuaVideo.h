#pragma once

#include "Lua.h"
#include "GLWindow.h"

typedef struct{
	unsigned int width, height;
	unsigned long int nframes;
	double fps;
}VInfo;
typedef struct{
	int n, pitch;
	const unsigned char *src;
	unsigned char *dst;
}FrmInfo;

class LuaVideo : public Lua
{
public:
	LuaVideo(unsigned int width, unsigned int height, double fps, unsigned long int nframes, bool onscreen);
	void dofile(const char *filename);
	void run_frame(int n, int pitch, const unsigned char *src, unsigned char *dst);
	virtual ~LuaVideo();

	static unsigned char *pixelbuffer;
	static VInfo info; static FrmInfo frames;
private:
	void register_video_access(lua_State *L);	//Lua functions for video information access
	GLWindow *wnd;
};
