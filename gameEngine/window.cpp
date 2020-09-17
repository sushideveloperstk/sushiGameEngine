#include "window.h"


namespace sushiEngine {
	namespace graphics {

		Window::Window(const char* name, int width, int hieght) {
			printf("Window properties -\n"
				   "Name: %s\n"
				   "Width: %i\n"
				   "Height: %i\n\n", 
				name, width, hieght);

			m_name = name;
			m_width = width;
			m_hieght = hieght;

			init();
		}

		Window::~Window() { glfwTerminate(); }
		
		int Window::closed() const { return glfwWindowShouldClose(m_Window); }

		bool Window::init() {

			if (!glfwInit()) {
				printf("Failed to initialize GLFW...\n\n");
			}
			else {
				printf("GLFW has been initialized.\n\n");
			}

			m_Window = glfwCreateWindow(m_width, m_hieght, m_name, NULL, NULL);
			if (!m_Window) {
				glfwTerminate();
				printf("ERROR: Failed to create window...\n");
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			// [STRIPPED CODE] glfwSetWindowSizeCallback(m_Window, resize); - Causes build errors, will need to be implemented eventually
			return true;
		}

		void Window::resize(GLFWwindow* Window, int width, int height) {
			glViewport(0, 0, m_width, m_hieght);
		}

		void Window::update() {
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		void Window::clear() const {
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

} }