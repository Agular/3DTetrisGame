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
	glm::mat4 Projection = glm::perspective(fov, (float)width/ (float)height, 0.1f, 100.f);

	cameraFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront.y = sin(glm::radians(pitch));
	cameraFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(cameraFront);

	View = glm::lookAt(cameraPos,cameraPos + cameraFront, cameraUp);
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "view"), 1, GL_FALSE, glm::value_ptr(View));
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "projection"), 1, GL_FALSE, glm::value_ptr(Projection));
}

void Camera::getWidthHeight(int width, int height) {
	this->width = width;
	this->height = height;
}
void Camera::getMouseWheel(float dz) {
		fov += dz * zoom_delta;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= DEFAULT_FOV)
		fov = DEFAULT_FOV;
}

void Camera::getMouse(float dx, float dy) {
	yaw += dx * SENSITIVITY;
	pitch += dy * SENSITIVITY;

	if (pitch > MAX_PITCH)
		pitch = MAX_PITCH;
	if (pitch < -MAX_PITCH)
		pitch = -MAX_PITCH;

	cameraFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront.y = sin(glm::radians(pitch));
	cameraFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(cameraFront);

	View = glm::lookAt(cameraPos, cameraFront, cameraUp);
	glUniformMatrix4fv(glGetUniformLocation(this->shader, "view"), 1, GL_FALSE, glm::value_ptr(View));
}

void Camera::update(float deltaTime) {
	if (keys['a']) {
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * delta * deltaTime;
	}
	if (keys['d']) {
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * delta * deltaTime;
	}
	if (keys['w']) {
		cameraPos += cameraFront * delta * deltaTime;
	}
	if (keys['s']) {
		cameraPos -= cameraFront * delta * deltaTime;

	}
}
void Camera::setKeyState(unsigned char key, bool value) {
	keys[key] = value;
}
