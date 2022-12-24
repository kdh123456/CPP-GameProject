#pragma once
#include "Object.h"

class Image;

class Wall :
    public Object
{
private:
    bool isDied = false;
    float hp = 5;
    float _speed;
    float _damage;
    Image* _image;
public:
    bool isParry;

private:
    void WallDamage();
public:
    Wall(float _speed, float _damage, Vec2 startPos);
    ~Wall();
public:
    Image* GetImage() { return _image; };
    void Update() override;
    void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    CLONE(Wall);
};

