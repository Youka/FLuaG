#include "env.h"
#define WINGDIAPI __declspec(dllimport)
#define APIENTRY __stdcall
#define CALLBACK __stdcall
#include <GL/glu.h>

#define LUAQUADRIC (char*)"LuaQuadric"
typedef struct Lquadric{
  GLUquadric* quad;
}Lquadric;
#define LUANURBS (char*)"LuaNurbs"
typedef struct Lnurbs{
  GLUnurbs* nurbs;
}Lnurbs;

void __stdcall quad_nurbs_error(GLenum error)
{
	throw (const char*)gluErrorString(error);
}
DEF_HEAD(gluErrorString, 1)
	lua_pushstring(L, (const char*)gluErrorString(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(gluGetString, 1)
	lua_pushstring(L, (const char*)gluGetString(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(gluOrtho2D, 4)
	gluOrtho2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(gluPerspective, 4)
	gluPerspective(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(gluPickMatrix, 5)
	LuaArray<GLint> viewport(L);
	viewport.get(5);
	gluPickMatrix(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), viewport);
DEF_TAIL
DEF_HEAD(gluLookAt, 9)
	gluLookAt(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), luaL_checknumber(L, 9));
DEF_TAIL
DEF_HEAD(gluProject, 6)
	GLdouble winx, winy, winz;
	LuaArray<GLdouble> mMat(L);
	mMat.get(4);
	LuaArray<GLdouble> pMat(L);
	pMat.get(5);
	LuaArray<GLint> viewport(L);
	viewport.get(6);
	gluProject(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), mMat, pMat, viewport, &winx, &winy, &winz);
	lua_pushnumber(L, winx);
	lua_pushnumber(L, winy);
	lua_pushnumber(L, winz);
	return 3;
DEF_TAIL
DEF_HEAD(gluUnProject, 6)
	GLdouble objx, objy, objz;
	LuaArray<GLdouble> mMat(L);
	mMat.get(4);
	LuaArray<GLdouble> pMat(L);
	pMat.get(5);
	LuaArray<GLint> viewport(L);
	viewport.get(6);
	gluUnProject(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), mMat, pMat, viewport, &objx, &objy, &objz);
	lua_pushnumber(L, objx);
	lua_pushnumber(L, objy);
	lua_pushnumber(L, objz);
	return 3;
DEF_TAIL
DEF_HEAD(gluScaleImage, 7)
	LuaArray<GLubyte> data_in(L);
	data_in.get(4);
    LuaArray<GLfloat> dest(L, luaL_checknumber(L, 7));
	int err = gluScaleImage(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), GL_UNSIGNED_BYTE, data_in, luaL_checknumber(L, 5), luaL_checknumber(L, 6), GL_UNSIGNED_BYTE, dest);
	if(err)
		lua_pushnumber(L, err);
	else
		dest.push();
	return 1;
DEF_TAIL
DEF_HEAD(gluBuild1DMipmaps, 5)
	LuaArray<GLubyte> data_in(L);
	data_in.get(5);
	lua_pushnumber(L, gluBuild1DMipmaps(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), GL_UNSIGNED_BYTE, data_in));
	return 1;
DEF_TAIL
DEF_HEAD(gluBuild2DMipmaps, 6)
	LuaArray<GLubyte> data_in(L);
	data_in.get(6);
	lua_pushnumber(L, gluBuild2DMipmaps(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), GL_UNSIGNED_BYTE, data_in));
	return 1;
DEF_TAIL
DEF_HEAD(gluNewQuadric, 0)
	Lquadric *lquad = lua_createuserdata<Lquadric>(L, LUAQUADRIC);
	lquad->quad = gluNewQuadric();
	gluQuadricCallback(lquad->quad, GLU_ERROR, (void (__stdcall*)(void))quad_nurbs_error);
	return 1;
