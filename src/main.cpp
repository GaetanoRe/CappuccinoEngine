#include "../include/engine.h"
#include <iostream>
#include <cstdlib>
#include <GLFW/glfw3.h>

int main(){
	Engine * engine = new Engine();
	float lastTime = glfwGetTime();
	engine->init();
	while(!engine->isWindowClosed()){
		float currentTime = glfwGetTime();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		engine->update(deltaTime);
	}
	delete engine;
	return 0;
}
