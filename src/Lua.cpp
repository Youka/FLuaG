#include "Lua.h"

Lua::Lua(void)
{
	L = luaL_newstate();
    luaL_openlibs(L);

	register_base(L);
	register_math(L);
	register_string(L);
	register_table(L);
}

Lua::~Lua(void)
{
	lua_close(L);
}

void Lua::dofile(const char *filename)
{
	if (luaL_dofile(L,filename))
		throw lua_tostring(L, -1);
	lua_gc(L, LUA_GCCOLLECT, 0);
}