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
    int anicount;

	void DrawMonster(HDC, HBITMAP&);
};

