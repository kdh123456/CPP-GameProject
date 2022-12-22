#include "pch.h"
#include "Wall.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Image.h"

Wall::Wall(float speed, float damage)
{
	_speed = speed;
	_damage = damage;

	_image = ResMgr::GetInst()->ImgLoad(L"Wall", L"Image\\Wall.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(500.f, 330.f));
}

Wall::~Wall()
{

}

void Wall::Update()
{
	Vec2 vPos = GetPos();
	vPos.y += _speed * fDT;

	SetPos(vPos);
}

void Wall::Render(HDC _dc)
{
//	Component_Render(_dc);
	int Width = (int)_image->GetWidth();
	int Height = (int)_image->GetHeight();

	Vec2 vPos = GetPos();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
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
	//if(pOtherObj->GetName() == L"Player")

}
