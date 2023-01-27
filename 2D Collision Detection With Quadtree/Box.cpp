#include "Box.h"
#define PI 3.141592
Box::Box()
{
	speed = 10.0f;
	scale = Vector3(rand() % 10 + 5, rand()% 10 + 5, 1);
	float angle = rand() % 360;
	float radian = angle * PI / 180;
	velocity.x = cosf(radian);
	velocity.y = sinf(radian);
}
Box::~Box()
{

}
void Box::Update(float deltaTime)
{
	isCollide = false;
	Vector3 moveVelocity = velocity * speed * deltaTime;
	position = position + moveVelocity;

	if (position.x - scale.x < -1000) velocity.x = MathUtil::Abs(velocity.x);
	else if (position.x + scale.x > 1000)velocity.x = -MathUtil::Abs(velocity.x);
	if (position.y - scale.y < -1000)velocity.y = MathUtil::Abs(velocity.y);
	else if (position.y + scale.y > 1000)velocity.y = -MathUtil::Abs(velocity.y);
}
void Box::Display()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(position.x - scale.x, position.y - scale.y);
	glVertex2f(position.x - scale.x, position.y + scale.y);
	glVertex2f(position.x + scale.x, position.y + scale.y);
	glVertex2f(position.x + scale.x, position.y - scale.y);
	glEnd();
}