#include "env.h"
#include <windows.h>
#include <lodepng.h>
#include <GL/gl.h>
#include <GL/glu.h>

//Utils
static wchar_t* ctow(const char *c)
{
	int wc_len = MultiByteToWideChar(CP_UTF8, 0, c, strlen(c), 0, 0);
	wchar_t *wc = new wchar_t[wc_len+1];
	MultiByteToWideChar(CP_UTF8, 0, c, strlen(c), wc, wc_len);
	wc[wc_len] = L'\0';
	return wc;
}
//TEXT
#define LUAFONT	"LuaFont"
#define FONT_SCALE 64.0L
DEF_HEAD(flCreateFont, 4)
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = luaL_checknumber(L, 2) * FONT_SCALE;
	lf.lfWeight = luaL_checkboolean(L, 3) ? FW_BOLD : FW_NORMAL;
	lf.lfItalic = luaL_checkboolean(L, 4);
	lf.lfStrikeOut = false;
	lf.lfUnderline = false;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfOutPrecision = OUT_TT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strncpy(lf.lfFaceName, luaL_checkstring(L, 1), 31);
	lf.lfFaceName[31] = '\0';

	HFONT hfont = CreateFontIndirect(&lf);
	if(!hfont)
		error_msg(L, "cannot create font");

	HFONT *font = lua_createuserdata<HFONT>(L, LUAFONT);
	*font = hfont;
	return 1;
DEF_TAIL
DEF_HEAD(DeleteFont, 1)
	HFONT *font = (HFONT*)luaL_checkuserdata(L, 1, LUAFONT);
	DeleteObject(*font);
DEF_TAIL
DEF_HEAD(GetFontData, 1)
	HFONT *font = (HFONT*)luaL_checkuserdata(L, 1, LUAFONT);
	LOGFONT lf;
	ZeroMemory(&lf, sizeof(lf));
	GetObject(*font, sizeof(lf), &lf);
	lua_pushstring(L, lf.lfFaceName);
	lua_pushnumber(L, lf.lfHeight / FONT_SCALE);
	lua_pushboolean(L, lf.lfWeight == FW_BOLD);
	lua_pushboolean(L, lf.lfItalic);
	return 4;
DEF_TAIL
DEF_HEAD(TextExtents, 2)
	HFONT *font = (HFONT*)luaL_checkuserdata(L, 1, LUAFONT);
	wchar_t *wc = ctow(luaL_checkstring(L, 2));

	SIZE sz;
	TEXTMETRICW tm;
	HDC dc = CreateCompatibleDC(0);
	SetMapMode(dc, MM_TEXT);
	SelectObject(dc, *font);
	GetTextExtentPoint32W(dc, wc, wcslen(wc), &sz);
	GetTextMetricsW(dc,&tm);
	delete(wc);
	DeleteDC(dc);

	lua_pushnumber(L, sz.cx / FONT_SCALE);
	lua_pushnumber(L, sz.cy / FONT_SCALE);
	lua_pushnumber(L, tm.tmAscent / FONT_SCALE);
	lua_pushnumber(L, tm.tmDescent / FONT_SCALE);
	lua_pushnumber(L, tm.tmInternalLeading / FONT_SCALE);
	lua_pushnumber(L, tm.tmExternalLeading / FONT_SCALE);

	return 6;
DEF_TAIL
DEF_HEAD(GetFontPath, 2)
		//Get data
		HFONT *font = (HFONT*)luaL_checkuserdata(L, 1, LUAFONT);
		wchar_t *wc = ctow(luaL_checkstring(L, 2));
		//Create context
		HDC dc = CreateCompatibleDC(0);
		SetMapMode(dc, MM_TEXT);
		SelectObject(dc, *font);
		//Draw flatten path
		BeginPath(dc);
		TextOutW(dc, 0, 0, wc, wcslen(wc));
		EndPath(dc);
		FlattenPath(dc);
		//Get path
		long point_n = GetPath(dc, NULL, NULL, NULL);
		POINT *points = new POINT[point_n];
		BYTE *types = new BYTE[point_n];
		GetPath(dc, points, types, point_n);
		POINT *p; BYTE *t;
		p = points + 4;
		t = types + 4;
		//Path to Lua
		lua_createtable(L, point_n - 4, 0);
		for (int point_i = 0; point_i < point_n - 4; point_i++)
		{
			//New point
			lua_createtable(L, 0, 4);
			//type
			switch(t[point_i]){
				case PT_MOVETO: lua_pushnumber(L, 0x00); break;
				case PT_LINETO: lua_pushnumber(L, GLU_LINE); break;
				default: lua_pushnumber(L, 0x02); break;
			}
			lua_setfield(L, -2, (char*)"type");
			//x
			lua_pushnumber(L, p[point_i].x / FONT_SCALE);
			lua_setfield(L, -2, (char*)"x");
			//y
			lua_pushnumber(L, p[point_i].y / FONT_SCALE);
			lua_setfield(L, -2, (char*)"y");
			//z
			lua_pushnumber(L, 0);
			lua_setfield(L, -2, (char*)"z");
			//Set point
			lua_rawseti(L, -2, point_i + 1);
		}
		//Free memory
		delete(points);
		delete(types);
		DeleteDC(dc);
		delete(wc);
		return 1;
