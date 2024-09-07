#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include "graphics/Renderer.hpp"
#include <GLFW/glfw3.h>

class OpenGLRenderer : public Renderer {
public:
    void initialize() override;
    void render() override;
    void shutdown() override;
    GLFWwindow* createWindow(int width, int height, const char* title) override;
};

#endif // OPENGL_RENDERER_HPP
