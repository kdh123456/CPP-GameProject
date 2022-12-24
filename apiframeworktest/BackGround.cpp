#include "pch.h"
#include "BackGround.h"
#include "Object.h"
#include "Image.h"
#include "ResMgr.h"

BackGround::BackGround()
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"Main", L"Image\\£í£á£é£î.bmp");
}

void BackGround::Update()
{
}
