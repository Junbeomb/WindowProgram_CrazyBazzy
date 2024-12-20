#include "Widget.h"
#include "Hero.h"
#include "Boss.h"
#include "Sprite.h"

void Widget::DrawCursor(HDC memDC, POINT cur, Sprite sprite)
{
    HDC  tempDC = CreateCompatibleDC(memDC);
    SelectObject(tempDC, sprite.cursor);
    TransparentBlt(memDC, cur.x, cur.y, 33, 36, tempDC, 0, 0, 33, 36, RGB(100, 100, 100));
    DeleteObject(tempDC);
}
void Widget::DrawHeart(HDC hDC, Hero hero, Boss snowBoss, Sprite os) {
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, os.heart);
    if (hero.GetLife() == 0) {
        SelectObject(tempDC, os.lose);
        TransparentBlt(hDC, 400, 300, 400, 200, tempDC, 0, 0, 400, 200, RGB(255, 255, 255));
    }
    if (hero.GetLife() >= 1)
        TransparentBlt(hDC, 20, 700, 50, 50, tempDC, 0, 0, 500, 400, RGB(0, 0, 0));
    if (hero.GetLife() >= 2)
        TransparentBlt(hDC, 60, 700, 50, 50, tempDC, 0, 0, 500, 400, RGB(0, 0, 0));
    if (hero.GetLife() >= 3)
        TransparentBlt(hDC, 100, 700, 50, 50, tempDC, 0, 0, 500, 400, RGB(0, 0, 0));

    //false 부분에 dieCount ==8 이런식으로 스테이지당 정해진 수 죽이면  win 나오게함.
    //수정해야함.
    if (snowBoss.GetLife() <= 0 && currentStage == 3 || (currentStage == 1 && false) || (currentStage == 2 && false)) {
        SelectObject(tempDC, os.win);
        TransparentBlt(hDC, 400, 300, 400, 200, tempDC, 0, 0, 600, 300, RGB(0, 0, 0));
    }

    DeleteObject(tempDC);
}
void Widget::DrawSkillIcon(HDC hDC, Hero hero, Sprite os) {
    HDC tempDC = CreateCompatibleDC(hDC);
    if (hero.skillX.coolTime == 0) {//쿨타임 없을때
        SelectObject(tempDC, os.heroSkillIcon);
        TransparentBlt(hDC, 160, 700, 40, 40, tempDC, 0, 0, 100, 100, RGB(127, 127, 127));
    }
    else {
        SelectObject(tempDC, os.heroSkillIconDark);
        TransparentBlt(hDC, 160, 700, 40, 40, tempDC, 0, 0, 100, 100, RGB(127, 127, 127));
        SelectObject(tempDC, os.number);
        int temp = hero.skillX.coolTime / 100;
        int twoNum = temp / 10;
        int oneNum = temp % 10;
        TransparentBlt(hDC, 153, 702, 30, 30, tempDC, twoNum * 100, 0, 100, 100, RGB(0, 0, 0));
        TransparentBlt(hDC, 173, 702, 30, 30, tempDC, oneNum * 100, 0, 100, 100, RGB(0, 0, 0));
    }

    if (hero.skillZ.coolTime == 0) { //쿨타임 없을때
        SelectObject(tempDC, os.heroSkillIcon);
        TransparentBlt(hDC, 230, 700, 40, 40, tempDC, 100, 0, 100, 100, RGB(127, 127, 127));
    }
    else {
        SelectObject(tempDC, os.heroSkillIconDark);
        TransparentBlt(hDC, 230, 700, 40, 40, tempDC, 100, 0, 100, 100, RGB(127, 127, 127));
        SelectObject(tempDC, os.number);
        int temp = hero.skillZ.coolTime / 100;
        int twoNum = temp / 10;
        int oneNum = temp % 10;
        TransparentBlt(hDC, 223, 702, 30, 30, tempDC, twoNum * 100, 0, 100, 100, RGB(0, 0, 0));
        TransparentBlt(hDC, 243, 702, 30, 30, tempDC, oneNum * 100, 0, 100, 100, RGB(0, 0, 0));
    }
    DeleteObject(tempDC);
}
