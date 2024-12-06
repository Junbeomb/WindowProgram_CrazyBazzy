#include "StageManager.h"
#include "globals.h"
#include "MonsterClass.h"
#include "Object.h"
#include "Item.h"
#include "Boss.h"
#include "Sprite.h"

void InitStage0()
{
}

void InitStage1(vector<MonsterClass>& monsters, vector<Object>& objects)
{
    //monsters==================================
    for (int i = 0; i < 8; ++i) {
        MonsterClass tMon;
        tMon.xPos = (rand() % 1180);
        tMon.life = 3;
        tMon.status = 0;
        tMon.direction = RIGHT;

        monsters.push_back(tMon);
    }
    monsters[0].yPos = 120;
    monsters[1].yPos = 170;
    monsters[2].yPos = 280;
    monsters[3].yPos = 330;
    monsters[4].yPos = 450;
    monsters[5].yPos = 490;
    monsters[6].yPos = 600;
    monsters[7].yPos = 650;
    //monsters==================================

    //objects==================================
    for (int j = 0; j < 29; j++) {
        for (int k = 2; k < 19; k += 4) {
            if (j == 0 && (k == 2 || k == 10 || k == 18)) continue;
            else if (j == 28 && (k == 6 || k == 14)) continue;
            Object tObject;
            tObject.SetType(rand() % 6 + 1);
            tObject.SetXY(j * 40, k * 40);
            objects.push_back(tObject);
        }
    }
    //objects==================================
}

void InitStage2(vector<class MonsterClass>& monsters, vector<class Object>& objects)
{
    //monsters==================================
    monsters.clear();
    for (int j = 0; j < MONSTEROFNUMBER; ++j) {
        MonsterClass tMon;
        tMon.xPos = (rand() % 800);
        tMon.life = 3;
        tMon.status = 0;
        tMon.direction = UP;

        monsters.push_back(tMon);
    }
    monsters[0].xPos = 75;
    monsters[1].xPos = 155;
    monsters[2].xPos = 235;
    monsters[3].xPos = 315;
    monsters[4].xPos = 395;
    monsters[5].xPos = 715;
    monsters[6].xPos = 795;
    monsters[7].xPos = 875;
    monsters[8].xPos = 955;
    monsters[9].xPos = 1035;
    //monsters==================================
    
    //objects==================================
    objects.clear();
    for (int j = 1; j < 29; j += 2)
    {
        for (int k = 1; k < 19; k += 2)
        {
            Object tObject;
            tObject.SetXY(j * 40, k * 40);

            if (j == 1 || j == 27 || k == 1 || k == 17)tObject.SetType(TREE);
            else if (j >= 9 && j <= 19 && k >= 7 && k <= 11) {
                if ((j == 13 || j == 15) && k == 9) continue;

                int random = rand() % 2;
                if (random == 0)tObject.SetType(BLOCK1);
                else tObject.SetType(BLOCK2);
            }
            else {
                int random = rand() % 3;
                if (random == 1)tObject.SetType(HOUSE1);
                else if (random == 2)tObject.SetType(HOUSE2);
                else tObject.SetType(HOUSE3);
            }
            objects.push_back(tObject);
        }
    }
    //objects==================================

}

void InitStageBoss(vector<Object>& objects, vector<Item>& items, Boss bossH)
{
    objects.clear();
    for (int i = 0; i < 10; i++) {
        Item tItem;
        tItem.SetXY(3 * i * 40, 17 * 40);
        switch (i) {
        case 0:case 1:case 2:
            tItem.SetType(SPEED);
            break;
        case 3:case 4:
            tItem.SetType(MAXPOTION);
            break;
        case 5:case 6:
            tItem.SetType(POTION);
            break;
        case 7:case 8:case 9:
            tItem.SetType(BALLOON);
            break;
        }
        items.push_back(tItem);
    }


    bossH.SetxPos(600);
    bossH.SetyPos(0);
    bossH.SetLife(40);
    bossH.SetDirection(DEFAULT);
    bossH.SetStatus(0);
    bossH.SetCount(0);
    bossH.SetSpriteCount(0);
    bossH.SetSkillMotionSpriteCount(0);
    bossH.SetShouldDraw(true);

    for (int i = 0; i < SKILL1NUMBER; i++) {
        bossH.skill1[i].skill1Toggle = 0;
        bossH.skill1[i].skill1Count = 0;
        bossH.skill1[i].skill1SpriteCount = 0;
        bossH.skill1[i].skill1Xpos = -1000;
        bossH.skill1[i].skill1Ypos = -1000;
        bossH.skill1[i].skill1Direction = 0;
        bossH.skill1[i].skill1DeadCount = 0;
    }
    bossH.skill2.skill2Toggle = 0;
    bossH.skill2.skill2Count = 0;
    bossH.skill2.skill2SpriteCount = 0;
    bossH.skill2.skill2SpreadCount = 0;
    bossH.skill2.skill2BombSpriteCount = 0;
    for (int i = 0; i < 4; i++) {
        bossH.skill2.skill2Xpos[i] = -1000;
        bossH.skill2.skill2Ypos[i] = -1000;
    }
    bossH.skill3.skill3Toggle = 0;
    bossH.skill3.skill3Count = 0;
    bossH.skill3.skill3SpriteCount = 0;
    bossH.skill3.skill3SpreadCount = 0;
    bossH.skill3.skill3BombSpriteCount = 0;
    for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
        bossH.skill4.mon[i].count = 0;
        bossH.skill4.mon[i].status = 0;
        bossH.skill4.mon[i].life = 0;
        bossH.skill4.mon[i].X = -1000;
        bossH.skill4.mon[i].Y = -1000;
    }
}
