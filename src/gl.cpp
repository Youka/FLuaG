#include "env.h"
#define WINGDIAPI __declspec(dllimport)
#define APIENTRY __stdcall
#include <GL/gl.h>

DEF_HEAD(glAccum, 2)
	glAccum(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glAlphaFunc, 2)
	glAlphaFunc(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glAreTexturesResident, 2)
	unsigned int len = luaL_checknumber(L, 1);
    LuaArray<GLuint> texts(L);
    texts.get(2);
	LuaArray<GLboolean> vals(L, len);
	if(glAreTexturesResident(len, texts, vals))
		lua_pushnumber(L, GL_TRUE);
	else
		vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glArrayElement, 1)
	glArrayElement(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glBegin, 1)
	glBegin(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glBindTexture, 2)
	glBindTexture(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glBitmap, 7)
    LuaArray<GLubyte> bitmap(L);
	bitmap.get(2);
	glBitmap(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), bitmap);
DEF_TAIL
DEF_HEAD(glBlendFunc, 2)
	glBlendFunc(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glCallList, 1)
	glCallList(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glCallLists, 2)
    LuaArray<GLuint> lists(L);
	lists.get(2);
	glCallLists(luaL_checknumber(L, 1), GL_UNSIGNED_INT, lists);
DEF_TAIL
DEF_HEAD(glClear, 1)
	glClear(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glClearAccum, 4)
	glClearAccum(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glClearColor, 4)
	glClearColor(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glClearDepth, 1)
	glClearDepth(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glClearIndex, 1)
	glClearIndex(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glClearStencil, 1)
	glClearStencil(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glClipPlane, 2)
    LuaArray<GLdouble> plane(L);
	plane.get(2);
	glClipPlane(luaL_checknumber(L, 1), plane);
DEF_TAIL
DEF_HEAD(glColor, 4)
        glColor4f(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
    }else if(lua_gettop(L) == 3){
		glColor3f(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glColorMask, 4)
	glColorMask(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glColorMaterial, 2)
	glColorMaterial(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glColorPointer, 3)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 3);
	glColorPointer(luaL_checknumber(L, 1), GL_DOUBLE, luaL_checknumber(L, 2) * 8, vals);
DEF_TAIL
DEF_HEAD(glCopyPixels, 5)
	glCopyPixels(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(glCopyTexImage1D, 7)
	glCopyTexImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7));
DEF_TAIL
DEF_HEAD(glCopyTexImage2D, 8)
	glCopyTexImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8));
DEF_TAIL
DEF_HEAD(glCopyTexSubImage1D, 6)
	glCopyTexSubImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(glCopyTexSubImage2D, 8)
	glCopyTexSubImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8));
DEF_TAIL
DEF_HEAD(glCullFace, 1)
	glCullFace(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDeleteLists, 2)
	glDeleteLists(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glDeleteTextures, 2)
    LuaArray<GLuint> texts(L);
	texts.get(2);
	glDeleteTextures(luaL_checknumber(L, 1), texts);
DEF_TAIL
DEF_HEAD(glDepthFunc, 1)
	glDepthFunc(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDepthMask, 1)
	glDepthMask(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDepthRange, 2)
	glDepthRange(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glDisable, 1)
	glDisable(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDisableClientState, 1)
	glDisableClientState(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDrawArrays, 3)
	glDrawArrays(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glDrawBuffer, 1)
	glDrawBuffer(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glDrawElements, 3)
	LuaArray<GLuint> elem(L);
	elem.get(3);
	glDrawElements(luaL_checknumber(L, 1), luaL_checknumber(L, 2), GL_UNSIGNED_INT, elem);
DEF_TAIL
DEF_HEAD(glDrawPixels, 4)
    LuaArray<GLubyte> pixels(L);
	pixels.get(4);
	glDrawPixels(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glEdgeFlag, 1)
	glEdgeFlag(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glEdgeFlagPointer, 2)
	static GLboolean *vals = NULL;
	delete(vals);
	vals = (GLboolean*)luaL_checktable<bool>(L, 2);
	glEdgeFlagPointer(luaL_checknumber(L, 1), vals);
DEF_TAIL
DEF_HEAD(glEnable, 1)
	glEnable(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glEnableClientState, 1)
	glEnableClientState(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glEnd, 0)
	glEnd();
DEF_TAIL
DEF_HEAD(glEndList, 0)
	glEndList();
DEF_TAIL
DEF_HEAD(glEvalCoord, 1)
        glEvalCoord1d(luaL_checknumber(L, 1));
    }else if(lua_gettop(L) == 2){
		glEvalCoord2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glEvalMesh, 3)
        glEvalMesh1(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }else if(lua_gettop(L) == 5){
		glEvalMesh2(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(glEvalPoint, 1)
        glEvalPoint1(luaL_checknumber(L, 1));
    }else if(lua_gettop(L) == 2){
		glEvalPoint2(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEFINE(glFeedbackBuffer)
{
    static GLfloat *fbbuffer0 = NULL;
    static GLfloat *fbbuffer1 = NULL;
    static GLfloat *fbbuffer2 = NULL;
    static GLsizei fbsize0 = 0;
    static GLsizei fbsize1 = 0;
    static GLsizei fbsize2 = 0;
    if(lua_gettop(L) == 4 && luaL_checknumber(L, 1) == GL_SET)
    {
        switch(int(luaL_checknumber(L, 2))){
            case 0:
                delete(fbbuffer0);
                fbsize0 = luaL_checknumber(L, 3);
                fbbuffer0 = new GLfloat[fbsize0];
                memset(fbbuffer0, 0, sizeof(GLfloat) * fbsize0);
                glFeedbackBuffer(fbsize0, luaL_checknumber(L, 4), fbbuffer0);
                break;
            case 1:
                delete(fbbuffer1);
                fbsize1 = luaL_checknumber(L, 2);
                fbbuffer1 = new GLfloat[fbsize1];
                memset(fbbuffer1, 0, sizeof(GLfloat) * fbsize1);
                glFeedbackBuffer(fbsize1, luaL_checknumber(L, 3), fbbuffer1);
                break;
            case 2:
                delete(fbbuffer2);
                fbsize2 = luaL_checknumber(L, 2);
                fbbuffer2 = new GLfloat[fbsize2];
                memset(fbbuffer2, 0, sizeof(GLfloat) * fbsize2);
                glFeedbackBuffer(fbsize2, luaL_checknumber(L, 3), fbbuffer2);
                break;
            default: error_msg(L); break;
        }
    }else if(lua_gettop(L) == 2 && luaL_checknumber(L, 1) == GL_LOAD){
        switch(int(luaL_checknumber(L, 2))){
            case 0:
                if(fbbuffer0)
                    lua_pushtable(L, fbbuffer0, fbsize0);
                else
                    error_msg(L);
                break;
            case 1:
                if(fbbuffer1)
                    lua_pushtable(L, fbbuffer1, fbsize1);
                else
                    error_msg(L);
                break;
            case 2:
                if(fbbuffer2)
                    lua_pushtable(L, fbbuffer2, fbsize2);
                else
                    error_msg(L);
                break;
            default: error_msg(L); break;
        }
        return 1;
DEF_TAIL

DEF_HEAD(glFog, 2)
	if(lua_istable(L, 2))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(2);
		glFogfv(luaL_checknumber(L, 1), vals);
	}else
		glFogf(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glFrontFace, 1)
	glFrontFace(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glFrustum, 6)
	glFrustum(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(glGenLists, 1)
	lua_pushnumber(L, glGenLists(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glGenTextures, 1)
	unsigned int len = luaL_checknumber(L, 1);
	LuaArray<GLuint> texts(L, len);
	glGenTextures(len, texts);
    texts.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetBoolean, 2)
	LuaArray<GLboolean> vals(L, luaL_checknumber(L, 2));
	glGetBooleanv(luaL_checknumber(L, 1), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetClipPlane, 1)
	LuaArray<GLdouble> vals(L, 4);
	glGetClipPlane(luaL_checknumber(L, 1), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetNumber, 2)
	LuaArray<GLdouble> vals(L, luaL_checknumber(L, 2));
	glGetDoublev(luaL_checknumber(L, 1), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetError, 0)
	lua_pushnumber(L, glGetError());
	return 1;
DEF_TAIL
DEF_HEAD(glGetLight, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 2));
	glGetLightfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetMap, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetMapfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetMaterial, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetMaterialfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetPixelMap, 2)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 2));
	glGetPixelMapfv(luaL_checknumber(L, 1), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetPolygonStipple, 0)
	LuaArray<GLubyte> vals(L, 32 * 4);
	glGetPolygonStipple(vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetString, 1)
	lua_pushstring(L, (const char*)glGetString(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glGetTexEnv, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetTexEnvfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetTexGen, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetTexGenfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetTexImage, 4)
	LuaArray<GLubyte> vals(L, luaL_checknumber(L, 4));
	glGetTexImage(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), GL_UNSIGNED_BYTE, vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetTexLevelParameter, 4)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 4));
	glGetTexLevelParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetTexParameter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetTexParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
    vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glHint, 2)
	glHint(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glIndexMask, 1)
	glIndexMask(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glIndexPointer, 2)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 2);
	glIndexPointer(GL_DOUBLE, luaL_checknumber(L, 1) * 8, vals);
