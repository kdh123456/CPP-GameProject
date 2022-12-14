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
		wall->SetName(L"Wall");
		wall->SetScale(Vec2(0.1f, 0.1f));
		return wall;
	}
	return nullptr;
}

Wall* WallMgr::WallCreate()
{
	srand(time(NULL));
	int randomDamage = rand() % maxDamage + minDamage;
	int randomSpeed = rand() % maxSpeed + minSpeed;
	
	return new Wall((float)randomDamage, (float)randomSpeed,pos[1]);
}
