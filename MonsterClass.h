#pragma once
#include "globals.h"
class MonsterClass
{

public:
    
    int xPos, yPos;
    int direction;
    int status;
    int life;
    int locatecount;

    int dieCount{};

    int anicount{};
    int aniSpeed{ 5 };

	void DrawMonster(HDC, HBITMAP&);
    void InitStage1();

    void SetAnim();
    void Move();
    bool CollisionCheck(int targetX, int targetY, int width, int height);
    void Damaged();
    void Die();
};

