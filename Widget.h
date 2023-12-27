#pragma once
#include "globals.h"

class Widget
{
public:
	Widget();

	void DrawCursor(HDC memDC, POINT cur, HBITMAP cursor);
	void DrawHeart(HDC hDC, HERO hero, BOSS snowBoss, OBJSPRITE os);
	void DrawSkillIcon(HDC hDC, HERO hero, OBJSPRITE os);
};

