#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace NebulousEngine {
	namespace Inputs {

#define MAX_BUTTONS	32
#define MAX_KEYS	1024

		class Input {
		public:
			static bool keyPressed(unsigned int keycode);
			static bool buttonPressed(unsigned int keycode);
			static void getMousePos(double& x, double& y);
		};

	}
}