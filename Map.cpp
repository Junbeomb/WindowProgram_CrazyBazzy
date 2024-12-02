#include "Map.h"

void Map::DrawBoard(HDC hDC, HBITMAP map)
{
    HDC tempDC = CreateCompatibleDC(hDC);

    SelectObject(tempDC, map);
    BitBlt(hDC, 0, 0, 1200, 800, tempDC, 0, 0, SRCCOPY);
    DeleteObject(tempDC);
}