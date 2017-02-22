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

//#########custom headers###########//
#include "Cube.h"
#include "Camera.h"
using namespace std;
GLuint loadShaders(const char* vertexFilePath, const char* fragmentFilePath, const char* geometryFilePath);
GLint height = 512, width = 512;
GLuint Shader;
# define PI 3.14159265358979323846  /* pi */
Cube cube;
Camera camera;
GLint texture;

void init(void)
{
	printf("\n%s", (char*)glGetString(GL_RENDERER));
	printf("\n%s", (char*)glGetString(GL_VERSION));
	printf("\n%s\n", (char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	Shader = loadShaders("mainVertex.vs", "mainFragment.fs", "");
	cube.setup();

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
}

void keyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey) {
	case 'a':
		camera.changePosX(-1);
		display();
		break;
	case 'd':
		camera.changePosX(1);
		display();
		break;
	case 'w':
		camera.changePosY(1);
		display();
		break;
	case 's':
		camera.changePosY(-1);
		display();
		break;
	}
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}