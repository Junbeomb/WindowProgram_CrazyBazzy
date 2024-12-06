#pragma once
#include "globals.h"

class Widget
{
public:
	void DrawCursor(HDC memDC, POINT cur, class Sprite sprite);
	void DrawHeart(HDC hDC, class Hero hero, class Boss snowBoss, class Sprite os);
	void DrawSkillIcon(HDC hDC, class Hero hero, class Sprite os);
};

