#pragma once
#include <windows.h>
#include<cmath>
#include<time.h>
#pragma comment(lib,"msimg32.lib")

//����
#define DEFAULT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
//����
#define ALIVE 0

//ĳ����
#define BAZZI 1
#define DAO 2
#define UNI 3
#define DIGENIE 4
#define BUBBLE_MAX 10
#define SKILL1NUMBER 10
//�ð�
#define main 1
//����
#define HeroWidth 50
#define HeroHeight 60
#define BoardWidth 40
#define HalfBoardWidth 20
//������Ʈ
#define TREE 1
#define HOUSE1 2
#define HOUSE2 3
#define HOUSE3 4
#define BLOCK1 5
#define BLOCK2 6
//������
#define SPEED 1
#define BALLOON 2
#define POTION 3
#define MAXPOTION 4
//�� ũ��
#define MAP_ROW 1160
#define MAP_COL 760
//���� ��ų�� ����
#define LEFT_DOWN 5
#define RIGHT_DOWN 6
#define LEFT_UP 7
#define RIGHT_UP 8
//���� �׸� �׸���
#define BOSS_WIDTH 250
#define BOSS_HEIGHT 250
//���� ��ų4 ���� �ִ�
#define BOSS_MONSTER_MAX 15

#define MONSTEROFNUMBER 10


static int heroSelected;
static int currentStage;
static int diecount;


typedef struct item
{
    int x{}, y{};
    int type{};//�̼� ��ǳ�� ���ٱ�
    bool shouldDraw{ false };
}ITEM;

typedef struct bubble {
    int xPos, yPos;
    int direction;
    int dieCount;
    int bigBubble;
    int status;
}BUBBLE;

typedef struct {
    int count;
    int toggle;
    int coolTime;
    BUBBLE bubble[20];
}SKILL;

typedef struct {
    int xPos, yPos;
    int status;
    int life;
    int direction;
    int count;
    int eggSpriteCount;
    int monSpriteCount;
    int dieCount;
}SKILL4MONSTER;

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
}BOSSSKILL;//���� ��ų

typedef struct {
    int xPos, yPos;
    int direction;
    int life;
    int status;
    int count;
    int spriteCount;
    int skillMotionSpriteCount;
    bool shouldDraw;
    BOSSSKILL skill1[SKILL1NUMBER];
    BOSSSKILL skill2;
    BOSSSKILL skill3;
    BOSSSKILL skill4;
}BOSS;

typedef struct object
{
    int type;//���� ����(���̳� ����, ���)
    int x, y;
    bool shouldDraw;
}OBJECT;

typedef struct objectSprite
{
    HBITMAP tree;
    HBITMAP redBlock;
    HBITMAP yellowBlock;
    HBITMAP redHouse;
    HBITMAP yellowHouse;
    HBITMAP blueHouse;
    HBITMAP heart;
    HBITMAP lose;
    HBITMAP bubble;
    HBITMAP bubbleBomb;
    HBITMAP heroSkillIcon;
    HBITMAP heroSkillIconDark;
    HBITMAP number;
    HBITMAP win;
}OBJSPRITE;

typedef struct hero
{
    int heroX{}, heroY{};//ĳ���� ��ǥ
    int direction{};//���� �ִ� ����
    int life{};//���
    int status{};//���� ǥ�ÿ� ����(�������, ��ǳ�� ����, ����)
    int speed{};//ĳ������ �ӵ�
    int spriteCount{};//�ִϸ��̼ǿ� ī��Ʈ
    int dieCount{};//�׾����� �ִϸ��̼�
    int resurrectionCount{};//��Ȱ �ִϸ��̼�
    int dashCount{};//�뽬 ī��Ʈ
    int dashCoolTime{};//�뽬 ��Ž
    int bubbleSpeed;
    BUBBLE bubble[BUBBLE_MAX];//��ǳ��
    SKILL skillX{};
    SKILL skillZ{};
    HBITMAP heroSprite{};

}HERO;

typedef struct bossSprite
{
    HBITMAP bossImage;
    HBITMAP snowBallImage;
    HBITMAP snowSignImage;
    HBITMAP snowBallBombImage;
    HBITMAP skill2CircleImage;
    HBITMAP skill2SnowBombImage;
    HBITMAP skill4Egg;
    HBITMAP skill4Monster;
    HBITMAP bossDie;
}BOSSSPRITE;

typedef struct Monster {
    int xPos, yPos;
    int direction;
    int status;
    int life;
    int locatecount;
    int anicount;
}MONSTER;

typedef struct {
    HBITMAP monImage;
}MONSPRITE;


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lPARAM);

