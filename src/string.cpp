#include "env.h"

DEF_HEAD(Ucharlen, 2)
	const char *text = luaL_checkstring(L, 1);
	unsigned long i = luaL_checknumber(L, 2);

	if( i < 0 || i >= strlen(text))
		error_msg(L, "invalid index");

	unsigned char c = unsigned char(text[i]);
	if(c < 192)
		lua_pushnumber(L, 1);
	else if(c < 224)
		lua_pushnumber(L, 2);
	else if(c < 240)
		lua_pushnumber(L, 3);
	else if(c < 248)
		lua_pushnumber(L, 4);
	else if(c < 252)
		lua_pushnumber(L, 5);
	else
		lua_pushnumber(L, 6);
		
	return 1;
DEF_TAIL

void register_string(lua_State *L){
	lua_getglobal(L, "string");
	lua_pushcfunction(L, l_Ucharlen);
	lua_setfield(L, -2, "ucharlen");
	lua_setglobal(L, "string");

	luaL_dostring(L, "function string.uchars(s)\
	if type(s) ~= \"string\" then\
		error(\"string expected\", 2)\
	end\
	local char_i, s_pos = 0, 1\
	local function itor()\
		if s_pos > s:len() then\
			return nil\
		end\
		local char_w = string.ucharlen(s, s_pos)\
		local cur_pos = s_pos\
		s_pos = s_pos + char_w\
		char_i = char_i + 1\
		return char_i, s:sub(cur_pos, cur_pos + char_w - 1)\
	end\
	return itor\
end");

	luaL_dostring(L, "function string.ulen(s)\
	if type(s) ~= \"string\" then\
		error(\"string expected\", 2)\
	end\
	local n = 0\
	for _ in string.uchars(s) do\
		n = n + 1\
	end\
	return n\
end");
}