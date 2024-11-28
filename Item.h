#pragma once
#include "globals.h"

class Item
{
    int x{}, y{};
    int type{};//이속 물풍선 물줄기
    bool shouldDraw{ false };

    HBITMAP sprite;
public:
    void DrawItem(HDC hDC);
};

