#include "Object.h"
#include "Hero.h"
#include "Sprite.h"

void Object::DrawBoard(HDC hDC, HBITMAP map)
{
    HDC tempDC = CreateCompatibleDC(hDC);

    SelectObject(tempDC, map);
    BitBlt(hDC, 0, 0, 1200, 800, tempDC, 0, 0, SRCCOPY);
    DeleteObject(tempDC);
}

void Object::DrawObjectUP(HDC hDC, Sprite& sprite, Hero& hero)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    if (y + 40 <= hero.heroY && shouldDraw)
    {
        switch (type)
        {
        case TREE:
            SelectObject(tempDC, sprite.tree);
            TransparentBlt(hDC, x, y - 30, 40, 70, tempDC, 0, 0, 40, 70, RGB(100, 100, 100));
            break;
        case HOUSE1:
            SelectObject(tempDC, sprite.redHouse);
            TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
            break;
        case HOUSE2:
            SelectObject(tempDC, sprite.yellowHouse);
            TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
            break;
        case HOUSE3:
            SelectObject(tempDC, sprite.blueHouse);
            TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
            break;
        case BLOCK1:
            SelectObject(tempDC, sprite.redBlock);
            TransparentBlt(hDC, x, y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
            break;
        case BLOCK2:
            SelectObject(tempDC, sprite.yellowBlock);
            TransparentBlt(hDC, x, y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
            break;
        }
    }
    DeleteObject(tempDC);
}
void Object::DrawObjectDOWN(HDC hDC, Sprite& sprite, Hero& hero) {
    HDC tempDC = CreateCompatibleDC(hDC);
        if (y + 40 > hero.heroY && shouldDraw)
        {
            switch (type)
            {
            case TREE:
                SelectObject(tempDC, sprite.tree);
                TransparentBlt(hDC, x, y - 30, 40, 70, tempDC, 0, 0, 40, 70, RGB(100, 100, 100));
                break;
            case HOUSE1:
                SelectObject(tempDC, sprite.redHouse);
                TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE2:
                SelectObject(tempDC, sprite.yellowHouse);
                TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE3:
                SelectObject(tempDC, sprite.blueHouse);
                TransparentBlt(hDC, x, y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case BLOCK1:
                SelectObject(tempDC, sprite.redBlock);
                TransparentBlt(hDC, x, y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            case BLOCK2:
                SelectObject(tempDC, sprite.yellowBlock);
                TransparentBlt(hDC, x, y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            }
        }
    DeleteObject(tempDC);
}

