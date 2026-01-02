#include <iostream>

//#include <GL/glew.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include "Window.h"
#include "RenderShape.h"
#include "LoadShaders.h"
#include "stb_image.h"
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shapes3D.h"
int main()
{
	// this is temporary because we will vert file, just dont know how to load shader with glad
	GLFWvidmode returnData;
	GLuint program;
	Window* OpenGLWindow = new Window();
	OpenGLWindow->windowUp();

	//std::vector<float> verticies =  {-0.1f, -0.1f, 0.0f, 1.0f, 0.0f, 0.0f,0.5f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f,0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 1.0f};
	//std::vector<unsigned int> indicies = { 1, 2, 3 };

	RenderShape* render = new RenderShape({ 1, 2, 3 }, { -0.1f, -0.1f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 1.0f },3, NULL,3);
	// X-Y-Z Cords - Z is Zero because we are only rendering 2D objects currently - therefore no depth is needed to the shape
	

	RenderShape* renderShape2 = new RenderShape({ 0,1,3, 1,2,3 }, {
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,0.0f, 0.0f,1.0f, -0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f, 1.0f,1.0f,-0.5f,0.5f,0.0f, 1.0f,1.0f,0.0f, 1.0f,1.0f,


	}, 36, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg",8);
	Shapes3D* newShape3D = new Shapes3D({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f }, 36, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg", 5);

	//shader import
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert"},
		{GL_FRAGMENT_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/fragmentshader.frag"},
		{GL_NONE, NULL}

	};
	program = LoadShaders(shaders);
	

	

	glUseProgram(program);
	glEnable(GL_DEPTH_TEST);
	render->ShapeInitialization();
	renderShape2->ShapeInitialization();

	//Model View Projection
	/*
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::translate(model, glm::vec3(0.0f, 1.0f, -1.5f));
	
	glm::mat4 view = lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	int width;
	int height;
	glfwGetWindowSize(OpenGLWindow->GetWindow(), &width, &height);

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

	glm::mat4 mvp = projection * view * model;
	glUniformMatrix4fv(glGetUniformLocation(program,"Model_View_Projection"), 1, GL_FALSE, value_ptr(mvp));
	*/

	
	
	//
	//Multiply vector by transformation matrix
	//vec = vec * transform;


	//Model_View_Projection

	
	

	
	newShape3D->ShapeInitialization();
	//Keeping window alive, need to make sure that
	//glm::mat4 model = glm::mat4(1.0f);
	//glm::mat4 view;
	//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//glm::mat4 projection = glm::mat4(1.0f);
	
	

	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));


	//Define the FOV and convert degrees to radians, the aspect radio - window width and height and the clipping space
	



	//order matters when multiplying because matrix math works  by columns and rows and if mixed, an incorrect output will occur
	int width;
	int height;
	glfwGetWindowSize(OpenGLWindow->GetWindow(), &width, &height);
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(0.5, 1.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);


	//Put this in a camera class
	glm::vec3 User_Look_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraDirectonVec = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp_Y = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewcamera = glm::mat4(1.0f);
	glm::mat4 projection2;
	
	//Making a fixed timestep

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	

	while (glfwWindowShouldClose(OpenGLWindow->GetWindow()) == false)
	{

		float current = glfwGetTime();
		deltaTime = current - lastFrame;
		
		//setting colour
		glClearColor(0.25f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
		
		//glm::mat4 view = glm::mat4(1.0f);
		//view = glm::lookAt(glm::vec3(0.0, 0.0f, 3.0f), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
		
		
		
		
		//Put this in a camera class to keep it all together
		//OpenGLWindow->ProcessUserInput(User_Look_Position, cameraDirectonVec, cameraUp_Y, deltaTime, float(height), float(width));
		//Transformatiom Matrix - adding the cameraPosition Matrix as well as the cameraFront matrix gives us target.
		
		model = glm::rotate(model, (float)glfwGetTime() * deltaTime , glm::vec3(0.5, 1.0f, 0.0f));
		
		glm::mat4 mvp = projection * view * model;
		
		glUniformMatrix4fv(glGetUniformLocation(program, "Model_View_Projection"), 1, GL_FALSE, value_ptr(mvp));


		//viewcamera = glm::lookAt(User_Look_Position, User_Look_Position + cameraDirectonVec, cameraUp_Y);

		//FOV, viewport params and clipspace, when objects should disapear
		//projection2 = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);



		//This need to be put into the seperate classes, OOP THIS CODE!
		
		OpenGLWindow->ProcessUserInput(User_Look_Position, cameraDirectonVec, cameraUp_Y, deltaTime, float(height), float(width));
		viewcamera = glm::lookAt(User_Look_Position, User_Look_Position + cameraDirectonVec, cameraUp_Y);
		projection2 = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
		glm::mat4 mvp2 = projection2 * viewcamera * model;
		glUniformMatrix4fv(glGetUniformLocation(program, "Model_View_Projection"), 1, GL_FALSE, value_ptr(mvp2));

		
		
		//some code to try and get movement working
		

		//glUniformMatrix4fv(glGetUniformLocation(program, "Model_View_Projection"), 1, GL_FALSE, value_ptr(mvp));
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//render->RenderShapeMain();
		//renderShape2->RenderShapeMain();
		newShape3D->RenderShapeMain();
		lastFrame = current;
		
		glfwSwapBuffers(OpenGLWindow->GetWindow());
		//glfwSetInputMode(OpenGLWindow->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		glfwPollEvents();


	}

	glfwTerminate();
}