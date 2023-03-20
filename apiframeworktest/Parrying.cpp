#include "pch.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Object.h"
#include "TimeMgr.h"
#include "Parrying.h"
#include "SceneMgr.h"
#include "Scene.h"

Parrying::Parrying(Vec2 pos, float _dieTime)
{
	SetPos(pos);
	m_maxTimer = _dieTime;
	SetName(L"Parry");
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 30.f));
}

void Parrying::EnterCollision(Collider* _pOther)
{
}

void Parrying::Update()
{
	m_dieTimer += fDT;
	if (m_dieTimer >= m_maxTimer)
		SceneMgr::GetInst()->GetCurScene()->DeleteGroup(GROUP_TYPE::BULLET_PLAYER);
}
