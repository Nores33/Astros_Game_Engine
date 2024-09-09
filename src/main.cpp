#include <iostream>
#include "graphics/Renderer.hpp"
#include "graphics/opengl/OpenGLRenderer.hpp"
#include "graphics/Shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    OpenGLRenderer* renderer = nullptr;
    renderer = new OpenGLRenderer();

    renderer->initialize();
    GLFWwindow* window = renderer->createWindow(SCR_WIDTH, SCR_HEIGHT, "Astros Game Engine");

    if (!window) {
        std::cerr << "Failed to create window!" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        renderer->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    renderer->shutdown();
    delete renderer;
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