DEF_TAIL
DEF_HEAD(gluDeleteQuadric, 1)
	gluDeleteQuadric( ((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad );
DEF_TAIL
DEF_HEAD(gluQuadricNormals, 2)
	gluQuadricNormals(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(gluQuadricTexture, 2)
	gluQuadricTexture(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(gluQuadricOrientation, 2)
	gluQuadricOrientation(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(gluQuadricDrawStyle, 2)
	gluQuadricDrawStyle(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(gluCylinder, 6)
	gluCylinder(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(gluDisk, 5)
	gluDisk(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(gluPartialDisk, 7)
	gluPartialDisk(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7));
DEF_TAIL
DEF_HEAD(gluSphere, 4)
	gluSphere(((Lquadric*)luaL_checkuserdata(L, 1, LUAQUADRIC))->quad, luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(gluNewNurbsRenderer, 0)
	Lnurbs *lnurb = lua_createuserdata<Lnurbs>(L, LUANURBS);
	lnurb->nurbs = gluNewNurbsRenderer();
	gluNurbsCallback(lnurb->nurbs, GLU_ERROR, (void (__stdcall*)(void))quad_nurbs_error);
	return 1;
DEF_TAIL
DEF_HEAD(gluDeleteNurbsRenderer, 1)
	gluDeleteNurbsRenderer( ((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs );
DEF_TAIL
DEF_HEAD(gluBeginSurface, 1)
	gluBeginSurface(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluBeginCurve, 1)
	gluBeginCurve(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluEndCurve, 1)
	gluEndCurve(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluEndSurface, 1)
	gluEndSurface(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluBeginTrim, 1)
	gluBeginTrim(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluEndTrim, 1)
	gluEndTrim(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs);
DEF_TAIL
DEF_HEAD(gluPwlCurve, 5)
	LuaArray<GLfloat> data_in(L);
	data_in.get(3);
	gluPwlCurve(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, luaL_checknumber(L, 2), data_in, luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(gluNurbsCurve, 7)
	LuaArray<GLfloat> data_in_one(L);
	data_in_one.get(3);
	LuaArray<GLfloat> data_in_two(L);
	data_in_two.get(5);
	gluNurbsCurve(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, luaL_checknumber(L, 2), data_in_one, luaL_checknumber(L, 4), data_in_two, luaL_checknumber(L, 6), luaL_checknumber(L, 7));
DEF_TAIL
DEF_HEAD(gluNurbsSurface, 11)
	LuaArray<GLfloat> data_in_one(L);
	data_in_one.get(3);
	LuaArray<GLfloat> data_in_two(L);
	data_in_two.get(5);
	LuaArray<GLfloat> data_in_three(L);
	data_in_three.get(8);
	gluNurbsSurface(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, luaL_checknumber(L, 2), data_in_one, luaL_checknumber(L, 4), data_in_two, luaL_checknumber(L, 6), luaL_checknumber(L, 7), data_in_three, luaL_checknumber(L, 9), luaL_checknumber(L, 10), luaL_checknumber(L, 11));
DEF_TAIL
DEF_HEAD(gluLoadSamplingMatrices, 4)
	LuaArray<GLfloat> mMat(L);
	mMat.get(2);
	LuaArray<GLfloat> pMat(L);
	pMat.get(3);
	LuaArray<GLint> viewport(L);
	viewport.get(4);
	gluLoadSamplingMatrices(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, mMat, pMat, viewport);
DEF_TAIL
DEF_HEAD(gluNurbsProperty, 3)
	gluNurbsProperty(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(gluGetNurbsProperty, 2)
	GLfloat *val = NULL;
	gluGetNurbsProperty(((Lnurbs*)luaL_checkuserdata(L, 1, LUANURBS))->nurbs, luaL_checknumber(L, 2), val);
	lua_pushnumber(L, *val);
	return 1;
DEF_TAIL

inline void register_constants_glu(lua_State *L)
{
	REGISTER_VAR(GLU_VERSION_1_1);
	REGISTER_VAR(GLU_VERSION_1_2);
	REGISTER_VAR(GLU_INVALID_ENUM);
	REGISTER_VAR(GLU_INVALID_VALUE);
	REGISTER_VAR(GLU_OUT_OF_MEMORY);
	REGISTER_VAR(GLU_INCOMPATIBLE_GL_VERSION);
	REGISTER_VAR(GLU_VERSION);
	REGISTER_VAR(GLU_EXTENSIONS);
	REGISTER_VAR(GLU_TRUE);
	REGISTER_VAR(GLU_FALSE);
	REGISTER_VAR(GLU_SMOOTH);
	REGISTER_VAR(GLU_FLAT);
	REGISTER_VAR(GLU_NONE);
	REGISTER_VAR(GLU_POINT);
	REGISTER_VAR(GLU_LINE);
	REGISTER_VAR(GLU_FILL);
	REGISTER_VAR(GLU_SILHOUETTE);
	REGISTER_VAR(GLU_OUTSIDE);
	REGISTER_VAR(GLU_INSIDE);
	REGISTER_VAR(GLU_TESS_MAX_COORD);
	REGISTER_VAR(GLU_AUTO_LOAD_MATRIX);
	REGISTER_VAR(GLU_CULLING);
	REGISTER_VAR(GLU_SAMPLING_TOLERANCE);
	REGISTER_VAR(GLU_DISPLAY_MODE);
	REGISTER_VAR(GLU_PARAMETRIC_TOLERANCE);
	REGISTER_VAR(GLU_SAMPLING_METHOD);
	REGISTER_VAR(GLU_U_STEP);
	REGISTER_VAR(GLU_V_STEP);
	REGISTER_VAR(GLU_PATH_LENGTH);
	REGISTER_VAR(GLU_PARAMETRIC_ERROR);
	REGISTER_VAR(GLU_DOMAIN_DISTANCE);
	REGISTER_VAR(GLU_MAP1_TRIM_2);
	REGISTER_VAR(GLU_MAP1_TRIM_3);
	REGISTER_VAR(GLU_OUTLINE_POLYGON);
	REGISTER_VAR(GLU_OUTLINE_PATCH);
	REGISTER_VAR(GLU_CW);
	REGISTER_VAR(GLU_CCW);
	REGISTER_VAR(GLU_INTERIOR);
	REGISTER_VAR(GLU_EXTERIOR);
	REGISTER_VAR(GLU_UNKNOWN);
	REGISTER_VAR(GLU_BEGIN);
	REGISTER_VAR(GLU_VERTEX);
	REGISTER_VAR(GLU_END);
	REGISTER_VAR(GLU_ERROR);
	REGISTER_VAR(GLU_EDGE_FLAG);
}

inline void register_funcs_glu(lua_State *L)
{
	REGISTER_FUNC(gluErrorString);
	REGISTER_FUNC(gluGetString);
	REGISTER_FUNC(gluOrtho2D);
	REGISTER_FUNC(gluPerspective);
	REGISTER_FUNC(gluPickMatrix);
	REGISTER_FUNC(gluLookAt);
	REGISTER_FUNC(gluProject);
	REGISTER_FUNC(gluUnProject);
	REGISTER_FUNC(gluScaleImage);
	REGISTER_FUNC(gluBuild1DMipmaps);
	REGISTER_FUNC(gluBuild2DMipmaps);
	REGISTER_FUNC(gluNewQuadric);
	REGISTER_FUNC(gluQuadricNormals);
	REGISTER_FUNC(gluQuadricTexture);
	REGISTER_FUNC(gluQuadricOrientation);
	REGISTER_FUNC(gluQuadricDrawStyle);
	REGISTER_FUNC(gluCylinder);
	REGISTER_FUNC(gluDisk);
	REGISTER_FUNC(gluPartialDisk);
	REGISTER_FUNC(gluSphere);
	REGISTER_FUNC(gluNewNurbsRenderer);
	REGISTER_FUNC(gluBeginSurface);
	REGISTER_FUNC(gluBeginCurve);
	REGISTER_FUNC(gluEndCurve);
	REGISTER_FUNC(gluEndSurface);
	REGISTER_FUNC(gluBeginTrim);
	REGISTER_FUNC(gluEndTrim);
	REGISTER_FUNC(gluPwlCurve);
	REGISTER_FUNC(gluNurbsCurve);
	REGISTER_FUNC(gluNurbsSurface);
	REGISTER_FUNC(gluLoadSamplingMatrices);
	REGISTER_FUNC(gluNurbsProperty);
	REGISTER_FUNC(gluGetNurbsProperty);
}

inline void register_meta_glu(lua_State *L)
{
	luaL_newmetatable(L, LUAQUADRIC);
    lua_pushcfunction(L, l_gluDeleteQuadric);
    lua_setfield(L, -2, "__gc");
	luaL_newmetatable(L, LUANURBS);
    lua_pushcfunction(L, l_gluDeleteNurbsRenderer);
    lua_setfield(L, -2, "__gc");
}

void register_glu(lua_State *L){
	register_constants_glu(L);
    register_meta_glu(L);
	register_funcs_glu(L);
}