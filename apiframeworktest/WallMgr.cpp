#include "pch.h"
#include "WallMgr.h"
#include "Wall.h"
#include<queue>
//#include "Core.h"
#include "Image.h"
#include<stdlib.h>
#include<time.h>
#include"TimeMgr.h"

WallMgr::WallMgr()
{
}

WallMgr::WallMgr(int _maxDamage, int _minDamage, int _maxSpeed, int _minSpeed, int _maxtimer)
{
	maxDamage = _maxDamage;
	minDamage = _minDamage;
	maxSpeed = _maxSpeed;
	minSpeed = _minSpeed;

	maxTimer = _maxtimer;
	timer = 0;
}

WallMgr::~WallMgr()
{

}



Wall* WallMgr::WallsRandomStart()
{
	timer += fDT;
	if (maxTimer <= timer)
	{
		timer = 0;
		Wall* wall = WallCreate();
		return wall;
	}
	return nullptr;
}

Wall* WallMgr::WallCreate()
{
	srand(time(NULL));
	if (wallQueue.empty())
	{
		int randomDamage = rand() % maxDamage + minDamage;
		int randomSpeed = rand() % maxSpeed + minSpeed;
		Wall* wall = new Wall((float)randomDamage, (float)randomSpeed, pos[1]);
		wall->SetName(L"Wall");
		wall->SetScale(Vec2(0.0001f, 0.0001f));
		wallQueue.push(*wall);
		return new Wall((float)randomDamage, (float)randomSpeed, pos[1]);
	}

	int randomDamage = rand() % maxDamage + minDamage;
	int randomSpeed = rand() % maxSpeed + minSpeed;
	Wall walls = wallQueue.front();
	Vec2 vec = walls.GetPos();
	vec.y -= 500;
	Wall* wall = new Wall((float)randomDamage, (float)randomSpeed, vec);
	wall->SetName(L"Wall");
	wall->SetScale(Vec2(0.0001f, 0.0001f));
	wallQueue.push(*wall);
	return wall;
}
