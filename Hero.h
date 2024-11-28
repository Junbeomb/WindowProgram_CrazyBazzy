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

    int life{};//���
    int speed{};//ĳ������ �ӵ�
    int resurrectionCount{};//��Ȱ �ִϸ��̼�
    int bubbleSpeed;

    //BUBBLE bubble[BUBBLE_MAX];//��ǳ��

    HBITMAP sprite;

public:

    SKILL skillX{};
    SKILL skillZ{};
    void SetSprite(const HBITMAP& s) { sprite = s; }
    void SetSpeed(int s) { speed = s; }
    void SetBubbleSpeed(int s) { bubbleSpeed = s; }

    int heroX{}, heroY{};//ĳ���� ��ǥ
    int direction{};//���� �ִ� ����
    int status{};//���� ǥ�ÿ� ����(�������, ��ǳ�� ����, ����)
    int spriteCount{};//�ִϸ��̼ǿ� ī��Ʈ
    int dieCount{};//�׾����� �ִϸ��̼�
    int dashCount{};//�뽬 ī��Ʈ
    int dashCoolTime{};//�뽬 ��Ž
    

	void DrawHero(HDC hDC);

};

