#pragma once
#include "globals.h"
class Object
{

	int type;//옵젝 종류(집이나 나무, 블록)
	int x, y;
	bool shouldDraw;


public:
	void DrawBoard(HDC, HBITMAP);

	void DrawObjectUP(HDC hDC, class Sprite&, class Hero&);
	void DrawObjectDOWN(HDC hDC, class Sprite&, class  Hero&);

};

