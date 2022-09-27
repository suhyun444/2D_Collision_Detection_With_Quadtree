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

Box box[BOXCOUNT];
CollisionHandler collisionHandler;
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

	//충돌 검출
	collisionCheckTimer.UpdateTime();
	//원하시는 방식을 선택해서 주석처리하고, 해체해주세요
	CollisionDetectionBruteForce();
	//CollisionHandlerQuadTree();
	collisionCheckTimer.Frame();
	std::cout << collisionCheckTimer.GetTime() << "\n";

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
	collisionCheckTimer.Initialize();
	for (int i = 0; i < BOXCOUNT; i++)
	{
		//box[i].position = Vector3(((i / 50) *35) - 900, ((i % 50) * 35) - 900, 0);
		box[i].position = Vector3(rand() % 1800 - 900, rand() % 1800 - 900, 0);
		//이 부분 나누는 수하고 곱해주는수를 BOXCOUNT에 맞게 적절히 바꿔줘야합니다
		//BOXCOUNT가 어느수의 제곱이 되는 수면 편해요!! 2500은 50의 제곱이라 50으로 나눠줬습니다 이런식으로요
	}
	//완전탐색으로 실행시키고 싶으실때 주석해제해주세요
	//반대로 쿼드트리일 경우엔 주석처리 해주세요
	BruteForceCollisionHandlerInit();

	glutMainLoop();
	return 0;
}

