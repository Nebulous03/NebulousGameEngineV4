#include "src\graphics\window.h"
#include "src\inputs\input.h"

// ----------------------------
// NEBULOUS GAME ENGINE v4.0.5a
// ----------------------------

void printSpecs();

int main()
{
	using namespace NebulousEngine;
	using namespace Graphics;
	using namespace Inputs;
	
	Window window("Nebulous C++ Game Engine V4.0.1", 640, 480);
	printSpecs();
	glClearColor(0.0f,0.7f,0.8f,1.0f);
	
	double x, y;
	
	while (!window.closed()) {
		window.clear();
		window.update();
		if(Input::keyPressed(GLFW_KEY_SPACE))
			std::cout << "SPACE BAR" << std::endl;
		if (Input::buttonPressed(GLFW_MOUSE_BUTTON_1)) {
			std::cout << "BUTTON ONE" << std::endl;
			Input::getMousePos(x, y);
			std::cout << x << ", " << y << std::endl; }
		if (Input::buttonPressed(GLFW_MOUSE_BUTTON_2))
			std::cout << "BUTTON TWO" << std::endl;
		if (Input::keyPressed(GLFW_KEY_ESCAPE)) {
			std::cout << "ESCAPE" << std::endl;
			glfwTerminate();
			break; }
	}

	return 0;
}

void printSpecs() {
	std::cout << glGetString(GL_VERSION) << std::endl;
}