#include "MonsterClass.h"

void MonsterClass::DrawMonster(HDC hDC, HBITMAP& ms)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, ms);

    if (status == 0) {
        if (direction == RIGHT)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount * 100, 95, 100, 100, RGB(100, 100, 100));
        else if (direction == LEFT)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount * 100, 195, 100, 100, RGB(100, 100, 100));
        else if (direction == DOWN)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount * 100, 0, 100, 100, RGB(100, 100, 100));
        else if (direction == UP)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount * 100, 300, 100, 100, RGB(100, 100, 100));
    }
    if (status == 1) {
        TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, 0, 380, 100, 100, RGB(100, 100, 100));
    }
    DeleteObject(tempDC);
}