#include "pch.h"
#include "Collider.h"
#include "Plane.h"
#include "Core.h"

void Plane::Update()
{
}

/*void Plane::Render(HDC _dc)
{
}*/

Plane::Plane()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2((float)Core::GetInst()->GetResolution().x * 2.0f, 20.0f));
	SetScale(Vec2((float)Core::GetInst()->GetResolution().x * 2.f, 20.0f));
	SetPos(Vec2
	(
		(float)Core::GetInst()->GetResolution().x,
		(float)Core::GetInst()->GetResolution().y)
	);
	SetName(L"Plane");
}

Plane::~Plane()
{
}
