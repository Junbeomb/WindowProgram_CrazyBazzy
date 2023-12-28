#pragma once
#include <windows.h>
#include<cmath>
#include<time.h>
#pragma comment(lib,"msimg32.lib")

//방향
#define DEFAULT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
//상태
#define ALIVE 0

//캐릭터
#define BAZZI 1
#define DAO 2
#define UNI 3
#define DIGENIE 4
#define BUBBLE_MAX 10
#define SKILL1NUMBER 10
//시간
#define main 1
//길이
#define HeroWidth 50
#define HeroHeight 60
#define BoardWidth 40
#define HalfBoardWidth 20
//오브젝트
#define TREE 1
#define HOUSE1 2
#define HOUSE2 3
#define HOUSE3 4
#define BLOCK1 5
#define BLOCK2 6
//아이템
#define SPEED 1
#define BALLOON 2
#define POTION 3
#define MAXPOTION 4
//맵 크기
#define MAP_ROW 1160
#define MAP_COL 760
//보스 스킬용 방향
#define LEFT_DOWN 5
#define RIGHT_DOWN 6
#define LEFT_UP 7
#define RIGHT_UP 8
//보스 그림 그릴때
#define BOSS_WIDTH 250
#define BOSS_HEIGHT 250
//보스 스킬4 몬스터 최대
#define BOSS_MONSTER_MAX 15

#define MONSTEROFNUMBER 10


static int heroSelected;
static int currentStage;
static int diecount;


typedef struct item
{
    int x{}, y{};
    int type{};//이속 물풍선 물줄기
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
}BOSSSKILL;//보스 스킬

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
    int type;//옵젝 종류(집이나 나무, 블록)
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
    int heroX{}, heroY{};//캐릭터 좌표
    int direction{};//보고 있는 방향
    int life{};//목숨
    int status{};//상태 표시용 변수(살아있음, 물풍선 갇힘, 디짐)
    int speed{};//캐릭터의 속도
    int spriteCount{};//애니메이션용 카운트
    int dieCount{};//죽었을때 애니메이션
    int resurrectionCount{};//부활 애니메이션
    int dashCount{};//대쉬 카운트
    int dashCoolTime{};//대쉬 쿨탐
    int bubbleSpeed;
    BUBBLE bubble[BUBBLE_MAX];//물풍선
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

