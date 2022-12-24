#include "pch.h"
#include "Wall.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Image.h"
#include "KeyMgr.h"
#include "Core.h"

Wall::Wall(float speed, float damage, Vec2 statPosition)
{
	jumpTimer = 0;
	jumpHeight = Core::GetInst()->GetResolution().y - Core::GetInst()->GetResolution().y / 9;
	_speed = speed;
	_damage = damage;

	_image = ResMgr::GetInst()->ImgLoad(L"Wall", L"Image\\Wall.bmp");

	isParry = false;

	SetPos(statPosition);
	CreateCollider();
	GetCollider()->SetScale(Vec2(500.f, 330.f));
}

Wall::~Wall()
{
	//뭔가 부서지면 wall을 관리 해주는 얘한테 보내줘야 한다.
}

void Wall::Update()
{
	if (KEY_TAP(KEY::SPACE))
	{
		isJump = true;
	}

	Vec2 vPos = GetPos();
	if (!isJump)
	{
		int Direction = isParry == true ? -1 : 1;

		vPos.y += _speed * fDT * Direction;

	}
	else
	{
		Jump(vPos.y, jumpTimer, 2);
	}
	SetPos(vPos);
}

void Wall::Render(HDC _dc)
{
	//	Component_Render(_dc);
	int Width = (int)_image->GetWidth();
	int Height = (int)_image->GetHeight();

	Vec2 vPos = GetPos();
	//마젠타 색상 뺄때 transparent: 투명한
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, _image->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}

void Wall::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Player")
	{

	}
	else if (pOtherObj->GetName() == L"Parry")
	{

	}
	else if (pOtherObj->GetName() == L"Ground")
	{

	}
	else if (pOtherObj->GetName() == L"Attack")
	{

	}
}
