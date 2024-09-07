#include <iostream>
#include "graphics/Renderer.hpp"
#include "graphics/opengl/OpenGLRenderer.hpp"
#include "graphics/Shader/Shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    Renderer* renderer = nullptr;
    renderer = new OpenGLRenderer();

    renderer->initialize();
    GLFWwindow* window = renderer->createWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");

    if (!window) {
        std::cerr << "Failed to create window!" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // TRIANGLE
    /* ------------------------------------------------------------------------ */
    Shader shader("vertex_shader.vs", "fragment_shader.fs");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    /* ------------------------------------------------------------------------ */

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        renderer->render();

        // Render Triangle
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

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
