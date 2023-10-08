//
// cc glfw-opengl-example.c glad.c -lglfw
//
#include <glad/glad.h> // https://glad.dav1d.de/
#define GLFW_DLL
#include <glfw/glfw3.h>
#include <stdio.h>
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>


double red = 0.1;
lua_State *L;

void luaAdd(lua_State* L)
{

    luaL_dofile(L, "script.lua");
    // Push the add function on the top of the lua stack
    lua_getglobal(L, "getRed");

    // Push the first argument on the top of the lua stack
    lua_pushnumber(L, red);

    // Call the function with 2 arguments, returning 1 result
    lua_call(L, 1, 1);

    // Get the result 
    red = (double)lua_tonumber(L, -1);
	
	// The one result that was returned needs to be popped off.  If the 3rd
	//  parameter to lua_call was larger than 1, we would need to pop off more
	//  elements from the lua stack.
    lua_pop(L, 1);
}

static void quit(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    printf("%i", scancode);
    printf("%i", mods);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_0 && action == GLFW_PRESS) {
        luaAdd(L);
    }
}

int main()
{
    L = luaL_newstate();
    luaL_openlibs(L);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window = glfwCreateWindow(1280, 720, "GLFW OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetKeyCallback(window, quit);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(red, 0.4, 0.9, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    lua_close(L);
}