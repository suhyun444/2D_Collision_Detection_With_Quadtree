#pragma once
#include <vector>
#include "Box.h";
#include "CollisionHandler.h"
struct Rect {
	float x, y, width, height;
	Rect(float x, float y, float width, float height)
		: x{ x }, y{ y }, width{ width }, height{ height }{};
	Rect()
		:x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 }{};
};
class QuadTree
{
private:
	const int MAX_OBJECTS = 5;
	const int MAX_LEVELS = 5;
	
	int level;
	std::vector<Box*> objects;
	std::vector<std::pair<Box*,std::vector<int>>> overLapBox;
	Rect rect;
	QuadTree* nodes[4];

public:
	QuadTree();
	QuadTree(int level,Rect rect);
	~QuadTree();
	void Clear();
	void Split();
	int GetQuadrant(Box* box);
	std::pair<Box*, std::vector<int>> GetOverLapQuadrant(Box* box);
	void Insert(Box* box);
	void Display();
	void BoardPhase();
};

