#include "LuaVideo.h"
#include <GL/gl.h>

void swap_red_blue(void *p){
	unsigned long plen = LuaVideo::info.width * LuaVideo::info.height;
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

DEF_HEAD(LoadFrame, 0)
	//Line by line copy (BGRA)
	for(unsigned int y = 0; y < LuaVideo::info.height; y++)
		memcpy(LuaVideo::pixelbuffer + y * LuaVideo::info.width * 4, LuaVideo::frames.src + y * LuaVideo::frames.pitch, LuaVideo::info.width * 4);

	//Swapping blue and red color channels
	swap_red_blue(LuaVideo::pixelbuffer);

	//RGBA data to Lua
	lua_createtable(L, LuaVideo::info.width * LuaVideo::info.height * 4, 0);
	unsigned char *data = LuaVideo::pixelbuffer;
	for(unsigned long i = 0; i < LuaVideo::info.width * LuaVideo::info.height * 4; i++){
		lua_pushnumber(L, *data++);
		lua_rawseti(L, -2, i+1);
	}

	return 1;
DEF_TAIL
DEF_HEAD(LoadFrameToContext, 0)
	//Line by line copy (BGRA)
	for(unsigned int y = 0; y < LuaVideo::info.height; y++)
		memcpy(LuaVideo::pixelbuffer + y * LuaVideo::info.width * 4, LuaVideo::frames.src + y * LuaVideo::frames.pitch, LuaVideo::info.width * 4);

	//Swapping blue and red color channels
	swap_red_blue(LuaVideo::pixelbuffer);

	//RGBA data to OpenGL context
	glDrawPixels(LuaVideo::info.width,  LuaVideo::info.height, GL_RGBA, GL_UNSIGNED_BYTE, LuaVideo::pixelbuffer);
DEF_TAIL
DEF_HEAD(SaveFrame, 1)
	//RGBA data from Lua
	LuaArray<unsigned char> data(L);
	data.get(1);
	if(lua_objlen(L,1) != LuaVideo::info.width * LuaVideo::info.height * 4)
		error_msg(L, "wrong table size");

	//Line by line copy (RGBA)
	for(unsigned int y = 0; y < LuaVideo::info.height; y++)
		memcpy(LuaVideo::frames.dst + y * LuaVideo::frames.pitch, (unsigned char*)data + y * LuaVideo::info.width * 4, LuaVideo::info.width * 4);

	//Swapping blue and red color channels
	swap_red_blue(LuaVideo::frames.dst);
DEF_TAIL
DEF_HEAD(SaveFrameFromContext, 0)
	//RGBA data from OpenGL context
	glReadPixels(0, 0, LuaVideo::info.width, LuaVideo::info.height, GL_RGBA, GL_UNSIGNED_BYTE, LuaVideo::pixelbuffer);

	//Line by line copy (RGBA)
	for(unsigned int y = 0; y < LuaVideo::info.height; y++)
		memcpy(LuaVideo::frames.dst + y * LuaVideo::frames.pitch, LuaVideo::pixelbuffer + y * LuaVideo::info.width * 4, LuaVideo::info.width * 4);

	//Swapping blue and red color channels
	swap_red_blue(LuaVideo::frames.dst);
DEF_TAIL

void LuaVideo::register_video_access(lua_State *L){
	lua_pushnumber(L, LuaVideo::info.width);
	lua_setglobal(L, "VIDEO_WIDTH");
	lua_pushnumber(L, LuaVideo::info.height);
	lua_setglobal(L, "VIDEO_HEIGHT");
	lua_pushnumber(L, LuaVideo::info.fps);
	lua_setglobal(L, "VIDEO_FPS");
	lua_pushnumber(L, LuaVideo::info.nframes);
	lua_setglobal(L, "VIDEO_FRAMES");
	REGISTER_FUNC(LoadFrame);
	REGISTER_FUNC(LoadFrameToContext);
	REGISTER_FUNC(SaveFrame);
	REGISTER_FUNC(SaveFrameFromContext);
}