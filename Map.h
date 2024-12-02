#pragma once
#include "globals.h"

class Map
{
	HBITMAP sprite;
public:

	Map(HBITMAP& s) : sprite{ s } {};

	void DrawBoard(HDC, HBITMAP);
};

