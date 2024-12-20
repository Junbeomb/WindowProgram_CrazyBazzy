#include "Bubble.h"
#include "Sprite.h"
#include "Hero.h"


void Bubble::DrawBubble(HDC hDC, Hero& hero, Sprite& sprite) {

    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, sprite.bubble);
    if (status == 1 && bigBubble == -100) { //일반 물풍선 날라가는 중
        TransparentBlt(hDC, X - 25, Y - 40, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
    }
    else if (status == 1 && bigBubble == 1) { //거대 물풍선 날라가는 중
        TransparentBlt(hDC, X - 25, Y - 40, 100, 100, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
    }
    else if (status == 2) { //물풍선 터지는 중
        SelectObject(tempDC, sprite.bubbleBomb);
        TransparentBlt(hDC, X - 60, Y - 60, 130, 130, tempDC, (6 - (dieCount / 5)) * 100, 0, 100, 100, RGB(0, 0, 0));
    }

    SelectObject(tempDC, sprite.bubble);
    if (hero.skillX.toggle == 1) { //스킬x 누름
        if (hero.skillX.count / 160 >= 0)
            TransparentBlt(hDC, hero.X - 100, hero.Y - 90, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
        if (hero.skillX.count / 160 >= 1)
            TransparentBlt(hDC, hero.X - 25, hero.Y - 115, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
        if (hero.skillX.count / 160 >= 2)
            TransparentBlt(hDC, hero.X + 50, hero.Y - 90, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
        if (hero.skillX.count / 160 >= 3)
            TransparentBlt(hDC, hero.X + 25, hero.Y + 10, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
        if (hero.skillX.count / 160 >= 4)
            TransparentBlt(hDC, hero.X - 75, hero.Y + 10, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
    }
    //if (hero.skillZ.toggle == 1) { //스킬z 누름
    //    for (int i = 0; i < 20; i++) {
    //        if (hero.skillZ.bubble[i].status == 2) {
    //            SelectObject(tempDC, sprite.bubbleBomb);
    //            TransparentBlt(hDC, hero.skillZ.bubble[i].xPos - 40, hero.skillZ.bubble[i].yPos - 40, 130, 130, tempDC, (6 - (hero.skillZ.bubble[i].dieCount / 5)) * 100, 0, 100, 100, RGB(0, 0, 0));
    //        }
    //        else {
    //            SelectObject(tempDC, sprite.bubble);
    //            TransparentBlt(hDC, hero.skillZ.bubble[i].xPos, hero.skillZ.bubble[i].yPos, 50, 50, tempDC, 0, 0, 40, 44, RGB(100, 100, 100));
    //        }
    //    }
    //}
    DeleteObject(tempDC);
}