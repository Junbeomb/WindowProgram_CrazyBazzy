#pragma once

#include <windows.h>
#include <cmath>
#include <time.h>
#include <iostream>
#include <vector>

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

using namespace std;
