#include "window.h"

namespace NebulousEngine { namespace Graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height) {
		m_title = title;
		m_height = height;
		m_width = width;
		if (!init()) glfwTerminate();
		else std::cout << "OpenGL init successful." << std::endl;
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
		} glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, windowResize);

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
		return glfwWindowShouldClose(m_window);
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

} }