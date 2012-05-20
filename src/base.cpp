#include "env.h"
#include <sstream>
#include <cstdio>

DEF_HEAD_NEG(pack, 0)
	int n = lua_gettop(L);
	lua_createtable(L, n, 0);
	for (int i = 1; i <= n; i++){
		lua_pushvalue(L, i);
		lua_rawseti(L, -2, i);
	}
	return 1;
DEF_TAIL
char log_path[128] = "log.txt";
DEF_HEAD(printpath, 1)
	const char *input = luaL_checkstring(L, 1);
	if(strlen(input) > 127)
		error_msg(L, "File path too big (limit: 127 characters)");
	strcpy(log_path, input);
DEF_TAIL
DEF_HEAD_NEG(print, 0)
	//Read
	std::ostringstream str;
	for (int i = 1; i <= lua_gettop(L); i++){
		//Boolean
		if(lua_isboolean(L,i))
			if(lua_toboolean(L,i))
				str << "true";
			else
				str << "false";
		//String or number
		else if(lua_isstring(L,i) || lua_isnumber(L,i))
			str << lua_tostring(L,i);
		//nil
		else if(lua_isnil(L,i))
			str << "nil";
		//table
		else if(lua_istable(L,1))
			str << "(table: " << (int)lua_topointer(L, -1) << ")";
        //function
		else if(lua_isfunction(L,1))
			str << "(function: " << (int)lua_topointer(L, -1) << ")";
		//Userdata
		else
			str << "(userdata: " << (int)lua_topointer(L, -1) << ")";
	}
	//Output
	static bool first_time = true;
	FILE *tf;
	if(first_time){
		tf = fopen(log_path,"w");
		first_time = false;
	}else
		tf = fopen(log_path,"a");
	if(tf){
		fputs(str.str().c_str(), tf);
		fputc('\n', tf);
		fclose(tf);
	}else
		error_msg(L, "cannot open log file");
DEF_TAIL

void register_base(lua_State *L){
	REGISTER_FUNC(pack);
	REGISTER_FUNC(printpath);
	REGISTER_FUNC(print);
}