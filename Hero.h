#pragma once
#include "globals.h"

class Hero
{
public:
	Hero();
	void DrawHero(HDC hDC, HERO hero);
	void DrawBubble(HDC hDC, HERO hero, OBJSPRITE os);
};

