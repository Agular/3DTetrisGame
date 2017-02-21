#include <glm.hpp>

class Cube {
private:
	const int N_VERTICES = 36;

	GLuint VAO, VBO;
	glm::vec3* vertices;
	GLint sizeVertices;

	GLint Cube::getSizeVertices();
	glm::vec3* Cube::createVertices(float x, float y, float z, float length);

public:
	GLint setup();
	void draw();

};
