#pragma once
#include "globals.h"

class Item
{
    int x{}, y{};
    int type{};//�̼� ��ǳ�� ���ٱ�
    bool shouldDraw{ false };

    HBITMAP sprite;
public:
    void DrawItem(HDC hDC);
};

