#pragma once
#include "globals.h"

class Widget
{
public:
	void DrawCursor(HDC memDC, POINT cur, HBITMAP cursor);
	void DrawHeart(HDC hDC, HERO hero, class Boss snowBoss, OBJSPRITE os);
	void DrawSkillIcon(HDC hDC, HERO hero, OBJSPRITE os);
};

