#pragma once
#include "globals.h"

class Item
{
    int type{};//�̼� ��ǳ�� ���ٱ�
public:
    int x{}, y{};
    HBITMAP sprite;

    void SetXY(int nX, int nY) { x = nX; y = nY; }
    int GetType() { return type; }
    void SetType(int t) { type = t; }
    void DrawItem(HDC hDC);
};

