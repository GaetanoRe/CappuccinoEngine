#include "../include/engine.h"
#include <iostream>
#include <cstdlib>
#include <memory>
#include <GLFW/glfw3.h>

int main(){
	if (!glfwInit()) {
		const char* description;
		glfwGetError(&description); // Get the error description
		std::cerr << "GLFW initialization failed: " << description << std::endl; // Log the error
		throw std::runtime_error("GLFW initialization failed"); // Throw the exception
		return -1;
	}
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	float lastTime = glfwGetTime();
	engine->init();
	while(!engine->isWindowClosed()){
		float currentTime = glfwGetTime();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		engine->update(deltaTime);
	}

	glfwTerminate();
	return 0;
}
