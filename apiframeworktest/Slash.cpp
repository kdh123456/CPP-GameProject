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
	// collider ����
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 30.f));

	// image ���ε�
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"Slash", L"Image\\swordSla.bmp");
	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(
		L"SlashIdle", // �ִ� �̸�
		pImg,  // Ÿ�� �̹���
		Vec2(0.f, 0.f), // ���� ��ġ
		Vec2(90.f, 75.f), // �ڸ��� ������
		Vec2(90.f, 0.f), // �����Ӵ� ������ ������?
		4,  // ������ ũ��
		0.05f); // ������ �� �ӵ�

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
