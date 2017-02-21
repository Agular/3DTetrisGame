#include <glew.h>
#include <freeglut.h>
#include <iostream>
#include "Cube.h"
using namespace std;

// Create the vertices
glm::vec3* Cube::createVertices(float x, float y, float z, float length) {

	glm::vec3 temp[36] = {
		//Front
		glm::vec3(x, y, z), glm::vec3(x + length, y, z), glm::vec3(x, y + length, z),
		glm::vec3(x + length, y, z), glm::vec3(x + length, y + length, z),  glm::vec3(x, y + length, z),
		
		//Back
		glm::vec3(x + length, y, z - length), glm::vec3(x , y, z - length), glm::vec3(x, y + length, z - length),
		glm::vec3(x + length, y, z - length), glm::vec3(x , y + length, z - length), glm::vec3(x + length, y + length, z - length),
		
		//Top 
		glm::vec3(x + length, y + length, z), glm::vec3(x, y + length, z - length), glm::vec3(x, y + length, z),
		glm::vec3(x + length, y + length, z), glm::vec3(x + length, y + length, z - length), glm::vec3(x, y + length, z - length),

		//Bottom
		glm::vec3(x, y, z - length), glm::vec3(x + length, y, z - length), glm::vec3(x + length, y, z),
		glm::vec3(x, y, z - length), glm::vec3(x + length, y, z), glm::vec3(x, y, z),

		//Right side
		glm::vec3(x + length, y, z - length), glm::vec3(x + length, y + length, z), glm::vec3(x + length, y, z),
		glm::vec3(x + length, y, z - length), glm::vec3(x + length, y + length, z - length), glm::vec3(x + length, y + length, z),

		//Left side
		glm::vec3(x, y, z), glm::vec3(x, y + length, z - length), glm::vec3(x, y, z - length),
		glm::vec3(x, y, z), glm::vec3(x, y + length, z), glm::vec3(x, y + length, z - length),
	};
	sizeVertices = sizeof(temp);
	glm::vec3 *ptr = (glm::vec3*) malloc(36* sizeof(glm::vec3));
	memcpy(ptr, temp, 36 * sizeof(glm::vec3));
	return ptr;
}

GLint Cube::getSizeVertices() {
	return sizeVertices;
}

GLint Cube::setup() {
	vertices = createVertices(0.0f, 0.0f, 0.0f, 0.5f);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, getSizeVertices(), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, getSizeVertices(), vertices);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	return VAO;
}
void Cube::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, N_VERTICES);
}
