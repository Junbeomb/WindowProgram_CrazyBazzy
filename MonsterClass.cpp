#include "MonsterClass.h"

MonsterClass::MonsterClass() {};

void MonsterClass::DrawMonster(HDC hDC, MONSTER monster, MONSPRITE ms)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, ms.monImage);
    if (monster.status == 0) {
        if (monster.direction == RIGHT)
            TransparentBlt(hDC, monster.xPos, monster.yPos, 50, 60, tempDC, monster.anicount * 100, 95, 100, 100, RGB(100, 100, 100));
        else if (monster.direction == LEFT)
            TransparentBlt(hDC, monster.xPos, monster.yPos, 50, 60, tempDC, monster.anicount * 100, 195, 100, 100, RGB(100, 100, 100));
        else if (monster.direction == DOWN)
            TransparentBlt(hDC, monster.xPos, monster.yPos, 50, 60, tempDC, monster.anicount * 100, 0, 100, 100, RGB(100, 100, 100));
        else if (monster.direction == UP)
            TransparentBlt(hDC, monster.xPos, monster.yPos, 50, 60, tempDC, monster.anicount * 100, 300, 100, 100, RGB(100, 100, 100));
    }
    if (monster.status == 1) {
        TransparentBlt(hDC, monster.xPos, monster.yPos, 50, 60, tempDC, 0, 380, 100, 100, RGB(100, 100, 100));
    }
    DeleteObject(tempDC);
}