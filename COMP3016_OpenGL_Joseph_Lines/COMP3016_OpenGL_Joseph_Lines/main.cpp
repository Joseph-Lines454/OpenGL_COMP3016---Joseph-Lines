#include <iostream>

//#include <GL/glew.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include "Window.h"
#include "RenderShape.h"
#include "LoadShaders.h"
#include "stb_image.h"

int main()
{
	// this is temporary because we will vert file, just dont know how to load shader with glad
	
	GLuint program;
	Window* OpenGLWindow = new Window();
	OpenGLWindow->windowUp();

	//std::vector<float> verticies =  {-0.1f, -0.1f, 0.0f, 1.0f, 0.0f, 0.0f,0.5f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f,0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 1.0f};
	//std::vector<unsigned int> indicies = { 1, 2, 3 };

	RenderShape* render = new RenderShape({ 1, 2, 3 }, { -0.1f, -0.1f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 1.0f },3, NULL,3);
	// X-Y-Z Cords - Z is Zero because we are only rendering 2D objects currently - therefore no depth is needed to the shape
	
	RenderShape* renderShape2 = new RenderShape({ 0,1,3, 1,2,3 }, { 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,0.0f, 0.0f,1.0f, -0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f, 1.0f,1.0f,
	-0.5f,0.5f,0.0f, 1.0f,1.0f,0.0f, 1.0f,1.0f, }, 6, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg",8);

	//shader import
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert"},
		{GL_FRAGMENT_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/fragmentshader.frag"},
		{GL_NONE, NULL}

	};
	program = LoadShaders(shaders);
	

	

	glUseProgram(program);
	render->ShapeInitialization();
	renderShape2->ShapeInitialization();

	//Keeping window alive, need to make sure that
	while (glfwWindowShouldClose(OpenGLWindow->GetWindow()) == false)
	{

		
		//setting colour
		glClearColor(0.25f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		render->RenderShapeMain();
		renderShape2->RenderShapeMain();

		glfwSwapBuffers(OpenGLWindow->GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();
}