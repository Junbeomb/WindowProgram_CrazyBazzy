#include "Item.h"
#include "Sprite.h"

void Item::DrawItem(HDC hDC)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, sprite);
    switch (type)
    {
    case SPEED:
        TransparentBlt(hDC, x - 5, y - 5, 40, 50, tempDC, 0, 0, 40, 50, RGB(100, 100, 100));
        break;
    case BALLOON:
        TransparentBlt(hDC, x - 5, y - 5, 40, 50, tempDC, 80, 0, 40, 50, RGB(100, 100, 100));
        break;
    case POTION:
        TransparentBlt(hDC, x - 5, y - 5, 40, 50, tempDC, 40, 0, 40, 50, RGB(100, 100, 100));
        break;
    case MAXPOTION:
        TransparentBlt(hDC, x - 5, y - 5, 40, 50, tempDC, 120, 0, 40, 50, RGB(100, 100, 100));
        break;
    default:
        break;
    }

    DeleteObject(tempDC);
}
