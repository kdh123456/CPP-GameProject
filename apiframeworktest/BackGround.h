#pragma once
#include "Object.h"
class BackGround : public Object
{
public:
	BackGround();
private:
	CLONE(BackGround);
public:
	void Update()       override;
};

