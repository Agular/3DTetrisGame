#include <glm.hpp>

class Cube {
private:
	const int N_VERTICES = 36;
	glm::vec3* vertices;
    GLuint VAO, VBO, texture;
	GLint sizeVertices;
	glm::vec3 normals[36] = {
	    //Front
		glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
		//Back
		glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f),
		//Top
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		//Bottom
		glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
		glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f),
		//Right
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
		//Left
		glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)
	};

	GLint sizeNormals = sizeof(normals);
	glm::vec2 textures[36] = {
		//Front
	    glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f),
		//Back
		glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f),
		//Top
		glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f),
		//Bottom
		glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f),
		//Right
		glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f),
		//Left
		glm::vec2(0.0f,0.0f), glm::vec2(1.0f,0.0f), glm::vec2(0.0f,1.0f),
		glm::vec2(1.0f,0.0f), glm::vec2(1.0f,1.0f), glm::vec2(0.0f,1.0f)
	};
	GLint sizeTextures = sizeof(textures);
	glm::vec3* Cube::createVertices(float x, float y, float z, float length);

public:
	void setup();
	void draw();
};
