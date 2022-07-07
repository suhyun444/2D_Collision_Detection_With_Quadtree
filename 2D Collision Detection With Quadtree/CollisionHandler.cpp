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
			if (boxes[i]->position.x + boxes[i]->scale.x < boxes[j]->position.x - boxes[j]->scale.x || boxes[i]->position.x - boxes[i]->scale.x> boxes[j]->position.x + boxes[j]->scale.x) continue;
			if (boxes[i]->position.y + boxes[i]->scale.y < boxes[j]->position.y - boxes[j]->scale.y || boxes[i]->position.y - boxes[i]->scale.y> boxes[j]->position.y + boxes[j]->scale.y) continue;
			boxes[i]->isCollide = true;
			boxes[j]->isCollide = true;
		}
	}
}