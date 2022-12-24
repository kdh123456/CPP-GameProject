#include "pch.h"
#include "GameManager.h"
#include "SceneMgr.h"
#include "SoundMgr.h"

void GameManager::Damage(int damage)
{
	hp -= damage;
	if (hp == 0)
	{
		SceneMgr::GetInst()->ChangeScene(SCENE_TYPE::SCENE_01);
		SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
		Reset();
	}
}

void GameManager::Reset()
{
	hp = 5;
}
