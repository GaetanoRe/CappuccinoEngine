#include "../include/window.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>

Window::Window(int w, int h, int x, int y, const std::string& title, int cMonitor, bool fullScreen) : width(w), height(h), windowX(x), windowY(y), chosenMonitor(cMonitor), isFullScreen_(fullScreen){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_.reset(glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr));
    if(!window_){
        throw std::runtime_error("GLFW initialization failed"); // Throw the exception
    }

    glfwMakeContextCurrent(window_.get());

    monitors = glfwGetMonitors(&monitorCount);

    if (monitorCount > 1) {
        monitor = monitors[chosenMonitor];
    }
    else {
        monitor = glfwGetPrimaryMonitor();
    }

    mode = glfwGetVideoMode(monitor);

    

    if (isFullScreen_) {
        toggleFullScreen();
    }

}

void Window::update(){
    glfwPollEvents();
    glfwSwapBuffers(window_.get());
}

void Window::close(){
    glfwSetWindowShouldClose(window_.get(), GLFW_TRUE);
}

void Window::showWindow(bool show){
    if(show){
        glfwShowWindow(window_.get());
    }
    else{
        glfwHideWindow(window_.get());
    }
}

void Window::toggleFullScreen() {
    if (isFullScreen_) {
        // Go fullscreen
        glfwSetWindowPos(window_.get(), windowX, windowY);
        glfwSetWindowMonitor(window_.get(), monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        isFullScreen_ = true;
    }
    else {
        // Restore windowed mode
        glfwSetWindowMonitor(window_.get(), nullptr, windowX, windowY, width, height, GLFW_DONT_CARE);
        isFullScreen_ = false;
    }
}

bool Window::windowShouldClose(){
    return glfwWindowShouldClose(window_.get());
}

int Window::getHeight() const{
    return height;
}

int Window::getWidth() const{
    return width;
}

GLFWwindow * Window::getGLFWWindow() const{
    return window_.get();
}
