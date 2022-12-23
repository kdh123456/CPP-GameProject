#pragma once
#include "Object.h"

class Image;

class Wall :
    public Object
{
private:
    float _speed;
    float _damage;
    Image* _image;
public:
    bool isParry;
public:
    Wall(float _speed, float _damage);
    ~Wall();
public:
    void Update() override;
    void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    CLONE(Wall);
};

