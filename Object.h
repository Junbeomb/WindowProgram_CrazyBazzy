#pragma once
#include "globals.h"
class Object
{

	int type;//���� ����(���̳� ����, ���)
	int x, y;
	bool shouldDraw;


public:
	void DrawBoard(HDC, HBITMAP);

	void DrawObjectUP(HDC hDC, class Sprite&, class Hero&);
	void DrawObjectDOWN(HDC hDC, class Sprite&, class  Hero&);

};

