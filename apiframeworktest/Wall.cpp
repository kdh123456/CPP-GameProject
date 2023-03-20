#include "pch.h"
#include "Wall.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Image.h"
#include "KeyMgr.h"
#include "Core.h"
#include "Plane.h"
#include "GameManager.h"
#include "Vec2.h";
#include "CollisionMgr.h"

void Wall::WallDamage()
{
	hp -= 1;
	if (hp == 0)
	{
		SetDead();
		SetPos(Vec2((float)Core::GetInst()->GetResolution().x * 3, 0.0f));
		DeleteObject(this);
	}
}

Wall::Wall(float damage, float speed, Vec2 statPosition)
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
	//���� �μ����� wall�� ���� ���ִ� ������ ������� �Ѵ�.
}

void Wall::Update()
{
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
	//����Ÿ ���� ���� transparent: ������
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

	if (pOtherObj->GetName() == L"Parry")
	{
		isJump = true;
	}
	else if (pOtherObj->GetName() == L"Plane")
	{
		GameManager::GetInst()->Damage(_damage);
		DeleteObject(this);
	}
	else if (pOtherObj->GetName() == L"Attack")
	{
		WallDamage();
	}
	else if (pOtherObj->GetName() == L"Wall")
	{
		isJump = true;
	}
}
