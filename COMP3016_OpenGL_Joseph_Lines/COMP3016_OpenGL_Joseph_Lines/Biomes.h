#pragma once
#include "FastNoiseLite.h"
#include <learnopengl/shader_m.h>
#include <learnopengl/model.h>
#define RENDER_DISTANCE 128
#define MAP_SIZE RENDER_DISTANCE * RENDER_DISTANCE
/**
class Biomes
{
private:
	const int squaresRow = RENDER_DISTANCE - 1;
	const int trianglesPerSquare = 2;
	const int trianglesGrid = squaresRow * squaresRow * trianglesPerSquare;
	GLfloat terrainVerticies[MAP_SIZE][6];
	GLuint terrainIndicies;
	float drawingStartPosition = 1.0f;
	float columnVerticiesOffset = drawingStartPosition;
	float rowVerticiesOffset = drawingStartPosition;
	int rowIndex = 0;
	FastNoiseLite BiomeNoise;
	void InitializeBiomeNoise()
	{
		
		BiomeNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
		BiomeNoise.SetFrequency(0.05f);
		int biomeSeed = rand() % 100;
		BiomeNoise.SetSeed(biomeSeed);
	}
	void HeightAndBiomeColours()
	{
		int i = 0;
		//height variation and mapping of colours
		for (int y = 0; y < RENDER_DISTANCE; y++)
		{
			for (int x = 0; x < RENDER_DISTANCE; x++)
			{
				terrainVerticies[i][1] = BiomeNoise.GetNoise((float)x, (float)y);
				i++;

				float biomeVal = BiomeNoise.GetNoise((float)x, (float)y);

				if (biomeVal <= 0.4f)
				{
					terrainVerticies[i][3] = 0.0f;
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
	}

	void SettingTerrainVerticies()
	{
		
		
		//Setting Terrain Verticies
		for (int i = 0; i < MAP_SIZE; i++)
		{
			terrainVerticies[i][0] = columnVerticiesOffset;
			terrainVerticies[i][2] = rowVerticiesOffset;

			//terrainVerticies[i][3] = 0.0f;
			//terrainVerticies[i][4] = 0.50f;
			//terrainVerticies[i][5] = 0.10f;

			columnVerticiesOffset = columnVerticiesOffset + -0.0625f;

			rowIndex++;

			if (rowIndex == RENDER_DISTANCE)
			{
				rowIndex = 0;

				columnVerticiesOffset = drawingStartPosition;
				rowVerticiesOffset = rowVerticiesOffset + -0.0625f;
			}
		}

		terrainIndicies = [trianglesGrid][3];

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
	}

	


public:
	void Innitialize()
	{
		InitializeBiomeNoise();

	}


};

*/