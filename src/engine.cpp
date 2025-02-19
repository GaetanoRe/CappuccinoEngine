#include "GLFW/glfw3.h"
#include "../include/engine.h"
#include "../include/window.h"
#include "../include/settings.h"
#include <memory>

Engine::Engine(){
    settings = std::make_unique<Settings>("C:/DEV/CappuccinoEngine/res/settings.ini");
    window = std::make_unique<Window>(settings->getInt("Graphics", "WindowWidth"), settings->getInt("Graphics", "WindowHeight"), 
        settings->getInt("Graphics", "WindowX"), settings->getInt("Graphics", "WindowY"), "Cappuccino", 
        settings->getInt("Graphics", "ChosenMonitor"), settings->getBool("Graphics", "FullScreen")
    );
    input = std::make_unique<Input>();
    std::map<std::string, std::string> inputMap = settings->getStrings("KeyBindings");
    loadKeyBindings();
    for (const auto& [command, key] : inputMap) {
        input->mapCommandToKey(command, input->getKeycode(key));
    }
    
}

Engine::~Engine() = default;

void Engine::init(){
    window->showWindow(true);
}

void Engine::update(float deltaTime){
    window->update();
    input->update();
}

void Engine::shutdown(){
    window->showWindow(false);
    window->close();
}

bool Engine::isWindowClosed(){
    return window->windowShouldClose();
}

void Engine::loadKeyBindings() {
    if (settings->sectionExists("KeyBindings")){ // Check if section exists
        std::map<std::string, std::string> inputMap = settings->getStrings("KeyBindings");
        for (const auto& [command, key] : inputMap) {
            std::string upperKey = key;
            std::transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper); // Case-insensitive
            int keyCode = input->getKeycode(upperKey);
            if (keyCode != GLFW_KEY_UNKNOWN) {
                input->mapCommandToKey(command, keyCode);
            }
            else {
                std::cerr << "Invalid key name: " << key << " for command: " << command << std::endl;
            }
        }
    }
    else {
        std::cerr << "KeyBindings section not found in settings file." << std::endl;
    }
}