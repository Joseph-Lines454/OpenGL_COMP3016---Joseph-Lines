#pragma once
#include "RenderShape.h"

//inherit objects from Render Shape


//we want to render more complex shapes that dont take verticies i.e glDrawArrays
class Shapes3D : RenderShape {
	//Want this way because its dyamic to allow for differnt verticies to be inputted
private:
	const char* MixingURL;
	unsigned int texture;

	unsigned int mixingTexture;
	void TextureRender()
	{
		
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glGenTextures(1, &texture);
		//Binding
		glBindTexture(GL_TEXTURE_2D, texture);
		//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
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
		//assign ID

		if (data)
		{
			std::cout << "We have found data! I think..." << std::endl;
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << stbi_failure_reason << std::endl;
			std::cout << "Issue no data???" << std::endl;
		}

		//first param asks how many text second is where it stores

		//Clearing from memory - we can now load our second image
		stbi_image_free(data);

		glEnableVertexAttribArray(2);
		glGenTextures(1, &mixingTexture);
		//Binding
		glBindTexture(GL_TEXTURE_2D, mixingTexture);
		//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		//params: type of texture, texure option and appropriate axis and texure wrapping mode
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		//GL_LINEAR_MIPMAP_LINEAR - texture quality from distance - when texures are downscaled.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//Loading an image into openGL, upon a quad
		
		stbi_set_flip_vertically_on_load(true);
		if (MixingURL != NULL)
		{
			data = stbi_load(MixingURL, &width, &height, &nrChannels, 0);
			if (data)
			{
				std::cout << "We have found data! I think..." << std::endl;
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
				
			}
			stbi_image_free(data);
		}
		
		//assign ID

		
		else
		{
			std::cout << stbi_failure_reason << std::endl;
			std::cout << "Issue no data???" << std::endl;
		}

		//first param asks how many text second is where it stores
		std::cout << "we made it here..." << std::endl;
		//Clearing from memory - we can now load our second image
		
		
		//glUniform1i(glGetUniformLocation(program, "tex"), 0);
		//pass this data into the vertex shader - uniforms?
		
	}

public:
	Shapes3D(std::vector<float> verticies, int indiciesAmount, const char* imageurl, const char* mixtexture, int stride) : RenderShape()
	{
		//this->indiciesTotal = verteciesTotal;
		this->verticies = verticies;
		this->indiciesAmount = indiciesAmount;
		this->imageurl = imageurl;
		this->stride = stride;
		this->MixingURL = mixtexture;
	}
	void ShapeInitialization(float width, float height)
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
		
		//This needs to be conditional

		if (imageurl != NULL)
		{
			std::cout << "Wrong texture" << std::endl;
			TextureRender();
			//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 0);
		}
		else
		{
			std::cout << "There is no texture for this shader" << std::endl;
			//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 0);
			//glUniform3f(glGetUniformLocation(program, "ColourUni"), 0.5, 0.0, 0.0);
		}

		
		//Check for textures, if so, render


		//glBindVertexArray(VAO);
		// get indice amount by dividing total bytes by bytes of one value
		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}

	void RenderShapeMain()
	{

		//actual floating point for each vertex is 2 and has an offest of 2 ()
		//sglEnableVertexAttribArray(1);
		//do we pass colour in as...???
		//glUniform1i(glGetUniformLocation(program, "istextureTrue"), 0);
		//pass colour as uniform i guess
		//glUniform3f(glGetUniformLocation(program, "ColourUni"), 0.5, 0.5, 0.5);
		
		glBindVertexArray(VAO);
		
		//std::cout << imageurl << std::endl;
		glBindTexture(GL_TEXTURE_2D, texture);
		// get indice amount by dividing total bytes by bytes of one value
		//glDrawElements(GL_TRIANGLES, indiciesAmount, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, indiciesAmount);
	}

	unsigned int GetTextureOne()
	{
		return texture;
	}

	unsigned int GetTextureTwo() {
		return mixingTexture;
	}




};