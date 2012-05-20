#pragma once

#include "env.h"

class Lua
{
public:
	Lua(void);
	virtual ~Lua(void);

	virtual void dofile(const char *filename);

protected:
	lua_State *L;
};
