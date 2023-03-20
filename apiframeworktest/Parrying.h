#pragma once
#include "Object.h"
class Parrying : public Object
{
private:
	CLONE(Parrying);
private:
	float m_dieTimer = 0.0f;
	float m_maxTimer;
public:
	Parrying(Vec2 pos, float _dieTime);
public:
	void EnterCollision(Collider* _pOther) override;
	void Update()       override;
};
