#include "LuaVideo.h"

VInfo LuaVideo::info = {0, 0, 0, 0};
unsigned char *LuaVideo::pixelbuffer = NULL;
LuaVideo::LuaVideo(unsigned int width, unsigned int height, double fps, unsigned long int nframes, bool onscreen)
{
	//Set meta data
	info.width = width;
	info.height = height;
	info.fps = fps;
	info.nframes = nframes;
	//Allocate picture buffer memory
	if(pixelbuffer)
		delete(pixelbuffer);
	pixelbuffer = new unsigned char[width * height * 4];
	//Create GL window
	wnd = new GLWindow(width, height, onscreen);
	//Register functions
	register_video_access(L);
	register_avs(L);
	register_gl(L);
	register_glu(L);
	register_glutess(L);
	register_fl(L);
	wnd->InitGL();
	register_glext(L);
	wnd->CloseGL();
}

FrmInfo LuaVideo::frames = {0, 0, 0, 0};
void LuaVideo::run_frame(int n, int pitch, const unsigned char *src, unsigned char *dst){
	//Set frame data
	frames.n = n;
	frames.pitch = pitch;
	frames.src = src;
	frames.dst = dst;
	//Run framework
	lua_getfield(L, LUA_GLOBALSINDEX, "GetFrame");
	if(lua_isfunction(L,-1)){
		wnd->InitGL();
		lua_pushnumber(L, n);
		lua_pushnumber(L, n * (1 / info.fps) * 1000);
		if(lua_pcall(L, 2, 0, 0)){
			wnd->CloseGL();
			throw lua_tostring(L,-1);
		}
		wnd->CloseGL();
		lua_gc(L, LUA_GCCOLLECT, 0);
	}else
		lua_pop(L,-1);
}

void LuaVideo::dofile(const char *filename){
	wnd->InitGL();
	Lua::dofile(filename);
	wnd->CloseGL();
}

LuaVideo::~LuaVideo(){
	delete(wnd);
}