#include "env.h"
#define WINGDIAPI __declspec(dllimport)
#define APIENTRY __stdcall
#define CALLBACK __stdcall
#include <GL/glu.h>

#define GLU_MOVE	0x00
//GLU_LINE exists already
#define GLU_ENDLINE 0x02

/*
Path:
table[i].x = path[i][0] *
table[i].y = path[i][1] *
table[i].z = path[i][2] *
table[i].r = path[i][3]
table[i].g = path[i][4]
table[i].b = path[i][5]
table[i].a = path[i][6]
table[i].type = path[i][7] *
table.nx = nx
table.ny = ny
table.nz = nz
table.windingrule = windingrule
*/
size_t len;
GLdouble **path;
GLUtesselator *tess;
double nx, ny, nz;
int windingrule;

static void init_path(lua_State *L)
{
    len = lua_objlen(L, 1);
    windingrule = nx = ny = nz = 0;
    path = new GLdouble*[len];
    for(int i = 0; i < len; i++)
    {
        path[i] = new GLdouble[8];
        for(int ii = 0; ii < 8; ii++)
            path[i][ii] = -1000;
    }

    for(unsigned int i = 1; i <= len; i++)
    {
        //Get point
        lua_rawgeti(L, 1, i);
        if(lua_istable(L, -1))
        {
            //Get needed content
            lua_getfield(L, -1, "x");
            if(lua_isnumber(L, -1))
            {
                path[i-1][0] = lua_tonumber(L, -1);
                lua_getfield(L, -2, "y");
                if(lua_isnumber(L, -1))
                {
                    path[i-1][1] = lua_tonumber(L, -1);
                    lua_getfield(L, -3, "z");
                    if(lua_isnumber(L, -1))
                    {
                        path[i-1][2] = lua_tonumber(L, -1);
                        lua_getfield(L, -4, "type");
                        if(lua_isnumber(L, -1))
                            path[i-1][7] = lua_tonumber(L, -1);
                        else
                            error_msg(L);
                        lua_pop(L, 1);
                    }else
                        error_msg(L);
                    lua_pop(L, 1);
                }else
                    error_msg(L);
                lua_pop(L, 1);
            }else
                error_msg(L);
            lua_pop(L, 1);
            //Get optional content
            lua_getfield(L, -1, "r");
            if(lua_isnumber(L, -1))
                path[i-1][3] = lua_tonumber(L, -1);
            lua_pop(L, 1);
            lua_getfield(L, -1, "g");
            if(lua_isnumber(L, -1))
                path[i-1][4] = lua_tonumber(L, -1);
            lua_pop(L, 1);
            lua_getfield(L, -1, "b");
            if(lua_isnumber(L, -1))
                path[i-1][5] = lua_tonumber(L, -1);
            lua_pop(L, 1);
            lua_getfield(L, -1, "a");
            if(lua_isnumber(L, -1))
                path[i-1][6] = lua_tonumber(L, -1);
            lua_pop(L, 1);
        }else
            error_msg(L);
        //Remove point
        lua_pop(L, 1);
    }
    lua_getfield(L, 1, "nx");
    if(lua_isnumber(L, -1))
        nx = lua_tonumber(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, 1, "ny");
    if(lua_isnumber(L, -1))
        ny = lua_tonumber(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, 1, "nz");
    if(lua_isnumber(L, -1))
        nz = lua_tonumber(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, 1, "windingrule");
    if(lua_isnumber(L, -1))
        windingrule = lua_tonumber(L, -1);
    lua_pop(L, 1);

    tess = gluNewTess();
}
static void free_path()
{
    gluDeleteTess(tess);
    for(int i = 0; i < len; i++)
        delete(path[i]);
    delete path;
}

static void __stdcall path_combine(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
const GLfloat neighborWeight[4], GLdouble **outData)
{
    GLdouble *combine_vertex = new GLdouble[7];

    combine_vertex[0] = newVertex[0]; //x
    combine_vertex[1] = newVertex[1]; //y
    combine_vertex[2] = newVertex[2]; //z
    combine_vertex[3] = neighborWeight[0] * neighborVertex[0][3] +
                        neighborWeight[1] * neighborVertex[1][3]; //r
    combine_vertex[4] = neighborWeight[0] * neighborVertex[0][4] +
                        neighborWeight[1] * neighborVertex[1][4]; //g
    combine_vertex[5] = neighborWeight[0] * neighborVertex[0][5] +
                        neighborWeight[1] * neighborVertex[1][5]; //b
    combine_vertex[6] = neighborWeight[0] * neighborVertex[0][6] +
                        neighborWeight[1] * neighborVertex[1][6]; //a
    *outData = combine_vertex;
}
static void __stdcall path_vertex(const GLdouble *data)
{
    if(data[3] >= 0
        && data[4] >= 0
        && data[5] >= 0
        && data[6] >= 0)
        glColor4d(data[3], data[4], data[5], data[6]);
    glVertex3dv(data);
}
static void __stdcall path_error(GLenum error)
{
    free_path();
    throw (const char*)gluErrorString(error);
}

static DEF_HEAD(gluDrawPath, 1)
    luaL_argcheck(L, lua_istable(L,1), 1, "table expected");
    //Initialize path object
    init_path(L);

    gluTessCallback(tess, GLU_TESS_BEGIN, (void (__stdcall*)(void))glBegin);
    gluTessCallback(tess, GLU_TESS_VERTEX, (void (__stdcall*)(void))path_vertex);
    gluTessCallback(tess, GLU_TESS_END, (void (__stdcall*)(void))glEnd);
    gluTessCallback(tess, GLU_TESS_ERROR, (void (__stdcall*)(void))path_error);
    gluTessCallback(tess, GLU_TESS_COMBINE, (void (__stdcall*)(void))path_combine);
    if(windingrule)
        gluTessProperty(tess, GLU_TESS_WINDING_RULE, windingrule);
    if(nx || ny || nz)
        gluTessNormal(tess, nx, ny, nz);
    //Tesselation
    glPushAttrib(GL_CURRENT_BIT);
    GLdouble *p;
    gluTessBeginPolygon(tess, NULL);
    for(unsigned int i = 0; i < len; i++)
    {
        p = path[i];
        if(p[7] == GLU_MOVE)
            gluTessBeginContour(tess);
        if(p[7] == GLU_MOVE
            || p[7] == GLU_LINE
            || p[7] == GLU_ENDLINE)
            gluTessVertex(tess, p, p);
        if(p[7] == GLU_ENDLINE)
            gluTessEndContour(tess);
    }
    gluTessEndPolygon(tess);
    glPopAttrib();
    free_path();
DEF_TAIL

void register_glutess(lua_State *L){
    REGISTER_VAR(GLU_TESS_WINDING_ODD);
    REGISTER_VAR(GLU_TESS_WINDING_NONZERO);
    REGISTER_VAR(GLU_TESS_WINDING_POSITIVE);
    REGISTER_VAR(GLU_TESS_WINDING_NEGATIVE);
    REGISTER_VAR(GLU_TESS_WINDING_ABS_GEQ_TWO);
    REGISTER_VAR(GLU_MOVE);
    REGISTER_VAR(GLU_LINE);
    REGISTER_VAR(GLU_ENDLINE);

    REGISTER_FUNC(gluDrawPath);
}