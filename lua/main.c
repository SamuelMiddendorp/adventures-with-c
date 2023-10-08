#include <stdlib.h>
#include <stdio.h>

#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>

int main(void) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    char in;
    for(int i = 0; i < 10; i++){
        scanf("%c", &in);
        luaL_dofile(L, "script.lua");
    }

    lua_close(L);
    return 0;
}