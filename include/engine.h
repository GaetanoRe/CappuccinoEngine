#include <string>
#include "window.h"
#include "input.h"
#include "settings.h"
#include <memory>
#pragma once

class Engine{
    public:
        Engine();
        ~Engine();
        void init();
        void update(float deltaTime);
        void shutdown();
        bool isWindowClosed();
        void loadKeyBindings();

    private:
        // This will have the Renderer, Sound, Physics, and Audio classes
        std::unique_ptr<Window> window;
        std::unique_ptr<Input> input;
        std::unique_ptr<Settings> settings;
};