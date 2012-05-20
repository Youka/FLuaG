#include "env.h"
#define GLEW_STATIC 1
#include <GL/glew.h>

//1.2
DEF_HEAD(glCopyTexSubImage3D, 9)
	glCopyTexSubImage3D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), luaL_checknumber(L, 9));
DEF_TAIL
DEF_HEAD(glDrawRangeElements, 5)
	LuaArray<GLuint> vals(L);
	vals.get(5);
	glDrawRangeElements(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), GL_UNSIGNED_INT, vals);
DEF_TAIL
DEF_HEAD(glTexImage3D, 9)
    LuaArray<GLubyte> pixels(L);
    pixels.get(9);
	glTexImage3D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
DEF_HEAD(glTexSubImage3D, 10)
    LuaArray<GLubyte> pixels(L);
    pixels.get(10);
	glTexSubImage3D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), luaL_checknumber(L, 9), GL_UNSIGNED_BYTE, pixels);
DEF_TAIL
//1.3
DEF_HEAD(glActiveTexture, 1)
	glActiveTexture(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glClientActiveTexture, 1)
	glClientActiveTexture(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glCompressedTexImage1D, 7)	
	LuaArray<GLubyte> vals(L);
	vals.get(7);
	glCompressedTexImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), vals);
DEF_TAIL
DEF_HEAD(glCompressedTexImage2D, 8)
	LuaArray<GLubyte> vals(L);
	vals.get(8);
	glCompressedTexImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), vals);
DEF_TAIL
DEF_HEAD(glCompressedTexImage3D, 9)
	LuaArray<GLubyte> vals(L);
	vals.get(9);
	glCompressedTexImage3D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), vals);
DEF_TAIL
DEF_HEAD(glCompressedTexSubImage1D, 7)
	LuaArray<GLubyte> vals(L);
	vals.get(7);
	glCompressedTexSubImage1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), vals);
DEF_TAIL
DEF_HEAD(glCompressedTexSubImage2D, 9)
	LuaArray<GLubyte> vals(L);
	vals.get(9);
	glCompressedTexSubImage2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), vals);
DEF_TAIL
DEF_HEAD(glCompressedTexSubImage3D, 11)
	LuaArray<GLubyte> vals(L);
	vals.get(11);
	glCompressedTexSubImage3D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7), luaL_checknumber(L, 8), luaL_checknumber(L, 9), luaL_checknumber(L, 10), vals);
DEF_TAIL
DEF_HEAD(glGetCompressedTexImage, 3)
	LuaArray<GLubyte> vals(L, luaL_checknumber(L, 3));
	glGetCompressedTexImage(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glLoadTransposeMatrix, 1)
	LuaArray<GLdouble> mat(L);
	mat.get(1);
	glLoadTransposeMatrixd(mat);
DEF_TAIL
DEF_HEAD(glMultTransposeMatrix, 1)
	LuaArray<GLdouble> mat(L);
	mat.get(1);
	glMultTransposeMatrixd(mat);
