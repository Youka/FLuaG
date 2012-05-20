#include "env.h"
#include <string>

DEF_HEAD(tablemax, 1)
    luaL_argcheck(L, lua_istable(L,1), 1, "table expected");
    unsigned int n = 0;
    lua_pushnil(L);
    while(lua_next(L, -2))
    {
        lua_pop(L,1);
        n++;
    }
    lua_pushnumber(L, n);
    return 1;
DEF_TAIL

static void recursive_copy(lua_State *L)
{
	//New table
	lua_newtable(L);
	//Old table iteration
	lua_pushnil(L);
	while (lua_next(L, -3)) {
		//Save new key
		lua_pushvalue(L, -2);
		lua_insert(L, -3);
		//If table then recursive call
		if(lua_istable(L,-1))
			recursive_copy(L);
		//Copy to new table
		lua_rawset(L, -4);
	}
	lua_remove(L,-2);
}
DEF_HEAD(tablecopy, 1)
    luaL_argcheck(L, lua_istable(L,1), 1, "table expected");
    //Deep copy
    recursive_copy(L);
    //Return new table
    return 1;
DEF_TAIL

static void recursive_print(lua_State *L, std::string &str, std::string tab)
{
	lua_pushnil(L);
	while (lua_next(L, -2)){
		//Pre-space
		str.append(tab);
		//Index
		std::string index;
		if(lua_isnumber(L,-2))
		{
			index.append("[");
			lua_pushvalue(L,-2); index.append(lua_tostring(L, -1)); lua_pop(L, 1);
			index.append("]");
		}else{
			index.append("[\"");
			lua_pushvalue(L,-2); index.append(lua_tostring(L, -1)); lua_pop(L, 1);
			index.append("\"]");
		}
		str.append(index);
		//Value
		if(lua_istable(L,-1))
		{
			str.append("\n");
			recursive_print(L, str, tab + "\t");
		}else{
			str.append(" = ");
			if(lua_isboolean(L,-1))
				if(lua_toboolean(L,-1))
					str.append("true");
				else
					str.append("false");
			else if(lua_isstring(L,-1) || lua_isnumber(L,-1))
				str.append(lua_tostring(L,-1));
			else if(lua_isnil(L,-1))
				str.append("nil");
			else{
				char adr[32];
				itoa((int)lua_topointer(L, -1), adr, 10);
				if(lua_isfunction(L,-1))
					str.append("(function: ");
				else
					str.append("(address: ");
				str.append(adr);
				str.append(")");
			}
			str.append("\n");
		}
		lua_pop(L, 1);
	}
}
DEF_HEAD(tablestring, 1)
    luaL_argcheck(L, lua_istable(L,1), 1, "table expected");
	std::string log, tab = "\t";
    recursive_print(L, log, tab);
	if(log.length() > 0)
		log.erase(log.length()-1);
    lua_pushstring(L, log.c_str());
    return 1;
DEF_TAIL

void register_table(lua_State *L){
	lua_getglobal(L, "table");

	lua_pushcfunction(L, l_tablecopy);
	lua_setfield(L, -2, "copy");
	lua_pushcfunction(L, l_tablemax);
	lua_setfield(L, -2, "max");
	lua_pushcfunction(L, l_tablestring);
	lua_setfield(L, -2, "tostring");

	lua_setglobal(L, "table");
}