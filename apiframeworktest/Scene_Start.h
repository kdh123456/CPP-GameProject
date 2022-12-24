#pragma once
#include "Scene.h"
#include "WallMgr.h"
class Scene_Start :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
private:
    WallMgr wallmgr;
public:
    Scene_Start();
    virtual ~Scene_Start();
};

