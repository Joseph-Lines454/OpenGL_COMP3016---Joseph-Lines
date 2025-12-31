#pragma once
#pragma once
#include <iostream>

//#include <GL/glew.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <filesystem>
#include <fstream>

class RenderShape {
private:
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

	void ReadShadersFromFiles()
	{
		

		std::ifstream file("/shaders/fragmentshader.txt");
		if (file.good())
		{
			std::cout << "File is good!" << std::endl;
		}
		if (file.is_open())
		{
			int size = file.tellg();
			char* memblock = new char[size];
			file.seekg(0, std::ios::end);
			file.read(memblock, size);
			//std::cout << memblock << std::endl;
		}
		else
		{
			//std::cout << "File is not open!" << std::endl;
		}
		

	}

public:
	void RenderShapeMain()
	{
		float verticies[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f,

		};
		//assigning a unique ID to that VBO
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		//vertex buffer object is GL_ARRAY_BUFFER - we are binding a newly created buffer(VBO)
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//any buffer calls made to GL_ARRAY_BUFFER will be used to configure the currently bound buffer(VBO) - we are copying data(vertices) into the vertex buffer
		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

		//GL_STATIC_DRAW - the data isnt changed and is used many times - each render


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		//this allows us to draw a triangle

		//creating shader object vectex shader


		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		//check if the shader compiled successfully potentially

		//Creating a fragement shader is the exact same as a vertex shader - just need to specify type of shader
		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragShaderSource, NULL);
		glCompileShader(fragmentShader);


		//Linking multiple shaders together
		GLuint shaderProgram;
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		int success;
		char infolog[512];
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
			std::cout << infolog << std::endl;
		}

		ReadShadersFromFiles();

		glUseProgram(shaderProgram);



		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLES, 0, 3);


	}
};