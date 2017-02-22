#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <glew.h>
#include <freeglut.h>
#include <FreeImage.h>
using namespace std;
//#########custom headers###########//
#include "Cube.h"
#include "Camera.h"

GLuint loadShaders(const char* vertexFilePath, const char* fragmentFilePath, const char* geometryFilePath);
int height = 512, width = 512, Shader, texture;
float lastX = (float)width/2, lastY = (float)height /2;
Camera camera; 
Cube cube;
int lastTime = glutGet(GLUT_ELAPSED_TIME);
bool firstMouse = true;


void init(void)
{
	printf("\n%s", (char*)glGetString(GL_RENDERER));
	printf("\n%s", (char*)glGetString(GL_VERSION));
	printf("\n%s\n", (char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	Shader = loadShaders("mainVertex.vs", "mainFragment.fs", "");
	cube.setup();
	camera.getWidthHeight(width, height);
}

void display(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GLUT_MULTISAMPLE);

	//===================================
	// Camera setup
	//===================================
	glUseProgram(Shader);
	camera.set(0, 0, width, height, Shader);
	
	glm::mat4 model = glm::mat4(1.0f);
	glUniformMatrix4fv(glGetUniformLocation(Shader, "model"), 1, GL_FALSE, glm::value_ptr(model));

	cube.draw();
	glFlush();
	
}

void reshape(int w, int h) {
	width = w;
	height = h;
	camera.getWidthHeight(width, height);
}

void keyboardDown(unsigned char theKey, int mouseX, int mouseY) {
	if (theKey == 'a') {
		camera.setKeyState(theKey, true);
	}
	if (theKey == 'd') {
		camera.setKeyState(theKey, true);
	}
	if (theKey == 'w') {
		camera.setKeyState(theKey, true);
	}
	if (theKey == 's') {
		camera.setKeyState(theKey, true);
	}
	//The escape key
	if (theKey == 27) {
		exit(-1);
	}
}

void keyboardUp(unsigned char theKey, int mouseX, int mouseY) {
	if (theKey == 'a') {
		camera.setKeyState(theKey, false);
	}
	if (theKey == 'd') {
		camera.setKeyState(theKey, false);
	}
	if (theKey == 'w') {
		camera.setKeyState(theKey, false);
	}
	if (theKey == 's') {
		camera.setKeyState(theKey, false);
	}
}

void mouse(int mouseX, int mouseY) {
	if (firstMouse) // this bool variable is initially set to true
	{
		lastX = (float)mouseX;
		lastY = (float)mouseY;
		firstMouse = false;
	}
	GLfloat xoffset = (float)mouseX - lastX;
	GLfloat yoffset = lastY - (float)mouseY; // Reversed since y-coordinates range from bottom to top

	//If we leave the screen and come back, there will be a big jump, so we will null it.
	if (abs(xoffset) > 1 || abs(yoffset) > 1) {
		xoffset > 0 ? xoffset = 1 : xoffset = -1;
		yoffset > 0 ? yoffset = 1 : yoffset = -1;
		lastX = mouseX;
		lastY = mouseY;
	}
	lastX = mouseX;
	lastY = mouseY;
	camera.getMouse(xoffset, yoffset);
}
void mouseWheel(int button, int dir, int x, int y) {
	if (dir > 0) {
		camera.getMouseWheel(-1.0f);
	}
	else {
		camera.getMouseWheel(1.0f);
	}
}

//===================================
// Timer function
//===================================
void timer(int v) {
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = float(currentTime - lastTime) / 1000.f;
	lastTime = currentTime;
	camera.update(deltaTime);
	display();
	glutTimerFunc(1000.0f / 60.0f, timer, v);
}


//===================================
// Main loop
//===================================
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitContextVersion(4, 2);  // (4,5) (3,3);
	glutInitContextProfile(GLUT_CORE_PROFILE);  //GLUT_COMPATIBILITY_PROFILE
	glutCreateWindow(argv[0]);
	glewExperimental = GL_TRUE;
	if (glewInit()) printf("Error");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutMotionFunc(mouse);
	glutMouseWheelFunc(mouseWheel);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutTimerFunc(1000.0f/60.0f, timer, 0);
	glutMainLoop();
}