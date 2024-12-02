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
    int bubbleSpeed;

    //BUBBLE bubble[BUBBLE_MAX];//��ǳ��

    HBITMAP sprite;

public:

    SKILL skillX{};
    SKILL skillZ{};
    void SetSprite(const HBITMAP& s) { sprite = s; }
    int GetSpeed() { return speed; }
    void SetSpeed(int s) { speed = s; }
    int GetBubbleSpeed() { return bubbleSpeed; }
    void SetBubbleSpeed(int s) { bubbleSpeed = s; }
    int GetLife() { return life; }
    void SetLife(int l) { life = l; }


    int heroX{}, heroY{};//ĳ���� ��ǥ
    int beforeX{}, beforeY{}; //���� ������ ��ġ

    int direction{};//���� �ִ� ����
    int status{};//���� ǥ�ÿ� ����(�������, ��ǳ�� ����, ����)
    int spriteCount{};//�ִϸ��̼ǿ� ī��Ʈ
    int dieCount{};//�׾����� �ִϸ��̼�
    int dashCount{};//�뽬 ī��Ʈ
    int dashCoolTime{};//�뽬 ��Ž
    int resurrectionCount{};//��Ȱ �ִϸ��̼�
    

	void DrawHero(HDC hDC);

};

