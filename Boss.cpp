#include "Boss.h"
#include "팀프로젝트.cpp"

void Boss::DrawBoss(HDC hDC, bossSprite bs)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    SelectObject(tempDC, bs.bossImage);

    if (life <= 0) {
        SelectObject(tempDC, bs.bossDie);
        TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, 0, 0, 200, 200, RGB(127, 127, 127));
    }
    else {
        if (direction == DEFAULT) {
            TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, 400, 0, 200, 200, RGB(127, 127, 127));
        }
        else if (direction == LEFT) {
            if (status == 2 || status == 3) { //스킬1 사용 시
                TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, spriteCount * 200, 800, 200, 200, RGB(127, 127, 127));
            }
            else
                TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, spriteCount * 200, 400, 200, 200, RGB(127, 127, 127));
        }
        else if (direction == RIGHT) {
            if (status == 2 || status == 3) { //스킬1 사용 시
                TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, spriteCount * 200, 600, 200, 200, RGB(127, 127, 127));
            }
            else
                TransparentBlt(hDC, xPos, yPos, 250, 250, tempDC, spriteCount * 200, 200, 200, 200, RGB(127, 127, 127));
        }
    }

    DeleteObject(tempDC);
}
void Boss::DrawBossSkill4(HDC hDC, bossSprite bs) { //스킬4
    HDC tempDC = CreateCompatibleDC(hDC);
    for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
        if (skill4.mon[i].status == 1) {
            if (skill4.mon[i].count > 35) {
                SelectObject(tempDC, bs.skill4Monster);
                if (skill4.mon[i].direction == LEFT) {
                    TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, skill4.mon[i].monSpriteCount * 150, 0, 150, 100, RGB(255, 255, 255));
                }
                if (skill4.mon[i].direction == RIGHT) {
                    TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, skill4.mon[i].monSpriteCount * 150, 100, 150, 100, RGB(255, 255, 255));
                }
                if (skill4.mon[i].direction == DOWN) {
                    TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, skill4.mon[i].monSpriteCount * 150, 200, 150, 100, RGB(255, 255, 255));
                }
                if (skill4.mon[i].direction == UP) {
                    TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, skill4.mon[i].monSpriteCount * 150, 300, 150, 100, RGB(255, 255, 255));
                }

            }
            else {
                SelectObject(tempDC, bs.skill4Egg);
                TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, skill4.mon[i].eggSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
        else if (skill4.mon[i].status == 2) {
            SelectObject(tempDC, bs.skill4Monster);
            TransparentBlt(hDC, skill4.mon[i].xPos, skill4.mon[i].yPos, 100, 100, tempDC, 0, 400, 150, 100, RGB(255, 255, 255));
        }

    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill3(HDC hDC, bossSprite bs) {//스킬3
    HDC tempDC = CreateCompatibleDC(hDC);
    if (skill3.skill3Toggle == 1) {
        if (skill3.skill3Count < 15) {
            SelectObject(tempDC, bs.skill2CircleImage);
            TransparentBlt(hDC, xPos + 90, yPos, 100, 100, tempDC, skill2.skill2SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        SelectObject(tempDC, bs.skill2SnowBombImage);
        if (skill3.skill3Count < 24) {
            for (int i = 0; i < 20; i++) {
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + (skill3.skill3Count * 50) - 100, 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + (skill3.skill3Count * 50) - 50, 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + (skill3.skill3Count * 50), 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
        else if (skill3.skill3Count >= 24) {
            SelectObject(tempDC, bs.snowSignImage);
            for (int i = 0; i < 20; i++) {
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + ((skill3.skill3Count - 24) * 50) - 100, 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + ((skill3.skill3Count - 24) * 50) - 50, 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                TransparentBlt(hDC, skill3.skill3Xpos[i], skill3.skill3Ypos[i] + ((skill3.skill3Count - 24) * 50), 100, 100, tempDC, skill3.skill3BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            }
        }
    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill2(HDC hDC, bossSprite bs)
{
    HDC tempDC = CreateCompatibleDC(hDC);
    if (skill2.skill2Toggle == 1) { //스킬2
        if (skill2.skill2Count < 15) {
            SelectObject(tempDC, bs.skill2CircleImage);
            TransparentBlt(hDC, xPos + 90, yPos, 100, 100, tempDC, skill2.skill2SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        for (int i = 0; i < 4; i++) {
            SelectObject(tempDC, bs.skill2SnowBombImage);
            TransparentBlt(hDC, skill2.skill2Xpos[i], skill2.skill2Ypos[i], 100, 100, tempDC, skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
            if (skill2.skill2Count > 40) { //2초뒤 양쪽으로 퍼짐
                for (int j = 1; j <= skill2.skill2SpreadCount; j++) {
                    TransparentBlt(hDC, skill2.skill2Xpos[i] + (j * 70), skill2.skill2Ypos[i], 100, 100, tempDC, skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                    TransparentBlt(hDC, skill2.skill2Xpos[i] - (j * 70), skill2.skill2Ypos[i], 100, 100, tempDC, skill2.skill2BombSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
                }
            }
        }
    }
    DeleteObject(tempDC);
}
void Boss::DrawBossSkill1(HDC memDC, bossSprite bs)
{
    HDC tempDC = CreateCompatibleDC(memDC);
    for (int i = 0; i < SKILL1NUMBER; i++) {//스킬1
        if (skill1[i].skill1Toggle == 1) {
            SelectObject(tempDC, bs.snowBallImage);
            TransparentBlt(memDC, skill1[i].skill1Xpos, skill1[i].skill1Ypos, 250, 250, tempDC, skill1[i].skill1SpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
        else if (skill1[i].skill1Toggle == 2) {
            SelectObject(tempDC, bs.snowBallBombImage);
            TransparentBlt(memDC, skill1[i].skill1Xpos, skill1[i].skill1Ypos, 250, 250, tempDC, skill1[i].skill1DeadSpriteCount * 100, 0, 100, 100, RGB(0, 0, 0));
        }
    }

    DeleteObject(tempDC);
}

void Boss::BossAlgorithm()
{
    if (!shouldDraw) return;

    bossrdCount++;
    if (bossrdCount == 5)
    {
        bossrdCount = 0;

        count++;
        if (count == 60)count = 0;
        //애니메이션 카운트
        spriteCount++;
        if (spriteCount > 5)
            spriteCount = 0;

        if (life > 0)
        {
            if (status == 0) { //스킬 미사용 시에만
                //count30마다 방향 전환
                if (count != 0 && count % 30 == 0) {
                    int directionRandom = rand() % 4;
                    if (directionRandom == 0 || directionRandom == 3)
                        direction = DEFAULT;
                    else if (directionRandom == 1) {
                        direction = LEFT;
                    }
                    else if (directionRandom == 2) {
                        direction = RIGHT;
                    }
                }
                //방향
                if (direction == LEFT) {
                    xPos -= 10;
                    if (xPos <= 0) {
                        direction = RIGHT;
                    }
                }
                else if (direction == RIGHT) {
                    xPos += 10;
                    if (xPos + 250 >= MAP_ROW) {
                        direction = LEFT;
                    }
                }
                //count10마다 스킬 사용
                if (count != 0 && count % 10 == 0) {
                    int skillRandom = rand() % 6;
                    if (direction == LEFT || direction == RIGHT) {
                        switch (skillRandom) {
                        case 0: //스킬 미사용
                        case 1:
                        case 2:
                            status = 0;
                            break;
                        case 3://스킬1
                        case 4:
                            for (int i = 0; i < SKILL1NUMBER; i++) {
                                if (skill1[i].skill1Toggle == 0) {
                                    status = 1;
                                    skill1[i].skill1Toggle = 1;
                                    skill1[i].skill1Xpos = xPos;
                                    skill1[i].skill1Ypos = yPos;
                                    if (direction == LEFT)
                                        skill1[i].skill1Direction = LEFT_DOWN;
                                    else if (direction == RIGHT)
                                        skill1[i].skill1Direction = RIGHT_DOWN;
                                    break;
                                }
                            }
                            break;
                        case 5://스킬4
                            status = 4;
                            skill4.skill4Toggle = 1;
                            break;
                        }
                    }
                    else if (direction == DEFAULT) {
                        skillRandom = rand() % 3;
                        switch (skillRandom) {
                        case 0: //스킬 미사용
                            status = 0;
                            break;
                        case 1: //스킬 2
                            if (skill2.skill2Toggle == 1) {
                                status = 0;
                            }
                            else {
                                status = 2;
                                skill2.skill2Toggle = 1;
                            }
                            break;
                        case 2: //스킬 3
                            if (skill3.skill3Toggle == 1) {
                                status = 0;
                            }
                            else {
                                status = 3;
                                skill3.skill3Toggle = 1;
                            }
                            break;
                        }
                    }
                }
            }
        }

        //boss가 스킬 사용 중
        if (status > 0) {
            skillMotionSpriteCount++; //transparentblt 스킬 모션 카운트를 직접 움직이지는 않음
            if (skillMotionSpriteCount >= 6) {
                skillMotionSpriteCount = 0;
                status = 0;
            }
        }

        //스킬1
        for (int i = 0; i < SKILL1NUMBER; i++) {
            if (skill1[i].skill1Toggle == 1) {
                skill1[i].skill1Count++;
                skill1[i].skill1SpriteCount++;
                if (skill1[i].skill1SpriteCount >= 7)
                    skill1[i].skill1SpriteCount = 0;

                if (skill1[i].skill1Direction == LEFT_DOWN) {
                    skill1[i].skill1Xpos -= 20;
                    skill1[i].skill1Ypos += 20;
                    if (skill1[i].skill1Xpos + 30 < 0) {
                        skill1[i].skill1Direction = RIGHT_DOWN;
                        skill1[i].skill1DeadCount++;
                    }
                    else if (skill1[i].skill1Ypos + 220 > MAP_COL) {
                        skill1[i].skill1Direction = LEFT_UP;
                        skill1[i].skill1DeadCount++;
                    }
                }
                else if (skill1[i].skill1Direction == RIGHT_DOWN) {
                    skill1[i].skill1Xpos += 20;
                    skill1[i].skill1Ypos += 20;
                    if (skill1[i].skill1Xpos + 220 > MAP_ROW) {
                        skill1[i].skill1Direction = LEFT_DOWN;
                        skill1[i].skill1DeadCount++;
                    }
                    else if (skill1[i].skill1Ypos + 220 > MAP_COL) {
                        skill1[i].skill1Direction = RIGHT_UP;
                        skill1[i].skill1DeadCount++;
                    }
                }
                else if (skill1[i].skill1Direction == LEFT_UP) {
                    skill1[i].skill1Xpos -= 20;
                    skill1[i].skill1Ypos -= 20;
                    if (skill1[i].skill1Xpos + 30 < 0) {
                        skill1[i].skill1Direction = RIGHT_UP;
                        skill1[i].skill1DeadCount++;
                    }
                    else if (skill1[i].skill1Ypos + 30 < 0) {
                        skill1[i].skill1Direction = LEFT_DOWN;
                        skill1[i].skill1DeadCount++;
                    }
                }
                else if (skill1[i].skill1Direction == RIGHT_UP) {
                    skill1[i].skill1Xpos += 20;
                    skill1[i].skill1Ypos -= 20;
                    if (skill1[i].skill1Xpos + 220 > MAP_ROW) {
                        skill1[i].skill1Direction = LEFT_UP;
                        skill1[i].skill1DeadCount++;
                    }
                    else if (skill1[i].skill1Ypos + 30 < 0) {
                        skill1[i].skill1Direction = RIGHT_DOWN;
                        skill1[i].skill1DeadCount++;
                    }
                }

                if (skill1[i].skill1DeadCount >= 4) { //눈덩이 벽 네번 부딪쳐서 부서짐
                    skill1[i].skill1Toggle = 2;//부서지는 중
                }
            }
            else if (skill1[i].skill1Toggle == 2) {
                skill1[i].skill1DeadSpriteCount++;
                if (skill1[i].skill1DeadSpriteCount >= 3) { //부서짐
                    skill1[i].skill1Toggle = 0;
                    skill1[i].skill1DeadSpriteCount = 0;
                    skill1[i].skill1Xpos = -1000;
                    skill1[i].skill1Ypos = -1000;
                    skill1[i].skill1Count = 0;
                    skill1[i].skill1SpriteCount = 0;
                    skill1[i].skill1DeadCount = 0;
                }
            }

            //if (hero.status == 0 && life > 0) {//배찌가 살아있을 때
            //    if (sqrt(pow((skill1[i].skill1Xpos + 125) - hero.heroX, 2) + pow((skill1[i].skill1Ypos + 125) - hero.heroY, 2)) < 100) {
            //        hero.life--;
            //        hero.status = 2;//배찌 사망중
            //    }
            //}
        }

        //스킬2
        if (skill2.skill2Toggle == 1) {

            skill2.skill2Count++;

            if (skill2.skill2SpriteCount < 10)
                skill2.skill2SpriteCount++;

            if (skill2.skill2Count >= 67) { //스킬2종료
                skill2.skill2SpriteCount = 0;
                skill2.skill2Toggle = 0;
                skill2.skill2Count = 0;
                skill2.skill2SpreadCount = 0;
                skill2.skill2BombSpriteCount = 0;
            }

            if (skill2.skill2Count == 1) { //처음 한번 만
                for (int i = 0; i < 4; i++) {
                    skill2.skill2Xpos[i] = (rand() % (MAP_ROW - 200)) + 100;
                    skill2.skill2Ypos[i] = (rand() % (MAP_COL - 300)) + 250;
                }
            }
            if (skill2.skill2Count > 40) {
                skill2.skill2SpreadCount++;
            }
            if (skill2.skill2Count > 60) {
                skill2.skill2BombSpriteCount++;
                if (skill2.skill2BombSpriteCount >= 7)
                    skill2.skill2BombSpriteCount = 0;
                //if (hero.status == 0 && life > 0) {//배찌가 살아있을 때
                //    for (int i = 0; i < 4; i++) {
                //        if (hero.heroY + 40 > skill2.skill2Ypos[i] + 50 && hero.heroY + 40 < skill2.skill2Ypos[i] + 90) {
                //            hero.life--;
                //            hero.status = 2;
                //            break;
                //        }
                //    }
                //}
            }
        }
        //스킬3
        if (skill3.skill3Toggle == 1) {
            skill3.skill3Count++;
            skill3.skill3BombSpriteCount++;
            if (skill3.skill3BombSpriteCount == 7)
                skill3.skill3BombSpriteCount = 0;
            if (skill3.skill3Count == 1) {
                for (int i = 0; i < 20; i++) {
                    skill3.skill3Xpos[i] = xPos - (230 - ((i) * 30));
                    skill3.skill3Ypos[i] = 0;
                }
            }
            //if (skill3.skill3Count > 24) {
            //    if (hero.status == 0 && life > 0) {//배찌가 살아있을 때
            //        if (hero.heroX > skill3.skill3Xpos[0] + 40 && hero.heroX < skill3.skill3Xpos[19] + 30
            //            && hero.heroY< ((skill3.skill3Count - 24) * 50) + 80 && hero.heroY>((skill3.skill3Count - 24) * 50) - 100) {
            //            hero.life--;
            //            hero.status = 2;
            //        }
            //    }
            //}

            if (skill3.skill3Count >= 50) {
                skill3.skill3SpriteCount = 0;
                skill3.skill3Toggle = 0;
                skill3.skill3Count = 0;
                skill3.skill3SpreadCount = 0;
                skill3.skill3BombSpriteCount = 0;
            }
        }

        //스킬 4
        if (skill4.skill4Toggle == 1) { //스킬 시전 시 최초 한번 발동
            int madeMonsterCount = 0;
            for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                if (skill4.mon[i].status == 0) {
                    madeMonsterCount++;
                    if (madeMonsterCount > 5) //다섯 마리 만들면 끝
                        break;
                    skill4.mon[i].status = 1;
                    skill4.mon[i].xPos = (rand() % (MAP_ROW - 200)) + 100;
                    skill4.mon[i].yPos = (rand() % (MAP_COL - 300)) + 250;
                    skill4.mon[i].life = 1;
                    skill4.mon[i].direction = (rand() % 4) + 1;
                    skill4.mon[i].count = 0;
                    skill4.mon[i].eggSpriteCount = 0;
                    skill4.mon[i].monSpriteCount = 0;
                }
            }
            skill4.skill4Toggle = 0;
        }
        for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
            if (skill4.mon[i].status == 1) { //필드위에 있는 몬스터들
                skill4.mon[i].count++;
                if (skill4.mon[i].count != 0 && skill4.mon[i].count % 5 == 0 && skill4.mon[i].count <= 35) {
                    if (skill4.mon[i].eggSpriteCount < 7) //달걀 애니메이션 카운트
                        skill4.mon[i].eggSpriteCount++;
                }
                if (skill4.mon[i].count > 35) { //달걀 부화 후
                    skill4.mon[i].monSpriteCount++;
                    if (skill4.mon[i].monSpriteCount >= 4)
                        skill4.mon[i].monSpriteCount = 0;
                    if (skill4.mon[i].direction == LEFT) {
                        skill4.mon[i].xPos -= 5;
                    }
                    else if (skill4.mon[i].direction == RIGHT) {
                        skill4.mon[i].xPos += 5;
                    }
                    else if (skill4.mon[i].direction == UP) {
                        skill4.mon[i].yPos -= 5;
                    }
                    else if (skill4.mon[i].direction == DOWN) {
                        skill4.mon[i].yPos += 5;
                    }
                    //벽 충돌시 방향 전환
                    if (skill4.mon[i].xPos < 0) skill4.mon[i].direction = RIGHT;
                    else if (skill4.mon[i].xPos + 100 > MAP_ROW) skill4.mon[i].direction = LEFT;
                    else if (skill4.mon[i].yPos < 135) skill4.mon[i].direction = DOWN; //보스 아래로만 움직임
                    else if (skill4.mon[i].yPos + 100 > MAP_COL) skill4.mon[i].direction = UP;
                    //랜덤 방향 전환
                    if (skill4.mon[i].count % 20 == 0) {
                        skill4.mon[i].direction = (rand() % 4) + 1;
                    }
                    if (skill4.mon[i].life <= 0) {
                        skill4.mon[i].status = 2;
                        skill4.mon[i].dieCount = 30;
                    }
                }
            }
            else if (skill4.mon[i].status == 2) { //죽는 중
                skill4.mon[i].dieCount--;
                if (skill4.mon[i].dieCount == 0) {
                    skill4.mon[i].status = 0;
                    skill4.mon[i].xPos = -200;
                    skill4.mon[i].yPos = -200;
                }
            }
        }
    }
}
