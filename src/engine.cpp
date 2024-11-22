#include "GLFW/glfw3.h"
#include "../include/engine.h"
#include "../include/window.h"

Engine::Engine(){
    window = new Window(800, 600, "Cappuccino");
}

Engine::~Engine(){
    delete window;
}

void Engine::init(){
    window->showWindow(true);
}

void Engine::update(float deltaTime){
    window->update();
}

void Engine::shutdown(){
    window->showWindow(false);
    window->close();
}

bool Engine::isWindowClosed(){
    return window->windowShouldClose();
}