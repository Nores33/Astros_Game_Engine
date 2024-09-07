#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void initialize() = 0;
    virtual void render() = 0;
    virtual void shutdown() = 0;
    virtual GLFWwindow* createWindow(int width, int height, const char* title) = 0;
};

#endif // RENDERER_HPP