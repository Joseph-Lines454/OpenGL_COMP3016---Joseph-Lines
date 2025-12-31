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
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragShaderSource = "#version 460 core\n"
		"out vec4 FragColor;\n"

	"void main()\n"
	"{\n"
		"FragColor = vec4(1.0f, 0.5f, 1.0f, 0.0f);\n"
	"}\0";
	GLuint program;
	Window* OpenGLWindow = new Window();
	OpenGLWindow->windowUp();
	RenderShape* render = new RenderShape();
	// X-Y-Z Cords - Z is Zero because we are only rendering 2D objects currently - therefore no depth is needed to the shape
	

	//shader import
	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert"},
		{GL_FRAGMENT_SHADER, "C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/shaders/fragmentshader.frag"},
		{GL_NONE, NULL}

	};
	program = LoadShaders(shaders);
	

	//render->RenderShapeMain();
		//Starting to get back into flow of how to interact with graphics pipeline.
	float verticies[] = {
	-0.1f,-0.1f,0.0f, 1.0f, 0.0f, 0.0f,
	0.5f,-0.1f,0.0f, 0.0f, 1.0f, 0.0f,
	0.0f,0.1f,0.0f, 0.0f, 0.0f, 1.0f,

	};

	unsigned int indiciesTri[] =
	{
		1,2,3
	};
	//This uses EBO which ensures that we dont render any points which are not needed. We are rendering a square, therefore we want to make sure that we dont render points that are duplicated (because we are rendering two triangles)
	//See below that we are reusing points in the indicies array
	float verticies2[] = {
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,0.0f, // TR
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f,0.0f, 0.0f,1.0f, // BR
	-0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f, 1.0f,1.0f, //BL
	-0.5f,0.5f,0.0f, 1.0f,1.0f,0.0f, 1.0f,0.0f, // TL

	};
	unsigned int indicies[] = {
		//Draw first triangle

		0,1,3,
		//draw second triangle
		1,2,3
	};





	//THIS IS CODE ON HOW TO RENDER A TRINALGE - CAN WE RENDER MULTIPLE VBO'S by assigning them to one VAO and binding them??
	glUseProgram(program);
	//generate an ID for our VAO
	unsigned int VAO;
	//here we are generating a unique ID for the VAO
	glGenVertexArrays(1, &VAO);
	//Binding the Vertex Array (VAO) to OpenGL - allows VBO to use it.
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);
	//assigning a unique ID to that VBO
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	//vertex buffer object is GL_ARRAY_BUFFER - we are binding a newly created buffer(VBO)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//any buffer calls made to GL_ARRAY_BUFFER will be used to configure the currently bound buffer(VBO) - we are copying data(vertices) into the vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indiciesTri), indiciesTri, GL_STATIC_DRAW);

	//GL_STATIC_DRAW - the data isnt changed and is used many times - each render

	// each vertex data, 9 floats in total, 3 bits of data for each point

	//increasing to stride of 32 bytes - foreach vertex 32 bytes of data.
	//appropriate offset has been applied
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//actual floating point for each vertex is 2 and has an offest of 2 ()



	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


	//creating shader object vectex shader

	unsigned int VAO2;
	//here we are generating a unique ID for the VAO
	glGenVertexArrays(1, &VAO2);
	//Binding the Vertex Array (VAO) to OpenGL - allows VBO to use it.
	glBindVertexArray(VAO2);
	unsigned int texture;
	glGenTextures(1, &texture);
	//Binding
	glBindTexture(GL_TEXTURE_2D, texture);
	
	//params: type of texture, texure option and appropriate axis and texure wrapping mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//GL_LINEAR_MIPMAP_LINEAR - texture quality from distance - when texures are downscaled.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Loading an image into openGL, upon a quad
	int width, height, nrChannels;
	unsigned char* data = stbi_load("C:/Users/pring/OneDrive/Documents/COMP3016 - OpenGL - Joseph_Lines/COMP3016_OpenGL_Joseph_Lines/textures_and_media/joseph_lines_signiture.jpg", &width, &height, &nrChannels, 0);
	//assign ID

	//first param asks how many text second is where it stores


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	//Clearing from memory
	stbi_image_free(data);
	//assigning a unique ID to that VBOs
	//glGenVertexArrays(1, &VAO);
	//Binding the Vertex Array (VAO) to OpenGL - allows VBO to use it.
	//glBindVertexArray(VAO);
	
	unsigned int EBO2;
	glGenBuffers(1, &EBO2);
	unsigned int VBO2;
	glGenBuffers(1, &VBO2);
	//vertex buffer object is GL_ARRAY_BUFFER - we are binding a newly created buffer(VBO)
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	//any buffer calls made to GL_ARRAY_BUFFER will be used to configure the currently bound buffer(VBO) - we are copying data(vertices) into the vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies2), verticies2, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	//GL_STATIC_DRAW - the data isnt changed and is used many times - each render

	// each vertex data, 9 floats in total, 3 bits of data for each point

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));


	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	//Texture

	//glBindTexture(GL_TEXTURE, texture);
	//this allows us to draw a tr
	// iangle


	//stbi_image_free(data);
	



	//Keeping window alive, need to make sure that
	while (glfwWindowShouldClose(OpenGLWindow->GetWindow()) == false)
	{

		glfwSwapBuffers(OpenGLWindow->GetWindow());
		//setting colour
		glClearColor(0.25f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO2);
		
		//Using indicies for triangles
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);




		glfwPollEvents();
	}

	glfwTerminate();
}