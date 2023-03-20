#include "pch.h"
#include "Scene_01.h"
#include "KeyMgr.h"
#include "SoundMgr.h"
#include "BackGround.h"
#include "Object.h"

Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	Object* pObj = new BackGround();
	AddObject(pObj, GROUP_TYPE::DEFAULT);
}

void Scene_01::Exit()
{
	DeleteAll();
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}
