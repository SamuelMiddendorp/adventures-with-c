//
// cc glfw-opengl-example.c glad.c -lglfw
//
#include <glad/glad.h> // https://glad.dav1d.de/
#define GLFW_DLL
#include <glfw/glfw3.h>
#include <stdio.h>

static void quit(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    printf("%i", scancode);
    printf("%i", mods);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main()
{
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

        glClearColor(0.3, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}