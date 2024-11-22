#include "../include/window.h"
#include <GLFW/glfw3.h>

Window::Window(int w, int h, const std::string& title) : window_(nullptr){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    Window::width = w;
    Window::height = h;

    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(!window_){
        glfwTerminate();
        // Handle Error
    }

    glfwMakeContextCurrent(window_);
}

Window::~Window(){
    glfwDestroyWindow(window_);
    glfwTerminate();
}

void Window::update(){
    glfwPollEvents();
    glfwSwapBuffers(window_);
}

void Window::close(){
    glfwSetWindowShouldClose(window_, GLFW_TRUE);
    glfwDestroyWindow(window_);

    glfwTerminate();
}

void Window::showWindow(bool show){
    if(show){
        glfwShowWindow(window_);
    }
    else{
        glfwHideWindow(window_);
    }
}

bool Window::windowShouldClose(){
    return glfwWindowShouldClose(window_);
}

int Window::getHeight() const{
    return height;
}

int Window::getWidth() const{
    return width;
}

GLFWwindow * Window::getGLFWWindow() const{
    return window_;
}
