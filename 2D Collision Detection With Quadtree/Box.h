#pragma once
#include "GL/freeglut.h"
#include "Math.h"

class Box
{
public:
	Box();
	~Box();
	float speed;
	Vector3 scale;
	Vector3 position;
	Vector3 velocity;
	void Update();
	void Display();
};

