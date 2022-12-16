#include "pch.h"
#include "Collider.h"
#include "Plane.h"

void Plane::Update()
{
}

/*void Plane::Render(HDC _dc)
{
}*/

Plane::Plane()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));
	SetName(L"Plane");
}

Plane::~Plane()
{
}
