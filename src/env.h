#pragma once

#include <lua_ext.h>

//Basic functions
void register_base(lua_State *L);
void register_math(lua_State *L);
void register_string(lua_State *L);
void register_table(lua_State *L);

//AVS functions
extern void **userdata_avs;
void register_avs(lua_State *L);

//OpenGL functions
void register_gl(lua_State *L);
void register_glu(lua_State *L);
void register_glutess(lua_State *L);
void register_glext(lua_State *L);
void register_fl(lua_State *L);