#pragma once

#include <windows.h>
#include <cmath>
#include <time.h>
#include <iostream>
#include <vector>

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

using namespace std;
