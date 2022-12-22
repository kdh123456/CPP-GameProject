#pragma once
#include "Object.h"

class Image;

class Player :
    public Object
{
private:
    Image* m_pImage;
    Vec2 m_pos;
    int m_maxAttackPoint = 10;
    int m_currentAttackPoint = 0;
    bool m_isGrounded = true;
    bool m_headBroken = false;
    float m_jumpPower = 100.0f;
    float m_gravityScale = 98.0f;

public:
    Player();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
private:
    CLONE(Player);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    void EnterCollision(Collider* _pOther) override;
    void Jump();
    void Move(MoveDir dir);
    void TryParrying();
    void TryAttack();
    void TrySkill();
    void Input();
};