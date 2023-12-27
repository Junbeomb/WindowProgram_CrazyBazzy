#pragma once
#include "globals.h"
class Object
{
public:
	Object();
	void DrawBoard(HDC, HBITMAP);
	void DrawItem(HDC hDC, ITEM item[100], HBITMAP hBitmap);
	void DrawObjectUP(HDC hDC, OBJECT object[150], OBJSPRITE os, HERO hero);
	void DrawObjectDOWN(HDC hDC, OBJECT object[150], OBJSPRITE os, HERO hero);
};

