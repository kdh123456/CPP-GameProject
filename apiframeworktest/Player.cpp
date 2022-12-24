#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Slash.h"
#include "Parrying.h"

Player::Player()
{
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\cppchar2.bmp");
	// animator 생성 및 animation 사용
	CreateAnimator();
	Animator* ani = GetAnimator();
	ani->CreateAnimation(
		L"PlayerIdle", // 애니 이름
		pImg,  // 타겟 이미지
		Vec2(0.f, 0.f), // 시작 위치
		Vec2(90.f, 75.f), // 자르기 사이즈
		Vec2(90.f, 0.f), // 프레임당 움직일 사이즈?
		2,  // 프레임 크기
		0.2f); // 프레임 당 속도
	ani->CreateAnimation(
		L"PlayerGroundAttack", pImg, Vec2(180.f, 0.f), Vec2(90.f, 75.f), Vec2(90.f, 0.f),
		2,  
		0.1f);
	ani->CreateAnimation(
		L"PlayerGroundParry", pImg, Vec2(360.f, 0.f), Vec2(90.f, 75.f), Vec2(90.f, 0.f),
		1,
		0.2f);
	ani->CreateAnimation(
		L"PlayerJump", pImg, Vec2(450.f, 0.f), Vec2(90.f, 75.f), Vec2(90.f, 0.f),
		1,
		0.2f);
	ani->CreateAnimation(
		L"PlayerJumpAttack", pImg, Vec2(540.f, 0.f), Vec2(90.f, 75.f), Vec2(90.f, 0.f),
		2,
		0.1f);
	ani->CreateAnimation(
		L"PlayerJumpParry", pImg, Vec2(720.f, 0.f), Vec2(90.f, 75.f), Vec2(90.f, 0.f),
		1,
		0.2f);

	ani->SetDefaultAnimation(L"PlayerIdle");
	ani->Play(L"PlayerIdle", true);
	// animation offset 위로 올리기. 
	//Animation* pAnim = GetAnimator()->FindAnimation(L"PlayerIdle");
	//for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
	//	pAnim->GetFrame(i).vOffset = Vec2(0.f, -0.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	m_pos = GetPos();
	Input();
	GetAnimator()->Update();
	JumpUpdate();
	if ((m_isGrounded == false && m_jumpLock == false) || m_headBroken)
		m_pos.y += m_gravityScale * fDT;
	SetPos(m_pos);
}

void Player::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Plane")
	{
		m_headBroken = false;
		m_isGrounded = true;
	}
	else if (pOtherObj->GetName() == L"Wall")
	{
		m_headBroken = true;
		m_isGrounded = false;
	}
}

void Player::PlayerJump()
{
	if (m_isGrounded == false || m_jumpLock)
		return;

	m_isGrounded = false;
	m_jumpLock = true;
	GetAnimator()->Play(L"PlayerJump", false);
}

void Player::JumpUpdate()
{
	if (m_jumpLock == false)
		return;
	if (m_headBroken || (m_jumpTimer <= m_maxTimer) == false)
	{
		m_jumpLock = false;
		m_jumpTimer = 0.0f;
		return;
	}
	m_pos.y -= m_jumpPower * fDT;
	m_jumpTimer += fDT;
}

void Player::Move(MoveDir dir)
{
	if (m_isGrounded == false)
		return;

	if (dir == MoveDir::Left)
		m_pos.x -= 300.f * fDT;
	else if (dir == MoveDir::Right)
		m_pos.x += 300.f * fDT;
}

void Player::TryParrying()
{
	if (m_isGrounded)
		GetAnimator()->Play(L"PlayerGroundParry", false);
	else
		GetAnimator()->Play(L"PlayerJumpParry", false);
	Vec2 summonPos = GetPos();
	summonPos.y -= 20.0f;
	Object* obj = new Parrying(summonPos, 0.2f);
	SceneMgr::GetInst()->GetCurScene()->AddObject(obj, GROUP_TYPE::BULLET_PLAYER);
}

void Player::TryAttack()
{
	if(m_isGrounded)
		GetAnimator()->Play(L"PlayerGroundAttack", false);
	else
		GetAnimator()->Play(L"PlayerJumpAttack", false);
	Vec2 summonPos = GetPos();
	summonPos.y -= 20.0f;
	Object* obj = new Slash(summonPos, 0.2f);
	SceneMgr::GetInst()->GetCurScene()->AddObject(obj, GROUP_TYPE::BULLET_PLAYER);
}

void Player::TrySkill()
{
}

void Player::Input()
{
	if (KEY_HOLD(KEY::LEFT))
		Move(MoveDir::Left);
	if (KEY_HOLD(KEY::RIGHT))
		Move(MoveDir::Right);
	if (KEY_TAP(KEY::DOWN))
		TryParrying();
	if (KEY_TAP(KEY::UP))
		PlayerJump();
	if (KEY_TAP(KEY::Z))
		TryAttack();
}

void Player::Render(HDC _dc)
{
	Component_Render(_dc);
	/*int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();*/
	//BitBlt(_dc
	//	,(int)(vPos.x - (float)(Width / 2))
	//	,(int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//    , m_pImage->GetDC()
	//    , 0,0, SRCCOPY);

	//마젠타 색상 뺄때 transparent: 투명한
	//TransparentBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//	,Width, Height
	//    , m_pImage->GetDC()
	//    ,0,0, Width, Height
	//    , RGB(255,0,255));

}