#pragma once
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
//#include <GL/glew.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

class Window {
private:
	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGLWindow", NULL, NULL);
	
	//float windowHeight = 800;
	//float windowWidth = 800;
	float mousesensitivity = 100;
	//glm::mat4 modelCamera = glm::mat4(1.0f);
	//Put this in a camera class
	//glm::vec3 User_Look_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	//glm::vec3 cameraDirectonVec = glm::vec3(0.0f, 0.0f, -1.0f);
	//glm::vec3 cameraUp_Y = glm::vec3(0.0f, 1.0f, 0.0f);
	//glm::mat4 viewcamera = glm::mat4(1.0f);
	//glm::mat4 projection2;
	
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
		

		//when the window is resized, we want to change openGL's viewport to match glfw's view
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	}

	GLFWwindow* GetWindow()
	{
		return window;
	}
	void ProcessUserInput(glm::vec3& User_Look_Position, glm::vec3& cameraDirectonVec, glm::vec3& cameraUp_Y, float& deltaTime, float windowHeight, float windowWidth)
	{
		float cameraSpeedforsakeoffunction = 2.5f * deltaTime;
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		{
			cameraSpeedforsakeoffunction = cameraSpeedforsakeoffunction * 2.0f;
		}
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwTerminate();
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			User_Look_Position += cameraSpeedforsakeoffunction * cameraDirectonVec;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			User_Look_Position -= cameraSpeedforsakeoffunction * cameraDirectonVec;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			User_Look_Position -= glm::normalize(glm::cross(cameraDirectonVec, cameraUp_Y)) * cameraSpeedforsakeoffunction;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			User_Look_Position += glm::normalize(glm::cross(cameraDirectonVec, cameraUp_Y)) * cameraSpeedforsakeoffunction;
		}


		//Get the mouse position got glfw
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		

		//We want to rotate the axis, so we 
		float RotateYaxis = mousesensitivity * (float)(mouseY - (windowHeight / 2)) / windowHeight;
		float RotateXaxis = mousesensitivity * (float)(mouseX - (windowWidth / 2)) / windowWidth;

		//This is getting the x direction - we are allowing us to spin freely
		glm::vec3 newDirection = glm::rotate(cameraDirectonVec, glm::radians(-RotateYaxis), glm::normalize(glm::cross(cameraDirectonVec, cameraUp_Y)));


		//We need to check the Y direction - So glm::angle is used to calculate angle between the Y pos and the newDirection - we want to make sure that the camera dosent do a 360 and is essentially
		//capped at 180degrees
		if (!(glm::angle(newDirection, cameraUp_Y) <= glm::radians(2.0f) || (glm::angle(newDirection, -cameraUp_Y) <= glm::radians(2.0f))))
		{
			//assign new Direction which we calculated above to out cameraDirectionVec
			cameraDirectonVec = newDirection;
		}
		// This is for the X axis - here we dont need to do any condition checking - we just rotate camera.
		cameraDirectonVec = glm::rotate(cameraDirectonVec, glm::radians(-RotateXaxis), cameraUp_Y);

		//reset the cursor positon to the 
		glfwSetCursorPos(window, (windowWidth / 2), (windowHeight / 2));
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}

	
	
	

};