#pragma once
#include "globals.h"

class Bubble
{
	int type;
	int status;
	int X, Y;
	int direction;
	int dieCount;
	bool bigBubble;

public:
	void DrawBubble(HDC hDC, class Hero& hero, class Sprite&);

	void SetType(int t) { type = t; }

	int GetStatus() { return status; }
	void SetStatus(int st) { status = st; }

	int GetX() { return X; }
	int GetY() { return Y; }
	void SetXY(int nX, int nY) { X = nX; Y = nY; }

	int GetDirection() { return direction; }
	void SetDirection(int d) { direction = d; }

	int GetDieCount() { return dieCount; }
	void SetDieCount(int dC) { dieCount = dC; }

	bool GetBigBubble() { return bigBubble; }
	void SetBigBubble(bool b) { bigBubble = b; }
};

