#include "env.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

typedef struct{double x, y, z;}POINT3D;
POINT3D normal_vector(POINT3D p1, POINT3D p2, POINT3D p3)
{
	// vector 1, vector 2
	POINT3D vec1, vec2;
	vec1.x = p2.x-p1.x;
	vec1.y = p2.y-p1.y;
	vec1.z = p2.z-p1.z;
	vec2.x = p3.x-p1.x;
	vec2.y = p3.y-p1.y;
	vec2.z = p3.z-p1.z;

	// vector 1 x vector 2
	POINT3D nvec;
	nvec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	nvec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	nvec.z = vec1.x * vec2.y - vec1.y * vec2.x;

	// Normalize divisor
	double divisor = sqrt( pow(nvec.x, 2) + pow(nvec.y, 2) + pow(nvec.z, 2) );
	nvec.x /= divisor;
	nvec.y /= divisor;
	nvec.z /= divisor;

	return nvec;
}

DEF_HEAD(Randomsteps, 3)
	double start = luaL_checknumber(L, 1);
	double end =  luaL_checknumber(L, 2);
	double step =  luaL_checknumber(L, 3);

	if(end < start || step <= 0)
		error_msg(L);

    lua_pushnumber(L, start + rand() % (unsigned int)(floor((end-start) / step) + 1) * step);
    return 1;
DEF_TAIL
DEF_HEAD(Reflect, 6)
	double ray_x =  luaL_checknumber(L, 1);
	double ray_y = luaL_checknumber(L, 2);
	double ray_z =  luaL_checknumber(L, 3);
	double plain_nx =  luaL_checknumber(L, 4);
	double plain_ny =  luaL_checknumber(L, 5);
	double plain_nz =  luaL_checknumber(L, 6);

	lua_pushnumber(L, ray_x - 2 * (ray_x*plain_nx) * plain_nx);
	lua_pushnumber(L, ray_y - 2 * (ray_y*plain_ny) * plain_ny);
	lua_pushnumber(L, ray_z - 2 * (ray_z*plain_nz) * plain_nz);

    return 3;
DEF_TAIL
DEF_HEAD(Sign, 1)
	double n = luaL_checknumber(L, 1);
	if(n<0)
		    lua_pushnumber(L, -1);
	else if(n>0)
		lua_pushnumber(L, 1);
	else
		lua_pushnumber(L, 0);
    return 1;
DEF_TAIL
DEF_HEAD(Round, 1)
    lua_pushnumber(L, floor(luaL_checknumber(L, 1) + 0.5));
    return 1;
DEF_TAIL
DEF_HEAD(Clamp, 3)
	double val = luaL_checknumber(L, 1);
	double min = luaL_checknumber(L, 2);
	double max = luaL_checknumber(L, 3);
	if(val > max)
		lua_pushnumber(L, max);
	else if(val < min)
		lua_pushnumber(L, min);
	else
		lua_pushnumber(L, val);
    return 1;
DEF_TAIL
DEF_HEAD(Interpolate, 3)
	double a = luaL_checknumber(L, 1);
	double b = luaL_checknumber(L, 2);
	double pct = luaL_checknumber(L, 3);

	lua_pushnumber(L, a + (b-a)*pct);
    return 1;
DEF_TAIL
DEF_HEAD(Length, 3)
    double w = luaL_checknumber(L, 1);
    double h = luaL_checknumber(L, 2);
    double d = luaL_checknumber(L, 3);

    lua_pushnumber(L, sqrt(w*w + h*h + d*d));
    return 1;
DEF_TAIL
DEF_HEAD(Dot, 6)
	lua_pushnumber(L, luaL_checknumber(L, 1) * luaL_checknumber(L, 4) + luaL_checknumber(L, 2) * luaL_checknumber(L, 5) + luaL_checknumber(L, 3) * luaL_checknumber(L, 6));
	return 1;
DEF_TAIL
DEF_HEAD(Cross, 6)
	double x1 = luaL_checknumber(L, 1);
	double y1 = luaL_checknumber(L, 2);
	double z1 = luaL_checknumber(L, 3);
	double x2 = luaL_checknumber(L, 4);
	double y2 = luaL_checknumber(L, 5);
	double z2 = luaL_checknumber(L, 6);

	lua_pushnumber(L, y1*z2 - z1*y2);
	lua_pushnumber(L, z1*x2 - x1*z2);
	lua_pushnumber(L, x1*y2 - y1*x2);
	return 3;
DEF_TAIL
DEF_HEAD_NEG(Normalize, 0)
	int n = lua_gettop(L);

	double divide = 0;
	for(int i = 1; i <= n; i++)
		divide += pow(luaL_checknumber(L, i), 2);
	divide = sqrt(divide);

	for(int i = 1; i <= n; i++)
		lua_pushnumber(L, lua_tonumber(L, i) / divide);

	return n;
DEF_TAIL
DEF_HEAD(CalcNormal, 9)
    // vertex1, vertex2, vertex3
    POINT3D p1, p2, p3;
    p1.x = luaL_checknumber(L, 1);
    p1.y = luaL_checknumber(L, 2);
    p1.z = luaL_checknumber(L, 3);
    p2.x = luaL_checknumber(L, 4);
    p2.y = luaL_checknumber(L, 5);
    p2.z = luaL_checknumber(L, 6);
    p3.x = luaL_checknumber(L, 7);
    p3.y = luaL_checknumber(L, 8);
    p3.z = luaL_checknumber(L, 9);

    // Calculation
    POINT3D nvec = normal_vector(p1, p2, p3);

    lua_pushnumber(L, nvec.x);
    lua_pushnumber(L, nvec.y);
    lua_pushnumber(L, nvec.z);

    return 3;
