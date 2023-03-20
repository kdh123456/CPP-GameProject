#pragma once
//#include"Vec2.h"
#include<queue>
#include"Core.h"
#include "Wall.h"

class WallMgr
{
private:
	Vec2 pos[3]{ 
		Vec2(0, -100),
		Vec2(Core::GetInst()->GetResolution().x / 2, (LONG)-100),
		Vec2(Core::GetInst()->GetResolution().x ,(LONG)-100)};

	int maxDamage;
	int minDamage;

	int maxSpeed;
	int minSpeed;

	float timer;
	int maxTimer;

	queue<Wall> wallQueue;
public:
	WallMgr();
	WallMgr(int _maxDamage, int _minDamage, int _maxSpeed, int _minSpeed, int maxtimer);
	~WallMgr();
	CLONE(WallMgr);
public:
	Wall* WallsRandomStart();
	Wall* WallCreate();
};