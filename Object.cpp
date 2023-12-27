#include "Object.h"

Object::Object() {};

void Object::DrawBoard(HDC hDC, HBITMAP map)
{
    HDC tempDC = CreateCompatibleDC(hDC);

    SelectObject(tempDC, map);
    BitBlt(hDC, 0, 0, 1200, 800, tempDC, 0, 0, SRCCOPY);
    DeleteObject(tempDC);
}
void Object::DrawObjectUP(HDC hDC, OBJECT object[150], OBJSPRITE os, HERO hero)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    for (int i = 0; i < 150; i++)
    {
        if (object[i].y + 40 <= hero.heroY && object[i].shouldDraw)
        {
            switch (object[i].type)
            {
            case TREE:
                SelectObject(tempDC, os.tree);
                TransparentBlt(hDC, object[i].x, object[i].y - 30, 40, 70, tempDC, 0, 0, 40, 70, RGB(100, 100, 100));
                break;
            case HOUSE1:
                SelectObject(tempDC, os.redHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE2:
                SelectObject(tempDC, os.yellowHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE3:
                SelectObject(tempDC, os.blueHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case BLOCK1:
                SelectObject(tempDC, os.redBlock);
                TransparentBlt(hDC, object[i].x, object[i].y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            case BLOCK2:
                SelectObject(tempDC, os.yellowBlock);
                TransparentBlt(hDC, object[i].x, object[i].y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            }
        }

    }
    DeleteObject(tempDC);
}
void Object::DrawObjectDOWN(HDC hDC, OBJECT object[150], OBJSPRITE os, HERO hero) {
    HDC tempDC = CreateCompatibleDC(hDC);
    for (int i = 0; i < 150; i++)
    {
        if (object[i].y + 40 > hero.heroY && object[i].shouldDraw)
        {
            switch (object[i].type)
            {
            case TREE:
                SelectObject(tempDC, os.tree);
                TransparentBlt(hDC, object[i].x, object[i].y - 30, 40, 70, tempDC, 0, 0, 40, 70, RGB(100, 100, 100));
                break;
            case HOUSE1:
                SelectObject(tempDC, os.redHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE2:
                SelectObject(tempDC, os.yellowHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case HOUSE3:
                SelectObject(tempDC, os.blueHouse);
                TransparentBlt(hDC, object[i].x, object[i].y - 13, 40, 53, tempDC, 0, 0, 40, 53, RGB(100, 100, 100));
                break;
            case BLOCK1:
                SelectObject(tempDC, os.redBlock);
                TransparentBlt(hDC, object[i].x, object[i].y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            case BLOCK2:
                SelectObject(tempDC, os.yellowBlock);
                TransparentBlt(hDC, object[i].x, object[i].y - 4, 40, 44, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
                break;
            }
        }

    }
    DeleteObject(tempDC);
}
void Object::DrawItem(HDC hDC, ITEM item[100], HBITMAP hBitmap)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, hBitmap);
    for (int i = 0; i < 100; i++)
    {
        if (item[i].shouldDraw)
        {
            switch (item[i].type)
            {
            case SPEED:
                TransparentBlt(hDC, item[i].x - 5, item[i].y - 5, 40, 50, tempDC, 0, 0, 40, 50, RGB(100, 100, 100));
                break;
            case BALLOON:
                TransparentBlt(hDC, item[i].x - 5, item[i].y - 5, 40, 50, tempDC, 80, 0, 40, 50, RGB(100, 100, 100));
                break;
            case POTION:
                TransparentBlt(hDC, item[i].x - 5, item[i].y - 5, 40, 50, tempDC, 40, 0, 40, 50, RGB(100, 100, 100));
                break;
            case MAXPOTION:
                TransparentBlt(hDC, item[i].x - 5, item[i].y - 5, 40, 50, tempDC, 120, 0, 40, 50, RGB(100, 100, 100));
                break;
            default:
                break;
            }
        }
    }
    DeleteObject(tempDC);
}

