#include "..\graphics\window.h"
#include "input.h"

namespace NebulousEngine {
	namespace Input {

		bool Input::keyPressed(unsigned int keycode) {
			if (keycode <= MAX_KEYS)
				return Graphics::Window::getKeyAt(keycode);
			else {
				std::cout << "Error: Keycode " << keycode << "is out of bounds." << std::endl;
				return false;
			}
		}

		bool Input::buttonPressed(unsigned int buttoncode) {
			if (buttoncode <= MAX_BUTTONS)
				return Graphics::Window::getButtonAt(buttoncode);
			else {
				std::cout << "Error: Buttoncode " << buttoncode << "is out of bounds." << std::endl;
				return false;
			}
		}

		void Input::getMousePos(double& x, double& y) {
			x = Graphics::Window::getMouseX();
			y = Graphics::Window::getMouseY();
		}

	}
}