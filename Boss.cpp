#include "Boss.h"

Boss::Boss() {};

void Boss::DrawBoss(HDC hDC, BOSS snowBoss, BOSSSPRITE bs)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, bs.bossImage);

    if (snowBoss.life <= 0) {
        SelectObject(tempDC, bs.bossDie);
        TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, 0, 0, 200, 200, RGB(127, 127, 127));
    }
    else {
        if (snowBoss.direction == DEFAULT) {
            TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, 400, 0, 200, 200, RGB(127, 127, 127));
        }
        else if (snowBoss.direction == LEFT) {
            if (snowBoss.status == 2 || snowBoss.status == 3) { //스킬1 사용 시
                TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, snowBoss.spriteCount * 200, 800, 200, 200, RGB(127, 127, 127));
            }
            else
                TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, snowBoss.spriteCount * 200, 400, 200, 200, RGB(127, 127, 127));
        }
        else if (snowBoss.direction == RIGHT) {
            if (snowBoss.status == 2 || snowBoss.status == 3) { //스킬1 사용 시
                TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, snowBoss.spriteCount * 200, 600, 200, 200, RGB(127, 127, 127));
            }
            else
                TransparentBlt(hDC, snowBoss.xPos, snowBoss.yPos, 250, 250, tempDC, snowBoss.spriteCount * 200, 200, 200, 200, RGB(127, 127, 127));
        }
    }

    DeleteObject(tempDC);
}
void Boss::DrawBossSkill4(HDC hDC, BOSS snowBoss, BOSSSPRITE bs) { //스킬4
    HDC tempDC = CreateCompatibleDC(hDC);
    for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
        if (snowBoss.skill4.mon[i].status == 1) {
            if (snowBoss.skill4.mon[i].count > 35) {
                SelectObject(tempDC, bs.skill4Monster);
                if (snowBoss.skill4.mon[i].direction == LEFT) {
                    TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, snowBoss.skill4.mon[i].monSpriteCount * 150, 0, 150, 100, RGB(255, 255, 255));
                }
                if (snowBoss.skill4.mon[i].direction == RIGHT) {
                    TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, snowBoss.skill4.mon[i].monSpriteCount * 150, 100, 150, 100, RGB(255, 255, 255));
                }
                if (snowBoss.skill4.mon[i].direction == DOWN) {
                    TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, snowBoss.skill4.mon[i].monSpriteCount * 150, 200, 150, 100, RGB(255, 255, 255));
                }
                if (snowBoss.skill4.mon[i].direction == UP) {
                    TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, snowBoss.skill4.mon[i].monSpriteCount * 150, 300, 150, 100, RGB(255, 255, 255));
                }

            }
            else {
                SelectObject(tempDC, bs.skill4Egg);
                TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, snowBoss.skill4.mon[i].eggSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
        else if (snowBoss.skill4.mon[i].status == 2) {
            SelectObject(tempDC, bs.skill4Monster);
            TransparentBlt(hDC, snowBoss.skill4.mon[i].xPos, snowBoss.skill4.mon[i].yPos, 100, 100, tempDC, 0, 400, 150, 100, RGB(255, 255, 255));
        }

    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill3(HDC hDC, BOSS snowBoss, BOSSSPRITE bs) {//스킬3
    HDC tempDC = CreateCompatibleDC(hDC);
    if (snowBoss.skill3.skill3Toggle == 1) {
        if (snowBoss.skill3.skill3Count < 15) {
            SelectObject(tempDC, bs.skill2CircleImage);
            TransparentBlt(hDC, snowBoss.xPos + 90, snowBoss.yPos, 100, 100, tempDC, snowBoss.skill2.skill2SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        SelectObject(tempDC, bs.skill2SnowBombImage);
        if (snowBoss.skill3.skill3Count < 24) {
            for (int i = 0; i < 20; i++) {
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + (snowBoss.skill3.skill3Count * 50) - 100, 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + (snowBoss.skill3.skill3Count * 50) - 50, 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + (snowBoss.skill3.skill3Count * 50), 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
        else if (snowBoss.skill3.skill3Count >= 24) {
            SelectObject(tempDC, bs.snowSignImage);
            for (int i = 0; i < 20; i++) {
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + ((snowBoss.skill3.skill3Count - 24) * 50) - 100, 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + ((snowBoss.skill3.skill3Count - 24) * 50) - 50, 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, snowBoss.skill3.skill3Xpos[i], snowBoss.skill3.skill3Ypos[i] + ((snowBoss.skill3.skill3Count - 24) * 50), 100, 100, tempDC, snowBoss.skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill2(HDC hDC, BOSS snowBoss, BOSSSPRITE bs)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    if (snowBoss.skill2.skill2Toggle == 1) { //스킬2
        if (snowBoss.skill2.skill2Count < 15) {
            SelectObject(tempDC, bs.skill2CircleImage);
            TransparentBlt(hDC, snowBoss.xPos + 90, snowBoss.yPos, 100, 100, tempDC, snowBoss.skill2.skill2SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        for (int i = 0; i < 4; i++) {
            SelectObject(tempDC, bs.skill2SnowBombImage);
            TransparentBlt(hDC, snowBoss.skill2.skill2Xpos[i], snowBoss.skill2.skill2Ypos[i], 100, 100, tempDC, snowBoss.skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            if (snowBoss.skill2.skill2Count > 40) { //2초뒤 양쪽으로 퍼짐
                for (int j = 1; j <= snowBoss.skill2.skill2SpreadCount; j++) {
                    TransparentBlt(hDC, snowBoss.skill2.skill2Xpos[i] + (j * 70), snowBoss.skill2.skill2Ypos[i], 100, 100, tempDC, snowBoss.skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                    TransparentBlt(hDC, snowBoss.skill2.skill2Xpos[i] - (j * 70), snowBoss.skill2.skill2Ypos[i], 100, 100, tempDC, snowBoss.skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                }
            }
        }
    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill1(HDC memDC, BOSS snowBoss, BOSSSPRITE bs)
{
    HDC tempDC = CreateCompatibleDC(memDC);
    for (int i = 0; i < SKILL1NUMBER; i++) {//스킬1
        if (snowBoss.skill1[i].skill1Toggle == 1) {
            SelectObject(tempDC, bs.snowBallImage);
            TransparentBlt(memDC, snowBoss.skill1[i].skill1Xpos, snowBoss.skill1[i].skill1Ypos, 250, 250, tempDC, snowBoss.skill1[i].skill1SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        else if (snowBoss.skill1[i].skill1Toggle == 2) {
            SelectObject(tempDC, bs.snowBallBombImage);
            TransparentBlt(memDC, snowBoss.skill1[i].skill1Xpos, snowBoss.skill1[i].skill1Ypos, 250, 250, tempDC, snowBoss.skill1[i].skill1DeadSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
    }

    DeleteObject(tempDC);
}