DEF_TAIL
DEF_HEAD(glMultiTexCoord, 1)
		glMultiTexCoord1d(luaL_checknumber(L,1), luaL_checknumber(L,2));
	}else if(lua_gettop(L) == 2)
		glMultiTexCoord2d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3));
	else if(lua_gettop(L) == 3)
		glMultiTexCoord3d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
	else if(lua_gettop(L) == 4){
		glMultiTexCoord4d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glSampleCoverage, 2)
	glSampleCoverage(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
//1.4
DEF_HEAD(glBlendColor, 4)
	glBlendColor(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
DEF_TAIL
DEF_HEAD(glBlendEquation, 1)
	glBlendEquation(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glBlendFuncSeparate, 4)
	glBlendFuncSeparate(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
DEF_TAIL
DEF_HEAD(glFogCoordPointer, 2)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 2);
	glFogCoordPointer(GL_DOUBLE, luaL_checknumber(L, 1) * 8, vals);
DEF_TAIL
DEF_HEAD(glFogCoord, 1)
	glFogCoordd(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glMultiDrawArrays, 4)
	LuaArray<GLint> first(L);
	first.get(2);
	LuaArray<GLsizei> count(L);
	count.get(3);
	glMultiDrawArrays(luaL_checknumber(L, 1), first, count, luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glPointParameter, 2)
	if(lua_istable(L,2)){
		LuaArray<GLfloat> vals(L);
		vals.get(2);
		glPointParameterfv(luaL_checknumber(L, 1), vals);
	}else
		glPointParameterf(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glSecondaryColor, 3)
	glSecondaryColor3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glSecondaryColorPointer, 1)
	static GLdouble *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLdouble>(L, 1);
	glSecondaryColorPointer(3, GL_DOUBLE, 8, vals);
DEF_TAIL
DEF_HEAD(glWindowPos, 2)
		glWindowPos2d(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
	}else if(lua_gettop(L) == 3){
		glWindowPos3d(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
//1.5
DEF_HEAD(glBeginQuery, 2)
	glBeginQuery(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glBindBuffer, 2)
	glBindBuffer(luaL_checknumber(L, 1), luaL_checknumber(L, 2));
DEF_TAIL
DEF_HEAD(glBufferData, 4)
	LuaArray<GLubyte> vals(L);
	vals.get(3);
	glBufferData(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals, luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glBufferSubData, 4)
	LuaArray<GLubyte> vals(L);
	vals.get(4);
	glBufferSubData(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), vals);
DEF_TAIL
DEF_HEAD(glDeleteBuffers, 2)
	LuaArray<GLuint> vals(L);
	vals.get(2);
	glDeleteBuffers(luaL_checknumber(L, 1), vals);
DEF_TAIL
DEF_HEAD(glDeleteQueries, 2)
	LuaArray<GLuint> vals(L);
	vals.get(2);
	glDeleteQueries(luaL_checknumber(L, 1), vals);
DEF_TAIL
DEF_HEAD(glEndQuery, 1)
	glEndQuery(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glGenBuffers, 1)
	unsigned int len = luaL_checknumber(L, 1);
	LuaArray<GLuint> buffers(L, len);
	glGenBuffers(len, buffers);
	buffers.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGenQueries, 1)
	unsigned int len = luaL_checknumber(L, 1);
	LuaArray<GLuint> queries(L, len);
	glGenQueries(len, queries);
	queries.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetBufferParameter, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L, 3));
	glGetBufferParameteriv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetBufferSubData, 4)
	LuaArray<GLubyte> vals(L, luaL_checknumber(L, 4));
	glGetBufferSubData(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetQueryObject, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L, 3));
	glGetQueryObjectiv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetQuery, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L, 3));
	glGetQueryiv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glIsBuffer, 1)
	lua_pushboolean(L, glIsBuffer(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glIsQuery, 1)
	lua_pushboolean(L, glIsQuery(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glMapBuffer, 2)
	if(glMapBuffer(luaL_checknumber(L,1), luaL_checknumber(L,2)))
		lua_pushnumber(L, GL_TRUE);
	else
		lua_pushnumber(L, GL_FALSE);
	return 1;
DEF_TAIL
DEF_HEAD(glUnmapBuffer, 1)
	lua_pushnumber(L, glUnmapBuffer(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
//2.0
DEF_HEAD(glAttachShader, 2)
	glAttachShader(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glBindAttribLocation, 3)
	glBindAttribLocation(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checkstring(L, 3));
DEF_TAIL
DEF_HEAD(glBlendEquationSeparate, 2)
	glBlendEquationSeparate(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glCompileShader, 1)
	glCompileShader(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glCreateProgram, 0)
	lua_pushnumber(L, glCreateProgram());
	return 1;
DEF_TAIL
DEF_HEAD(glCreateShader, 1)
	lua_pushnumber(L, glCreateShader(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glDeleteProgram, 1)
	glDeleteProgram(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glDeleteShader, 1)
	glDeleteShader(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glDetachShader, 2)
	glDetachShader(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glDisableVertexAttribArray, 1)
	glDisableVertexAttribArray(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glDrawBuffers, 2)
	LuaArray<GLenum> vals(L);
	vals.get(2);
	glDrawBuffers(luaL_checknumber(L,1), vals);
DEF_TAIL
DEF_HEAD(glEnableVertexAttribArray, 1)
	glEnableVertexAttribArray(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glGetActiveAttrib, 3)
	GLsizei length;
	GLint size;
	GLenum type;
	GLchar *name;
	glGetActiveAttrib(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), &length, &size, &type, name);
	lua_pushnumber(L, length);
	lua_pushnumber(L, size);
	lua_pushnumber(L, type);
	lua_pushstring(L, name);
	delete(name);
	return 4;
DEF_TAIL
DEF_HEAD(glGetActiveUniform, 3)
	GLsizei length;
	GLint size;
	GLenum type;
	GLchar *name;
	glGetActiveUniform(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), &length, &size, &type, name);
	lua_pushnumber(L, length);
	lua_pushnumber(L, size);
	lua_pushnumber(L, type);
	lua_pushstring(L, name);
	delete(name);
	return 4;
DEF_TAIL
DEF_HEAD(glGetAttachedShaders, 2)
	GLsizei count;
	GLuint *shaders;
	glGetAttachedShaders(luaL_checknumber(L,1), luaL_checknumber(L,2), &count, shaders);
	lua_pushnumber(L, count);
	lua_pushtable(L, shaders, count);
	delete(shaders);
	return 2;
DEF_TAIL
DEF_HEAD(glGetAttribLocation, 2)
	lua_pushnumber(L, glGetAttribLocation(luaL_checknumber(L,1), luaL_checkstring(L, 2)));
	return 1;
DEF_TAIL
DEF_HEAD(glGetProgramInfoLog, 2)
	GLsizei length;
	GLchar *log;
	glGetProgramInfoLog(luaL_checknumber(L,1), luaL_checknumber(L,2), &length, log);
	lua_pushnumber(L, length);
	lua_pushstring(L, log);
	delete(log);
	return 2;
DEF_TAIL
DEF_HEAD(glGetProgram, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L,3));
	glGetProgramiv(luaL_checknumber(L,1), luaL_checknumber(L,2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetShaderInfoLog, 2)
	GLsizei length;
	GLchar *log;
	glGetShaderInfoLog(luaL_checknumber(L,1), luaL_checknumber(L,2), &length, log);
	lua_pushnumber(L, length);
	lua_pushstring(L, log);
	delete(log);
	return 2;
DEF_TAIL
DEF_HEAD(glGetShaderSource, 2)
	GLsizei length;
	GLchar *source;
	glGetShaderSource(luaL_checknumber(L,1), luaL_checknumber(L,2), &length, source);
	lua_pushnumber(L, length);
	lua_pushstring(L, source);
	delete(source);
	return 2;
DEF_TAIL
DEF_HEAD(glGetShader, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L,3));
	glGetShaderiv(luaL_checknumber(L,1), luaL_checknumber(L,2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetUniformLocation, 2)
	lua_pushnumber(L, glGetUniformLocation(luaL_checknumber(L,1), luaL_checkstring(L, 2)));
	return 1;
DEF_TAIL
DEF_HEAD(glGetUniform, 3)
	LuaArray<GLint> vals(L, luaL_checknumber(L,3));
	glGetUniformiv(luaL_checknumber(L,1), luaL_checknumber(L,2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetVertexAttrib, 3)
	LuaArray<GLdouble> vals(L, luaL_checknumber(L,3));
	glGetVertexAttribdv(luaL_checknumber(L,1), luaL_checknumber(L,2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glIsProgram, 1)
	lua_pushboolean(L, glIsProgram(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glIsShader, 1)
	lua_pushboolean(L, glIsShader(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glLinkProgram, 1)
	glLinkProgram(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glShaderSource, 2)
	const GLchar *source = luaL_checkstring(L, 2);
	glShaderSource(luaL_checknumber(L,1), 1, &source, NULL);
DEF_TAIL
DEF_HEAD(glStencilFuncSeparate, 4)
	glStencilFuncSeparate(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
DEF_TAIL
DEF_HEAD(glStencilMaskSeparate, 2)
	glStencilMaskSeparate(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glStencilOpSeparate, 4)
	glStencilOpSeparate(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
DEF_TAIL
DEF_HEAD(glUniform, 2)
		glUniform1f(luaL_checknumber(L,1), luaL_checknumber(L,2));
	}else if(lua_gettop(L) == 3)
		glUniform2f(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3));
	else if(lua_gettop(L) == 4)
		glUniform3f(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
	else if(lua_gettop(L) == 5){
		glUniform4f(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glUniformMatrix2, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix2fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix3, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix3fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix4, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix4fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUseProgram, 1)
	glUseProgram(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glValidateProgram, 1)
	glValidateProgram(luaL_checknumber(L,1));
DEF_TAIL
DEF_HEAD(glVertexAttrib, 2)
		glVertexAttrib1d(luaL_checknumber(L,1), luaL_checknumber(L,2));
	}else if(lua_gettop(L) == 3)
		glVertexAttrib2d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3));
	else if(lua_gettop(L) == 4)
		glVertexAttrib3d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
	else if(lua_gettop(L) == 5){
		glVertexAttrib4d(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glVertexAttribPointer, 4)
	static GLfloat *vals = NULL;
	delete(vals);
	vals = luaL_checktable<GLfloat>(L, 4);
	glVertexAttribPointer(luaL_checknumber(L,1), luaL_checknumber(L,2), GL_FLOAT, luaL_checknumber(L,3), 4, vals);
DEF_TAIL
//2.1
DEF_HEAD(glUniformMatrix2x3, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix2x3fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix2x4, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix2x4fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix3x2, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix3x2fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix3x4, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix3x4fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix4x2, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix4x2fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
DEF_HEAD(glUniformMatrix4x3, 4)
	LuaArray<GLfloat> mat(L);
	mat.get(4);
	glUniformMatrix4x3fv(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), mat);
DEF_TAIL
//Framebuffer
DEF_HEAD(glBindFramebuffer, 2)
	glBindFramebuffer(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glBindRenderbuffer, 2)
	glBindRenderbuffer(luaL_checknumber(L,1), luaL_checknumber(L,2));
DEF_TAIL
DEF_HEAD(glBlitFramebuffer, 10)
	glBlitFramebuffer(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5), luaL_checknumber(L,6), luaL_checknumber(L,7), luaL_checknumber(L,8), luaL_checknumber(L,9), luaL_checknumber(L,10));
DEF_TAIL
DEF_HEAD(glCheckFramebufferStatus, 1)
	lua_pushnumber(L, glCheckFramebufferStatus(luaL_checknumber(L,1)));
	return 1;
DEF_TAIL
DEF_HEAD(glDeleteFramebuffers, 2)
	LuaArray<GLuint> fbos(L);
	fbos.get(2);
	glDeleteFramebuffers(luaL_checknumber(L,1), fbos);
DEF_TAIL
DEF_HEAD(glDeleteRenderbuffers, 2)
	LuaArray<GLuint> rbos(L);
	rbos.get(2);
	glDeleteRenderbuffers(luaL_checknumber(L,1), rbos);
DEF_TAIL
DEF_HEAD(glFramebufferRenderbuffer, 4)
	glFramebufferRenderbuffer(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4));
DEF_TAIL
DEF_HEAD(glFramebufferTexture1D, 5)
	glFramebufferTexture1D(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glFramebufferTexture2D, 5)
	glFramebufferTexture2D(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glFramebufferTexture3D, 6)
	glFramebufferTexture3D(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5), luaL_checknumber(L,6));
DEF_TAIL
DEF_HEAD(glFramebufferTextureLayer, 5)
	glFramebufferTextureLayer(luaL_checknumber(L,1), luaL_checknumber(L,2), luaL_checknumber(L,3), luaL_checknumber(L,4), luaL_checknumber(L,5));
DEF_TAIL
DEF_HEAD(glGenFramebuffers, 1)
	unsigned long int len = luaL_checknumber(L, 1);
	LuaArray<GLuint> fbos(L, len);
	glGenFramebuffers(len, fbos);
	fbos.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGenRenderbuffers, 1)
	unsigned long int len = luaL_checknumber(L, 1);
	LuaArray<GLuint> rbos(L, len);
	glGenFramebuffers(len, rbos);
	rbos.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGenerateMipmap, 1)
	glGenerateMipmap(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glGetFramebufferAttachmentParameter, 3)
	GLint val;
	glGetFramebufferAttachmentParameteriv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), &val);
	lua_pushnumber(L, val);
	return 1;
