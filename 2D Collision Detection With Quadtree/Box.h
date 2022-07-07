#pragma once
#include "GL/freeglut.h"
#include "Math.h"

class Box
{
public:
	bool isCollide;
	float speed;
	Vector3 scale;
	Vector3 position;
	Vector3 velocity;
	Box();
	~Box();
	void Update();
	void Display();
};

