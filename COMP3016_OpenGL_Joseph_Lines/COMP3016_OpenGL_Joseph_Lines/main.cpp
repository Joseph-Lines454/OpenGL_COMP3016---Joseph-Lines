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

	
	//shader import
	//"C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert"
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "../../COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert"},
		{GL_FRAGMENT_SHADER, "../../COMP3016_OpenGL_Joseph_Lines/shaders/fragmentshader.frag"},
		{GL_NONE, NULL}

	};
	program = LoadShaders(shaders);




	glUseProgram(program);

	RenderShape* renderShape2 = new RenderShape({ 0,1,3, 1,2,3 }, {
		0.5f, 0.5f,0.0f,    0.1f, 0.5f, 0.0f,   1.0f,1.0f,  // top right
		0.5f,-0.5f,0.0f,    0.5f, 0.0f,0.0f,   1.0f,0.0f,  //bottom right
		-0.5f,-0.5f,0.0f,   0.5f,0.0f,0.0f,    0.0f,0.0f, //bottom left
		-0.5f,0.5f,0.0f,    0.5f,0.0f,0.0f,      0.0f,1.0f, // top left


	}, 36, "../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg",8, program);
	
	Shapes3D* newShape3D = new Shapes3D({ 
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f, 0.1f, 0.5f, 
	 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f }, 36, "../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg", "../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/img2.png", 5);
	
	/*
	Shapes3D* newShape3D = new Shapes3D({ -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,}, 5, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg", 5);*/



	
	glEnable(GL_DEPTH_TEST);
	
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

	int width;
	int height;
	glfwGetWindowSize(OpenGLWindow->GetWindow(), &width, &height);
	

	
	newShape3D->ShapeInitialization((float)width, (float)height);
	//Keeping window alive, need to make sure that
	//glm::mat4 model = glm::mat4(1.0f);
	//glm::mat4 view;
	//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//glm::mat4 projection = glm::mat4(1.0f);
	
	

	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));


	//Define the FOV and convert degrees to radians, the aspect radio - window width and height and the clipping space
	



	//order matters when multiplying because matrix math works  by columns and rows and if mixed, an incorrect output will occur
	
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(0.5, 1.0f, 0.0f));
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 2.0f, -3.0f));
	glm::mat4 projection;
//	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);


	//glm::mat4 model3 = glm::mat4(1.0f);
	//model3 = glm::rotate(model, glm::radians(-45.0f), glm::vec3(0.5, 1.0f, 1.0f));
	//glm::mat4 view3 = glm::mat4(1.0f);
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
	//glm::mat4 projection3;
	//projection3 = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	//glm::mat4 modelCamera = glm::mat4(1.0f);
	// 
	//Put this in a camera class
	glm::vec3 User_Look_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraDirectonVec = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp_Y = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewcamera = glm::mat4(1.0f);
	glm::mat4 projection2;
	glm::mat4 model2 = glm::mat4(1.0f);
	//Making a fixed timestep
	
	model2 = glm::translate(model, glm::vec3(1.0f, 3.0f, -5.0f));

	view = glm::translate(view, glm::vec3(0.0f, 2.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	
	GLuint getMVP = glGetUniformLocation(program, "Model_View_Projection");
	GLuint getMVP2 = glGetUniformLocation(program, "Model_View_Projection");
	GLuint getMVP3 = glGetUniformLocation(program, "Model_View_Projection");
	glm::mat4 mvp;
	while (glfwWindowShouldClose(OpenGLWindow->GetWindow()) == false)
	{
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 model2 = glm::mat4(1.0f);
		//setting colour
		glClearColor(0.25f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		float current = glfwGetTime();
		deltaTime = current - lastFrame;
		

		OpenGLWindow->ProcessUserInput(User_Look_Position, cameraDirectonVec, cameraUp_Y, deltaTime, float(height), float(width));
		viewcamera = glm::lookAt(User_Look_Position, User_Look_Position + cameraDirectonVec, cameraUp_Y);
		//projection2 = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
		//mvp = projection2 * viewcamera * model2;
		//glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(mvp));

		//TRANSLATION HAS TO HAPPEN BEFORE ROTATION - IMPORTANT

		
		model = glm::translate(model, glm::vec3(0.0f, 2.0f, -3.0f));
		model = glm::rotate(model, (float)glfwGetTime() * 1.0f, glm::vec3(0.5, 1.0f, 0.0f));
		
		mvp = projection * viewcamera * model;


		glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(mvp));
		//we need to structure this in a better way - we need to check for each object weather somthing is allowed or not
		//glUniform1i(glGetUniformLocation(program, "isMultipletextureTrue"), 1);
		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, newShape3D->GetTextureTwo());
		glUniform1i(glGetUniformLocation(program, "textureOne"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, newShape3D->GetTextureOne());
		glUniform1i(glGetUniformLocation(program, "textureTwo"), 1);

		//pass colour as uniform i guess
		//This is where we draw the new shape
		newShape3D->RenderShapeMain();
		

		//model2 = glm::translate(model, glm::vec3(1.0f, 3.0f, -3.0f));
		model2 = glm::rotate(model2, (float)glfwGetTime() * 1.0f, glm::vec3(0.5, 1.0f, 0.0f));
		mvp = projection * viewcamera * model2;

		//Lets write some code here with conditions on how to render different colours
		
		// hopefully this works
		glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(mvp));
		//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		
		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, renderShape2->GetTexture());
		glUniform1i(glGetUniformLocation(program, "textureOne"), 0);
		glActiveTexture(GL_TEXTURE1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, 0);
		//glUniform1i(glGetUniformLocation(program, "textureTwo"), 1);

		renderShape2->RenderShapeMain();

		
		


		lastFrame = current;
		
		glfwSwapBuffers(OpenGLWindow->GetWindow());
		
		
		glfwPollEvents();


	}

	glfwTerminate();
}