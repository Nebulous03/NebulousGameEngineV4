#include "window.h"

namespace NebulousEngine { namespace Graphics {

	bool Window::m_keys[MAX_KEYS];
	bool Window::m_buttons[MAX_BUTTONS];
	double Window::mx, Window::my;

	Window::Window(const char *title, int width, int height) {
		m_title = title;
		m_height = height;
		m_width = width;
		if (!init()) glfwTerminate();
		else std::cout << "OpenGL init successful." << std::endl;
		for (int i = 0; i < MAX_KEYS; i++)
			m_keys[i] = false;
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_buttons[i] = false;
		std::cout << "GLWindow init successful." << std::endl;
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			std::cout << "Error: Failed to init GLFW." << std::endl;
			return false;
		} else std::cout << "GLFW init successful." << std::endl;

		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

		if (!m_window) {
			std::cout << "Error: Failed to create GLFW window." << std::endl;
			return false;
		} 
		
		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, windowResize);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, button_callback);
		glfwSetCursorPosCallback(m_window, cursor_callback);

		if (glewInit() != GLEW_OK) {
			std::cout << "Error: Failed to init GLEW." << std::endl;
			return false;
		} else std::cout << "GLEW init successful." << std::endl;
		return true;
	}
	
	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() {
		glfwPollEvents();
		//glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_window) == 1;
	}

	int Window::getWidth() const {
		return m_width;
	}

	int Window::getHeight() const {
		return m_height;
	}

	void windowResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		Window *win = (Window*) glfwGetWindowUserPointer(window);
		win->m_keys[key] = action != GLFW_RELEASE;
	}

	void button_callback(GLFWwindow *window, int button, int action, int mods) {
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->m_buttons[button] = action != GLFW_RELEASE;
	}

	void cursor_callback(GLFWwindow * window, double xpos, double ypos) {
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

	bool Window::keyPressed(unsigned int keycode) {
		if (keycode <= MAX_KEYS) {
			return m_keys[keycode];
		} else {
			std::cout << "Error: Keycode " << keycode << "is out of bounds." << std::endl;
			return false;
		}
	}

	bool Window::buttonPressed(unsigned int buttoncode){
		if (buttoncode <= MAX_BUTTONS) {
			return m_buttons[buttoncode];
		}
		else {
			std::cout << "Error: Buttoncode " << buttoncode << "is out of bounds." << std::endl;
			return false;
		}
	}

	void Window::getMousePos(double& x, double& y) {
		x = mx;
		y = my;
	}
} }