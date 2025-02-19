#include "../include/input.h"
#include <GLFW/glfw3.h>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory> // Include for smart pointers

Input::Input() {}

// The destructor is now AUTOMATICALLY handled. No need to define it!
Input::~Input() = default;  // Or just remove it entirely

void Input::update() {
    glfwPollEvents();
    keyStates.clear();

    GLFWwindow* window = glfwGetCurrentContext();
    if (window) {
        for (const auto& [key, command] : keyMappings) {
            keyStates[command] = glfwGetKey(window, key);
        }
    }
}

bool Input::getCommand(const std::string& name) {
    return keyStates[name] == GLFW_PRESS;
}

void Input::mapCommandToKey(const std::string& name, int key) {
    keyMappings[key] = name;
}

int Input::getKeycode(const std::string& keyName) {
    std::string upperKeyName = keyName;
    std::transform(upperKeyName.begin(), upperKeyName.end(), upperKeyName.begin(), ::toupper); // Case-insensitive
    if (keycodeMap.count(upperKeyName)) {
        return keycodeMap.at(upperKeyName);
    }
    return GLFW_KEY_UNKNOWN; // Or -1, but GLFW_KEY_UNKNOWN is a bit more descriptive
}