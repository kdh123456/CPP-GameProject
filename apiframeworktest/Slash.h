#pragma once
#include "Object.h"
class Slash : public Object
{
private:
	CLONE(Slash);
private:
	float m_dieTimer = 0.0f;
	float m_maxTimer;
public:
	Slash(Vec2 pos, float _dieTime);
public:
	void EnterCollision(Collider* _pOther) override;
	void Update()       override;
};

