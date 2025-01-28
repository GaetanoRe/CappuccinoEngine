#include <string>
#include "window.h"
#pragma once

class Engine{
    public:
        Engine();
        ~Engine();
        void init();
        void update(float deltaTime);
        void shutdown();
        bool isWindowClosed();

    private:
        // This will have the Renderer, Sound, Physics, and Audio classes
        Window * window;
        
    
};