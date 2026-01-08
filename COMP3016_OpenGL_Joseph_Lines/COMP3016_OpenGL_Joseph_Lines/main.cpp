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
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/model.h>
#include "FastNoiseLite.h"

#define RENDER_DISTANCE 128
#define MAP_SIZE RENDER_DISTANCE * RENDER_DISTANCE

const int squaresRow = RENDER_DISTANCE - 1;
const int trianglesPerSquare = 2;
const int trianglesGrid = squaresRow * squaresRow * trianglesPerSquare;

GLfloat terrainVerticies[MAP_SIZE][6];

float drawingStartPosition = 1.0f;
float columnVerticiesOffset = drawingStartPosition;
float rowVerticiesOffset = drawingStartPosition;
int rowIndex = 0;




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
	
	

	Shader Shaders("../../COMP3016_OpenGL_Joseph_Lines/shaders/vertexshader.vert", "../../COMP3016_OpenGL_Joseph_Lines/shaders/fragmentshader.frag");
	Model Deer("../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/Deer/deer.gltf");
	Model Tiger("../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/tiger/tiger_001.obj");
	//Model Rock("../../COMP3016_OpenGL_Joseph_Lines/textures_and_media/tiger/tiger3.obj");
	Shaders.use();
	//glUseProgram(program);

	RenderShape* renderShape2 = new RenderShape({ 0,1,3, 1,2,3 }, {
		0.5f, 0.5f,0.0f,    0.1f, 0.5f, 0.0f,   1.0f,1.0f,  
		0.5f,-0.5f,0.0f,    0.5f, 0.0f,0.0f,   1.0f,0.0f,  
		-0.5f,-0.5f,0.0f,   0.5f,0.0f,0.0f,    0.0f,0.0f, 
		-0.5f,0.5f,0.0f,    0.5f,0.0f,0.0f,      0.0f,1.0f,


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
	view = glm::translate(view, glm::vec3(0.0f, 10.0f, -2.0f));
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
	
	glm::mat4 model_Deer = glm::mat4(1.0f);
	//model_RK = glm::translate(model_RK, glm::vec3(1.0f, 3.0f, -5.0f));
	model_Deer = glm::scale(model_Deer, glm::vec3(0.3f,0.3f,0.3f));
	model_Deer = glm::translate(model_Deer, glm::vec3(-10.0f, 9.0f, -13.0f));
	model2 = glm::translate(model, glm::vec3(1.0f, 2.0f, -5.0f));

	glm::mat4 model_Tiger = glm::mat4(1.0f);
	//model_RK = glm::translate(model_RK, glm::vec3(1.0f, 3.0f, -5.0f));
	model_Tiger = glm::scale(model_Tiger, glm::vec3(0.3f, 0.3f, 0.3f));
	model_Tiger = glm::translate(model_Tiger, glm::vec3(-4.0f, 6.5f, -30.0f));
	

	view = glm::translate(view, glm::vec3(0.0f, 2.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	glm::mat4 modelTerrain = glm::mat4(1.0f);

	GLuint getMVP = glGetUniformLocation(program, "Model_View_Projection");
	GLuint getMVP2 = glGetUniformLocation(program, "Model_View_Projection");
	GLuint getMVP3 = glGetUniformLocation(program, "Model_View_Projection");
	GLuint getMVP4 = glGetUniformLocation(program, "Model_View_Projection");
	glm::mat4 mvp;
	glm::mat4 MVPTerrain;

	FastNoiseLite BiomeNoise;
	BiomeNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
	BiomeNoise.SetFrequency(0.05f);
	int biomeSeed = rand() % 100;
	BiomeNoise.SetSeed(biomeSeed);

	int i = 0;
	//height variation and mapping of colours
	for (int y = 0; y < RENDER_DISTANCE; y++)
	{
		for (int x = 0; x < RENDER_DISTANCE; x++)
		{
			terrainVerticies[i][1] = BiomeNoise.GetNoise((float)x, (float)y);
			i++;

			float biomeVal = BiomeNoise.GetNoise((float)x, (float)y);

			

			if (i >= trianglesGrid / 4)
			{
				if (biomeVal <= 0.4f)
				{
					terrainVerticies[i][3] = 0.0f;
					terrainVerticies[i][4] = 0.75f;
					terrainVerticies[i][5] = 0.25f;
				}
				terrainVerticies[i][3] = 0.25f;
				terrainVerticies[i][4] = 0.75f;
				terrainVerticies[i][5] = 0.25f;
			}
			
			else
			{
				terrainVerticies[i][3] = 1.0f;
				terrainVerticies[i][3] = 1.0f;
				terrainVerticies[i][4] = 1.0f;
				terrainVerticies[i][5] = 0.5f;
			}

			

		}
	}

	//Setting Terrain Verticies
	for (int i = 0; i < MAP_SIZE; i++)
	{
		terrainVerticies[i][0] = columnVerticiesOffset;
		terrainVerticies[i][2] = rowVerticiesOffset;

		columnVerticiesOffset = columnVerticiesOffset + -0.0625f;

		rowIndex++;

		if (rowIndex == RENDER_DISTANCE)
		{
			rowIndex = 0;

			columnVerticiesOffset = drawingStartPosition;
			rowVerticiesOffset = rowVerticiesOffset + -0.0625f;
		}
	}
	std::cout << "Made it here before GLUINT" << std::endl;
	GLuint terrainIndicies[trianglesGrid][3];

	int columnIndiciesOffset = 0;
	int rowIndiciesOffset = 0;

	rowIndex = 0;

	for (int i = 0; i < trianglesGrid - 1; i += 2)
	{
		terrainIndicies[i][0] = columnIndiciesOffset + rowIndiciesOffset;
		terrainIndicies[i][2] = RENDER_DISTANCE + columnIndiciesOffset + rowIndiciesOffset;
		terrainIndicies[i][1] = 1 + columnIndiciesOffset + rowIndiciesOffset;

		terrainIndicies[i + 1][0] = 1 + columnIndiciesOffset + rowIndiciesOffset;
		terrainIndicies[i + 1][2] = RENDER_DISTANCE + columnIndiciesOffset + rowIndiciesOffset;
		terrainIndicies[i + 1][1] = 1 + RENDER_DISTANCE + columnIndiciesOffset + rowIndiciesOffset;

		columnIndiciesOffset = columnIndiciesOffset + 1;

		rowIndex++;

		if (rowIndex == squaresRow)
		{
			rowIndex = 0;
			columnIndiciesOffset = 0;
			rowIndiciesOffset = rowIndiciesOffset + RENDER_DISTANCE;
		}



	}


	
	modelTerrain = glm::rotate(modelTerrain, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	modelTerrain = glm::translate(modelTerrain, glm::vec3(0.0f, 2.0f, -3.0f));
	modelTerrain = glm::scale(modelTerrain, glm::vec3(1.0f));
	std::cout << "Made it here before AFTER" << std::endl;

	unsigned int NewVBO;
		
		unsigned int newVAO;
		unsigned int NEWEBO;
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, 0);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, 0);
		glGenVertexArrays(1, &newVAO);
		//Binding the Vertex Array (VAO) to OpenGL - allows VBO to use it.
		glBindVertexArray(newVAO);

		//glEnableVertexAttribArray(0);
		//glEnableVertexAttribArray(1);
		//glEnableVertexAttribArray(2);
		//assigning a unique ID to that VBO
		
		//putthis somewhere else
		glGenBuffers(1, &NEWEBO);

		glBindBuffer(GL_ARRAY_BUFFER, NEWEBO);

		glGenBuffers(1, &NewVBO);
		glBindBuffer(GL_ARRAY_BUFFER, NewVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(terrainVerticies), terrainVerticies, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NEWEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(terrainIndicies), terrainIndicies, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	int modelMaxVal = 1.0f;
	float counter = 0.0f;
	int minVal = 0.0f;
	

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

		
		model = glm::translate(model, glm::vec3(0.0f, 10.0f, -3.0f));
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
		//model2 = glm::rotate(model2, (float)glfwGetTime() * 1.0f, glm::vec3(0.5, 1.0f, 0.0f));
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

		
		//some code for da model
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D,0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, 0);
		model_Deer = glm::rotate(model_Deer, glm::radians((float)glfwGetTime() * 0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 modelMVP = projection * viewcamera * model_Deer;
		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(modelMVP));
		Deer.Draw(Shaders);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, 0);
		//we need to add some animation code - 
		//we want to make the tiger move
		
		model_Tiger = glm::rotate(model_Tiger, glm::radians((float)glfwGetTime() * 0.5f), glm::vec3(0.0f, 1.0f, 1.0f));
	
		
		//model_Tiger = glm::translate(model_Tiger,glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 modelTigerMVP = projection * viewcamera * model_Tiger;

		

		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 1);
		glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(modelTigerMVP));
		Tiger.Draw(Shaders);


		lastFrame = current;
		

		//ALL TERRAIN - PROCEDURAL GENERATION STUFF IS BEING BUILT HERE
		

		
		
		MVPTerrain = projection * viewcamera * modelTerrain;
		glUniformMatrix4fv(getMVP, 1, GL_FALSE, value_ptr(MVPTerrain));
		glUniform1i(glGetUniformLocation(program, "istextureTrue"), 0);
		glBindVertexArray(newVAO);
		glDrawElements(GL_TRIANGLES, MAP_SIZE * 32, GL_UNSIGNED_INT, 0);

		
		
		glfwSwapBuffers(OpenGLWindow->GetWindow());
		
		
		glfwPollEvents();




	}

	glfwTerminate();
}