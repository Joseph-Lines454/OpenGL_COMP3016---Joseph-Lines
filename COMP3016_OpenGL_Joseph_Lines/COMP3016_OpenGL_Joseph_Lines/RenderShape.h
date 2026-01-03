#pragma once
#pragma once
#include <iostream>

//#include <GL/glew.h>
#include <glad/glad.h>
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include "stb_image.h"

class RenderShape {
protected:
	//Want this way because its dyamic to allow for differnt verticies to be inputted
	std::vector<float> verticies;
	std::vector<unsigned int> indicies;
	int indiciesAmount;
	unsigned int VAO;
	const char* imageurl;
	const char* MixingURL;
	unsigned int texture;
	int stride;
	GLuint program;
	void TextureRender()
	{
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glGenTextures(1, &texture);
		//Binding
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		//params: type of texture, texure option and appropriate axis and texure wrapping mode
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		//GL_LINEAR_MIPMAP_LINEAR - texture quality from distance - when texures are downscaled.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//Loading an image into openGL, upon a quad
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(imageurl, &width, &height, &nrChannels, 0);
		if (data)
		{
			std::cout << "We have found data!" << std::endl;
		}


		
		

		//assign ID

		

		//first param asks how many text second is where it stores


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		//Clearing from memory
		stbi_image_free(data);
	}

public:
	RenderShape() {};
	RenderShape(std::vector<unsigned int> indiciesOrder, std::vector<float> verticies, int indiciesAmount, const char* imageurl, int stride, GLuint program)
	{
		//this->indiciesTotal = verteciesTotal;
		this->indicies = indiciesOrder;
		this->verticies = verticies;
		this->indiciesAmount = indiciesAmount;
		this->imageurl = imageurl;
		this->stride = stride;
		this->program = program;
	}
	unsigned int GetTexture()
	{
		return texture;
	}
	void ShapeInitialization()
	{
		
		//generate an ID for our VAO
		//unsigned int VAO;
		//here we are generating a unique ID for the VAO
		glGenVertexArrays(1, &VAO);
		//Binding the Vertex Array (VAO) to OpenGL - allows VBO to use it.
		glBindVertexArray(VAO);
		//glEnableVertexAttribArray(0);
		//glEnableVertexAttribArray(1);
		//glEnableVertexAttribArray(2);
		//assigning a unique ID to that VBO
		unsigned int EBO;
		glGenBuffers(1, &EBO);
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		//vertex buffer object is GL_ARRAY_BUFFER - we are binding a newly created buffer(VBO)
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//any buffer calls made to GL_ARRAY_BUFFER will be used to configure the currently bound buffer(VBO) - we are copying data(vertices) into the vertex buffer

		//need to get the first element of the vector to allow for rendering - 
		glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(indicies), indicies.data(), GL_STATIC_DRAW);

		//GL_STATIC_DRAW - the data isnt changed and is used many times - each render

		// each vertex data, 9 floats in total, 3 bits of data for each point

		//increasing to stride of 32 bytes - foreach vertex 32 bytes of data.
		//appropriate offset has been applied
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//if we have two textures we can look here and do somthing

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		//This needs to be conditional
		
		if (imageurl != NULL)
		{
			TextureRender();
		}
		else
		{
			glUniform1i(glGetUniformLocation(program, "istextureTrue"), 0);
		}
		

		//Check for textures, if so, render
		
		
		//glBindVertexArray(VAO);
		// get indice amount by dividing total bytes by bytes of one value
		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}

	void RenderShapeMain()
	{
		glBindVertexArray(VAO);
		
		glBindTexture(GL_TEXTURE_2D, texture);
		// get indice amount by dividing total bytes by bytes of one value	
		glDrawElements(GL_TRIANGLES, indiciesAmount, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
	}


	

};