#include "pch.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Slash.h"
#include "TimeMgr.h"
#include "Object.h"
#include "SceneMgr.h"
#include "Scene.h"


Slash::Slash(Vec2 pos, float _dieTime)
{
	SetPos(pos);
	m_maxTimer = _dieTime;
	SetName(L"Attack");
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 30.f));

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"Slash", L"Image\\swordSla.bmp");
	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"SlashIdle", // 애니 이름
		pImg,  // 타겟 이미지
		Vec2(0.f, 0.f), // 시작 위치
		Vec2(90.f, 75.f), // 자르기 사이즈
		Vec2(90.f, 0.f), // 프레임당 움직일 사이즈?
		4,  // 프레임 크기
		0.05f); // 프레임 당 속도

	//GetAnimator()->SetDefaultAnimation(L"SlashIdle");
	GetAnimator()->Play(L"SlashIdle", false);
}

void Slash::EnterCollision(Collider* _pOther)
{
}

void Slash::Update()
{
	GetAnimator()->Update();
	m_dieTimer += fDT;
	if (m_dieTimer >= m_maxTimer)
		SceneMgr::GetInst()->GetCurScene()->DeleteGroup(GROUP_TYPE::BULLET_PLAYER);
}
