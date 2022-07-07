#include "GL/glut.h"
#include <iostream>
#include "Box.h"
#include "CollisionHandler.h"

Box box[4];
CollisionHandler collisionHandler;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);
	glLoadIdentity();
	glScaled(0.01f, 0.01f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 4; i++)
		box[i].Update();

	//충돌 검출
	collisionHandler.BoardPhase();

	for (int i = 0; i < 4; i++)
	{
		if(box[i].isCollide) glColor3f(1.0f, 0.0f, 0.0f);
		else glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		box[i].Display();
		glEnd();
	}
	glFinish();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("2D Collision Detection");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	
	for (int i = 0; i < 4; i++)
	{
		box[i].position = Vector3(i * 3, 0, 0);
		collisionHandler.Add(&box[i]);
	}

	glutMainLoop();
	return 0;
}
