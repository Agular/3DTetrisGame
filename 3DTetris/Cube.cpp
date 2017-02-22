#include <glew.h>
#include <freeglut.h>
#include <iostream>
#include "Cube.h"
#include <FreeImage.h>
using namespace std;

// Create the vertices
glm::vec3* Cube::createVertices(float x, float y, float z, float length) {

	glm::vec3 temp[36] = {
		//Front
		glm::vec3(x, y, z), glm::vec3(x + length, y, z), glm::vec3(x, y + length , z),
		glm::vec3(x + length, y, z), glm::vec3(x + length, y + length, z),  glm::vec3(x, y + length, z),
		
		//Back
		glm::vec3(x + length, y, z - length), glm::vec3(x , y, z - length), glm::vec3(x + length, y + length, z - length),
		glm::vec3(x, y, z - length), glm::vec3(x , y + length, z - length), glm::vec3(x + length, y + length, z - length),
		
		//Top 
		glm::vec3(x, y + length, z), glm::vec3(x + length, y + length, z), glm::vec3(x, y + length, z - length),
		glm::vec3(x + length, y + length, z), glm::vec3(x + length, y + length, z - length), glm::vec3(x, y + length, z - length),

		//Bottom
		glm::vec3(x, y, z - length), glm::vec3(x + length, y, z - length), glm::vec3(x, y, z),
		glm::vec3(x + length, y, z - length), glm::vec3(x + length, y, z), glm::vec3(x, y, z),

		//Right side
		glm::vec3(x + length, y, z), glm::vec3(x + length, y, z - length), glm::vec3(x + length, y + length, z),
		glm::vec3(x + length, y, z - length), glm::vec3(x + length, y + length, z - length), glm::vec3(x + length, y + length, z),

		//Left side
		glm::vec3(x, y, z - length), glm::vec3(x, y, z), glm::vec3(x, y + length, z - length),
		glm::vec3(x, y, z), glm::vec3(x, y + length, z), glm::vec3(x, y + length, z - length)
	};
	sizeVertices = sizeof(temp);
	glm::vec3 *ptr = (glm::vec3*) malloc(36* sizeof(glm::vec3));
	memcpy(ptr, temp, 36 * sizeof(glm::vec3));
	return ptr;
}


void Cube::setup() {
	vertices = createVertices(0.0f, 0.0f, 0.0f, 0.5f);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeVertices + sizeTextures + sizeNormals, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeVertices, vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeVertices, sizeTextures, textures);
	glBufferSubData(GL_ARRAY_BUFFER, sizeVertices + sizeTextures, sizeNormals, normals);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)(N_VERTICES * sizeof(glm::vec3)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(N_VERTICES * sizeof(glm::vec3) + N_VERTICES * sizeof(glm::vec2)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	FreeImage_Initialise(TRUE);
	FIBITMAP *bitmapData;
	int bitmapWidth, bitmapHeight;
	BYTE *bimapBits;
	FREE_IMAGE_FORMAT bitmapFormat = FIF_UNKNOWN;

	bitmapFormat = FreeImage_GetFileType("yellow.png");
	bitmapData = FreeImage_Load(bitmapFormat, "yellow.png");
	bitmapWidth = FreeImage_GetWidth(bitmapData);
	bitmapHeight = FreeImage_GetHeight(bitmapData);
	bimapBits = FreeImage_GetBits(bitmapData);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexStorage2D(GL_TEXTURE_2D, 0, GL_RGBA8, bitmapWidth, bitmapHeight);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapWidth, bitmapHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, bimapBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_WRAP_BORDER, GL_REPEAT);
	FreeImage_Unload(bitmapData);

}
void Cube::draw() {
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawArrays(GL_TRIANGLES, 0, N_VERTICES);
}
