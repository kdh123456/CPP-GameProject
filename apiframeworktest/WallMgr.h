#pragma once
//#include"Vec2.h"
#include<queue>
class WallMgr
{
private:
	queue<Vec2> wallsPos;
	LONG maxX;
public:
	WallMgr();
	~WallMgr();
private:
	void WallCreate();
};

//struct Wallinfo()
//{
//
//}