DEF_TAIL
DEF_HEAD(glIndex, 1)
	glIndexd(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glInitNames, 0)
	glInitNames();
DEF_TAIL
DEF_HEAD(glInterleavedArrays, 3)
	LuaArray<GLfloat> arrs(L);
	arrs.get(3);
	glInterleavedArrays(luaL_checknumber(L, 1), luaL_checknumber(L, 2) * 4, arrs);
DEF_TAIL
DEF_HEAD(glIsEnabled, 1)
	lua_pushboolean(L, glIsEnabled(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glIsList, 1)
	lua_pushboolean(L, glIsList(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glIsTexture, 1)
	lua_pushboolean(L, glIsTexture(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glLightModel, 2)
	if(lua_istable(L, 2))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(2);
		glLightModelfv(luaL_checknumber(L, 1), vals);
	}else
		glLightModelf(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glLight, 3)
	if(lua_istable(L, 3))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(3);
		glLightfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glLightf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glLineStipple, 2)
	glLineStipple(luaL_checknumber(L, 1), (GLushort)luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glLineWidth, 1)
	glLineWidth(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glListBase, 1)
	glListBase(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glLoadIdentity, 0)
	glLoadIdentity();
DEF_TAIL
DEF_HEAD(glLoadMatrix, 1)
    LuaArray<GLdouble> mat(L);
    mat.get(1);
	glLoadMatrixd(mat);
DEF_TAIL
DEF_HEAD(glLoadName, 1)
	glLoadName(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glLogicOp, 1)
	glLogicOp(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glMap, 10)
	LuaArray<GLdouble> map(L);
    map.get(10);
	glMap2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), luaL_checknumber(L, 9), map);
}else if(lua_gettop(L) == 6){
    LuaArray<GLdouble> map(L);
    map.get(6);
	glMap1d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), map);
DEF_TAIL
DEF_HEAD(glMapGrid, 3)
        glMapGrid1d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }else if(lua_gettop(L) == 6){
		glMapGrid2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(glMaterial, 3)
	if(lua_istable(L, 3))
	{
        LuaArray<GLfloat> vals(L);
        vals.get(3);
		glMaterialfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glMaterialf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glMatrixMode, 1)
	glMatrixMode(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glMultMatrix, 1)
    LuaArray<GLdouble> mat(L);
    mat.get(1);
	glMultMatrixd(mat);
DEF_TAIL
DEF_HEAD(glNewList, 2)
	glNewList(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glNormal, 3)
	glNormal3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glNormalPointer, 2)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 2);
	glNormalPointer(GL_DOUBLE, luaL_checknumber(L, 1) * 8, vals);
DEF_TAIL
DEF_HEAD(glOrtho, 6)
	glOrtho(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(glPassThrough, 1)
	glPassThrough(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glPixelMap, 3)
    LuaArray<GLfloat> map(L);
    map.get(3);
	glPixelMapfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), map);
DEF_TAIL
DEF_HEAD(glPixelStore, 2)
	glPixelStoref(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glPixelTransfer, 2)
	glPixelTransferf(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glPixelZoom, 2)
	glPixelZoom(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glPointSize, 1)
	glPointSize(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glPolygonMode, 2)
	glPolygonMode(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glPolygonOffset, 2)
	glPolygonOffset(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glPolygonStipple, 1)
    LuaArray<GLubyte> stipple(L);
    stipple.get(1);
	glPolygonStipple(stipple);
DEF_TAIL
DEF_HEAD(glPopAttrib, 0)
	glPopAttrib();
DEF_TAIL
DEF_HEAD(glPopClientAttrib, 0)
	glPopClientAttrib();
DEF_TAIL
DEF_HEAD(glPopMatrix, 0)
	glPopMatrix();
DEF_TAIL
DEF_HEAD(glPopName, 0)
	glPopName();
DEF_TAIL
DEF_HEAD(glPrioritizeTextures, 3)
    LuaArray<GLuint> texts(L);
    texts.get(2);
    LuaArray<GLfloat> prior(L);
    prior.get(3);
	glPrioritizeTextures(luaL_checknumber(L, 1), texts, prior);
DEF_TAIL
DEF_HEAD(glPushAttrib, 1)
	glPushAttrib(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glPushClientAttrib, 1)
	glPushClientAttrib(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glPushMatrix, 0)
	glPushMatrix();
DEF_TAIL
DEF_HEAD(glPushName, 1)
	glPushName(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glRasterPos, 3)
        glRasterPos3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }else if(lua_gettop(L) == 2){
		glRasterPos2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
	}else if(lua_gettop(L) == 4){
        glRasterPos4d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glReadBuffer, 1)
	glReadBuffer(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glReadPixels, 5)
	LuaArray<GLubyte> pixels(L, luaL_checknumber(L, 3) * luaL_checknumber(L, 4) * 4);
	glReadPixels(luaL_checknumber(L, 1), luaL_checknumber(L, 2), lua_tonumber(L, 3), lua_tonumber(L, 4), luaL_checknumber(L, 5), GL_UNSIGNED_BYTE, pixels);
    pixels.push();
	return 1;
