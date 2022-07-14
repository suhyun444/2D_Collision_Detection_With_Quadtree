#include "math.h"

float MathUtil::PI = 3.141592f;
float MathUtil::Abs(float n)
{
    if (n < 0)return -n;
    return n;
}
Vector2::Vector2()
{
    x = 0;
    y = 0;
}
Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}
Vector2 Vector2::operator+(Vector2& v)
{
    return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator-(Vector2& v)
{
    return Vector2(x - v.x, y - v.y);
}
float Vector2::Dot(Vector2& v)
{
    return (x * v.x + y * v.y);
}

Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}
Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3 Vector3::operator+(Vector3& v)
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 Vector3::operator-(Vector3& v)
{
    return Vector3(x - v.x, y - v.y, z + v.z);
}
float Vector3::Dot(Vector3& v)
{
    return x * v.x + y * v.y + z * v.z;
}
Vector3 Vector3::Cross(Vector3& v)
{
    return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
Vector3 Vector3::operator*(float& o)
{
    return Vector3(x * o, y * o, z * o);
}
Vector3 Vector3::operator/(float& o)
{
    return Vector3(x / o, y / o, z / o);
}

