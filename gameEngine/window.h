#pragma once

#include <glfw3.h>
#include <stdio.h>

namespace sushiEngine {
	namespace graphics {

		class Window {
			// Window properties
		private:
			const char* m_name;
			int m_width, m_hieght;
			GLFWwindow* m_Window;
			bool m_closed;
			// Window methods
		public:
			// Window properties constructor
			Window(const char *name, int width, int hight);
			// Window destructor
			~Window();
			// Returns if window is closed or not
			int closed() const;
			// Places viewpoint for when window is resized
			void resize(GLFWwindow *Window, int width, int height);
			// Updates the window with buffer
			void update();
			// Clears the window with a black screen
			void clear() const;

			inline int getWidth() const { return m_width; }
			inline int getHieght() const { return m_hieght; }
		private:
			// Window init method
			bool init();
		};
	}
}