DEF_TAIL
DEF_HEAD(glRect, 4)
	glRectd(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glRenderMode, 1)
	lua_pushnumber(L, glRenderMode(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glRotate, 4)
	glRotatef(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glScale, 3)
	glScalef(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glScissor, 4)
	glScissor(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEFINE(glSelectBuffer)
{
    static GLuint *sbuffer = NULL;
    static GLsizei ssize = 0;
    if(lua_gettop(L) == 2 && luaL_checknumber(L, 1) == GL_SET)
    {
        delete(sbuffer);
        ssize = luaL_checknumber(L, 2);
        sbuffer = new GLuint[ssize];
        memset(sbuffer, 0, sizeof(GLuint) * ssize);
        glSelectBuffer(ssize, sbuffer);
    }else if(lua_gettop(L) == 1 && luaL_checknumber(L, 1) == GL_LOAD && sbuffer){
        lua_pushtable(L, sbuffer, ssize);
        return 1;
DEF_TAIL
DEF_HEAD(glShadeModel, 1)
	glShadeModel(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glStencilFunc, 3)
	glStencilFunc(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glStencilMask, 1)
	glStencilMask(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glStencilOp, 3)
	glStencilOp(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glTexCoord, 3)
        glTexCoord3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }else if(lua_gettop(L) == 1){
		glTexCoord1d(luaL_checknumber(L, 1));
	}else if(lua_gettop(L) == 2){
        glTexCoord2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
    }else if(lua_gettop(L) == 4){
        glTexCoord4d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glTexCoordPointer, 3)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 3);
	glTexCoordPointer(luaL_checknumber(L, 1), GL_DOUBLE, luaL_checknumber(L, 2) * 8, vals);
DEF_TAIL
DEF_HEAD(glTexEnv, 3)
	if(lua_istable(L, 3))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(3);
		glTexEnvfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glTexEnvf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glTexGen, 3)
	if(lua_istable(L, 3))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(3);
		glTexGenfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glTexGenf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glTexImage1D, 7)
    LuaArray<GLubyte> pixels(L);
    pixels.get(7);
	glTexImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glTexImage2D, 8)
    LuaArray<GLubyte> pixels(L);
    pixels.get(8);
	glTexImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glTexParameter, 3)
	if(lua_istable(L, 3))
	{
		LuaArray<GLfloat> vals(L);
		vals.get(3);
		glTexParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glTexParameterf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glTexSubImage1D, 6)
    LuaArray<GLubyte> pixels(L);
    pixels.get(6);
	glTexSubImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glTexSubImage2D, 8)
    LuaArray<GLubyte> pixels(L);
    pixels.get(8);
	glTexSubImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glTranslate, 3)
	glTranslatef(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glVertex, 3)
        glVertex3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }else if(lua_gettop(L) == 2){
		glVertex2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
	}else if(lua_gettop(L) == 4){
			glVertex4d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glVertexPointer, 3)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 3);
	glVertexPointer(luaL_checknumber(L, 1), GL_DOUBLE, luaL_checknumber(L, 2) * 8, vals);
