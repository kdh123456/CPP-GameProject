#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Plane.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Wall.h"
#include "WallMgr.h"

Scene_Start::Scene_Start()
{

}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	WallMgr* wallmg = new WallMgr(5, 1, 100, 100, 5);
	wallmgr = *wallmg;

	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object 추가
	Object* pObj = new Player;
	AddObject(pObj, GROUP_TYPE::PLAYER);

	Object* plane = new Plane;
	AddObject(plane, GROUP_TYPE::DEFAULT);

		// 몬스터 배치
	/*Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iMonster = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonster - 1);
	Monster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonster; i++)
	{
		pMonsterObj = new Monster;
		pMonsterObj->SetName(L"Monster");
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i * fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}*/
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::DEFAULT);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::Wall);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::Wall, GROUP_TYPE::BULLET_PLAYER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::Wall, GROUP_TYPE::DEFAULT);
}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{
	Scene::Update();
	Wall*wall = wallmgr.WallsRandomStart();

	if(wall != nullptr)
		AddObject(wall, GROUP_TYPE::Wall);
}
