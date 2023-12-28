#pragma once
#include "globals.h"

class Boss
{
public:
	Boss();
	void DrawBoss(HDC hDC, BOSS snowBoss, BOSSSPRITE bs);
	void DrawBossSkill4(HDC hDC, BOSS snowBoss, BOSSSPRITE bs);
	void DrawBossSkill3(HDC hDC, BOSS snowBoss, BOSSSPRITE bs);
	void DrawBossSkill2(HDC hDC, BOSS snowBoss, BOSSSPRITE bs);
	void DrawBossSkill1(HDC hDC, BOSS snowBoss, BOSSSPRITE bs);
};

