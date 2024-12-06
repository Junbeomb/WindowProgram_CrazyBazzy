#pragma once
#include "globals.h"

class Sprite
{
    HINSTANCE g_hinst;
public:

    HBITMAP cursor = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/cursor.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP map0 = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/stage0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP map1 = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/stage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP map2 = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/stage2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP bossMap = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/bossstage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP items = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/item.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));

    //object
    HBITMAP tree = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/tree.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP redBlock = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/block_red.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP yellowBlock = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/block_orange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP redHouse = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/house_red.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP yellowHouse = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/house_yellow.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP blueHouse = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/house_blue.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP heart = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/heart.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP lose = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/Lose.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP bubble = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/bubble.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP bubbleBomb = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/bubblebomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP heroSkillIcon = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/heroSkillIcon.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP heroSkillIconDark = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/heroSkillIconDark.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP number = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/number.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP win = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));

    //monster
    HBITMAP monImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/ms1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    //hero
    HBITMAP bazziSprite = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/bazzi.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP daoSprite = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/dao.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP uniSprite = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/uni.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP digenieSprite = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/digenie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    
    //boss
    HBITMAP bossImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/boss.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP bossDie = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/bossDie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP skill2CircleImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/skill2Circle.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP skill2SnowBombImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/skill2SnowBomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP snowBallBombImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/snowBallBomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP snowBallImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/snowBall.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP snowSignImage = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/snowSign.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP skill4Egg = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/egg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
    HBITMAP skill4Monster = static_cast<HBITMAP>(LoadImage(g_hinst, TEXT("BMP/skill4monster.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));

    void SetgInst(HINSTANCE& h) { g_hinst = h; };

};

