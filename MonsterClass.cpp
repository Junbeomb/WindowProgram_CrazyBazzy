#include "MonsterClass.h"
#include "Hero.h"

void MonsterClass::DrawMonster(HDC hDC, HBITMAP& ms)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, ms);

    if (status == 0) {
        if (direction == RIGHT)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount/ aniSpeed * 100, 95, 100, 100, RGB(100, 100, 100));
        else if (direction == LEFT)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount / aniSpeed * 100, 195, 100, 100, RGB(100, 100, 100));
        else if (direction == DOWN)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount / aniSpeed * 100, 0, 100, 100, RGB(100, 100, 100));
        else if (direction == UP)
            TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, anicount / aniSpeed * 100, 300, 100, 100, RGB(100, 100, 100));
    }
    if (status == 1) {
        TransparentBlt(hDC, xPos, yPos, 50, 60, tempDC, 0, 380, 100, 100, RGB(100, 100, 100));
    }
    DeleteObject(tempDC);
}

void MonsterClass::SetAnim()
{
}

void MonsterClass::Move()
{
    locatecount++;
    if (locatecount != 0 && locatecount % 20 == 0) {
        int directionRandom = rand() % 2;
        if (direction == RIGHT || direction == LEFT) {
            if (directionRandom == 0) direction = RIGHT;
            else if (directionRandom == 1) direction = LEFT;
        }
        else {
            if (directionRandom == 0) direction = UP;
            else if (directionRandom == 1) direction = DOWN;
        }
    }

    if (direction == LEFT) {
        xPos -= 5;
        if (xPos <= 0) direction = RIGHT;
    }
    else if (direction == RIGHT) {
        xPos += 5;
        if (xPos + 130 >= MAP_ROW)direction = LEFT;
    }
    if (direction == UP) { //πÊ«‚
        yPos -= 5;
        if (yPos <= 0) direction = DOWN;
    }
    else if (direction == DOWN) {
        yPos += 5;
        if (yPos + 130 >= MAP_COL) direction = UP;
    }
}

bool MonsterClass::CollisionCheck(int targetX, int targetY, int width, int height)
{
    if (targetX  < xPos + width &&
        targetX > xPos &&
        targetY  < yPos + height &&
        targetY > yPos) {
        return true;
    }
    return false;
}

void MonsterClass::Damaged()
{
    life--;
    if (life == 0) status = 1;
}

void MonsterClass::Die()
{
}
