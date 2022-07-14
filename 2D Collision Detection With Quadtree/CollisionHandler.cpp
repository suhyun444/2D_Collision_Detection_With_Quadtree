#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{

}
CollisionHandler::~CollisionHandler()
{

}
void CollisionHandler::Add(Box* box)
{
	boxes.push_back(box);
}
void CollisionHandler::BoardPhase()
{
	for (int i = 0; i < boxes.size() - 1; i++)
	{
		for (int j = i + 1; j < boxes.size(); j++)
		{
		}
	}
}
bool CollisionHandler::Collide(Box* a, Box* b)
{
	if (a->position.x + a->scale.x < b->position.x - b->scale.x 
		|| a->position.x - a->scale.x> b->position.x + b->scale.x) return false;
	if (a->position.y + a->scale.y < b->position.y - b->scale.y 
		|| a->position.y - a->scale.y> b->position.y + b->scale.y) return false;
	a->isCollide = true;
	b->isCollide = true;
	return true;
}