DEF_TAIL
DEF_HEAD(glGetRenderbufferParameter, 2)
	GLint val;
	glGetRenderbufferParameteriv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), &val);
	lua_pushnumber(L, val);
	return 1;
DEF_TAIL
DEF_HEAD(glIsFramebuffer, 1)
	lua_pushboolean(L, glIsFramebuffer(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glIsRenderbuffer, 1)
	lua_pushboolean(L, glIsRenderbuffer(luaL_checknumber(L, 1)));
	return 1;
DEF_TAIL
DEF_HEAD(glRenderbufferStorage, 4)
	glRenderbufferStorage(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glRenderbufferStorageMultisample, 5)
	glRenderbufferStorageMultisample(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
//Imaging
DEF_HEAD(glColorSubTable, 5)
	LuaArray<GLfloat> vals(L);
	vals.get(5);
	glColorSubTable(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), GL_FLOAT, vals);
DEF_TAIL
DEF_HEAD(glColorTable, 5)
	LuaArray<GLfloat> vals(L);
	vals.get(5);
	glColorTable(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), GL_FLOAT, vals);
DEF_TAIL
DEF_HEAD(glColorTableParameter, 3)
	LuaArray<GLfloat> vals(L);
	vals.get(3);
	glColorTableParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
DEF_TAIL
DEF_HEAD(glConvolutionFilter1D, 5)
	LuaArray<GLfloat> vals(L);
	vals.get(5);
	glConvolutionFilter1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), GL_FLOAT, vals);
DEF_TAIL
DEF_HEAD(glConvolutionFilter2D, 6)
	LuaArray<GLfloat> vals(L);
	vals.get(6);
	glConvolutionFilter2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), GL_FLOAT, vals);
DEF_TAIL
DEF_HEAD(glConvolutionParameter, 3)
	if(lua_istable(L,3)){
		LuaArray<GLfloat> vals(L);
		vals.get(3);
		glConvolutionParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	}else
		glConvolutionParameterf(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glCopyColorSubTable, 5)
	glCopyColorSubTable(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(glCopyColorTable, 5)
	glCopyColorTable(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(glCopyConvolutionFilter1D, 5)
	glCopyConvolutionFilter1D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5));
DEF_TAIL
DEF_HEAD(glCopyConvolutionFilter2D, 6)
	glCopyConvolutionFilter2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), luaL_checknumber(L, 6));
DEF_TAIL
DEF_HEAD(glGetColorTable, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetColorTable(luaL_checknumber(L, 1), luaL_checknumber(L, 2), GL_FLOAT, vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetColorTableParameter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetColorTableParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetConvolutionFilter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetConvolutionFilter(luaL_checknumber(L, 1), luaL_checknumber(L, 2), GL_FLOAT, vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetConvolutionParameter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetConvolutionParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetHistogram, 4)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 4));
	glGetHistogram(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), GL_FLOAT, vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetHistogramParameter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetHistogramParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetMinmax, 4)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 4));
	glGetMinmax(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), GL_FLOAT, vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetMinmaxParameter, 3)
	LuaArray<GLfloat> vals(L, luaL_checknumber(L, 3));
	glGetMinmaxParameterfv(luaL_checknumber(L, 1), luaL_checknumber(L, 2), vals);
	vals.push();
	return 1;
DEF_TAIL
DEF_HEAD(glGetSeparableFilter, 4)
	LuaArray<GLfloat> row(L, luaL_checknumber(L, 3));
	LuaArray<GLfloat> column(L, luaL_checknumber(L, 4));
	glGetSeparableFilter(luaL_checknumber(L, 1), luaL_checknumber(L, 2), GL_FLOAT, row, column, NULL);
	row.push();
	column.push();
	return 2;
DEF_TAIL
DEF_HEAD(glHistogram, 4)
	glHistogram(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4));
DEF_TAIL
DEF_HEAD(glMinmax, 3)
	glMinmax(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3));
DEF_TAIL
DEF_HEAD(glResetHistogram, 1)
	glResetHistogram(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glResetMinmax, 1)
	glResetMinmax(luaL_checknumber(L, 1));
DEF_TAIL
DEF_HEAD(glSeparableFilter2D, 7)
	LuaArray<GLfloat> row(L);
	row.get(6);
	LuaArray<GLfloat> column(L);
	column.get(7);
	glSeparableFilter2D(luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4), luaL_checknumber(L, 5), GL_FLOAT, row, column);
DEF_TAIL

