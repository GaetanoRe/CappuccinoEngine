#include <GLFW/glfw3.h>
#include <string>
#include <list>
#include <memory>
#include <iostream>
#include <map>
#pragma once

class Input {
	public:
		Input();
		~Input();
		void update();
		bool getCommand(const std::string& commandName);
		void mapCommandToKey(const std::string& commandName, int key);
        int getKeycode(const std::string& keyName);




	private:
		std::map<std::string, int> keyStates;
		std::map<int, std::string> keyMappings;
        std::map<std::string, int> keycodeMap = {
    {"Space", GLFW_KEY_SPACE},
    {"'", GLFW_KEY_APOSTROPHE},
    {",", GLFW_KEY_COMMA},
    {"-", GLFW_KEY_MINUS},
    {".", GLFW_KEY_PERIOD},
    {"/", GLFW_KEY_SLASH},
    {"0", GLFW_KEY_0},
    {"1", GLFW_KEY_1},
    {"2", GLFW_KEY_2},
    {"3", GLFW_KEY_3},
    {"4", GLFW_KEY_4},
    {"5", GLFW_KEY_5},
    {"6", GLFW_KEY_6},
    {"7", GLFW_KEY_7},
    {"8", GLFW_KEY_8},
    {"9", GLFW_KEY_9},
    {"Semicolon", GLFW_KEY_SEMICOLON},
    {"Equal", GLFW_KEY_EQUAL},
    {"A", GLFW_KEY_A},
    {"B", GLFW_KEY_B},
    {"C", GLFW_KEY_C},
    {"D", GLFW_KEY_D},
    {"E", GLFW_KEY_E},
    {"F", GLFW_KEY_F},
    {"G", GLFW_KEY_G},
    {"H", GLFW_KEY_H},
    {"I", GLFW_KEY_I},
    {"J", GLFW_KEY_J},
    {"K", GLFW_KEY_K},
    {"L", GLFW_KEY_L},
    {"M", GLFW_KEY_M},
    {"N", GLFW_KEY_N},
    {"O", GLFW_KEY_O},
    {"P", GLFW_KEY_P},
    {"Q", GLFW_KEY_Q},
    {"R", GLFW_KEY_R},
    {"S", GLFW_KEY_S},
    {"T", GLFW_KEY_T},
    {"U", GLFW_KEY_U},
    {"V", GLFW_KEY_V},
    {"W", GLFW_KEY_W},
    {"X", GLFW_KEY_X},
    {"Y", GLFW_KEY_Y},
    {"Z", GLFW_KEY_Z},
    {"LeftBracket", GLFW_KEY_LEFT_BRACKET},
    {"Backslash", GLFW_KEY_BACKSLASH},
    {"RightBracket", GLFW_KEY_RIGHT_BRACKET},
    {"GraveAccent", GLFW_KEY_GRAVE_ACCENT},
    {"World1", GLFW_KEY_WORLD_1},
    {"World2", GLFW_KEY_WORLD_2},
    {"Escape", GLFW_KEY_ESCAPE},
    {"Enter", GLFW_KEY_ENTER},
    {"Tab", GLFW_KEY_TAB},
    {"Backspace", GLFW_KEY_BACKSPACE},
    {"Insert", GLFW_KEY_INSERT},
    {"Delete", GLFW_KEY_DELETE},
    {"Right", GLFW_KEY_RIGHT},
    {"Left", GLFW_KEY_LEFT},
    {"Down", GLFW_KEY_DOWN},
    {"Up", GLFW_KEY_UP},
    {"PageUp", GLFW_KEY_PAGE_UP},
    {"PageDown", GLFW_KEY_PAGE_DOWN},
    {"Home", GLFW_KEY_HOME},
    {"End", GLFW_KEY_END},
    {"CapsLock", GLFW_KEY_CAPS_LOCK},
    {"ScrollLock", GLFW_KEY_SCROLL_LOCK},
    {"NumLock", GLFW_KEY_NUM_LOCK},
    {"PrintScreen", GLFW_KEY_PRINT_SCREEN},
    {"Pause", GLFW_KEY_PAUSE},
    {"F1", GLFW_KEY_F1},
    {"F2", GLFW_KEY_F2},
    {"F3", GLFW_KEY_F3},
    {"F4", GLFW_KEY_F4},
    {"F5", GLFW_KEY_F5},
    {"F6", GLFW_KEY_F6},
    {"F7", GLFW_KEY_F7},
    {"F8", GLFW_KEY_F8},
    {"F9", GLFW_KEY_F9},
    {"F10", GLFW_KEY_F10},
    {"F11", GLFW_KEY_F11},
    {"F12", GLFW_KEY_F12},
    {"F13", GLFW_KEY_F13},
    {"F14", GLFW_KEY_F14},
    {"F15", GLFW_KEY_F15},
    {"F16", GLFW_KEY_F16},
    {"F17", GLFW_KEY_F17},
    {"F18", GLFW_KEY_F18},
    {"F19", GLFW_KEY_F19},
    {"F20", GLFW_KEY_F20},
    {"F21", GLFW_KEY_F21},
    {"F22", GLFW_KEY_F22},
    {"F23", GLFW_KEY_F23},
    {"F24", GLFW_KEY_F24},
    {"F25", GLFW_KEY_F25},
    {"LeftShift", GLFW_KEY_LEFT_SHIFT},
    {"LeftControl", GLFW_KEY_LEFT_CONTROL},
    {"LeftAlt", GLFW_KEY_LEFT_ALT},
    {"LeftSuper", GLFW_KEY_LEFT_SUPER},
    {"RightShift", GLFW_KEY_RIGHT_SHIFT},
    {"RightControl", GLFW_KEY_RIGHT_CONTROL},
    {"RightAlt", GLFW_KEY_RIGHT_ALT},
    {"RightSuper", GLFW_KEY_RIGHT_SUPER},
    {"Menu", GLFW_KEY_MENU},
    {"Last", GLFW_KEY_LAST}
        };

		float mouseX;
		float mouseY;

		
};
