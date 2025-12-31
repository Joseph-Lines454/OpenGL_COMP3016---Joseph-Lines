#pragma once
#include <iostream>

//#include <GL/glew.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>


class Window {
private:
	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGLWindow", NULL, NULL);
	
public:
	void static framebuffer_size_callback(GLFWwindow* window, int width, int height) {

		glViewport(0, 0, width, height);
	}
	void windowUp()
	{
		glfwInit();
		window = glfwCreateWindow(1280, 720, "OpenGLWindow", NULL, NULL);
		

		if (window == NULL)
		{
			std::cout << "Window has not initialized!" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Could not initliaze GLAD" << std::endl;
			
		}

		//glewInit();
		glViewport(0, 0, 1280, 720);
		std::cout << glGetString(GL_VERSION) << std::endl;

		//when the window is resized, we want to change openGL's viewport to match glfw's view
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		
	}

	GLFWwindow* GetWindow()
	{
		return window;
	}
};