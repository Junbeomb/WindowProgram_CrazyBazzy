#pragma once
#include "globals.h"
class Object
{
	int type;//���� ����(���̳� ����, ���)

public:
	int x, y;

	void DrawObjectUP(HDC hDC, class Sprite&, class Hero&);
	void DrawObjectDOWN(HDC hDC, class Sprite&, class  Hero&);

	int GetType() { return type; }
	void SetType(int t) { type = t; }
	void SetXY(int nX, int nY) { x = nX; y = nY; }
};

