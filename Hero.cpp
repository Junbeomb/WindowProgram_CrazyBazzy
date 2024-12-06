#include "Hero.h"

void Hero::DrawHero(HDC hDC)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, sprite);

    if (status == 0 || status == 10)
    {
        TransparentBlt(hDC, X - 25, Y - 40, HeroWidth, HeroHeight, tempDC, spriteCount * HeroWidth, direction * HeroHeight, 50, 60, RGB(100, 100, 100));
    }
    else if (status == 2) {
        TransparentBlt(hDC, X - 25, Y - 40, HeroWidth, HeroHeight, tempDC, 0, 300, 50, 60, RGB(100, 100, 100));
    }
    else if (status == 3) {
        if (resurrectionCount % 2 == 1)
            TransparentBlt(hDC, X - 25, Y - 40, HeroWidth, HeroHeight, tempDC, spriteCount * HeroWidth, direction * HeroHeight, 50, 60, RGB(100, 100, 100));
    }

    DeleteObject(tempDC);
}

void Hero::Damaged()
{
    life--;
    status = 2;
}
