#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace NebulousEngine { namespace Graphics {

		class Window
		{
		private:
			const char *m_title;
			int m_width, m_height;
			GLFWwindow *m_window;

			bool init();
		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			int getWidth() const;
			int getHeight() const;
		};

} }