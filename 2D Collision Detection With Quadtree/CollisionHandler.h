#pragma once
#include "Box.h"
#include <vector>

class CollisionHandler
{
private:
	std::vector<Box*> boxes;
public:
	CollisionHandler();
	~CollisionHandler();
	void Add(Box* box);
	void BoardPhase();
	bool Collide(Box* a, Box* b);
};

