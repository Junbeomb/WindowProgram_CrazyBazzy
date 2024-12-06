#pragma once
#include "globals.h"

class Boss
{

    typedef struct {
        int X, Y;
        int status;
        int life;
        int direction;
        int count;
        int eggSpriteCount;
        int monSpriteCount;
        int dieCount;
    }SKILL4MONSTER;


    int xPos, yPos;
    int direction;
    int life;
    int status;
    int count;
    int spriteCount;
    int skillMotionSpriteCount;

    bool shouldDraw{ false };

    int bossrdCount{};

public:
    //void DrawBoss(HDC, Sprite);
    //void DrawBossSkill4(HDC, Sprite);
    //void DrawBossSkill3(HDC, Sprite);
    //void DrawBossSkill2(HDC, Sprite);
    //void DrawBossSkill1(HDC, Sprite);

    //void BossAlgorithm();

public:
    typedef struct {
        int skill1Toggle;
        int skill1Count;
        int skill1SpriteCount;
        int skill1DeadSpriteCount;
        int skill1Xpos, skill1Ypos;
        int skill1Direction;
        int skill1DeadCount;

        int skill2Toggle;
        int skill2Count;
        int skill2SpriteCount;
        int skill2Xpos[4], skill2Ypos[4];
        int skill2SpreadCount;
        int skill2BombSpriteCount;

        int skill3Toggle;
        int skill3Count;
        int skill3SpriteCount;
        int skill3Xpos[20], skill3Ypos[20];
        int skill3SpreadCount;
        int skill3BombSpriteCount;

        int skill4Toggle;
        int skill4Count;
        SKILL4MONSTER mon[BOSS_MONSTER_MAX];
    }BOSSSKILL;//보스 스킬


    BOSSSKILL skill1[SKILL1NUMBER];
    BOSSSKILL skill2;
    BOSSSKILL skill3;
    BOSSSKILL skill4;

    int GetLife() const { return life; }
    void SetLife(int value) { life = value; life = max(life, 0); }

    int GetxPos() const { return xPos; }
    void SetxPos(int x) { xPos = x; }
    int GetyPos() const { return yPos; }
    void SetyPos(int y) { yPos = y; }

    int GetDirection() const { return direction; }
    void SetDirection(int d) { direction = d; }

    int GetStatus() const { return status; }
    void SetStatus(int s) { status = s; }

    int GetCount() const { return count; }
    void SetCount(int c) { count = c; }

    int GetSpriteCount() const { return spriteCount; }
    void SetSpriteCount(int sC) { spriteCount = sC; }

    int GetSkillMotionSpriteCount() const { return skillMotionSpriteCount; }
    void SetSkillMotionSpriteCount(int sM) { skillMotionSpriteCount = sM; }

    bool GetShouldDraw() const { return shouldDraw; }
    void SetShouldDraw(bool sD) { shouldDraw= sD; }
};

