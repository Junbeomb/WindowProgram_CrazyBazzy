#pragma once
#include "globals.h"

class Bubble
{
	int type;
	int status;
	int X, Y;
	int direction;
	int dieCount;
	int bigBubble;

public:
	void DrawBubble(HDC hDC, class Hero& hero, class Sprite&);

	void SetType(int t) { type = t; }
	void SetStatus(int st) { status = st; }
	void SetXY(int nX, int nY) { X = nX; Y = nY; }
	void SetDirection(int d) { direction = d; }
	void SetDieCount(int dC) { dieCount = dC; }
	void SetBigBubble(int b) { bigBubble = b; }
};

