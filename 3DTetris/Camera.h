#include <glm.hpp>

class Camera {
private:
	const GLfloat MAX_PITCH = 89.0f;
	const GLfloat DEFAULT_FOV = 45.0f;
	const GLfloat YAW = -90.0f;
	const GLfloat PITCH = 0.0f;
	const GLfloat SPEED = 3.0f;
	const GLfloat SENSITIVITY = 0.25f;
	const GLfloat ZOOM = 45.0f;

	GLfloat yaw = YAW;
	GLfloat pitch = PITCH;
	GLfloat fov = DEFAULT_FOV;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 View;
	GLint shader;
	float delta = 5.0;
	float zoom_delta = 0.1f;
	bool keys[256];
	int width, height;

	
public: 
	void set(int leftX, int leftY, int rightX, int rightY, GLint shader);
	void setKeyState(unsigned char key, bool value);
	void update(float deltaTime);
	void getMouse(float dx, float dy);
	void getMouseWheel(float dz);
	void getWidthHeight(int width, int height);
};