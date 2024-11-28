#pragma once
#include "globals.h"

class Hero
{



    typedef struct {
        int count;
        int toggle;
        int coolTime;
        //BUBBLE bubble[20];
    }SKILL;

    int life{};//목숨
    int speed{};//캐릭터의 속도
    int resurrectionCount{};//부활 애니메이션
    int bubbleSpeed;

    //BUBBLE bubble[BUBBLE_MAX];//물풍선

    HBITMAP sprite;

public:

    SKILL skillX{};
    SKILL skillZ{};
    void SetSprite(const HBITMAP& s) { sprite = s; }
    void SetSpeed(int s) { speed = s; }
    void SetBubbleSpeed(int s) { bubbleSpeed = s; }

    int heroX{}, heroY{};//캐릭터 좌표
    int direction{};//보고 있는 방향
    int status{};//상태 표시용 변수(살아있음, 물풍선 갇힘, 죽음)
    int spriteCount{};//애니메이션용 카운트
    int dieCount{};//죽었을때 애니메이션
    int dashCount{};//대쉬 카운트
    int dashCoolTime{};//대쉬 쿨탐
    

	void DrawHero(HDC hDC);

};