inline void register_constants_glext(lua_State *L)
{
	if(GLEW_VERSION_1_2){
		REGISTER_VAR(GL_VERSION_1_2);
		REGISTER_VAR(GL_SMOOTH_POINT_SIZE_RANGE);
		REGISTER_VAR(GL_SMOOTH_POINT_SIZE_GRANULARITY);
		REGISTER_VAR(GL_SMOOTH_LINE_WIDTH_RANGE);
		REGISTER_VAR(GL_SMOOTH_LINE_WIDTH_GRANULARITY);
		REGISTER_VAR(GL_RESCALE_NORMAL);
		REGISTER_VAR(GL_TEXTURE_BINDING_3D);
		REGISTER_VAR(GL_PACK_SKIP_IMAGES);
		REGISTER_VAR(GL_PACK_IMAGE_HEIGHT);
		REGISTER_VAR(GL_UNPACK_SKIP_IMAGES);
		REGISTER_VAR(GL_UNPACK_IMAGE_HEIGHT);
		REGISTER_VAR(GL_TEXTURE_3D);
		REGISTER_VAR(GL_PROXY_TEXTURE_3D);
		REGISTER_VAR(GL_TEXTURE_DEPTH);
		REGISTER_VAR(GL_TEXTURE_WRAP_R);
		REGISTER_VAR(GL_MAX_3D_TEXTURE_SIZE);
		REGISTER_VAR(GL_BGR);
		REGISTER_VAR(GL_BGRA);
		REGISTER_VAR(GL_MAX_ELEMENTS_VERTICES);
		REGISTER_VAR(GL_MAX_ELEMENTS_INDICES);
		REGISTER_VAR(GL_CLAMP_TO_EDGE);
		REGISTER_VAR(GL_TEXTURE_MIN_LOD);
		REGISTER_VAR(GL_TEXTURE_MAX_LOD);
		REGISTER_VAR(GL_TEXTURE_BASE_LEVEL);
		REGISTER_VAR(GL_TEXTURE_MAX_LEVEL);
		REGISTER_VAR(GL_LIGHT_MODEL_COLOR_CONTROL);
		REGISTER_VAR(GL_SINGLE_COLOR);
		REGISTER_VAR(GL_SEPARATE_SPECULAR_COLOR);
		REGISTER_VAR(GL_ALIASED_POINT_SIZE_RANGE);
		REGISTER_VAR(GL_ALIASED_LINE_WIDTH_RANGE);
	}
	if(GLEW_VERSION_1_3){
		REGISTER_VAR(GL_VERSION_1_3);
		REGISTER_VAR(GL_MULTISAMPLE);
		REGISTER_VAR(GL_SAMPLE_ALPHA_TO_COVERAGE);
		REGISTER_VAR(GL_SAMPLE_ALPHA_TO_ONE);
		REGISTER_VAR(GL_SAMPLE_COVERAGE);
		REGISTER_VAR(GL_SAMPLE_BUFFERS);
		REGISTER_VAR(GL_SAMPLES);
		REGISTER_VAR(GL_SAMPLE_COVERAGE_VALUE);
		REGISTER_VAR(GL_SAMPLE_COVERAGE_INVERT);
		REGISTER_VAR(GL_CLAMP_TO_BORDER);
		REGISTER_VAR(GL_TEXTURE0);
		REGISTER_VAR(GL_TEXTURE1);
		REGISTER_VAR(GL_TEXTURE2);
		REGISTER_VAR(GL_TEXTURE3);
		REGISTER_VAR(GL_TEXTURE4);
		REGISTER_VAR(GL_TEXTURE5);
		REGISTER_VAR(GL_TEXTURE6);
		REGISTER_VAR(GL_TEXTURE7);
		REGISTER_VAR(GL_TEXTURE8);
		REGISTER_VAR(GL_TEXTURE9);
		REGISTER_VAR(GL_TEXTURE10);
		REGISTER_VAR(GL_TEXTURE11);
		REGISTER_VAR(GL_TEXTURE12);
		REGISTER_VAR(GL_TEXTURE13);
		REGISTER_VAR(GL_TEXTURE14);
		REGISTER_VAR(GL_TEXTURE15);
		REGISTER_VAR(GL_TEXTURE16);
		REGISTER_VAR(GL_TEXTURE17);
		REGISTER_VAR(GL_TEXTURE18);
		REGISTER_VAR(GL_TEXTURE19);
		REGISTER_VAR(GL_TEXTURE20);
		REGISTER_VAR(GL_TEXTURE21);
		REGISTER_VAR(GL_TEXTURE22);
		REGISTER_VAR(GL_TEXTURE23);
		REGISTER_VAR(GL_TEXTURE24);
		REGISTER_VAR(GL_TEXTURE25);
		REGISTER_VAR(GL_TEXTURE26);
		REGISTER_VAR(GL_TEXTURE27);
		REGISTER_VAR(GL_TEXTURE28);
		REGISTER_VAR(GL_TEXTURE29);
		REGISTER_VAR(GL_TEXTURE30);
		REGISTER_VAR(GL_TEXTURE31);
		REGISTER_VAR(GL_ACTIVE_TEXTURE);
		REGISTER_VAR(GL_CLIENT_ACTIVE_TEXTURE);
		REGISTER_VAR(GL_MAX_TEXTURE_UNITS);
		REGISTER_VAR(GL_TRANSPOSE_MODELVIEW_MATRIX);
		REGISTER_VAR(GL_TRANSPOSE_PROJECTION_MATRIX);
		REGISTER_VAR(GL_TRANSPOSE_TEXTURE_MATRIX);
		REGISTER_VAR(GL_TRANSPOSE_COLOR_MATRIX);
		REGISTER_VAR(GL_SUBTRACT);
		REGISTER_VAR(GL_COMPRESSED_ALPHA);
		REGISTER_VAR(GL_COMPRESSED_LUMINANCE);
		REGISTER_VAR(GL_COMPRESSED_LUMINANCE_ALPHA);
		REGISTER_VAR(GL_COMPRESSED_INTENSITY);
		REGISTER_VAR(GL_COMPRESSED_RGB);
		REGISTER_VAR(GL_COMPRESSED_RGBA);
		REGISTER_VAR(GL_TEXTURE_COMPRESSION_HINT);
		REGISTER_VAR(GL_NORMAL_MAP);
		REGISTER_VAR(GL_REFLECTION_MAP);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP);
		REGISTER_VAR(GL_TEXTURE_BINDING_CUBE_MAP);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
		REGISTER_VAR(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
		REGISTER_VAR(GL_PROXY_TEXTURE_CUBE_MAP);
		REGISTER_VAR(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
		REGISTER_VAR(GL_COMBINE);
		REGISTER_VAR(GL_COMBINE_RGB);
		REGISTER_VAR(GL_COMBINE_ALPHA);
		REGISTER_VAR(GL_RGB_SCALE);
		REGISTER_VAR(GL_ADD_SIGNED);
		REGISTER_VAR(GL_INTERPOLATE);
		REGISTER_VAR(GL_CONSTANT);
		REGISTER_VAR(GL_PRIMARY_COLOR);
		REGISTER_VAR(GL_PREVIOUS);
		REGISTER_VAR(GL_SOURCE0_RGB);
		REGISTER_VAR(GL_SOURCE1_RGB);
		REGISTER_VAR(GL_SOURCE2_RGB);
		REGISTER_VAR(GL_SOURCE0_ALPHA);
		REGISTER_VAR(GL_SOURCE1_ALPHA);
		REGISTER_VAR(GL_SOURCE2_ALPHA);
		REGISTER_VAR(GL_OPERAND0_RGB);
		REGISTER_VAR(GL_OPERAND1_RGB);
		REGISTER_VAR(GL_OPERAND2_RGB);
		REGISTER_VAR(GL_OPERAND0_ALPHA);
		REGISTER_VAR(GL_OPERAND1_ALPHA);
		REGISTER_VAR(GL_OPERAND2_ALPHA);
		REGISTER_VAR(GL_TEXTURE_COMPRESSED_IMAGE_SIZE);
		REGISTER_VAR(GL_TEXTURE_COMPRESSED);
		REGISTER_VAR(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
		REGISTER_VAR(GL_COMPRESSED_TEXTURE_FORMATS);
		REGISTER_VAR(GL_DOT3_RGB);
		REGISTER_VAR(GL_DOT3_RGBA);
		REGISTER_VAR(GL_MULTISAMPLE_BIT);
	}
	if(GLEW_VERSION_1_4){
		REGISTER_VAR(GL_VERSION_1_4);
		REGISTER_VAR(GL_BLEND_DST_RGB);
		REGISTER_VAR(GL_BLEND_SRC_RGB);
		REGISTER_VAR(GL_BLEND_DST_ALPHA);
		REGISTER_VAR(GL_BLEND_SRC_ALPHA);
		REGISTER_VAR(GL_POINT_SIZE_MIN);
		REGISTER_VAR(GL_POINT_SIZE_MAX);
		REGISTER_VAR(GL_POINT_FADE_THRESHOLD_SIZE);
		REGISTER_VAR(GL_POINT_DISTANCE_ATTENUATION);
		REGISTER_VAR(GL_GENERATE_MIPMAP);
		REGISTER_VAR(GL_GENERATE_MIPMAP_HINT);
		REGISTER_VAR(GL_DEPTH_COMPONENT16);
		REGISTER_VAR(GL_DEPTH_COMPONENT24);
		REGISTER_VAR(GL_DEPTH_COMPONENT32);
		REGISTER_VAR(GL_MIRRORED_REPEAT);
		REGISTER_VAR(GL_FOG_COORDINATE_SOURCE);
		REGISTER_VAR(GL_FOG_COORDINATE);
		REGISTER_VAR(GL_FRAGMENT_DEPTH);
		REGISTER_VAR(GL_CURRENT_FOG_COORDINATE);
		REGISTER_VAR(GL_FOG_COORDINATE_ARRAY_TYPE);
		REGISTER_VAR(GL_FOG_COORDINATE_ARRAY_STRIDE);
		REGISTER_VAR(GL_FOG_COORDINATE_ARRAY_POINTER);
		REGISTER_VAR(GL_FOG_COORDINATE_ARRAY);
		REGISTER_VAR(GL_COLOR_SUM);
		REGISTER_VAR(GL_CURRENT_SECONDARY_COLOR);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY_SIZE);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY_TYPE);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY_STRIDE);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY_POINTER);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY);
		REGISTER_VAR(GL_MAX_TEXTURE_LOD_BIAS);
		REGISTER_VAR(GL_TEXTURE_FILTER_CONTROL);
		REGISTER_VAR(GL_TEXTURE_LOD_BIAS);
		REGISTER_VAR(GL_INCR_WRAP);
		REGISTER_VAR(GL_DECR_WRAP);
		REGISTER_VAR(GL_TEXTURE_DEPTH_SIZE);
		REGISTER_VAR(GL_DEPTH_TEXTURE_MODE);
		REGISTER_VAR(GL_TEXTURE_COMPARE_MODE);
		REGISTER_VAR(GL_TEXTURE_COMPARE_FUNC);
		REGISTER_VAR(GL_COMPARE_R_TO_TEXTURE);
	}
	if(GLEW_VERSION_1_5){
		REGISTER_VAR(GL_VERSION_1_5);
		REGISTER_VAR(GL_FOG_COORD_SRC);
		REGISTER_VAR(GL_FOG_COORD);
		REGISTER_VAR(GL_FOG_COORD_ARRAY);
		REGISTER_VAR(GL_SRC0_RGB);
		REGISTER_VAR(GL_FOG_COORD_ARRAY_POINTER);
		REGISTER_VAR(GL_FOG_COORD_ARRAY_TYPE);
		REGISTER_VAR(GL_SRC1_ALPHA);
		REGISTER_VAR(GL_CURRENT_FOG_COORD);
		REGISTER_VAR(GL_FOG_COORD_ARRAY_STRIDE);
		REGISTER_VAR(GL_SRC0_ALPHA);
		REGISTER_VAR(GL_SRC1_RGB);
		REGISTER_VAR(GL_FOG_COORD_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_SRC2_ALPHA);
		REGISTER_VAR(GL_SRC2_RGB);
		REGISTER_VAR(GL_BUFFER_SIZE);
		REGISTER_VAR(GL_BUFFER_USAGE);
		REGISTER_VAR(GL_QUERY_COUNTER_BITS);
		REGISTER_VAR(GL_CURRENT_QUERY);
		REGISTER_VAR(GL_QUERY_RESULT);
		REGISTER_VAR(GL_QUERY_RESULT_AVAILABLE);
		REGISTER_VAR(GL_ARRAY_BUFFER);
		REGISTER_VAR(GL_ELEMENT_ARRAY_BUFFER);
		REGISTER_VAR(GL_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_ELEMENT_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_VERTEX_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_NORMAL_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_COLOR_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_INDEX_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_WEIGHT_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);
		REGISTER_VAR(GL_READ_ONLY);
		REGISTER_VAR(GL_WRITE_ONLY);
		REGISTER_VAR(GL_READ_WRITE);
		REGISTER_VAR(GL_BUFFER_ACCESS);
		REGISTER_VAR(GL_BUFFER_MAPPED);
		REGISTER_VAR(GL_BUFFER_MAP_POINTER);
		REGISTER_VAR(GL_STREAM_DRAW);
		REGISTER_VAR(GL_STREAM_READ);
		REGISTER_VAR(GL_STREAM_COPY);
		REGISTER_VAR(GL_STATIC_DRAW);
		REGISTER_VAR(GL_STATIC_READ);
		REGISTER_VAR(GL_STATIC_COPY);
		REGISTER_VAR(GL_DYNAMIC_DRAW);
		REGISTER_VAR(GL_DYNAMIC_READ);
		REGISTER_VAR(GL_DYNAMIC_COPY);
		REGISTER_VAR(GL_SAMPLES_PASSED);
	}
	if(GLEW_VERSION_2_0){
		REGISTER_VAR(GL_VERSION_2_0);
		REGISTER_VAR(GL_BLEND_EQUATION_RGB);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_SIZE);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_TYPE);
		REGISTER_VAR(GL_CURRENT_VERTEX_ATTRIB);
		REGISTER_VAR(GL_VERTEX_PROGRAM_POINT_SIZE);
		REGISTER_VAR(GL_VERTEX_PROGRAM_TWO_SIDE);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_POINTER);
		REGISTER_VAR(GL_STENCIL_BACK_FUNC);
		REGISTER_VAR(GL_STENCIL_BACK_FAIL);
		REGISTER_VAR(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
		REGISTER_VAR(GL_STENCIL_BACK_PASS_DEPTH_PASS);
		REGISTER_VAR(GL_MAX_DRAW_BUFFERS);
		REGISTER_VAR(GL_DRAW_BUFFER0);
		REGISTER_VAR(GL_DRAW_BUFFER1);
		REGISTER_VAR(GL_DRAW_BUFFER2);
		REGISTER_VAR(GL_DRAW_BUFFER3);
		REGISTER_VAR(GL_DRAW_BUFFER4);
		REGISTER_VAR(GL_DRAW_BUFFER5);
		REGISTER_VAR(GL_DRAW_BUFFER6);
		REGISTER_VAR(GL_DRAW_BUFFER7);
		REGISTER_VAR(GL_DRAW_BUFFER8);
		REGISTER_VAR(GL_DRAW_BUFFER9);
		REGISTER_VAR(GL_DRAW_BUFFER10);
		REGISTER_VAR(GL_DRAW_BUFFER11);
		REGISTER_VAR(GL_DRAW_BUFFER12);
		REGISTER_VAR(GL_DRAW_BUFFER13);
		REGISTER_VAR(GL_DRAW_BUFFER14);
		REGISTER_VAR(GL_DRAW_BUFFER15);
		REGISTER_VAR(GL_BLEND_EQUATION_ALPHA);
		REGISTER_VAR(GL_POINT_SPRITE);
		REGISTER_VAR(GL_COORD_REPLACE);
		REGISTER_VAR(GL_MAX_VERTEX_ATTRIBS);
		REGISTER_VAR(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
		REGISTER_VAR(GL_MAX_TEXTURE_COORDS);
		REGISTER_VAR(GL_MAX_TEXTURE_IMAGE_UNITS);
		REGISTER_VAR(GL_FRAGMENT_SHADER);
		REGISTER_VAR(GL_VERTEX_SHADER);
		REGISTER_VAR(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
		REGISTER_VAR(GL_MAX_VERTEX_UNIFORM_COMPONENTS);
		REGISTER_VAR(GL_MAX_VARYING_FLOATS);
		REGISTER_VAR(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
		REGISTER_VAR(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
		REGISTER_VAR(GL_SHADER_TYPE);
		REGISTER_VAR(GL_FLOAT_VEC2);
		REGISTER_VAR(GL_FLOAT_VEC3);
		REGISTER_VAR(GL_FLOAT_VEC4);
		REGISTER_VAR(GL_INT_VEC2);
		REGISTER_VAR(GL_INT_VEC3);
		REGISTER_VAR(GL_INT_VEC4);
		REGISTER_VAR(GL_BOOL);
		REGISTER_VAR(GL_BOOL_VEC2);
		REGISTER_VAR(GL_BOOL_VEC3);
		REGISTER_VAR(GL_BOOL_VEC4);
		REGISTER_VAR(GL_FLOAT_MAT2);
		REGISTER_VAR(GL_FLOAT_MAT3);
		REGISTER_VAR(GL_FLOAT_MAT4);
		REGISTER_VAR(GL_SAMPLER_1D);
		REGISTER_VAR(GL_SAMPLER_2D);
		REGISTER_VAR(GL_SAMPLER_3D);
		REGISTER_VAR(GL_SAMPLER_CUBE);
		REGISTER_VAR(GL_SAMPLER_1D_SHADOW);
		REGISTER_VAR(GL_SAMPLER_2D_SHADOW);
		REGISTER_VAR(GL_DELETE_STATUS);
		REGISTER_VAR(GL_COMPILE_STATUS);
		REGISTER_VAR(GL_LINK_STATUS);
		REGISTER_VAR(GL_VALIDATE_STATUS);
		REGISTER_VAR(GL_INFO_LOG_LENGTH);
		REGISTER_VAR(GL_ATTACHED_SHADERS);
		REGISTER_VAR(GL_ACTIVE_UNIFORMS);
		REGISTER_VAR(GL_ACTIVE_UNIFORM_MAX_LENGTH);
		REGISTER_VAR(GL_SHADER_SOURCE_LENGTH);
		REGISTER_VAR(GL_ACTIVE_ATTRIBUTES);
		REGISTER_VAR(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
		REGISTER_VAR(GL_FRAGMENT_SHADER_DERIVATIVE_HINT);
		REGISTER_VAR(GL_SHADING_LANGUAGE_VERSION);
		REGISTER_VAR(GL_CURRENT_PROGRAM);
		REGISTER_VAR(GL_POINT_SPRITE_COORD_ORIGIN);
		REGISTER_VAR(GL_LOWER_LEFT);
		REGISTER_VAR(GL_UPPER_LEFT);
		REGISTER_VAR(GL_STENCIL_BACK_REF);
		REGISTER_VAR(GL_STENCIL_BACK_VALUE_MASK);
		REGISTER_VAR(GL_STENCIL_BACK_WRITEMASK);
	}
	if(GLEW_VERSION_2_1){
		REGISTER_VAR(GL_VERSION_2_1);
		REGISTER_VAR(GL_CURRENT_RASTER_SECONDARY_COLOR);
		REGISTER_VAR(GL_PIXEL_PACK_BUFFER);
		REGISTER_VAR(GL_PIXEL_UNPACK_BUFFER);
		REGISTER_VAR(GL_PIXEL_PACK_BUFFER_BINDING);
		REGISTER_VAR(GL_PIXEL_UNPACK_BUFFER_BINDING);
		REGISTER_VAR(GL_FLOAT_MAT2x3);
		REGISTER_VAR(GL_FLOAT_MAT2x4);
		REGISTER_VAR(GL_FLOAT_MAT3x2);
		REGISTER_VAR(GL_FLOAT_MAT3x4);
		REGISTER_VAR(GL_FLOAT_MAT4x2);
		REGISTER_VAR(GL_FLOAT_MAT4x3);
		REGISTER_VAR(GL_SRGB);
		REGISTER_VAR(GL_SRGB8);
		REGISTER_VAR(GL_SRGB_ALPHA);
		REGISTER_VAR(GL_SRGB8_ALPHA8);
		REGISTER_VAR(GL_SLUMINANCE_ALPHA);
		REGISTER_VAR(GL_SLUMINANCE8_ALPHA8);
		REGISTER_VAR(GL_SLUMINANCE);
		REGISTER_VAR(GL_SLUMINANCE8);
		REGISTER_VAR(GL_COMPRESSED_SRGB);
		REGISTER_VAR(GL_COMPRESSED_SRGB_ALPHA);
		REGISTER_VAR(GL_COMPRESSED_SLUMINANCE);
		REGISTER_VAR(GL_COMPRESSED_SLUMINANCE_ALPHA);
	}
	if(GLEW_ARB_framebuffer_object){
		REGISTER_VAR(GL_ARB_framebuffer_object);
		REGISTER_VAR(GL_INVALID_FRAMEBUFFER_OPERATION);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_DEFAULT);
		REGISTER_VAR(GL_FRAMEBUFFER_UNDEFINED);
		REGISTER_VAR(GL_DEPTH_STENCIL_ATTACHMENT);
		REGISTER_VAR(GL_INDEX);
		REGISTER_VAR(GL_MAX_RENDERBUFFER_SIZE);
		REGISTER_VAR(GL_DEPTH_STENCIL);
		REGISTER_VAR(GL_UNSIGNED_INT_24_8);
		REGISTER_VAR(GL_DEPTH24_STENCIL8);
		REGISTER_VAR(GL_TEXTURE_STENCIL_SIZE);
		REGISTER_VAR(GL_UNSIGNED_NORMALIZED);
		REGISTER_VAR(GL_SRGB);
		REGISTER_VAR(GL_DRAW_FRAMEBUFFER_BINDING);
		REGISTER_VAR(GL_FRAMEBUFFER_BINDING);
		REGISTER_VAR(GL_RENDERBUFFER_BINDING);
		REGISTER_VAR(GL_READ_FRAMEBUFFER);
		REGISTER_VAR(GL_DRAW_FRAMEBUFFER);
		REGISTER_VAR(GL_READ_FRAMEBUFFER_BINDING);
		REGISTER_VAR(GL_RENDERBUFFER_SAMPLES);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);
		REGISTER_VAR(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER);
		REGISTER_VAR(GL_FRAMEBUFFER_COMPLETE);
		REGISTER_VAR(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
		REGISTER_VAR(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
		REGISTER_VAR(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER);
		REGISTER_VAR(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER);
		REGISTER_VAR(GL_FRAMEBUFFER_UNSUPPORTED);
		REGISTER_VAR(GL_MAX_COLOR_ATTACHMENTS);
		REGISTER_VAR(GL_COLOR_ATTACHMENT0);
		REGISTER_VAR(GL_COLOR_ATTACHMENT1);
		REGISTER_VAR(GL_COLOR_ATTACHMENT2);
		REGISTER_VAR(GL_COLOR_ATTACHMENT3);
		REGISTER_VAR(GL_COLOR_ATTACHMENT4);
		REGISTER_VAR(GL_COLOR_ATTACHMENT5);
		REGISTER_VAR(GL_COLOR_ATTACHMENT6);
		REGISTER_VAR(GL_COLOR_ATTACHMENT7);
		REGISTER_VAR(GL_COLOR_ATTACHMENT8);
		REGISTER_VAR(GL_COLOR_ATTACHMENT9);
		REGISTER_VAR(GL_COLOR_ATTACHMENT10);
		REGISTER_VAR(GL_COLOR_ATTACHMENT11);
		REGISTER_VAR(GL_COLOR_ATTACHMENT12);
		REGISTER_VAR(GL_COLOR_ATTACHMENT13);
		REGISTER_VAR(GL_COLOR_ATTACHMENT14);
		REGISTER_VAR(GL_COLOR_ATTACHMENT15);
		REGISTER_VAR(GL_DEPTH_ATTACHMENT);
		REGISTER_VAR(GL_STENCIL_ATTACHMENT);
		REGISTER_VAR(GL_FRAMEBUFFER);
		REGISTER_VAR(GL_RENDERBUFFER);
		REGISTER_VAR(GL_RENDERBUFFER_WIDTH);
		REGISTER_VAR(GL_RENDERBUFFER_HEIGHT);
		REGISTER_VAR(GL_RENDERBUFFER_INTERNAL_FORMAT);
		REGISTER_VAR(GL_STENCIL_INDEX1);
		REGISTER_VAR(GL_STENCIL_INDEX4);
		REGISTER_VAR(GL_STENCIL_INDEX8);
		REGISTER_VAR(GL_STENCIL_INDEX16);
		REGISTER_VAR(GL_RENDERBUFFER_RED_SIZE);
		REGISTER_VAR(GL_RENDERBUFFER_GREEN_SIZE);
		REGISTER_VAR(GL_RENDERBUFFER_BLUE_SIZE);
		REGISTER_VAR(GL_RENDERBUFFER_ALPHA_SIZE);
		REGISTER_VAR(GL_RENDERBUFFER_DEPTH_SIZE);
		REGISTER_VAR(GL_RENDERBUFFER_STENCIL_SIZE);
		REGISTER_VAR(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE);
		REGISTER_VAR(GL_MAX_SAMPLES);
	}
	if(GLEW_ARB_imaging){
		REGISTER_VAR(GL_ARB_imaging);
		REGISTER_VAR(GL_CONSTANT_COLOR);
		REGISTER_VAR(GL_ONE_MINUS_CONSTANT_COLOR);
		REGISTER_VAR(GL_CONSTANT_ALPHA);
		REGISTER_VAR(GL_ONE_MINUS_CONSTANT_ALPHA);
		REGISTER_VAR(GL_BLEND_COLOR);
		REGISTER_VAR(GL_FUNC_ADD);
		REGISTER_VAR(GL_MIN);
		REGISTER_VAR(GL_MAX);
		REGISTER_VAR(GL_BLEND_EQUATION);
		REGISTER_VAR(GL_FUNC_SUBTRACT);
		REGISTER_VAR(GL_FUNC_REVERSE_SUBTRACT);
		REGISTER_VAR(GL_CONVOLUTION_1D);
		REGISTER_VAR(GL_CONVOLUTION_2D);
		REGISTER_VAR(GL_SEPARABLE_2D);
		REGISTER_VAR(GL_CONVOLUTION_BORDER_MODE);
		REGISTER_VAR(GL_CONVOLUTION_FILTER_SCALE);
		REGISTER_VAR(GL_CONVOLUTION_FILTER_BIAS);
		REGISTER_VAR(GL_REDUCE);
		REGISTER_VAR(GL_CONVOLUTION_FORMAT);
		REGISTER_VAR(GL_CONVOLUTION_WIDTH);
		REGISTER_VAR(GL_CONVOLUTION_HEIGHT);
		REGISTER_VAR(GL_MAX_CONVOLUTION_WIDTH);
		REGISTER_VAR(GL_MAX_CONVOLUTION_HEIGHT);
		REGISTER_VAR(GL_POST_CONVOLUTION_RED_SCALE);
		REGISTER_VAR(GL_POST_CONVOLUTION_GREEN_SCALE);
		REGISTER_VAR(GL_POST_CONVOLUTION_BLUE_SCALE);
		REGISTER_VAR(GL_POST_CONVOLUTION_ALPHA_SCALE);
		REGISTER_VAR(GL_POST_CONVOLUTION_RED_BIAS);
		REGISTER_VAR(GL_POST_CONVOLUTION_GREEN_BIAS);
		REGISTER_VAR(GL_POST_CONVOLUTION_BLUE_BIAS);
		REGISTER_VAR(GL_POST_CONVOLUTION_ALPHA_BIAS);
		REGISTER_VAR(GL_HISTOGRAM);
		REGISTER_VAR(GL_PROXY_HISTOGRAM);
		REGISTER_VAR(GL_HISTOGRAM_WIDTH);
		REGISTER_VAR(GL_HISTOGRAM_FORMAT);
		REGISTER_VAR(GL_HISTOGRAM_RED_SIZE);
		REGISTER_VAR(GL_HISTOGRAM_GREEN_SIZE);
		REGISTER_VAR(GL_HISTOGRAM_BLUE_SIZE);
		REGISTER_VAR(GL_HISTOGRAM_ALPHA_SIZE);
		REGISTER_VAR(GL_HISTOGRAM_LUMINANCE_SIZE);
		REGISTER_VAR(GL_HISTOGRAM_SINK);
		REGISTER_VAR(GL_MINMAX);
		REGISTER_VAR(GL_MINMAX_FORMAT);
		REGISTER_VAR(GL_MINMAX_SINK);
		REGISTER_VAR(GL_TABLE_TOO_LARGE);
		REGISTER_VAR(GL_COLOR_MATRIX);
		REGISTER_VAR(GL_COLOR_MATRIX_STACK_DEPTH);
		REGISTER_VAR(GL_MAX_COLOR_MATRIX_STACK_DEPTH);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_RED_SCALE);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_GREEN_SCALE);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_BLUE_SCALE);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_ALPHA_SCALE);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_RED_BIAS);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_GREEN_BIAS);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_BLUE_BIAS);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_ALPHA_BIAS);
		REGISTER_VAR(GL_COLOR_TABLE);
		REGISTER_VAR(GL_POST_CONVOLUTION_COLOR_TABLE);
		REGISTER_VAR(GL_POST_COLOR_MATRIX_COLOR_TABLE);
		REGISTER_VAR(GL_PROXY_COLOR_TABLE);
		REGISTER_VAR(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE);
		REGISTER_VAR(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE);
		REGISTER_VAR(GL_COLOR_TABLE_SCALE);
		REGISTER_VAR(GL_COLOR_TABLE_BIAS);
		REGISTER_VAR(GL_COLOR_TABLE_FORMAT);
		REGISTER_VAR(GL_COLOR_TABLE_WIDTH);
		REGISTER_VAR(GL_COLOR_TABLE_RED_SIZE);
		REGISTER_VAR(GL_COLOR_TABLE_GREEN_SIZE);
		REGISTER_VAR(GL_COLOR_TABLE_BLUE_SIZE);
		REGISTER_VAR(GL_COLOR_TABLE_ALPHA_SIZE);
		REGISTER_VAR(GL_COLOR_TABLE_LUMINANCE_SIZE);
		REGISTER_VAR(GL_COLOR_TABLE_INTENSITY_SIZE);
		REGISTER_VAR(GL_IGNORE_BORDER);
		REGISTER_VAR(GL_CONSTANT_BORDER);
		REGISTER_VAR(GL_WRAP_BORDER);
		REGISTER_VAR(GL_REPLICATE_BORDER);
		REGISTER_VAR(GL_CONVOLUTION_BORDER_COLOR);
	}
}
inline void register_funcs_glext(lua_State *L)
{
	if(GLEW_VERSION_1_2){
		REGISTER_FUNC(glCopyTexSubImage3D);
		REGISTER_FUNC(glDrawRangeElements);
		REGISTER_FUNC(glTexImage3D);
		REGISTER_FUNC(glTexSubImage3D);
	}
	if(GLEW_VERSION_1_3){
		REGISTER_FUNC(glActiveTexture);
		REGISTER_FUNC(glClientActiveTexture);
		REGISTER_FUNC(glCompressedTexImage1D);
		REGISTER_FUNC(glCompressedTexImage2D);
		REGISTER_FUNC(glCompressedTexImage3D);
		REGISTER_FUNC(glCompressedTexSubImage1D);
		REGISTER_FUNC(glCompressedTexSubImage2D);
		REGISTER_FUNC(glCompressedTexSubImage3D);
		REGISTER_FUNC(glGetCompressedTexImage);
		REGISTER_FUNC(glLoadTransposeMatrix);
		REGISTER_FUNC(glMultTransposeMatrix);
		REGISTER_FUNC(glMultiTexCoord);
		REGISTER_FUNC(glSampleCoverage);
	}
	if(GLEW_VERSION_1_4){
		REGISTER_FUNC(glFogCoordPointer);
		REGISTER_FUNC(glFogCoord);
		REGISTER_FUNC(glMultiDrawArrays);
		REGISTER_FUNC(glPointParameter);
		REGISTER_FUNC(glSecondaryColor);
		REGISTER_FUNC(glSecondaryColorPointer);
		REGISTER_FUNC(glWindowPos);
	}
	if(GLEW_VERSION_1_5){
		REGISTER_FUNC(glBeginQuery);
		REGISTER_FUNC(glBindBuffer);
		REGISTER_FUNC(glBufferData);
		REGISTER_FUNC(glBufferSubData);
		REGISTER_FUNC(glDeleteBuffers);
		REGISTER_FUNC(glDeleteQueries);
		REGISTER_FUNC(glEndQuery);
		REGISTER_FUNC(glGenBuffers);
		REGISTER_FUNC(glGenQueries);
		REGISTER_FUNC(glGetBufferParameter);
		REGISTER_FUNC(glGetBufferSubData);
		REGISTER_FUNC(glGetQueryObject);
		REGISTER_FUNC(glGetQuery);
		REGISTER_FUNC(glIsBuffer);
		REGISTER_FUNC(glIsQuery);
		REGISTER_FUNC(glMapBuffer);
		REGISTER_FUNC(glUnmapBuffer);
	}
	if(GLEW_VERSION_2_0){
		REGISTER_FUNC(glAttachShader);
		REGISTER_FUNC(glBindAttribLocation);
		REGISTER_FUNC(glBlendEquationSeparate);
		REGISTER_FUNC(glCompileShader);
		REGISTER_FUNC(glCreateProgram);
		REGISTER_FUNC(glCreateShader);
		REGISTER_FUNC(glDeleteProgram);
		REGISTER_FUNC(glDeleteShader);
		REGISTER_FUNC(glDetachShader);
		REGISTER_FUNC(glDisableVertexAttribArray);
		REGISTER_FUNC(glDrawBuffers);
		REGISTER_FUNC(glEnableVertexAttribArray);
		REGISTER_FUNC(glGetActiveAttrib);
		REGISTER_FUNC(glGetActiveUniform);
		REGISTER_FUNC(glGetAttachedShaders);
		REGISTER_FUNC(glGetAttribLocation);
		REGISTER_FUNC(glGetProgramInfoLog);
		REGISTER_FUNC(glGetProgram);
		REGISTER_FUNC(glGetShaderInfoLog);
		REGISTER_FUNC(glGetShaderSource);
		REGISTER_FUNC(glGetShader);
		REGISTER_FUNC(glGetUniformLocation);
		REGISTER_FUNC(glGetUniform);
		REGISTER_FUNC(glGetVertexAttrib);
		REGISTER_FUNC(glIsProgram);
		REGISTER_FUNC(glIsShader);
		REGISTER_FUNC(glLinkProgram);
		REGISTER_FUNC(glShaderSource);
		REGISTER_FUNC(glStencilFuncSeparate);
		REGISTER_FUNC(glStencilMaskSeparate);
		REGISTER_FUNC(glStencilOpSeparate);
		REGISTER_FUNC(glUniform);
		REGISTER_FUNC(glUniformMatrix2);
		REGISTER_FUNC(glUniformMatrix3);
		REGISTER_FUNC(glUniformMatrix4);
		REGISTER_FUNC(glUseProgram);
		REGISTER_FUNC(glValidateProgram);
		REGISTER_FUNC(glVertexAttrib);
		REGISTER_FUNC(glVertexAttribPointer);
	}
	if(GLEW_VERSION_2_1){
		REGISTER_FUNC(glUniformMatrix2x3);
		REGISTER_FUNC(glUniformMatrix2x4);
		REGISTER_FUNC(glUniformMatrix3x2);
		REGISTER_FUNC(glUniformMatrix3x4);
		REGISTER_FUNC(glUniformMatrix4x2);
		REGISTER_FUNC(glUniformMatrix4x3);
	}
	if(GLEW_ARB_framebuffer_object){
		REGISTER_FUNC(glBindFramebuffer);
		REGISTER_FUNC(glBindRenderbuffer);
		REGISTER_FUNC(glBlitFramebuffer);
		REGISTER_FUNC(glCheckFramebufferStatus);
		REGISTER_FUNC(glDeleteFramebuffers);
		REGISTER_FUNC(glDeleteRenderbuffers);
		REGISTER_FUNC(glFramebufferRenderbuffer);
		REGISTER_FUNC(glFramebufferTexture1D);
		REGISTER_FUNC(glFramebufferTexture2D);
		REGISTER_FUNC(glFramebufferTexture3D);
		REGISTER_FUNC(glFramebufferTextureLayer);
		REGISTER_FUNC(glGenFramebuffers);
		REGISTER_FUNC(glGenRenderbuffers);
		REGISTER_FUNC(glGenerateMipmap);
		REGISTER_FUNC(glGetFramebufferAttachmentParameter);
		REGISTER_FUNC(glGetRenderbufferParameter);
		REGISTER_FUNC(glIsFramebuffer);
		REGISTER_FUNC(glIsRenderbuffer);
		REGISTER_FUNC(glRenderbufferStorage);
		REGISTER_FUNC(glRenderbufferStorageMultisample);
	}
	if(GLEW_ARB_imaging){
		REGISTER_FUNC(glColorSubTable);
		REGISTER_FUNC(glColorTable);
		REGISTER_FUNC(glColorTableParameter);
		REGISTER_FUNC(glConvolutionFilter1D);
		REGISTER_FUNC(glConvolutionFilter2D);
		REGISTER_FUNC(glConvolutionParameter);
		REGISTER_FUNC(glCopyColorSubTable);
		REGISTER_FUNC(glCopyColorTable);
		REGISTER_FUNC(glCopyConvolutionFilter1D);
		REGISTER_FUNC(glCopyConvolutionFilter2D);
		REGISTER_FUNC(glGetColorTable);
		REGISTER_FUNC(glGetColorTableParameter);
		REGISTER_FUNC(glGetConvolutionFilter);
		REGISTER_FUNC(glGetConvolutionParameter);
		REGISTER_FUNC(glGetHistogram);
		REGISTER_FUNC(glGetHistogramParameter);
		REGISTER_FUNC(glGetMinmax);
		REGISTER_FUNC(glGetMinmaxParameter);
		REGISTER_FUNC(glGetSeparableFilter);
		REGISTER_FUNC(glHistogram);
		REGISTER_FUNC(glMinmax);
		REGISTER_FUNC(glResetHistogram);
		REGISTER_FUNC(glResetMinmax);
		REGISTER_FUNC(glSeparableFilter2D);
	}
}

void register_glext(lua_State *L){
	static bool glext_init = false;
	if(!glext_init){
		GLenum err = glewInit();
		if(err != GLEW_OK)
			throw (const char*)glewGetErrorString(err);
		else
			glext_init = true;
	}
	register_constants_glext(L);
	register_funcs_glext(L);
}