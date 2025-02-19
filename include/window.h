#include<string>
#include<GLFW/glfw3.h>
#include <memory>
#pragma once
class Window{
    public:
    Window(int w, int h, int x, int y, const std::string& title, int cMonitor, bool fullScreen);

    void update();
    void close();
    void showWindow(bool show);
    void toggleFullScreen();
    
    int getWidth() const;
    int getHeight() const;
    int getMonitorCount() const;
    int getSelectedMonitor() const;

    bool windowShouldClose();

    GLFWwindow * getGLFWWindow() const;
    GLFWmonitor* getPrimaryMonitor() const;


    private:
        int width;
        int height;
        int windowX;
        int windowY;
        int monitorCount;
        int chosenMonitor;
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window_{ nullptr, glfwDestroyWindow };
        GLFWmonitor* monitor;
        GLFWmonitor** monitors;
        const GLFWvidmode* mode;
        bool isFullScreen_;
        
        
};