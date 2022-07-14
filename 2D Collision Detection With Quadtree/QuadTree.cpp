#include "QuadTree.h"

QuadTree::QuadTree()
{

}
QuadTree::QuadTree(int level, Rect rect)
{
	this->level = level;
	this->rect = rect;
	for (int i = 0; i < 4; i++)nodes[i] = NULL;
}
QuadTree::~QuadTree()
{

}
void QuadTree::Clear()
{
	objects.clear();
	for (int i = 0; i < 4; i++)
	{
		if (nodes[i] != NULL)
		{
			nodes[i]->Clear();
			nodes[i] = NULL;
		}
	}
}

/*
	0 | 1
   --------
	2 | 3
*/
void QuadTree::Split()
{
	float halfWidth = rect.width / 2;
	float halfHeight = rect.height / 2;

	nodes[0] = new QuadTree(level + 1,Rect(rect.x,			   rect.y,				halfWidth,halfHeight));
	nodes[0] = new QuadTree(level + 1,Rect(rect.x + halfWidth, rect.y,				halfWidth,halfHeight));
	nodes[0] = new QuadTree(level + 1,Rect(rect.x,			   rect.y + halfHeight, halfWidth,halfHeight));
	nodes[0] = new QuadTree(level + 1,Rect(rect.x + halfWidth, rect.y + halfHeight, halfWidth,halfHeight));
}
//두가지 사분면에 걸쳐있는 사각형은 따로 처리
//리프 노드에 넣지않고 바로 충돌처리를 해준다
//여러개가 존재할경우 서로 한번씩만 검사해준다
int QuadTree::GetQuadrant(Box box)
{
	int index = -1;
	Vector2 halfPosition = Vector2(rect.x + rect.width / 2, rect.y + rect.height / 2);
	Vector3 minPosition = box.position - box.scale;
	Vector3 maxPosition = box.position + box.scale;
	if (maxPosition.x < halfPosition.x && minPosition.y > halfPosition.y)
		index = 0;
	else if (minPosition.x > halfPosition.x && minPosition.y > halfPosition.y)
		index = 1;
	else if (maxPosition.x < halfPosition.x && maxPosition.y < halfPosition.y)
		index = 2;
	else if (minPosition.x > halfPosition.x && maxPosition.y < halfPosition.y)
		index = 3;
	return index;
}
void QuadTree::Insert(Box box)
{
	if (nodes[0] != NULL)
	{
		int index = GetQuadrant(box);
		if (index != -1)
			nodes[index]->Insert(box);
	
		return;
	}
	objects.push_back(box);
	
	if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS)
	{
		if (nodes[0] == NULL)
			Split();
		int t = objects.size();
		while (t--)
		{
			//-1이면 리프노드에 넣지말고 본인이 가지고 있도록
			int index = GetQuadrant(objects.back());
			if (index != -1)
				nodes[index]->Insert(objects.back());
			else
				

		}
	}
}