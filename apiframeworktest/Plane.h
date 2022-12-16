#pragma once
#include "Object.h"

class Plane : public Object
{
private:
	

public:
	CLONE(Plane);
public:
	void Update()       override;
	//void Render(HDC _dc) override;
	Plane();
	~Plane();
};

