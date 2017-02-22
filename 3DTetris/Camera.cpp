#include <glew.h>
#include <freeglut.h>
#include <iostream>
#include "Camera.h"
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>
using namespace std;

void Camera::set(int leftX, int leftY, int rightX, int rightY, GLint shader) {
	this->shader = shader;
	glViewport(leftX, leftY, rightX, rightY);
	glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.f);
	View = glm::lookAt(cameraPos,
		cameraPos + cameraFront, cameraUp);
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "view"), 1, GL_FALSE, glm::value_ptr(View));
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "projection"), 1, GL_FALSE, glm::value_ptr(Projection));
}

void Camera::update() {
	View  = View = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "view"), 1, GL_FALSE, glm::value_ptr(View));
}
void Camera::changePosX(int direction)
{
	cameraPos.x += direction * delta;
	update();
}

void Camera::changePosY(int direction)
{
	cameraPos.y += direction * delta;
	update();
}

