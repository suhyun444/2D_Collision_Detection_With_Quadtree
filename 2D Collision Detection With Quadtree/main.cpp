#include "GL/glut.h"
#include <iostream>
#include "Box.h"
#include "CollisionHandler.h"
#include "QuadTree.h"
#define BOXCOUNT 100
Box box[BOXCOUNT];
CollisionHandler collisionHandler;
QuadTree quadTree = QuadTree(0, Rect(-99, -99, 198, 198));

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);
	glLoadIdentity();
	glScaled(0.01f, 0.01f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i < BOXCOUNT; i++)
		box[i].Update();

	//충돌 검출
	//collisionHandler.BoardPhase();
	for (int i = 0; i < BOXCOUNT; i++)
		quadTree.Insert(&box[i]);

	glColor3f(0.0f, 1.0f, 0.0f);
	quadTree.Display();
	quadTree.BoardPhase();
	quadTree.Clear();

	for (int i = 0; i < BOXCOUNT; i++)
	{
		if(box[i].isCollide) glColor3f(1.0f, 0.0f, 0.0f);
		else glColor3f(0.0f, 0.0f, 1.0f);
		box[i].Display();
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
	
	//for (int i = 0; i < BOXCOUNT; i++)
		//collisionHandler.Add(&box[i]);

	for (int i = 0; i < BOXCOUNT; i++)
	{
		box[i].position = Vector3(((i / 10) *10) - 50, ((i % 10) * 10) - 50, 0);
	}
	glutMainLoop();
	return 0;
}