DEF_TAIL
//IMAGE
DEF_HEAD(flLoadPNG, 1)
	//Load PNG image
	std::vector<unsigned char> buffer, image;
	LodePNG::loadFile(buffer, luaL_checkstring(L, 1));
	LodePNG::Decoder decoder;
	decoder.decode(image, buffer.size() ? &buffer[0] : 0, (unsigned)buffer.size());
	if(decoder.hasError())
		error_msg(L, "cannot decode PNG image");

	//Image to Lua
	lua_createtable(L, image.size(), 2);
	lua_pushnumber(L, decoder.getWidth());
	lua_setfield(L, -2, "width");
	lua_pushnumber(L, decoder.getHeight());
	lua_setfield(L, -2, "height");
	for(unsigned int i = 0; i < image.size(); i++){
		lua_pushnumber(L, image[i]);
		lua_rawseti(L, -2, i+1);
	}

	return 1;
DEF_TAIL
DEF_HEAD(flSavePNG, 2)
	const char *filename = luaL_checkstring(L,1);

	luaL_argcheck(L, lua_istable(L, 2), 2, "table expected");
	unsigned int width, height;
	lua_getfield(L, 2, "width");
	if(!lua_isnumber(L, -1))
		error_msg(L, "invalid image table");
	else
		width = lua_tonumber(L, -1);
	lua_pop(L, 1);
	lua_getfield(L, 2, "height");
	if(!lua_isnumber(L, -1))
		error_msg(L, "invalid image table");
	else
		height = lua_tonumber(L, -1);
	lua_pop(L, 1);
	if(lua_objlen(L, 2) != width * height * 4)
		error_msg(L, "invalid image table");

	std::vector<unsigned char> image;
	image.resize(width * height * 4);
	for(unsigned int i = 0; i < lua_objlen(L, 2); i++){
		lua_rawgeti(L, 2, i+1);
		if(!lua_isnumber(L, -1))
			error_msg(L, "invalid image table");
		else
			image[i] = lua_tonumber(L, -1);
		lua_pop(L, 1);
	}

	//Encode
	std::vector<unsigned char> buffer;
	LodePNG::Encoder encoder;
	encoder.addText("Comment", "Created with FLuaG");
	encoder.encode(buffer, image, width, height);
	if(encoder.hasError())
		error_msg(L, "cannot encode PNG image");
	LodePNG::saveFile(buffer, filename);
DEF_TAIL
//MACROS
DEF_HEAD(flConvolutionFilter, 3)
	//Get filter arguments
	int width = luaL_checknumber(L, 1);
	int height = luaL_checknumber(L, 2);
	LuaArray<double> filter(L);
	filter.get(3);
	//Test arguments
	if(width < 1 || !(width & 1) || height < 1 || !(height & 1) || lua_objlen(L, 3) < width*height)
		error_msg(L, "invalid values");
	//Save
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//Get screen resolution
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	//Set screen matrices
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, viewport[2], viewport[3], 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Framebuffer to texture
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, viewport[2], viewport[3], 0);
	//Prepare buffers
	glClearColor(0, 0, 0, 0);
	glClearAccum(0, 0, 0, 0);
	glClear(GL_ACCUM_BUFFER_BIT);
	//Filter execution
	glEnable(GL_TEXTURE_2D);
	glColor4f(1, 1, 1, 1);
	GLdouble *fp = filter;
	for(int off_y = -(height-1)/2; off_y <= (height-1)/2; off_y++)
	{
		for(int off_x = -(width-1)/2; off_x <= (width-1)/2; off_x++)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(0, 0);
			glVertex2d(off_x, off_y + viewport[3]);
			glTexCoord2f(1, 0);
			glVertex2d(off_x + viewport[2], off_y + viewport[3]);
			glTexCoord2f(1, 1);
			glVertex2d(off_x + viewport[2], off_y);
			glTexCoord2f(0, 1);
			glVertex2d(off_x, off_y);
			glEnd();
			glAccum(GL_ACCUM, *fp++);
		}
	}
	glDisable(GL_TEXTURE_2D);
	//Final image from accumulation buffer to texture
	glAccum(GL_RETURN, 1);
	glClear(GL_ACCUM_BUFFER_BIT);
	glDeleteTextures(1, &tex);
	//Restore
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glPopAttrib();
DEF_TAIL
//INFO
DEF_HEAD(flGetVersion, 0)
	lua_pushstring(L, "0.6");
	return 1;
DEF_TAIL

inline void register_meta_fl(lua_State *L)
{
	luaL_newmetatable(L, LUAFONT);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, l_DeleteFont);
    lua_setfield(L, -2, "__gc");
}
inline void register_funcs_fl(lua_State *L)
{
	//Text
	REGISTER_FUNC(flCreateFont);
	luaL_newmetatable(L, LUAFONT);
	lua_pushcfunction(L, l_GetFontData);
    lua_setfield(L, -2, "getdata");
	lua_pushcfunction(L, l_TextExtents);
    lua_setfield(L, -2, "textextents");
	lua_pushcfunction(L, l_GetFontPath);
    lua_setfield(L, -2, "getpath");
	//Image
	REGISTER_FUNC(flLoadPNG);
	REGISTER_FUNC(flSavePNG);
	//Macros
	REGISTER_FUNC(flConvolutionFilter);
	//Info
	REGISTER_FUNC(flGetVersion);
}

void register_fl(lua_State *L){
	register_meta_fl(L);
	register_funcs_fl(L);
}