DEF_TAIL
DEF_HEAD(glViewport, 4)
	glViewport(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL

inline void register_constants_gl(lua_State *L)
{
	// Boolean values
	REGISTER_VAR(GL_FALSE);
	REGISTER_VAR(GL_TRUE);
	// Primitives
	REGISTER_VAR(GL_POINTS);
	REGISTER_VAR(GL_LINES);
	REGISTER_VAR(GL_LINE_LOOP);
	REGISTER_VAR(GL_LINE_STRIP);
	REGISTER_VAR(GL_TRIANGLES);
	REGISTER_VAR(GL_TRIANGLE_STRIP);
	REGISTER_VAR(GL_TRIANGLE_FAN);
	REGISTER_VAR(GL_QUADS);
	REGISTER_VAR(GL_QUAD_STRIP);
	REGISTER_VAR(GL_POLYGON);
	// Vertex Arrays
	REGISTER_VAR(GL_VERTEX_ARRAY);
	REGISTER_VAR(GL_NORMAL_ARRAY);
	REGISTER_VAR(GL_COLOR_ARRAY);
	REGISTER_VAR(GL_INDEX_ARRAY);
	REGISTER_VAR(GL_TEXTURE_COORD_ARRAY);
	REGISTER_VAR(GL_EDGE_FLAG_ARRAY);
	REGISTER_VAR(GL_VERTEX_ARRAY_SIZE);
	REGISTER_VAR(GL_VERTEX_ARRAY_TYPE);
	REGISTER_VAR(GL_VERTEX_ARRAY_STRIDE);
	REGISTER_VAR(GL_NORMAL_ARRAY_TYPE);
	REGISTER_VAR(GL_NORMAL_ARRAY_STRIDE);
	REGISTER_VAR(GL_COLOR_ARRAY_SIZE);
	REGISTER_VAR(GL_COLOR_ARRAY_TYPE);
	REGISTER_VAR(GL_COLOR_ARRAY_STRIDE);
	REGISTER_VAR(GL_INDEX_ARRAY_TYPE);
	REGISTER_VAR(GL_INDEX_ARRAY_STRIDE);
	REGISTER_VAR(GL_TEXTURE_COORD_ARRAY_SIZE);
	REGISTER_VAR(GL_TEXTURE_COORD_ARRAY_TYPE);
	REGISTER_VAR(GL_TEXTURE_COORD_ARRAY_STRIDE);
	REGISTER_VAR(GL_EDGE_FLAG_ARRAY_STRIDE);
	REGISTER_VAR(GL_VERTEX_ARRAY_POINTER);
	REGISTER_VAR(GL_NORMAL_ARRAY_POINTER);
	REGISTER_VAR(GL_COLOR_ARRAY_POINTER);
	REGISTER_VAR(GL_INDEX_ARRAY_POINTER);
	REGISTER_VAR(GL_TEXTURE_COORD_ARRAY_POINTER);
	REGISTER_VAR(GL_EDGE_FLAG_ARRAY_POINTER);
	REGISTER_VAR(GL_V2F);
	REGISTER_VAR(GL_V3F);
	REGISTER_VAR(GL_C3F_V3F);
	REGISTER_VAR(GL_N3F_V3F);
	REGISTER_VAR(GL_C4F_N3F_V3F);
	REGISTER_VAR(GL_T2F_V3F);
	REGISTER_VAR(GL_T4F_V4F);
	REGISTER_VAR(GL_T2F_C3F_V3F);
	REGISTER_VAR(GL_T2F_N3F_V3F);
	REGISTER_VAR(GL_T2F_C4F_N3F_V3F);
	REGISTER_VAR(GL_T4F_C4F_N3F_V4F);
	// Matrix Mode
	REGISTER_VAR(GL_MATRIX_MODE);
	REGISTER_VAR(GL_MODELVIEW);
	REGISTER_VAR(GL_PROJECTION);
	REGISTER_VAR(GL_TEXTURE);
	// Points
	REGISTER_VAR(GL_POINT_SMOOTH);
	REGISTER_VAR(GL_POINT_SIZE);
	REGISTER_VAR(GL_POINT_SIZE_GRANULARITY);
	REGISTER_VAR(GL_POINT_SIZE_RANGE);
	// Lines
	REGISTER_VAR(GL_LINE_SMOOTH);
	REGISTER_VAR(GL_LINE_STIPPLE);
	REGISTER_VAR(GL_LINE_STIPPLE_PATTERN);
	REGISTER_VAR(GL_LINE_STIPPLE_REPEAT);
	REGISTER_VAR(GL_LINE_WIDTH);
	REGISTER_VAR(GL_LINE_WIDTH_GRANULARITY);
	REGISTER_VAR(GL_LINE_WIDTH_RANGE);
	// Polygons
	REGISTER_VAR(GL_POINT);
	REGISTER_VAR(GL_LINE);
	REGISTER_VAR(GL_FILL);
	REGISTER_VAR(GL_CW);
	REGISTER_VAR(GL_CCW);
	REGISTER_VAR(GL_FRONT);
	REGISTER_VAR(GL_BACK);
	REGISTER_VAR(GL_POLYGON_MODE);
	REGISTER_VAR(GL_POLYGON_SMOOTH);
	REGISTER_VAR(GL_POLYGON_STIPPLE);
	REGISTER_VAR(GL_EDGE_FLAG);
	REGISTER_VAR(GL_CULL_FACE);
	REGISTER_VAR(GL_CULL_FACE_MODE);
	REGISTER_VAR(GL_FRONT_FACE);
	REGISTER_VAR(GL_POLYGON_OFFSET_FACTOR);
	REGISTER_VAR(GL_POLYGON_OFFSET_UNITS);
	REGISTER_VAR(GL_POLYGON_OFFSET_POINT);
	REGISTER_VAR(GL_POLYGON_OFFSET_LINE);
	REGISTER_VAR(GL_POLYGON_OFFSET_FILL);
	// Display Lists
	REGISTER_VAR(GL_COMPILE);
	REGISTER_VAR(GL_COMPILE_AND_EXECUTE);
	REGISTER_VAR(GL_LIST_BASE);
	REGISTER_VAR(GL_LIST_INDEX);
	REGISTER_VAR(GL_LIST_MODE);
	// Depth buffer
	REGISTER_VAR(GL_NEVER);
	REGISTER_VAR(GL_LESS);
	REGISTER_VAR(GL_EQUAL);
	REGISTER_VAR(GL_LEQUAL);
	REGISTER_VAR(GL_GREATER);
	REGISTER_VAR(GL_NOTEQUAL);
	REGISTER_VAR(GL_GEQUAL);
	REGISTER_VAR(GL_ALWAYS);
	REGISTER_VAR(GL_DEPTH_TEST);
	REGISTER_VAR(GL_DEPTH_BITS);
	REGISTER_VAR(GL_DEPTH_CLEAR_VALUE);
	REGISTER_VAR(GL_DEPTH_FUNC);
	REGISTER_VAR(GL_DEPTH_RANGE);
	REGISTER_VAR(GL_DEPTH_WRITEMASK);
	REGISTER_VAR(GL_DEPTH_COMPONENT);
	// Lighting
	REGISTER_VAR(GL_LIGHTING);
	REGISTER_VAR(GL_LIGHT0);
	REGISTER_VAR(GL_LIGHT1);
	REGISTER_VAR(GL_LIGHT2);
	REGISTER_VAR(GL_LIGHT3);
	REGISTER_VAR(GL_LIGHT4);
	REGISTER_VAR(GL_LIGHT5);
	REGISTER_VAR(GL_LIGHT6);
	REGISTER_VAR(GL_LIGHT7);
	REGISTER_VAR(GL_SPOT_EXPONENT);
	REGISTER_VAR(GL_SPOT_CUTOFF);
	REGISTER_VAR(GL_CONSTANT_ATTENUATION);
	REGISTER_VAR(GL_LINEAR_ATTENUATION);
	REGISTER_VAR(GL_QUADRATIC_ATTENUATION);
	REGISTER_VAR(GL_AMBIENT);
	REGISTER_VAR(GL_DIFFUSE);
	REGISTER_VAR(GL_SPECULAR);
	REGISTER_VAR(GL_SHININESS);
	REGISTER_VAR(GL_EMISSION);
	REGISTER_VAR(GL_POSITION);
	REGISTER_VAR(GL_SPOT_DIRECTION);
	REGISTER_VAR(GL_AMBIENT_AND_DIFFUSE);
	REGISTER_VAR(GL_COLOR_INDEXES);
	REGISTER_VAR(GL_LIGHT_MODEL_TWO_SIDE);
	REGISTER_VAR(GL_LIGHT_MODEL_LOCAL_VIEWER);
	REGISTER_VAR(GL_LIGHT_MODEL_AMBIENT);
	REGISTER_VAR(GL_FRONT_AND_BACK);
	REGISTER_VAR(GL_SHADE_MODEL);
	REGISTER_VAR(GL_FLAT);
	REGISTER_VAR(GL_SMOOTH);
	REGISTER_VAR(GL_COLOR_MATERIAL);
	REGISTER_VAR(GL_COLOR_MATERIAL_FACE);
	REGISTER_VAR(GL_COLOR_MATERIAL_PARAMETER);
	REGISTER_VAR(GL_NORMALIZE);
	// User clipping planes
	REGISTER_VAR(GL_CLIP_PLANE0);
	REGISTER_VAR(GL_CLIP_PLANE1);
	REGISTER_VAR(GL_CLIP_PLANE2);
	REGISTER_VAR(GL_CLIP_PLANE3);
	REGISTER_VAR(GL_CLIP_PLANE4);
	REGISTER_VAR(GL_CLIP_PLANE5);
	// Accumulation buffer
	REGISTER_VAR(GL_ACCUM_RED_BITS);
	REGISTER_VAR(GL_ACCUM_GREEN_BITS);
	REGISTER_VAR(GL_ACCUM_BLUE_BITS);
	REGISTER_VAR(GL_ACCUM_ALPHA_BITS);
	REGISTER_VAR(GL_ACCUM_CLEAR_VALUE);
	REGISTER_VAR(GL_ACCUM);
	REGISTER_VAR(GL_ADD);
	REGISTER_VAR(GL_LOAD);
	REGISTER_VAR(GL_MULT);
	REGISTER_VAR(GL_RETURN);
	// Alpha testing
	REGISTER_VAR(GL_ALPHA_TEST);
	REGISTER_VAR(GL_ALPHA_TEST_REF);
	REGISTER_VAR(GL_ALPHA_TEST_FUNC);
	// Blending
	REGISTER_VAR(GL_BLEND);
	REGISTER_VAR(GL_BLEND_SRC);
	REGISTER_VAR(GL_BLEND_DST);
	REGISTER_VAR(GL_ZERO);
	REGISTER_VAR(GL_ONE);
	REGISTER_VAR(GL_SRC_COLOR);
	REGISTER_VAR(GL_ONE_MINUS_SRC_COLOR);
	REGISTER_VAR(GL_SRC_ALPHA);
	REGISTER_VAR(GL_ONE_MINUS_SRC_ALPHA);
	REGISTER_VAR(GL_DST_ALPHA);
	REGISTER_VAR(GL_ONE_MINUS_DST_ALPHA);
	REGISTER_VAR(GL_DST_COLOR);
	REGISTER_VAR(GL_ONE_MINUS_DST_COLOR);
	REGISTER_VAR(GL_SRC_ALPHA_SATURATE);
	//REGISTER_VAR(GL_CONSTANT_COLOR);
	//REGISTER_VAR(GL_ONE_MINUS_CONSTANT_COLOR);
	//REGISTER_VAR(GL_CONSTANT_ALPHA);
	//REGISTER_VAR(GL_ONE_MINUS_CONSTANT_ALPHA);
	// Render Mode
	REGISTER_VAR(GL_FEEDBACK);
	REGISTER_VAR(GL_RENDER);
	REGISTER_VAR(GL_SELECT);
	// Feedback
	REGISTER_VAR(GL_2D);
	REGISTER_VAR(GL_3D);
	REGISTER_VAR(GL_3D_COLOR);
	REGISTER_VAR(GL_3D_COLOR_TEXTURE);
	REGISTER_VAR(GL_4D_COLOR_TEXTURE);
	REGISTER_VAR(GL_POINT_TOKEN);
	REGISTER_VAR(GL_LINE_TOKEN);
	REGISTER_VAR(GL_LINE_RESET_TOKEN);
	REGISTER_VAR(GL_POLYGON_TOKEN);
	REGISTER_VAR(GL_BITMAP_TOKEN);
	REGISTER_VAR(GL_DRAW_PIXEL_TOKEN);
	REGISTER_VAR(GL_COPY_PIXEL_TOKEN);
	REGISTER_VAR(GL_PASS_THROUGH_TOKEN);
	REGISTER_VAR(GL_FEEDBACK_BUFFER_POINTER);
	REGISTER_VAR(GL_FEEDBACK_BUFFER_SIZE);
	REGISTER_VAR(GL_FEEDBACK_BUFFER_TYPE);
	// Selection
	REGISTER_VAR(GL_SELECTION_BUFFER_POINTER);
	REGISTER_VAR(GL_SELECTION_BUFFER_SIZE);
	// Fog
	REGISTER_VAR(GL_FOG);
	REGISTER_VAR(GL_FOG_MODE);
	REGISTER_VAR(GL_FOG_DENSITY);
	REGISTER_VAR(GL_FOG_COLOR);
	REGISTER_VAR(GL_FOG_INDEX);
	REGISTER_VAR(GL_FOG_START);
	REGISTER_VAR(GL_FOG_END);
	REGISTER_VAR(GL_LINEAR);
	REGISTER_VAR(GL_EXP);
	REGISTER_VAR(GL_EXP2);
	// Logic Ops
	REGISTER_VAR(GL_LOGIC_OP);
	REGISTER_VAR(GL_INDEX_LOGIC_OP);
	REGISTER_VAR(GL_COLOR_LOGIC_OP);
	REGISTER_VAR(GL_LOGIC_OP_MODE);
	REGISTER_VAR(GL_CLEAR);
	REGISTER_VAR(GL_SET);
	REGISTER_VAR(GL_COPY);
	REGISTER_VAR(GL_COPY_INVERTED);
	REGISTER_VAR(GL_NOOP);
	REGISTER_VAR(GL_INVERT);
	REGISTER_VAR(GL_AND);
	REGISTER_VAR(GL_NAND);
	REGISTER_VAR(GL_OR);
	REGISTER_VAR(GL_NOR);
	REGISTER_VAR(GL_XOR);
	REGISTER_VAR(GL_EQUIV);
	REGISTER_VAR(GL_AND_REVERSE);
	REGISTER_VAR(GL_AND_INVERTED);
	REGISTER_VAR(GL_OR_REVERSE);
	REGISTER_VAR(GL_OR_INVERTED);
	// Stencil
	REGISTER_VAR(GL_STENCIL_TEST);
	REGISTER_VAR(GL_STENCIL_WRITEMASK);
	REGISTER_VAR(GL_STENCIL_BITS);
	REGISTER_VAR(GL_STENCIL_FUNC);
	REGISTER_VAR(GL_STENCIL_VALUE_MASK);
	REGISTER_VAR(GL_STENCIL_REF);
	REGISTER_VAR(GL_STENCIL_FAIL);
	REGISTER_VAR(GL_STENCIL_PASS_DEPTH_PASS);
	REGISTER_VAR(GL_STENCIL_PASS_DEPTH_FAIL);
	REGISTER_VAR(GL_STENCIL_CLEAR_VALUE);
	REGISTER_VAR(GL_STENCIL_INDEX);
	REGISTER_VAR(GL_KEEP);
	REGISTER_VAR(GL_REPLACE);
	REGISTER_VAR(GL_INCR);
	REGISTER_VAR(GL_DECR);
	// Buffers, Pixel Drawing/Reading
	REGISTER_VAR(GL_NONE);
	REGISTER_VAR(GL_LEFT);
	REGISTER_VAR(GL_RIGHT);
	REGISTER_VAR(GL_FRONT_LEFT);
	REGISTER_VAR(GL_FRONT_RIGHT);
	REGISTER_VAR(GL_BACK_LEFT);
	REGISTER_VAR(GL_BACK_RIGHT);
	REGISTER_VAR(GL_AUX0);
	REGISTER_VAR(GL_AUX1);
	REGISTER_VAR(GL_AUX2);
	REGISTER_VAR(GL_AUX3);
	REGISTER_VAR(GL_COLOR_INDEX);
	REGISTER_VAR(GL_RED);
	REGISTER_VAR(GL_GREEN);
	REGISTER_VAR(GL_BLUE);
	REGISTER_VAR(GL_ALPHA);
	REGISTER_VAR(GL_LUMINANCE);
	REGISTER_VAR(GL_LUMINANCE_ALPHA);
	REGISTER_VAR(GL_ALPHA_BITS);
	REGISTER_VAR(GL_RED_BITS);
	REGISTER_VAR(GL_GREEN_BITS);
	REGISTER_VAR(GL_BLUE_BITS);
	REGISTER_VAR(GL_INDEX_BITS);
	REGISTER_VAR(GL_SUBPIXEL_BITS);
	REGISTER_VAR(GL_AUX_BUFFERS);
	REGISTER_VAR(GL_READ_BUFFER);
	REGISTER_VAR(GL_DRAW_BUFFER);
	REGISTER_VAR(GL_DOUBLEBUFFER);
	REGISTER_VAR(GL_STEREO);
	REGISTER_VAR(GL_BITMAP);
	REGISTER_VAR(GL_COLOR);
	REGISTER_VAR(GL_DEPTH);
	REGISTER_VAR(GL_STENCIL);
	REGISTER_VAR(GL_DITHER);
	REGISTER_VAR(GL_RGB);
	REGISTER_VAR(GL_RGBA);
	// Implementation limits
	REGISTER_VAR(GL_MAX_LIST_NESTING);
	REGISTER_VAR(GL_MAX_ATTRIB_STACK_DEPTH);
	REGISTER_VAR(GL_MAX_MODELVIEW_STACK_DEPTH);
	REGISTER_VAR(GL_MAX_NAME_STACK_DEPTH);
	REGISTER_VAR(GL_MAX_PROJECTION_STACK_DEPTH);
	REGISTER_VAR(GL_MAX_TEXTURE_STACK_DEPTH);
	REGISTER_VAR(GL_MAX_EVAL_ORDER);
	REGISTER_VAR(GL_MAX_LIGHTS);
	REGISTER_VAR(GL_MAX_CLIP_PLANES);
	REGISTER_VAR(GL_MAX_TEXTURE_SIZE);
	REGISTER_VAR(GL_MAX_PIXEL_MAP_TABLE);
	REGISTER_VAR(GL_MAX_VIEWPORT_DIMS);
	REGISTER_VAR(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH);
	// Gets
	REGISTER_VAR(GL_ATTRIB_STACK_DEPTH);
	REGISTER_VAR(GL_CLIENT_ATTRIB_STACK_DEPTH);
	REGISTER_VAR(GL_COLOR_CLEAR_VALUE);
	REGISTER_VAR(GL_COLOR_WRITEMASK);
	REGISTER_VAR(GL_CURRENT_INDEX);
	REGISTER_VAR(GL_CURRENT_COLOR);
	REGISTER_VAR(GL_CURRENT_NORMAL);
	REGISTER_VAR(GL_CURRENT_RASTER_COLOR);
	REGISTER_VAR(GL_CURRENT_RASTER_DISTANCE);
	REGISTER_VAR(GL_CURRENT_RASTER_INDEX);
	REGISTER_VAR(GL_CURRENT_RASTER_POSITION);
	REGISTER_VAR(GL_CURRENT_RASTER_TEXTURE_COORDS);
	REGISTER_VAR(GL_CURRENT_RASTER_POSITION_VALID);
	REGISTER_VAR(GL_CURRENT_TEXTURE_COORDS);
	REGISTER_VAR(GL_INDEX_CLEAR_VALUE);
	REGISTER_VAR(GL_INDEX_MODE);
	REGISTER_VAR(GL_INDEX_WRITEMASK);
	REGISTER_VAR(GL_MODELVIEW_MATRIX);
	REGISTER_VAR(GL_MODELVIEW_STACK_DEPTH);
	REGISTER_VAR(GL_NAME_STACK_DEPTH);
	REGISTER_VAR(GL_PROJECTION_MATRIX);
	REGISTER_VAR(GL_PROJECTION_STACK_DEPTH);
	REGISTER_VAR(GL_RENDER_MODE);
	REGISTER_VAR(GL_RGBA_MODE);
	REGISTER_VAR(GL_TEXTURE_MATRIX);
	REGISTER_VAR(GL_TEXTURE_STACK_DEPTH);
	REGISTER_VAR(GL_VIEWPORT);
	// Evaluators
	REGISTER_VAR(GL_AUTO_NORMAL);
	REGISTER_VAR(GL_MAP1_COLOR_4);
	REGISTER_VAR(GL_MAP1_GRID_DOMAIN);
	REGISTER_VAR(GL_MAP1_GRID_SEGMENTS);
	REGISTER_VAR(GL_MAP1_INDEX);
	REGISTER_VAR(GL_MAP1_NORMAL);
	REGISTER_VAR(GL_MAP1_TEXTURE_COORD_1);
	REGISTER_VAR(GL_MAP1_TEXTURE_COORD_2);
	REGISTER_VAR(GL_MAP1_TEXTURE_COORD_3);
	REGISTER_VAR(GL_MAP1_TEXTURE_COORD_4);
	REGISTER_VAR(GL_MAP1_VERTEX_3);
	REGISTER_VAR(GL_MAP1_VERTEX_4);
	REGISTER_VAR(GL_MAP2_COLOR_4);
	REGISTER_VAR(GL_MAP2_GRID_DOMAIN);
	REGISTER_VAR(GL_MAP2_GRID_SEGMENTS);
	REGISTER_VAR(GL_MAP2_INDEX);
	REGISTER_VAR(GL_MAP2_NORMAL);
	REGISTER_VAR(GL_MAP2_TEXTURE_COORD_1);
	REGISTER_VAR(GL_MAP2_TEXTURE_COORD_2);
	REGISTER_VAR(GL_MAP2_TEXTURE_COORD_3);
	REGISTER_VAR(GL_MAP2_TEXTURE_COORD_4);
	REGISTER_VAR(GL_MAP2_VERTEX_3);
	REGISTER_VAR(GL_MAP2_VERTEX_4);
	REGISTER_VAR(GL_COEFF);
	REGISTER_VAR(GL_DOMAIN);
	REGISTER_VAR(GL_ORDER);
	// Hints
	REGISTER_VAR(GL_FOG_HINT);
	REGISTER_VAR(GL_LINE_SMOOTH_HINT);
	REGISTER_VAR(GL_PERSPECTIVE_CORRECTION_HINT);
	REGISTER_VAR(GL_POINT_SMOOTH_HINT);
	REGISTER_VAR(GL_POLYGON_SMOOTH_HINT);
	REGISTER_VAR(GL_DONT_CARE);
	REGISTER_VAR(GL_FASTEST);
	REGISTER_VAR(GL_NICEST);
	// Scissor box
	REGISTER_VAR(GL_SCISSOR_TEST);
	REGISTER_VAR(GL_SCISSOR_BOX);
	// Pixel Mode / Transfer
	REGISTER_VAR(GL_MAP_COLOR);
	REGISTER_VAR(GL_MAP_STENCIL);
	REGISTER_VAR(GL_INDEX_SHIFT);
	REGISTER_VAR(GL_INDEX_OFFSET);
	REGISTER_VAR(GL_RED_SCALE);
	REGISTER_VAR(GL_RED_BIAS);
	REGISTER_VAR(GL_GREEN_SCALE);
	REGISTER_VAR(GL_GREEN_BIAS);
	REGISTER_VAR(GL_BLUE_SCALE);
	REGISTER_VAR(GL_BLUE_BIAS);
	REGISTER_VAR(GL_ALPHA_SCALE);
	REGISTER_VAR(GL_ALPHA_BIAS);
	REGISTER_VAR(GL_DEPTH_SCALE);
	REGISTER_VAR(GL_DEPTH_BIAS);
	REGISTER_VAR(GL_PIXEL_MAP_S_TO_S_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_I_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_R_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_G_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_B_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_A_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_R_TO_R_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_G_TO_G_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_B_TO_B_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_A_TO_A_SIZE);
	REGISTER_VAR(GL_PIXEL_MAP_S_TO_S);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_I);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_R);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_G);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_B);
	REGISTER_VAR(GL_PIXEL_MAP_I_TO_A);
	REGISTER_VAR(GL_PIXEL_MAP_R_TO_R);
	REGISTER_VAR(GL_PIXEL_MAP_G_TO_G);
	REGISTER_VAR(GL_PIXEL_MAP_B_TO_B);
	REGISTER_VAR(GL_PIXEL_MAP_A_TO_A);
	REGISTER_VAR(GL_PACK_ALIGNMENT);
	REGISTER_VAR(GL_PACK_LSB_FIRST);
	REGISTER_VAR(GL_PACK_ROW_LENGTH);
	REGISTER_VAR(GL_PACK_SKIP_PIXELS);
	REGISTER_VAR(GL_PACK_SKIP_ROWS);
	REGISTER_VAR(GL_PACK_SWAP_BYTES);
	REGISTER_VAR(GL_UNPACK_ALIGNMENT);
	REGISTER_VAR(GL_UNPACK_LSB_FIRST);
	REGISTER_VAR(GL_UNPACK_ROW_LENGTH);
	REGISTER_VAR(GL_UNPACK_SKIP_PIXELS);
	REGISTER_VAR(GL_UNPACK_SKIP_ROWS);
	REGISTER_VAR(GL_UNPACK_SWAP_BYTES);
	REGISTER_VAR(GL_ZOOM_X);
	REGISTER_VAR(GL_ZOOM_Y);
	// Texture mapping
	REGISTER_VAR(GL_TEXTURE_ENV);
	REGISTER_VAR(GL_TEXTURE_ENV_MODE);
	REGISTER_VAR(GL_TEXTURE_1D);
	REGISTER_VAR(GL_TEXTURE_2D);
	REGISTER_VAR(GL_TEXTURE_WRAP_S);
	REGISTER_VAR(GL_TEXTURE_WRAP_T);
	REGISTER_VAR(GL_TEXTURE_MAG_FILTER);
	REGISTER_VAR(GL_TEXTURE_MIN_FILTER);
	REGISTER_VAR(GL_TEXTURE_ENV_COLOR);
	REGISTER_VAR(GL_TEXTURE_GEN_S);
	REGISTER_VAR(GL_TEXTURE_GEN_T);
	REGISTER_VAR(GL_TEXTURE_GEN_MODE);
	REGISTER_VAR(GL_TEXTURE_BORDER_COLOR);
	REGISTER_VAR(GL_TEXTURE_WIDTH);
	REGISTER_VAR(GL_TEXTURE_HEIGHT);
	REGISTER_VAR(GL_TEXTURE_BORDER);
	REGISTER_VAR(GL_TEXTURE_COMPONENTS);
	REGISTER_VAR(GL_TEXTURE_RED_SIZE);
	REGISTER_VAR(GL_TEXTURE_GREEN_SIZE);
	REGISTER_VAR(GL_TEXTURE_BLUE_SIZE);
	REGISTER_VAR(GL_TEXTURE_ALPHA_SIZE);
	REGISTER_VAR(GL_TEXTURE_LUMINANCE_SIZE);
	REGISTER_VAR(GL_TEXTURE_INTENSITY_SIZE);
	REGISTER_VAR(GL_NEAREST_MIPMAP_NEAREST);
	REGISTER_VAR(GL_NEAREST_MIPMAP_LINEAR);
	REGISTER_VAR(GL_LINEAR_MIPMAP_NEAREST);
	REGISTER_VAR(GL_LINEAR_MIPMAP_LINEAR);
	REGISTER_VAR(GL_OBJECT_LINEAR);
	REGISTER_VAR(GL_OBJECT_PLANE);
	REGISTER_VAR(GL_EYE_LINEAR);
	REGISTER_VAR(GL_EYE_PLANE);
	REGISTER_VAR(GL_SPHERE_MAP);
	REGISTER_VAR(GL_DECAL);
	REGISTER_VAR(GL_MODULATE);
	REGISTER_VAR(GL_NEAREST);
	REGISTER_VAR(GL_REPEAT);
	REGISTER_VAR(GL_CLAMP);
	REGISTER_VAR(GL_S);
	REGISTER_VAR(GL_T);
	REGISTER_VAR(GL_R);
	REGISTER_VAR(GL_Q);
	REGISTER_VAR(GL_TEXTURE_GEN_R);
	REGISTER_VAR(GL_TEXTURE_GEN_Q);
	// Utility
	REGISTER_VAR(GL_VENDOR);
	REGISTER_VAR(GL_RENDERER);
	REGISTER_VAR(GL_VERSION);
	REGISTER_VAR(GL_EXTENSIONS);
	// Errors
	REGISTER_VAR(GL_NO_ERROR);
	REGISTER_VAR(GL_INVALID_VALUE);
	REGISTER_VAR(GL_INVALID_ENUM);
	REGISTER_VAR(GL_INVALID_OPERATION);
	REGISTER_VAR(GL_STACK_OVERFLOW);
	REGISTER_VAR(GL_STACK_UNDERFLOW);
	REGISTER_VAR(GL_OUT_OF_MEMORY);
	// glPush/PopAttrib bits
	REGISTER_VAR(GL_CURRENT_BIT);
	REGISTER_VAR(GL_POINT_BIT);
	REGISTER_VAR(GL_LINE_BIT);
	REGISTER_VAR(GL_POLYGON_BIT);
	REGISTER_VAR(GL_POLYGON_STIPPLE_BIT);
	REGISTER_VAR(GL_PIXEL_MODE_BIT);
	REGISTER_VAR(GL_LIGHTING_BIT);
	REGISTER_VAR(GL_FOG_BIT);
	REGISTER_VAR(GL_DEPTH_BUFFER_BIT);
	REGISTER_VAR(GL_ACCUM_BUFFER_BIT);
	REGISTER_VAR(GL_STENCIL_BUFFER_BIT);
	REGISTER_VAR(GL_VIEWPORT_BIT);
	REGISTER_VAR(GL_TRANSFORM_BIT);
	REGISTER_VAR(GL_ENABLE_BIT);
	REGISTER_VAR(GL_COLOR_BUFFER_BIT);
	REGISTER_VAR(GL_HINT_BIT);
	REGISTER_VAR(GL_EVAL_BIT);
	REGISTER_VAR(GL_LIST_BIT);
	REGISTER_VAR(GL_TEXTURE_BIT);
	REGISTER_VAR(GL_SCISSOR_BIT);
	REGISTER_VAR(GL_ALL_ATTRIB_BITS);
	// OpenGL 1.1
	REGISTER_VAR(GL_PROXY_TEXTURE_1D);
	REGISTER_VAR(GL_PROXY_TEXTURE_2D);
	REGISTER_VAR(GL_TEXTURE_PRIORITY);
	REGISTER_VAR(GL_TEXTURE_RESIDENT);
	REGISTER_VAR(GL_TEXTURE_BINDING_1D);
	REGISTER_VAR(GL_TEXTURE_BINDING_2D);
	REGISTER_VAR(GL_TEXTURE_INTERNAL_FORMAT);
	REGISTER_VAR(GL_ALPHA4);
	REGISTER_VAR(GL_ALPHA8);
	REGISTER_VAR(GL_ALPHA12);
	REGISTER_VAR(GL_ALPHA16);
	REGISTER_VAR(GL_LUMINANCE4);
	REGISTER_VAR(GL_LUMINANCE8);
	REGISTER_VAR(GL_LUMINANCE12);
	REGISTER_VAR(GL_LUMINANCE16);
	REGISTER_VAR(GL_LUMINANCE4_ALPHA4);
	REGISTER_VAR(GL_LUMINANCE6_ALPHA2);
	REGISTER_VAR(GL_LUMINANCE8_ALPHA8);
	REGISTER_VAR(GL_LUMINANCE12_ALPHA4);
	REGISTER_VAR(GL_LUMINANCE12_ALPHA12);
	REGISTER_VAR(GL_LUMINANCE16_ALPHA16);
	REGISTER_VAR(GL_INTENSITY);
	REGISTER_VAR(GL_INTENSITY4);
	REGISTER_VAR(GL_INTENSITY8);
	REGISTER_VAR(GL_INTENSITY12);
	REGISTER_VAR(GL_INTENSITY16);
	REGISTER_VAR(GL_R3_G3_B2);
	REGISTER_VAR(GL_RGB4);
	REGISTER_VAR(GL_RGB5);
	REGISTER_VAR(GL_RGB8);
	REGISTER_VAR(GL_RGB10);
	REGISTER_VAR(GL_RGB12);
	REGISTER_VAR(GL_RGB16);
	REGISTER_VAR(GL_RGBA2);
	REGISTER_VAR(GL_RGBA4);
	REGISTER_VAR(GL_RGB5_A1);
	REGISTER_VAR(GL_RGBA8);
	REGISTER_VAR(GL_RGB10_A2);
	REGISTER_VAR(GL_RGBA12);
	REGISTER_VAR(GL_RGBA16);
	REGISTER_VAR(GL_CLIENT_PIXEL_STORE_BIT);
	REGISTER_VAR(GL_CLIENT_VERTEX_ARRAY_BIT);
	//REGISTER_VAR(GL_ALL_CLIENT_ATTRIB_BITS);
	REGISTER_VAR(GL_CLIENT_ALL_ATTRIB_BITS);
}

