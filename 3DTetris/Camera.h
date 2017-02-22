#include <glm.hpp>

class Camera {
private:
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 View;
	GLint shader;
	float delta = 0.1;
	void update();
public: 
	void set(int leftX, int leftY, int rightX, int rightY, GLint shader);
	void changePosX(int direction);
	void changePosY(int direction);
};