#include "pch.h"
#include "BackGround.h"
#include "Object.h"
#include "Image.h"
#include "ResMgr.h"

BackGround::BackGround()
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"Main", L"Image\\�����.bmp");
}

void BackGround::Update()
{
}
