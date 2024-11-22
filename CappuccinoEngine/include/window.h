#include<string>
#include<GLFW/glfw3.h>
#pragma once
class Window{
    public:
    Window(int w, int h, const std::string& title);
    ~Window();

    void update();
    void close();
    void showWindow(bool show);
    
    int getWidth() const;
    int getHeight() const;

    bool windowShouldClose();

    GLFWwindow * getGLFWWindow() const;

    private:
        int width;
        int height;
        GLFWwindow * window_;
};