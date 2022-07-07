#pragma once
#include <math.h>

class MathUtil
{
public:
	static float PI;
	static float Abs(float n);
};
class Vector3
{
public:
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z);
	Vector3 operator+(Vector3& v);
	Vector3 operator-(Vector3& v);
	Vector3 operator*(float& o);
	float Dot(Vector3& v);
	Vector3 Cross(Vector3& v);
};

class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float x, float y);
	Vector2 operator+(Vector2& v);
	Vector2 operator-(Vector2& v);
	float Dot(Vector2& v);
};

