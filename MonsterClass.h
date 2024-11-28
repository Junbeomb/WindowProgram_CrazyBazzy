#pragma once
#include "globals.h"
class MonsterClass
{

public:
    MonsterClass(HBITMAP& h) : sprite{ h } {};
    HBITMAP sprite;

    int xPos, yPos;
    int direction;
    int status;
    int life;
    int locatecount;
    int anicount;

	void DrawMonster(HDC, HBITMAP&);
};

