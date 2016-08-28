#include "src\graphics\window.h"

// ---------------------------
// NEBULOUS GAME ENGINE v4.0.1
// ---------------------------

void printSpecs();

int main()
{
	using namespace NebulousEngine;
	using namespace Graphics;

	Window window("Nebulous C++ Game Engine V4.0.1", 640, 480);
	printSpecs();
	glClearColor(0.0f,0.7f,0.8f,1.0f);

	while (!window.closed()) {
		window.clear();
		window.update();
	}

	return 0;
}

void printSpecs() {
	std::cout << glGetString(GL_VERSION) << std::endl;
}