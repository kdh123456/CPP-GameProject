#pragma once
#include "EventMgr.h"

class GameManager
{
private:
	int hp = 5;
public:
	void Damage(int damage);
	void Reset();
	SINGLE(GameManager);
};

