#include "include/GL/glut.h"
#include <iostream>
#include <string>
#include "Box.h"
#include "CollisionHandler.h"
#include "QuadTree.h"
#include "Timer.h"
#include "include/GL/freeglut_ext.h"
#pragma comment(lib, "freeglut.lib")

#define BOXCOUNT 5000

#include "Timer.h"

#define BOXCOUNT 2500

Box box[BOXCOUNT];
CollisionHandler collisionHandler;
QuadTree quadTree = QuadTree(0, Rect(-1000, -1000, 2000, 2000));
Timer timer;
Timer collisionCheckTimer;
QuadTree quadTree = QuadTree(0, Rect(-1000, -1000, 2000, 2000));
Timer timer;
Timer collisionCheckTimer;

void BruteForceCollisionHandlerInit()
{
	for (int i = 0; i < BOXCOUNT; i++) collisionHandler.Add(&box[i]);
}
void CollisionDetectionBruteForce()
{
	collisionHandler.BoardPhase();
}
void CollisionHandlerQuadTree()
{
	for (int i = 0; i < BOXCOUNT; i++)
		quadTree.Insert(&box[i]);

	glColor3f(0.0f, 1.0f, 0.0f);
	quadTree.Display();
	quadTree.BoardPhase();
	quadTree.Clear();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);
	glLoadIdentity();
	glScaled(0.001f, 0.001f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);

	timer.Frame();
	float deltaTime = timer.GetTime() / 1000;
	int frame = timer.GetFramePerSecond();
	glRasterPos2f(900.0f, 900.0f);
	std::string frameString = std::to_string(frame);
	const char* frameChar = frameString.c_str();
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)frameChar);
	for (int i = 0; i < BOXCOUNT; i++)
		box[i].Update(deltaTime);

	//CollisionDetectionBruteForce();
	CollisionHandlerQuadTree();

	for (int i = 0; i < BOXCOUNT; i++)
	{
		if(box[i].isCollide) glColor3f(1.0f, 0.0f, 0.0f);
		else glColor3f(0.0f, 0.0f, 1.0f);
		box[i].Display();
	}
	

	glFinish();
}
//실행 시켜 보실려면 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("2D Collision Detection");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	timer.Initialize();

	for (int i = 0; i < BOXCOUNT; i++)
		box[i].position = Vector3(((i / 50) *35) - 900, ((i % 50) * 35) - 900, 0);
		box[i].position = Vector3(((i / 10) *10) - 50, ((i % 10) * 10) - 50, 0);
	//BruteForceCollisionHandlerInit();

	}
	glutMainLoop();
	return 0;
}