inline void register_funcs_gl(lua_State *L)
{
	REGISTER_FUNC(glAccum);
	REGISTER_FUNC(glAlphaFunc);
	REGISTER_FUNC(glAreTexturesResident);
	REGISTER_FUNC(glArrayElement);
	REGISTER_FUNC(glBegin);
	REGISTER_FUNC(glBindTexture);
	REGISTER_FUNC(glBitmap);
	REGISTER_FUNC(glBlendFunc);
	REGISTER_FUNC(glCallList);
	REGISTER_FUNC(glCallLists);
	REGISTER_FUNC(glClear);
	REGISTER_FUNC(glClearAccum);
	REGISTER_FUNC(glClearColor);
	REGISTER_FUNC(glClearDepth);
	REGISTER_FUNC(glClearIndex);
	REGISTER_FUNC(glClearStencil);
	REGISTER_FUNC(glClipPlane);
	REGISTER_FUNC(glColor);
	REGISTER_FUNC(glColorMask);
	REGISTER_FUNC(glColorMaterial);
	REGISTER_FUNC(glColorPointer);
	REGISTER_FUNC(glCopyPixels);
	REGISTER_FUNC(glCopyTexImage1D);
	REGISTER_FUNC(glCopyTexImage2D);
	REGISTER_FUNC(glCopyTexSubImage1D);
	REGISTER_FUNC(glCopyTexSubImage2D);
	REGISTER_FUNC(glCullFace);
	REGISTER_FUNC(glDeleteLists);
	REGISTER_FUNC(glDeleteTextures);
	REGISTER_FUNC(glDepthFunc);
	REGISTER_FUNC(glDepthMask);
	REGISTER_FUNC(glDepthRange);
	REGISTER_FUNC(glDisable);
	REGISTER_FUNC(glDisableClientState);
	REGISTER_FUNC(glDrawArrays);
	REGISTER_FUNC(glDrawBuffer);
	REGISTER_FUNC(glDrawElements);
	REGISTER_FUNC(glDrawPixels);
	REGISTER_FUNC(glEdgeFlag);
	REGISTER_FUNC(glEdgeFlagPointer);
	REGISTER_FUNC(glEnable);
	REGISTER_FUNC(glEnableClientState);
	REGISTER_FUNC(glEnd);
	REGISTER_FUNC(glEndList);
	REGISTER_FUNC(glEvalCoord);
	REGISTER_FUNC(glEvalMesh);
	REGISTER_FUNC(glEvalPoint);
	REGISTER_FUNC(glFeedbackBuffer);
	REGISTER_FUNC(glFog);
	REGISTER_FUNC(glFrontFace);
	REGISTER_FUNC(glFrustum);
	REGISTER_FUNC(glGenLists);
	REGISTER_FUNC(glGenTextures);
	REGISTER_FUNC(glGetBoolean);
	REGISTER_FUNC(glGetClipPlane);
	REGISTER_FUNC(glGetNumber);
	REGISTER_FUNC(glGetError);
	REGISTER_FUNC(glGetLight);
	REGISTER_FUNC(glGetMap);
	REGISTER_FUNC(glGetMaterial);
	REGISTER_FUNC(glGetPixelMap);
	REGISTER_FUNC(glGetPolygonStipple);
	REGISTER_FUNC(glGetString);
	REGISTER_FUNC(glGetTexEnv);
	REGISTER_FUNC(glGetTexGen);
	REGISTER_FUNC(glGetTexImage);
	REGISTER_FUNC(glGetTexLevelParameter);
	REGISTER_FUNC(glGetTexParameter);
	REGISTER_FUNC(glHint);
	REGISTER_FUNC(glIndexMask);
	REGISTER_FUNC(glIndex);
	REGISTER_FUNC(glIndexPointer);
	REGISTER_FUNC(glInitNames);
	REGISTER_FUNC(glInterleavedArrays); //just float values allowed
	REGISTER_FUNC(glIsEnabled);
	REGISTER_FUNC(glIsList);
	REGISTER_FUNC(glIsTexture);
	REGISTER_FUNC(glLightModel);
	REGISTER_FUNC(glLight);
	REGISTER_FUNC(glLineStipple);
	REGISTER_FUNC(glLineWidth);
	REGISTER_FUNC(glListBase);
	REGISTER_FUNC(glLoadIdentity);
	REGISTER_FUNC(glLoadMatrix);
	REGISTER_FUNC(glLoadName);
	REGISTER_FUNC(glLogicOp);
	REGISTER_FUNC(glMap);
	REGISTER_FUNC(glMapGrid);
	REGISTER_FUNC(glMaterial);
	REGISTER_FUNC(glMatrixMode);
	REGISTER_FUNC(glMultMatrix);
	REGISTER_FUNC(glNewList);
	REGISTER_FUNC(glNormal);
	REGISTER_FUNC(glNormalPointer);
	REGISTER_FUNC(glOrtho);
	REGISTER_FUNC(glPassThrough);
	REGISTER_FUNC(glPixelMap);
	REGISTER_FUNC(glPixelStore);
	REGISTER_FUNC(glPixelTransfer);
	REGISTER_FUNC(glPixelZoom);
	REGISTER_FUNC(glPointSize);
	REGISTER_FUNC(glPolygonMode);
	REGISTER_FUNC(glPolygonOffset);
	REGISTER_FUNC(glPolygonStipple);
	REGISTER_FUNC(glPopAttrib);
	REGISTER_FUNC(glPopClientAttrib);
	REGISTER_FUNC(glPopMatrix);
	REGISTER_FUNC(glPopName);
	REGISTER_FUNC(glPrioritizeTextures);
	REGISTER_FUNC(glPushAttrib);
	REGISTER_FUNC(glPushClientAttrib);
	REGISTER_FUNC(glPushMatrix);
	REGISTER_FUNC(glPushName);
	REGISTER_FUNC(glRasterPos);
	REGISTER_FUNC(glReadBuffer);
	REGISTER_FUNC(glReadPixels);
	REGISTER_FUNC(glRect);
	REGISTER_FUNC(glRenderMode);
	REGISTER_FUNC(glRotate);
	REGISTER_FUNC(glScale);
	REGISTER_FUNC(glScissor);
	REGISTER_FUNC(glSelectBuffer);
	REGISTER_FUNC(glShadeModel);
	REGISTER_FUNC(glStencilFunc);
	REGISTER_FUNC(glStencilMask);
	REGISTER_FUNC(glStencilOp);
	REGISTER_FUNC(glTexCoord);
	REGISTER_FUNC(glTexCoordPointer);
	REGISTER_FUNC(glTexEnv);
	REGISTER_FUNC(glTexGen);
	REGISTER_FUNC(glTexImage1D);
	REGISTER_FUNC(glTexImage2D);
	REGISTER_FUNC(glTexParameter);
	REGISTER_FUNC(glTexSubImage1D);
	REGISTER_FUNC(glTexSubImage2D);
	REGISTER_FUNC(glTranslate);
	REGISTER_FUNC(glVertex);
	REGISTER_FUNC(glVertexPointer);
	REGISTER_FUNC(glViewport);
}

void register_gl(lua_State *L){
	register_constants_gl(L);
	register_funcs_gl(L);
}