DEF_TAIL
DEF_HEAD(Ellipse, 5)
	// point, base, radius
	double x = luaL_checknumber(L, 1);
	double y = luaL_checknumber(L, 2);
	double w = luaL_checknumber(L, 3);
	double h = luaL_checknumber(L, 4);
	double angle = luaL_checknumber(L, 5);

    // Calculate point
	double radian = angle / 180 * M_PI;
	lua_pushnumber(L, x + w / 2 * cos(radian));
	lua_pushnumber(L, y + h / 2 * sin(radian));

	return 2;
DEF_TAIL
unsigned int fac(unsigned int n)
{
	unsigned int k = 1;
	if (n > 1)
		for(unsigned int i = 2; i <= n; i++)
			k *= i;
	return k;
}
double bin_coeff(unsigned int i, unsigned int n)
{
	return (double)fac(n) / (fac(i) * fac(n-i));
}
double bernstein(double pct, unsigned int i, unsigned int n)
{
		return bin_coeff(i, n) * pow(pct, (int)i) * pow((1 - pct), (int)(n - i));
}
DEF_HEAD(Bezier, 2)
    luaL_argcheck(L, lua_istable(L, 2), 2, "table expected");
	// progress, points, number of points
	double pct = luaL_checknumber(L, 1);
	size_t len = lua_objlen(L, 2);

	// test values
	if(len%3 || pct < 0 || pct > 1)
		error_msg(L);

	for (unsigned int i = 1; i <= len; i++){
		lua_rawgeti(L, 2, i);
		if(!lua_isnumber(L,-1))
			error_msg(L);
		lua_pop(L,1);
	}

	// Calculate point
	double x, y, z;
	x = y = z = 0;
	size_t pn = len/3;
	for (unsigned int i = 0; i < pn; i++)
	{
		double bern = bernstein(pct, i, pn-1);
		lua_rawgeti(L, 2, i*3+1);
		lua_rawgeti(L, 2, i*3+2);
		lua_rawgeti(L, 2, i*3+3);
		x += bern * lua_tonumber(L, -3);
		y += bern * lua_tonumber(L, -2);
		z += bern * lua_tonumber(L, -1);
		lua_pop(L, 3);
	}

	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	lua_pushnumber(L, z);

	return 3;
DEF_TAIL
DEF_HEAD(InTriangle, 12)
    // point, vertex1, vertex2, vertex3
    POINT3D pp, p1, p2, p3;
    pp.x = luaL_checknumber(L, 1);
    pp.y = luaL_checknumber(L, 2);
    pp.z = luaL_checknumber(L, 3);
    p1.x = luaL_checknumber(L, 4);
    p1.y = luaL_checknumber(L, 5);
    p1.z = luaL_checknumber(L, 6);
    p2.x = luaL_checknumber(L, 7);
    p2.y = luaL_checknumber(L, 8);
    p2.z = luaL_checknumber(L, 9);
    p3.x = luaL_checknumber(L, 10);
    p3.y = luaL_checknumber(L, 11);
    p3.z = luaL_checknumber(L, 12);

    // Get normals
    POINT3D nvec12 = normal_vector(p1, pp, p2);
    POINT3D nvec23 = normal_vector(p2, pp, p3);
    POINT3D nvec31 = normal_vector(p3, pp, p1);

    //Test
    if (
        nvec12.x == nvec23.x && nvec23.x == nvec31.x &&
        nvec12.y == nvec23.y && nvec23.y == nvec31.y &&
        nvec12.z == nvec23.z && nvec23.z == nvec31.z
        )
        lua_pushboolean(L, true);
    else
        lua_pushboolean(L, false);

    return 1;
DEF_TAIL

void register_math(lua_State *L){
	lua_getglobal(L, "math");

	lua_pushcfunction(L, l_Randomsteps);
	lua_setfield(L, -2, "randomsteps");
	lua_pushcfunction(L, l_Reflect);
	lua_setfield(L, -2, "reflect");
	lua_pushcfunction(L, l_Sign);
	lua_setfield(L, -2, "sign");
	lua_pushcfunction(L, l_Round);
	lua_setfield(L, -2, "round");
	lua_pushcfunction(L, l_Clamp);
	lua_setfield(L, -2, "clamp");
	lua_pushcfunction(L, l_Interpolate);
	lua_setfield(L, -2, "interpolate");
	lua_pushcfunction(L, l_Length);
	lua_setfield(L, -2, "length");
	lua_pushcfunction(L, l_Dot);
	lua_setfield(L, -2, "dot");
	lua_pushcfunction(L, l_Cross);
	lua_setfield(L, -2, "cross");
	lua_pushcfunction(L, l_Normalize);
	lua_setfield(L, -2, "normalize");
	lua_pushcfunction(L, l_CalcNormal);
	lua_setfield(L, -2, "calcnormal");
	lua_pushcfunction(L, l_Ellipse);
	lua_setfield(L, -2, "ellipse");
	lua_pushcfunction(L, l_Bezier);
	lua_setfield(L, -2, "bezier");
	lua_pushcfunction(L, l_InTriangle);
	lua_setfield(L, -2, "intriangle");

	lua_setglobal(L, "math");
}