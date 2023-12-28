#include "Widget.h"
#include "Hero.h"
#include "Object.h"
#include "Boss.h"
#include "MonsterClass.h"

Widget widgetH;
Hero heroH;
Object objectH;
Boss bossH;
MonsterClass monsterH;

HINSTANCE g_hinst;
LPCTSTR lpszClass = L"windows_program1";
LPCTSTR lpszWindowName = L"Crazzy Bazzy";


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE  hPrevInstance, LPSTR IpszCMDParam, int nCmdShow) {
    HWND hWnd;
    MSG Message;
    WNDCLASSEX WndClass;
    g_hinst = hInstance;

    WndClass.cbSize = sizeof(WndClass);
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = lpszClass;
    WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassEx(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, 1180, 800, NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
    srand(time(NULL));
    PAINTSTRUCT ps;
    HDC hDC;
    HBRUSH hBrush, oldBrush;
    //기본
    static HDC memDC, tempDC;
    static HBITMAP hBitmap, oldBitmap;
    static RECT rectView;
    static HBITMAP map0,map1,map2,bossMap,cursor;
    static POINT cur;
    //주인공
    static HERO hero;
    static HBITMAP heroSprite;
    static int reduceCount;
    static int bubbleCount;

    //스테이지용
    static OBJECT object[150];
    static OBJSPRITE os;
    static int objCount;
    static ITEM item[100];
    static int itemCount;
    static HBITMAP items;
    static bool itemUPDOWN;

    //보스용 변수
    static BOSS snowBoss;
    static BOSSSPRITE bs;
    static int bossrdCount;

    static HBITMAP monsterSprite;
    static MONSTER monster[MONSTEROFNUMBER];
    static MONSPRITE ms, ms2;
    static int stageChangeCount;

    switch (iMsg) {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
 
        ShowCursor(false);
        SetTimer(hWnd, main, 10, NULL);
        currentStage = 0;
        hero.heroSprite = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bazzi.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        hero.speed = 1;
        heroSelected = BAZZI;
        

        cursor = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/cursor.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        map0 = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/stage0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        map1 = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/stage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        map2 = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/stage2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bossMap = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bossstage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        items = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/item.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


        ms.monImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/ms1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        ms2.monImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/ms1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        os.tree = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/tree.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.redBlock = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/block_red.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.yellowBlock = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/block_orange.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.redHouse = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/house_red.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.yellowHouse = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/house_yellow.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.blueHouse = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/house_blue.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.heart = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/heart.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.lose = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/Lose.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.bubble = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bubble.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.bubbleBomb = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bubblebomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.heroSkillIcon = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/heroSkillIcon.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.heroSkillIconDark = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/heroSkillIconDark.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.number = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/number.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        os.win = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/win.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        bs.bossDie = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bossDie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.bossImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/boss.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.skill2CircleImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/skill2Circle.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.skill2SnowBombImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/skill2SnowBomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.snowBallBombImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/snowBallBomb.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.snowBallImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/snowBall.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.snowSignImage = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/snowSign.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.skill4Egg = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/egg.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        bs.skill4Monster = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/skill4monster.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

        break;
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        memDC = CreateCompatibleDC(hDC);
        tempDC = CreateCompatibleDC(memDC);
        hBitmap = CreateCompatibleBitmap(hDC, rectView.right, rectView.bottom);
        oldBitmap = (HBITMAP)SelectObject(memDC, hBitmap);
        //그리기 시작
        switch (currentStage)
        {
        case 0:
            objectH.DrawBoard(memDC, map0);
            break;
        case 1:
            objectH.DrawBoard(memDC, map1);
            objectH.DrawObjectUP(memDC, object, os, hero);
            for (int i = 0; i < MONSTEROFNUMBER - 2; i++) { 
                monsterH.DrawMonster(memDC, monster[i], ms);
            }
            heroH.DrawHero(memDC, hero);
            objectH.DrawObjectDOWN(memDC, object, os, hero);
            objectH.DrawItem(memDC, item, items);
            heroH.DrawBubble(memDC, hero, os);
            widgetH.DrawHeart(memDC, hero, snowBoss, os);
            break;
        case 2:
            objectH.DrawBoard(memDC, map2);
            objectH.DrawObjectUP(memDC, object, os, hero);
            for (int i = 0; i < MONSTEROFNUMBER; i++) { 
                monsterH.DrawMonster(memDC, monster[i], ms2);
            }
            heroH.DrawHero(memDC, hero);
            objectH.DrawObjectDOWN(memDC, object, os, hero);
            objectH.DrawItem(memDC, item, items);
            heroH.DrawBubble(memDC, hero, os);
            widgetH.DrawHeart(memDC, hero, snowBoss, os);
            break;
        case 3:
            objectH.DrawBoard(memDC, bossMap);
            bossH.DrawBossSkill3(memDC, snowBoss, bs);
            bossH.DrawBoss(memDC, snowBoss, bs);
            bossH.DrawBossSkill2(memDC, snowBoss, bs);
            bossH.DrawBossSkill4(memDC, snowBoss, bs);
            heroH.DrawHero(memDC, hero);
            bossH.DrawBossSkill1(memDC, snowBoss, bs);
            RoundRect(memDC, 8, 8, 1132, 32, 5, 5);
            hBrush = CreateSolidBrush(RGB(255, 0, 0));
            oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
            RoundRect(memDC, 10, 10, 10 + snowBoss.life * 28, 30, 5, 5);
            SelectObject(memDC, oldBrush);
            DeleteObject(hBrush);
            DeleteObject(oldBrush);
            objectH.DrawItem(memDC, item, items);
            heroH.DrawBubble(memDC, hero, os);
            widgetH.DrawHeart(memDC, hero, snowBoss, os);

            widgetH.DrawSkillIcon(memDC, hero, os);

            break;
        default:
            break;
        }
        

        widgetH.DrawCursor(memDC, cur, cursor);
        BitBlt(hDC, 0, 0, rectView.right, rectView.bottom, memDC, 0, 0, SRCCOPY);
        SelectObject(memDC, oldBitmap);
        DeleteObject(memDC);
        DeleteObject(hBitmap);
        DeleteObject(oldBitmap);
        EndPaint(hWnd, &ps);

        break;
    case WM_TIMER:
        //애니메이션용
        if (hero.status == 0 || hero.status == 10) {
            if (hero.dashCoolTime > 0)
                hero.dashCoolTime--;
            reduceCount++;
            if (reduceCount == 25)
            {
                hero.spriteCount++;
                if (hero.spriteCount == 4)hero.spriteCount = 0;
                reduceCount = 0;
                if (itemUPDOWN)
                {
                    for (int i = 0; i < 100; i++)
                    {
                        item[i].y++;
                    }
                    itemUPDOWN = false;
                }
                else
                {
                    for (int i = 0; i < 100; i++)
                    {
                        item[i].y--;
                    }
                    itemUPDOWN = true;
                }
            }

            //보스랑 히어로 충돌
            if (sqrt(pow((hero.heroX - (snowBoss.xPos + 125)), 2) + pow(((hero.heroY) - (snowBoss.yPos + 125)), 2)) < 130 && snowBoss.life > 0) {
                hero.life--;
                hero.status = 2;
            }
            //skill4몬스터랑 히어로 충돌
            for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                if (snowBoss.skill4.mon[i].status == 1 && snowBoss.skill4.mon[i].count > 35) {
                    if (sqrt(pow((hero.heroX - (snowBoss.skill4.mon[i].xPos + 50)), 2) + pow(((hero.heroY) - (snowBoss.skill4.mon[i].yPos + 50)), 2)) < 40 && snowBoss.life > 0) {
                        hero.life--;
                        hero.status = 2;
                        break;
                    }
                }
            }
            if (sqrt(pow((hero.heroX - (snowBoss.xPos + 125)), 2) + pow(((hero.heroY) - (snowBoss.yPos + 125)), 2)) < 130 && snowBoss.life > 0) {
                hero.life--;
                hero.status = 2;
            }
            //방향키 및 오브젝트 충돌처리
            if (hero.status != 10) {//대쉬가 아닐때만
                if (GetAsyncKeyState(VK_UP))
                {
                    hero.direction = UP;
                    hero.heroY -= hero.speed;
                    for (int i = 0; i < 150; i++)
                    {
                        if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                        {
                            hero.heroY += hero.speed;

                            if (hero.heroX < object[i].x + 20)hero.heroX -= 2;
                            else hero.heroX += 2;
                        }
                    }
                }
                else if (GetAsyncKeyState(VK_LEFT))
                {
                    hero.direction = LEFT;
                    hero.heroX -= hero.speed;
                    for (int i = 0; i < 150; i++)
                    {
                        if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                        {
                            hero.heroX += hero.speed;
                            if (hero.heroY < object[i].y + 20)hero.heroY -= 2;
                            else hero.heroY += 2;
                        }
                    }
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    hero.direction = DOWN;
                    hero.heroY += hero.speed;
                    for (int i = 0; i < 150; i++)
                    {
                        if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                        {
                            hero.heroY -= hero.speed;
                            if (hero.heroX < object[i].x + 20)hero.heroX -= 2;
                            else hero.heroX += 2;
                        }
                    }
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    hero.direction = RIGHT;
                    hero.heroX += hero.speed;
                    for (int i = 0; i < 150; i++)
                    {
                        if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                        {
                            hero.heroX -= hero.speed;
                            if (hero.heroY < object[i].y + 20)hero.heroY -= 2;
                            else hero.heroY += 2;
                        }
                    }
                }
            }
            else if (hero.status == 10) {
                hero.dashCount--;
                if (hero.dashCount == 0) {
                    hero.status = 0;
                    hero.dashCoolTime = 30;
                }
                if (hero.direction == LEFT) {
                    hero.heroX -= 10;
                }
                else if (hero.direction == RIGHT) {
                    hero.heroX += 10;
                }
                else if (hero.direction == UP) {
                    hero.heroY -= 10;
                }
                else if (hero.direction == DOWN) {
                    hero.heroY += 10;
                }
            }
            //X공격
            if (GetAsyncKeyState(0x58) && currentStage==3) {//'x'
                if (hero.skillX.coolTime == 0) {
                    if (hero.skillX.count < 800)
                        hero.skillX.count += 4;
                    hero.skillX.toggle = 1;
                }
            }
            if (GetAsyncKeyState(0x43)) {//'c'
                if (hero.dashCount == 0 && hero.dashCoolTime == 0) {
                    hero.status = 10; //대쉬
                    hero.dashCount = 8;
                }
            }

        }
        else if (hero.status == 2) {
            if (hero.life == 0) { //게임 끝

            }
            else {
                hero.dieCount++;
                if (hero.dieCount >= 100)hero.status = 3;
            }
        }
        else if (hero.status == 3) {
            hero.resurrectionCount++;
            if (GetAsyncKeyState(VK_UP))
            {
                hero.direction = UP;
                hero.heroY -= hero.speed;
                for (int i = 0; i < 150; i++)
                {
                    if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                    {
                        hero.heroY += hero.speed;

                        if (hero.heroX < object[i].x + 20)hero.heroX -= 2;
                        else hero.heroX += 2;
                    }
                }
            }
            else if (GetAsyncKeyState(VK_LEFT))
            {
                hero.direction = LEFT;
                hero.heroX -= hero.speed;
                for (int i = 0; i < 150; i++)
                {
                    if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                    {
                        hero.heroX += hero.speed;
                        if (hero.heroY < object[i].y + 20)hero.heroY -= 2;
                        else hero.heroY += 2;
                    }
                }
            }
            else if (GetAsyncKeyState(VK_DOWN))
            {
                hero.direction = DOWN;
                hero.heroY += hero.speed;
                for (int i = 0; i < 150; i++)
                {
                    if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                    {
                        hero.heroY -= hero.speed;
                        if (hero.heroX < object[i].x + 20)hero.heroX -= 2;
                        else hero.heroX += 2;
                    }
                }
            }
            else if (GetAsyncKeyState(VK_RIGHT))
            {
                hero.direction = RIGHT;
                hero.heroX += hero.speed;
                for (int i = 0; i < 150; i++)
                {
                    if (object[i].x<hero.heroX + 18 && object[i].y<hero.heroY + 18 && object[i].x + 40>hero.heroX - 18 && object[i].y + 40>hero.heroY - 18 && object[i].shouldDraw)
                    {
                        hero.heroX -= hero.speed;
                        if (hero.heroY < object[i].y + 20)hero.heroY -= 2;
                        else hero.heroY += 2;
                    }
                }
            }
            if (hero.resurrectionCount > 100) {
                hero.status = 0;
                hero.dieCount = 0;
                hero.resurrectionCount = 0;
            }
        }

        for (int i = 0; i < bubbleCount; i++) { //주인공 일반 공격
            if (hero.bubble[i].status == 1) {
                if (hero.bubble[i].direction == LEFT) {
                    if(hero.bubble[i].bigBubble== -100)
                        hero.bubble[i].xPos -= 5+(5*hero.bubbleSpeed);
                    else
                        hero.bubble[i].xPos -= 10;

                }
                else if (hero.bubble[i].direction == RIGHT) {
                    if (hero.bubble[i].bigBubble == -100)
                        hero.bubble[i].xPos += 5 + (5 * hero.bubbleSpeed);
                    else
                        hero.bubble[i].xPos += 10;
                }
                else if (hero.bubble[i].direction == UP) {
                    if (hero.bubble[i].bigBubble == -100)
                        hero.bubble[i].yPos -= 5 + (5 * hero.bubbleSpeed);
                    else
                        hero.bubble[i].yPos -= 10;
                }
                else if (hero.bubble[i].direction == DOWN) {
                    if (hero.bubble[i].bigBubble == -100)
                        hero.bubble[i].yPos += 5 + (5 * hero.bubbleSpeed);
                    else
                        hero.bubble[i].yPos += 10;
                }

                if (hero.bubble[i].xPos > snowBoss.xPos && hero.bubble[i].xPos < snowBoss.xPos + BOSS_WIDTH && hero.bubble[i].yPos + 25 > snowBoss.yPos && hero.bubble[i].yPos + 25 < snowBoss.yPos + BOSS_HEIGHT && currentStage == 3) {
                    hero.bubble[i].status = 2; //bubble 터지는 중
                    hero.bubble[i].dieCount = 30;
                    if (snowBoss.life > 0 && hero.bubble[i].bigBubble != 1)snowBoss.life--;
                    else if (snowBoss.life > 0 && hero.bubble[i].bigBubble == 1 && snowBoss.life > 5)snowBoss.life -= 5;
                    else if (snowBoss.life > 0 && hero.bubble[i].bigBubble == 1 && snowBoss.life > 0)snowBoss.life = 0;
                }
                for (int j = 0; j < BOSS_MONSTER_MAX; j++) { //skill4monster 충돌
                    if (snowBoss.skill4.mon[j].status == 1 && snowBoss.skill4.mon[j].count>35) { 
                        if (hero.bubble[i].bigBubble == -100 && hero.bubble[i].xPos > snowBoss.skill4.mon[j].xPos && hero.bubble[i].xPos < snowBoss.skill4.mon[j].xPos + 100 && hero.bubble[i].yPos - 15 > snowBoss.skill4.mon[j].yPos && hero.bubble[i].yPos - 15 < snowBoss.skill4.mon[j].yPos + 100) {
                            hero.bubble[i].status = 2;
                            hero.bubble[i].dieCount = 30;
                            snowBoss.skill4.mon[j].life--;
                            break;
                        }
                        else if (hero.bubble[i].bigBubble == 1 && hero.bubble[i].xPos > snowBoss.skill4.mon[j].xPos && hero.bubble[i].xPos < snowBoss.skill4.mon[j].xPos + 100 && hero.bubble[i].yPos - 15 > snowBoss.skill4.mon[j].yPos && hero.bubble[i].yPos - 15 < snowBoss.skill4.mon[j].yPos + 100) {
                            snowBoss.skill4.mon[j].life--;
                            break;
                        }
                    }
                }
                for (int j = 0; j < MONSTEROFNUMBER; j++) { 
                    if (monster[j].status == 0) {
                        if (hero.bubble[i].xPos < monster[j].xPos + 50 && hero.bubble[i].xPos > monster[j].xPos && hero.bubble[i].yPos < monster[j].yPos + 60 && hero.bubble[i].yPos > monster[j].yPos && hero.bubble[i].status == 1) {
                            hero.bubble[i].status = 2; //bubble 터지는 중
                            hero.bubble[i].dieCount = 30;
                            monster[j].life--;
                            if (monster[j].life == 0)
                                diecount++;
                        }
                    }
                }

                if (hero.bubble[i].xPos < 0 || hero.bubble[i].xPos> MAP_ROW || hero.bubble[i].yPos < 0 || hero.bubble[i].yPos > MAP_COL) { //맵 밖으로 나가면
                    hero.bubble[i].xPos = -100;
                    hero.bubble[i].yPos = -100;
                    hero.bubble[i].status = -100;
                    hero.bubble[i].bigBubble = -100;
                }
                for (int j = 0; j < 150; j++)
                {
                    if (object[j].x<hero.bubble[i].xPos + 5 && object[j].y<hero.bubble[i].yPos + 5 && object[j].x + 40>hero.bubble[i].xPos - 5 && object[j].y + 40>hero.bubble[i].yPos - 5 && object[j].shouldDraw)
                    {
                        hero.bubble[i].status = 2; //bubble 터지는 중
                        hero.bubble[i].dieCount = 30;
                        switch (object[j].type)
                        {
                        case BLOCK1:
                        case BLOCK2:
                            object[j].shouldDraw = false;
                            for (int k = 0; k < 100; k++)
                            {
                                if (!item[k].shouldDraw)
                                {
                                    itemCount = k;
                                    break;
                                }
                            }
                            item[itemCount].shouldDraw = true;
                            item[itemCount].x = object[j].x;
                            item[itemCount].y = object[j].y;
                            item[itemCount].type = rand() % 4 + 1;

                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            else if (hero.bubble[i].status == 2) { //bubble 터지는 중
                hero.bubble[i].dieCount--;
                if (hero.bubble[i].dieCount == 0) {
                    hero.bubble[i].status = -100;
                    hero.bubble[i].bigBubble = -100;
                }
            }
        }

        if (hero.skillZ.toggle == 1) { //'z'
            if (hero.skillZ.coolTime == 10) {//쿨타임 10초일때 초기화
                hero.skillZ.toggle = 0;
            }
            for (int i = 0; i < 20; i++) {
                if (hero.skillZ.bubble[i].status == 1) {
                    if (hero.skillZ.bubble[i].direction == LEFT) {
                        hero.skillZ.bubble[i].xPos -= 10;
                    }
                    else if (hero.skillZ.bubble[i].direction == RIGHT) {
                        hero.skillZ.bubble[i].xPos += 10;
                    }
                    else if (hero.skillZ.bubble[i].direction == UP) {
                        hero.skillZ.bubble[i].yPos -= 10;
                    }
                    else if (hero.skillZ.bubble[i].direction == DOWN) {
                        hero.skillZ.bubble[i].yPos += 10;
                    }
                }
                else if (hero.skillZ.bubble[i].status == 2) { //터지는 중
                    hero.skillZ.bubble[i].dieCount--;
                    if (hero.skillZ.bubble[i].dieCount == 0) {
                        hero.skillZ.bubble[i].xPos = -100;
                        hero.skillZ.bubble[i].yPos = -100;
                        hero.skillZ.bubble[i].status = -100;
                    }
                }
                if (hero.skillZ.bubble[i].xPos < 0 || hero.skillZ.bubble[i].xPos> MAP_ROW || hero.skillZ.bubble[i].yPos < 0 || hero.skillZ.bubble[i].yPos > MAP_COL) { //맵 밖으로 나가면
                    hero.skillZ.bubble[i].xPos = -100;
                    hero.skillZ.bubble[i].yPos = -100;
                    hero.skillZ.bubble[i].status = -100;
                }
                if (hero.skillZ.bubble[i].status != 2 && sqrt(pow(hero.skillZ.bubble[i].xPos - (snowBoss.xPos + 125), 2) + pow(hero.skillZ.bubble[i].yPos - (snowBoss.yPos + 125), 2)) < 100) {
                    hero.skillZ.bubble[i].status = 2; //보스 충돌
                    hero.skillZ.bubble[i].dieCount = 30;
                    if(snowBoss.life>0)snowBoss.life--;
                }
                for (int j = 0; j < BOSS_MONSTER_MAX; j++) {
                    if (snowBoss.skill4.mon[j].status == 1 && snowBoss.skill4.mon[j].count > 30) {
                        if (hero.skillZ.bubble[i].status != 2 && sqrt(pow(hero.skillZ.bubble[i].xPos - (snowBoss.skill4.mon[j].xPos + 50), 2) + pow(hero.skillZ.bubble[i].yPos - (snowBoss.skill4.mon[j].yPos + 50), 2)) < 100) {
                            hero.skillZ.bubble[i].status = 2;
                            hero.skillZ.bubble[i].dieCount = 30;
                            snowBoss.skill4.mon[j].life--;
                            break;
                        }
                    }
                }
            }
        }

        if (hero.skillX.coolTime != 0) { //skillX 쿨타임 = 20 초
            hero.skillX.coolTime--;
        }
        if (hero.skillZ.coolTime != 0) { //skillZ 쿨타임 = 20 초
            hero.skillZ.coolTime--;
        }
        //보스
        if (currentStage == 3)
        {
            bossrdCount++;
            if (bossrdCount == 5)
            {
                if (snowBoss.shouldDraw) {
                    snowBoss.count++;
                    if (snowBoss.count == 60)snowBoss.count = 0;
                    //애니메이션 카운트
                    snowBoss.spriteCount++;
                    if (snowBoss.spriteCount > 5)
                        snowBoss.spriteCount = 0;

                    if (snowBoss.life > 0)
                    {

                        if (snowBoss.status == 0) { //스킬 미사용 시에만
                        //count30마다 방향 전환
                            if (snowBoss.count != 0 && snowBoss.count % 30 == 0) {
                                int directionRandom = rand() % 4;
                                if (directionRandom == 0 || directionRandom == 3)
                                    snowBoss.direction = DEFAULT;
                                else if (directionRandom == 1) {
                                    snowBoss.direction = LEFT;
                                }
                                else if (directionRandom == 2) {
                                    snowBoss.direction = RIGHT;
                                }
                            }
                            //방향
                            if (snowBoss.direction == LEFT) {
                                snowBoss.xPos -= 10;
                                if (snowBoss.xPos <= 0) {
                                    snowBoss.direction = RIGHT;
                                }
                            }
                            else if (snowBoss.direction == RIGHT) {
                                snowBoss.xPos += 10;
                                if (snowBoss.xPos + 250 >= MAP_ROW) {
                                    snowBoss.direction = LEFT;
                                }
                            }
                            //count10마다 스킬 사용
                            if (snowBoss.count != 0 && snowBoss.count % 10 == 0) {
                                int skillRandom = rand() % 6;
                                if (snowBoss.direction == LEFT || snowBoss.direction == RIGHT) {
                                    switch (skillRandom) {
                                    case 0: //스킬 미사용
                                    case 1:
                                    case 2:
                                        snowBoss.status = 0;
                                        break;
                                    case 3://스킬1
                                    case 4:
                                        for (int i = 0; i < SKILL1NUMBER; i++) {
                                            if (snowBoss.skill1[i].skill1Toggle == 0) {
                                                snowBoss.status = 1;
                                                snowBoss.skill1[i].skill1Toggle = 1;
                                                snowBoss.skill1[i].skill1Xpos = snowBoss.xPos;
                                                snowBoss.skill1[i].skill1Ypos = snowBoss.yPos;
                                                if (snowBoss.direction == LEFT)
                                                    snowBoss.skill1[i].skill1Direction = LEFT_DOWN;
                                                else if (snowBoss.direction == RIGHT)
                                                    snowBoss.skill1[i].skill1Direction = RIGHT_DOWN;
                                                break;
                                            }
                                        }
                                        break;
                                    case 5://스킬4
                                        snowBoss.status = 4;
                                        snowBoss.skill4.skill4Toggle = 1;
                                        break;
                                    }
                                }
                                else if (snowBoss.direction == DEFAULT) {
                                    skillRandom = rand() % 3;
                                    switch (skillRandom) {
                                    case 0: //스킬 미사용
                                        snowBoss.status = 0;
                                        break;
                                    case 1: //스킬 2
                                        if (snowBoss.skill2.skill2Toggle == 1) {
                                            snowBoss.status = 0;
                                        }
                                        else {
                                            snowBoss.status = 2;
                                            snowBoss.skill2.skill2Toggle = 1;
                                        }
                                        break;
                                    case 2: //스킬 3
                                        if (snowBoss.skill3.skill3Toggle == 1) {
                                            snowBoss.status = 0;
                                        }
                                        else {
                                            snowBoss.status = 3;
                                            snowBoss.skill3.skill3Toggle = 1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    //boss가 스킬 사용 중
                    if (snowBoss.status > 0) {
                        snowBoss.skillMotionSpriteCount++; //transparentblt 스킬 모션 카운트를 직접 움직이지는 않음
                        if (snowBoss.skillMotionSpriteCount >= 6) {
                            snowBoss.skillMotionSpriteCount = 0;
                            snowBoss.status = 0;
                        }
                    }

                    //스킬1
                    for (int i = 0; i < SKILL1NUMBER; i++) {
                        if (snowBoss.skill1[i].skill1Toggle == 1) {
                            snowBoss.skill1[i].skill1Count++;
                            snowBoss.skill1[i].skill1SpriteCount++;
                            if (snowBoss.skill1[i].skill1SpriteCount >= 7)
                                snowBoss.skill1[i].skill1SpriteCount = 0;

                            if (snowBoss.skill1[i].skill1Direction == LEFT_DOWN) {
                                snowBoss.skill1[i].skill1Xpos -= 20;
                                snowBoss.skill1[i].skill1Ypos += 20;
                                if (snowBoss.skill1[i].skill1Xpos + 30 < 0) {
                                    snowBoss.skill1[i].skill1Direction = RIGHT_DOWN;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                                else if (snowBoss.skill1[i].skill1Ypos + 220 > MAP_COL) {
                                    snowBoss.skill1[i].skill1Direction = LEFT_UP;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                            }
                            else if (snowBoss.skill1[i].skill1Direction == RIGHT_DOWN) {
                                snowBoss.skill1[i].skill1Xpos += 20;
                                snowBoss.skill1[i].skill1Ypos += 20;
                                if (snowBoss.skill1[i].skill1Xpos + 220 > MAP_ROW) {
                                    snowBoss.skill1[i].skill1Direction = LEFT_DOWN;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                                else if (snowBoss.skill1[i].skill1Ypos + 220 > MAP_COL) {
                                    snowBoss.skill1[i].skill1Direction = RIGHT_UP;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                            }
                            else if (snowBoss.skill1[i].skill1Direction == LEFT_UP) {
                                snowBoss.skill1[i].skill1Xpos -= 20;
                                snowBoss.skill1[i].skill1Ypos -= 20;
                                if (snowBoss.skill1[i].skill1Xpos + 30 < 0) {
                                    snowBoss.skill1[i].skill1Direction = RIGHT_UP;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                                else if (snowBoss.skill1[i].skill1Ypos + 30 < 0) {
                                    snowBoss.skill1[i].skill1Direction = LEFT_DOWN;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                            }
                            else if (snowBoss.skill1[i].skill1Direction == RIGHT_UP) {
                                snowBoss.skill1[i].skill1Xpos += 20;
                                snowBoss.skill1[i].skill1Ypos -= 20;
                                if (snowBoss.skill1[i].skill1Xpos + 220 > MAP_ROW) {
                                    snowBoss.skill1[i].skill1Direction = LEFT_UP;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                                else if (snowBoss.skill1[i].skill1Ypos + 30 < 0) {
                                    snowBoss.skill1[i].skill1Direction = RIGHT_DOWN;
                                    snowBoss.skill1[i].skill1DeadCount++;
                                }
                            }

                            if (snowBoss.skill1[i].skill1DeadCount >= 4) { //눈덩이 벽 네번 부딪쳐서 부서짐
                                snowBoss.skill1[i].skill1Toggle = 2;//부서지는 중
                            }
                        }
                        else if (snowBoss.skill1[i].skill1Toggle == 2) {
                            snowBoss.skill1[i].skill1DeadSpriteCount++;
                            if (snowBoss.skill1[i].skill1DeadSpriteCount >= 3) { //부서짐
                                snowBoss.skill1[i].skill1Toggle = 0;
                                snowBoss.skill1[i].skill1DeadSpriteCount = 0;
                                snowBoss.skill1[i].skill1Xpos = -1000;
                                snowBoss.skill1[i].skill1Ypos = -1000;
                                snowBoss.skill1[i].skill1Count = 0;
                                snowBoss.skill1[i].skill1SpriteCount = 0;
                                snowBoss.skill1[i].skill1DeadCount = 0;
                            }
                        }

                        if (hero.status == 0 && snowBoss.life > 0) {//배찌가 살아있을 때
                            if (sqrt(pow((snowBoss.skill1[i].skill1Xpos + 125) - hero.heroX, 2) + pow((snowBoss.skill1[i].skill1Ypos + 125) - hero.heroY, 2)) < 100) {
                                hero.life--;
                                hero.status = 2;//배찌 사망중
                            }
                        }
                    }

                    //스킬2
                    if (snowBoss.skill2.skill2Toggle == 1) {

                        snowBoss.skill2.skill2Count++;

                        if (snowBoss.skill2.skill2SpriteCount < 10)
                            snowBoss.skill2.skill2SpriteCount++;

                        if (snowBoss.skill2.skill2Count >= 67) { //스킬2종료
                            snowBoss.skill2.skill2SpriteCount = 0;
                            snowBoss.skill2.skill2Toggle = 0;
                            snowBoss.skill2.skill2Count = 0;
                            snowBoss.skill2.skill2SpreadCount = 0;
                            snowBoss.skill2.skill2BombSpriteCount = 0;
                        }

                        if (snowBoss.skill2.skill2Count == 1) { //처음 한번 만
                            for (int i = 0; i < 4; i++) {
                                snowBoss.skill2.skill2Xpos[i] = (rand() % (MAP_ROW - 200)) + 100;
                                snowBoss.skill2.skill2Ypos[i] = (rand() % (MAP_COL - 300)) + 250;
                            }
                        }
                        if (snowBoss.skill2.skill2Count > 40) {
                            snowBoss.skill2.skill2SpreadCount++;
                        }
                        if (snowBoss.skill2.skill2Count > 60) {
                            snowBoss.skill2.skill2BombSpriteCount++;
                            if (snowBoss.skill2.skill2BombSpriteCount >= 7)
                                snowBoss.skill2.skill2BombSpriteCount = 0;
                            if (hero.status == 0 && snowBoss.life > 0) {//배찌가 살아있을 때
                                for (int i = 0; i < 4; i++) {
                                    if (hero.heroY + 40 > snowBoss.skill2.skill2Ypos[i] + 50 && hero.heroY + 40 < snowBoss.skill2.skill2Ypos[i] + 90) {
                                        hero.life--;
                                        hero.status = 2;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    //스킬3
                    if (snowBoss.skill3.skill3Toggle == 1) {
                        snowBoss.skill3.skill3Count++;
                        snowBoss.skill3.skill3BombSpriteCount++;
                        if (snowBoss.skill3.skill3BombSpriteCount == 7)
                            snowBoss.skill3.skill3BombSpriteCount = 0;
                        if (snowBoss.skill3.skill3Count == 1) {
                            for (int i = 0; i < 20; i++) {
                                snowBoss.skill3.skill3Xpos[i] = snowBoss.xPos - (230 - ((i) * 30));
                                snowBoss.skill3.skill3Ypos[i] = 0;
                            }
                        }
                        if (snowBoss.skill3.skill3Count > 24) {
                            if (hero.status == 0 && snowBoss.life > 0) {//배찌가 살아있을 때
                                if (hero.heroX > snowBoss.skill3.skill3Xpos[0] + 40 && hero.heroX < snowBoss.skill3.skill3Xpos[19] + 30
                                    && hero.heroY< ((snowBoss.skill3.skill3Count - 24) * 50) + 80 && hero.heroY>((snowBoss.skill3.skill3Count - 24) * 50)-100) {
                                    hero.life--;
                                    hero.status = 2;
                                }
                            }
                        }

                        if (snowBoss.skill3.skill3Count >= 50) {
                            snowBoss.skill3.skill3SpriteCount = 0;
                            snowBoss.skill3.skill3Toggle = 0;
                            snowBoss.skill3.skill3Count = 0;
                            snowBoss.skill3.skill3SpreadCount = 0;
                            snowBoss.skill3.skill3BombSpriteCount = 0;
                        }
                    }

                    //스킬 4
                    if (snowBoss.skill4.skill4Toggle == 1) { //스킬 시전 시 최초 한번 발동
                        int madeMonsterCount = 0;
                        for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                            if (snowBoss.skill4.mon[i].status == 0) {
                                madeMonsterCount++;
                                if (madeMonsterCount > 5) //다섯 마리 만들면 끝
                                    break;
                                snowBoss.skill4.mon[i].status = 1;
                                snowBoss.skill4.mon[i].xPos = (rand() % (MAP_ROW - 200)) + 100;
                                snowBoss.skill4.mon[i].yPos = (rand() % (MAP_COL - 300)) + 250;
                                snowBoss.skill4.mon[i].life = 1;
                                snowBoss.skill4.mon[i].direction = (rand() % 4) + 1;
                                snowBoss.skill4.mon[i].count = 0;
                                snowBoss.skill4.mon[i].eggSpriteCount = 0;
                                snowBoss.skill4.mon[i].monSpriteCount = 0;
                            }
                        }
                        snowBoss.skill4.skill4Toggle = 0;
                    }
                    for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                        if (snowBoss.skill4.mon[i].status == 1) { //필드위에 있는 몬스터들
                            snowBoss.skill4.mon[i].count++;
                            if (snowBoss.skill4.mon[i].count != 0 && snowBoss.skill4.mon[i].count % 5 == 0 && snowBoss.skill4.mon[i].count <= 35) {
                                if (snowBoss.skill4.mon[i].eggSpriteCount <7) //달걀 애니메이션 카운트
                                    snowBoss.skill4.mon[i].eggSpriteCount++;
                            }
                            if (snowBoss.skill4.mon[i].count > 35) { //달걀 부화 후
                                snowBoss.skill4.mon[i].monSpriteCount++;
                                if (snowBoss.skill4.mon[i].monSpriteCount >= 4)
                                    snowBoss.skill4.mon[i].monSpriteCount = 0;
                                if (snowBoss.skill4.mon[i].direction == LEFT) {
                                    snowBoss.skill4.mon[i].xPos -= 5;
                                }
                                else if (snowBoss.skill4.mon[i].direction == RIGHT) {
                                    snowBoss.skill4.mon[i].xPos += 5;
                                }
                                else if (snowBoss.skill4.mon[i].direction == UP) {
                                    snowBoss.skill4.mon[i].yPos -= 5;
                                }
                                else if (snowBoss.skill4.mon[i].direction == DOWN) {
                                    snowBoss.skill4.mon[i].yPos += 5;
                                }
                                //벽 충돌시 방향 전환
                                if (snowBoss.skill4.mon[i].xPos < 0) snowBoss.skill4.mon[i].direction = RIGHT;
                                else if (snowBoss.skill4.mon[i].xPos + 100 > MAP_ROW) snowBoss.skill4.mon[i].direction = LEFT;
                                else if (snowBoss.skill4.mon[i].yPos < 135) snowBoss.skill4.mon[i].direction = DOWN; //보스 아래로만 움직임
                                else if (snowBoss.skill4.mon[i].yPos + 100 > MAP_COL) snowBoss.skill4.mon[i].direction = UP;
                                //랜덤 방향 전환
                                if (snowBoss.skill4.mon[i].count % 20 == 0) {
                                    snowBoss.skill4.mon[i].direction = (rand() % 4) + 1;
                                }
                                if (snowBoss.skill4.mon[i].life <= 0) {
                                    snowBoss.skill4.mon[i].status = 2;
                                    snowBoss.skill4.mon[i].dieCount = 30;
                                }
                            }
                        }
                        else if (snowBoss.skill4.mon[i].status == 2) { //죽는 중
                            snowBoss.skill4.mon[i].dieCount--;
                            if (snowBoss.skill4.mon[i].dieCount == 0) {
                                snowBoss.skill4.mon[i].status = 0;
                                snowBoss.skill4.mon[i].xPos = -200;
                                snowBoss.skill4.mon[i].yPos = -200;
                            }
                        }
                    }

                }
                bossrdCount = 0;
            }
        }
        //화면밖으로 나가지 못하게하는 충돌처리
        if (hero.heroX - 20 < 0)hero.heroX = 20;
        if (hero.heroX > 1140)hero.heroX = 1140;
        if (hero.heroY < 20)hero.heroY = 20;
        if (hero.heroY > 740)hero.heroY = 740;
        //아이템 먹었는지 확인하는 부분
        for (int i = 0; i < 100; i++)
        {
            if (item[i].x<hero.heroX + 20 && item[i].y<hero.heroY + 20 && item[i].x + 40>hero.heroX - 20 && item[i].y + 40>hero.heroY - 20 && item[i].shouldDraw)
            {
                item[i].shouldDraw = false;
                switch (item[i].type) {
                case SPEED:
                    if (hero.speed < 6)hero.speed++;
                    break;
                case BALLOON:
                    if (bubbleCount < 10)bubbleCount++;
                case POTION:
                    if (hero.bubbleSpeed < 3) 
                        hero.bubbleSpeed++;
                    break;
                case MAXPOTION:
                    hero.bubbleSpeed = 3;
                    break;
                }
            }
        }

        if (currentStage == 1)
        {
            for (int j = 0; j < MONSTEROFNUMBER - 2; j++) {
                if (monster[j].life != 0) {
                    monster[j].locatecount++;

                    monster[j].anicount++;
                    if (monster[j].anicount >= 4)
                        monster[j].anicount = 0;

                    if (monster[j].status == 0) { //살아있을 때
                    //count20마다 방향 전환
                        if (monster[j].locatecount != 0 && monster[j].locatecount % 20 == 0) {
                            int directionRandom = rand() % 2;
                            if (directionRandom == 0)
                                monster[j].direction = RIGHT;
                            else if (directionRandom == 1) {
                                monster[j].direction = LEFT;
                            }
                        }
                        if (monster[j].direction == LEFT) { //방향
                            monster[j].xPos -= 5;
                            if (monster[j].xPos <= 0) {
                                monster[j].direction = RIGHT;
                            }
                        }
                        else if (monster[j].direction == RIGHT) {
                            monster[j].xPos += 5;
                            if (monster[j].xPos + 130 >= MAP_ROW) {
                                monster[j].direction = LEFT;
                            }
                        }
                        if (hero.status == 0) {//배찌가 살아있을 때
                            if (hero.heroX  < monster[j].xPos + 50 && hero.heroX > monster[j].xPos && hero.heroY  < monster[j].yPos + 55 && hero.heroY > monster[j].yPos) {
                                hero.life--;
                                hero.status = 2;//배찌 사망중

                            }
                        }
                    }

                }
                if (monster[j].life == 0) {
                    monster[j].status = 1; //몬스터 처치
                    monster[j].xPos += 0;
                }
            }
            if (currentStage == 1&&diecount==8) 
            {
                stageChangeCount++;
                if (stageChangeCount == 200)
                {
                    currentStage = 2;
                    diecount = 0;
                    stageChangeCount = 0;
                    objCount = 0;
                    for (int j = 1; j < 29; j += 2)
                    {
                        for (int k = 1; k < 19; k += 2)
                        {
                            object[objCount].x = j * 40;
                            object[objCount].y = k * 40;
                            object[objCount].shouldDraw = true;
                            if (j == 1 || j == 27 || k == 1 || k == 17)object[objCount].type = TREE;
                            else if (j >= 9 && j <= 19 && k >= 7 && k <= 11)
                            {
                                if ((j == 13 || j == 15) && k == 9)object[objCount].shouldDraw = false;
                                int random = rand() % 2;
                                if (random == 0)object[objCount].type = BLOCK1;
                                else object[objCount].type = BLOCK2;
                            }
                            else
                            {
                                int random = rand() % 3;
                                if (random == 1)object[objCount].type = HOUSE1;
                                else if (random == 2)object[objCount].type = HOUSE2;
                                else object[objCount].type = HOUSE3;
                            }
                            objCount++;
                        }
                    }

              
                    for (int j = 0; j < MONSTEROFNUMBER; j++) {
                        monster[j].yPos = (rand() % 800);
                        monster[j].life = 3;
                        monster[j].status = 0;
                        monster[j].direction = UP;
                    }
                    monster[0].xPos = 75;
                    monster[1].xPos = 155;
                    monster[2].xPos = 235;
                    monster[3].xPos = 315;
                    monster[4].xPos = 395;
                    monster[5].xPos = 715;
                    monster[6].xPos = 795;
                    monster[7].xPos = 875;
                    monster[8].xPos = 955;
                    monster[9].xPos = 1035;

                    for (int i = objCount; i < 150; i++)
                    {
                        object[i].shouldDraw = false;
                    }
                    hero.heroX = 14 * 40 + 20;
                    hero.heroY = 10 * 40 - 20;
                }
            }
            
        }
        if (currentStage == 2) {
            for (int j = 0; j < MONSTEROFNUMBER; j++) {
                if (monster[j].life != 0) {
                    monster[j].locatecount++;

                    monster[j].anicount++;
                    if (monster[j].anicount >= 4)
                        monster[j].anicount = 0;

                    if (monster[j].status == 0) { //살아있을 때
                    //count20마다 방향 전환
                        if (monster[j].locatecount != 0 && monster[j].locatecount % 20 == 0) {
                            int directionRandom = rand() % 2;
                            if (directionRandom == 0)
                                monster[j].direction = UP;
                            else if (directionRandom == 1) {
                                monster[j].direction = DOWN;
                            }
                        }
                        if (monster[j].direction == UP) { //방향
                            monster[j].yPos -= 5;
                            if (monster[j].yPos <= 0) {
                                monster[j].direction = DOWN;
                            }
                        }
                        else if (monster[j].direction == DOWN) {
                            monster[j].yPos += 5;
                            if (monster[j].yPos + 130 >= MAP_COL) {
                                monster[j].direction = UP;
                            }
                        }
                        if (hero.status == 0) {//배찌가 살아있을 때
                            if (hero.heroX < monster[j].xPos + 50 && hero.heroX > monster[j].xPos && hero.heroY < monster[j].yPos + 55 && hero.heroY > monster[j].yPos) {
                                hero.life--;
                                hero.status = 2;//배찌 사망중

                            }
                        }
                    }

                }
                if (monster[j].life == 0) {
                    monster[j].status = 1; //몬스터 처치
                    monster[j].xPos += 0;
                }
                if (currentStage == 2 && diecount == 10)
                {
                    stageChangeCount++;
                    if (stageChangeCount == 200)
                    {
                        currentStage = 3;
                        diecount = 0;
                        stageChangeCount = 0;
                        objCount = 0;
                        for (int i = 0; i < 150; i++)
                        {
                            object[i].shouldDraw = false;
                        }
                        hero.heroX = 14 * 40 + 20;
                        hero.heroY = 18 * 40 - 20;
                        for (int i = 0; i < 10; i++)
                        {
                            item[i].x = 3 * i * 40;
                            item[i].y = 17 * 40;
                            switch (i)
                            {
                            case 0:
                            case 1:
                            case 2:
                                item[i].type = 1;
                                break;
                            case 3:
                            case 4:
                                item[i].type = 4;
                                break;
                            case 5:
                            case 6:
                                item[i].type = 3;
                                break;
                            case 7:
                            case 8:
                            case 9:
                                item[i].type = 2;
                                break;
                            }
                            item[i].shouldDraw = true;
                        }
                        snowBoss.xPos = 600;
                        snowBoss.yPos = 0;
                        snowBoss.life = 40;
                        snowBoss.direction = DEFAULT;
                        snowBoss.status = 0;
                        snowBoss.count = 0;
                        snowBoss.spriteCount = 0;
                        snowBoss.skillMotionSpriteCount = 0;
                        for (int i = 0; i < SKILL1NUMBER; i++) {
                            snowBoss.skill1[i].skill1Toggle = 0;
                            snowBoss.skill1[i].skill1Count = 0;
                            snowBoss.skill1[i].skill1SpriteCount = 0;
                            snowBoss.skill1[i].skill1Xpos = -1000;
                            snowBoss.skill1[i].skill1Ypos = -1000;
                            snowBoss.skill1[i].skill1Direction = 0;
                            snowBoss.skill1[i].skill1DeadCount = 0;
                        }
                        snowBoss.skill2.skill2Toggle = 0;
                        snowBoss.skill2.skill2Count = 0;
                        snowBoss.skill2.skill2SpriteCount = 0;
                        snowBoss.skill2.skill2SpreadCount = 0;
                        snowBoss.skill2.skill2BombSpriteCount = 0;
                        for (int i = 0; i < 4; i++) {
                            snowBoss.skill2.skill2Xpos[i] = -1000;
                            snowBoss.skill2.skill2Ypos[i] = -1000;
                        }
                        snowBoss.skill3.skill3Toggle = 0;
                        snowBoss.skill3.skill3Count = 0;
                        snowBoss.skill3.skill3SpriteCount = 0;
                        snowBoss.skill3.skill3SpreadCount = 0;
                        snowBoss.skill3.skill3BombSpriteCount = 0;
                        snowBoss.shouldDraw = true;
                        for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                            snowBoss.skill4.mon[i].count = 0;
                            snowBoss.skill4.mon[i].status = 0;
                            snowBoss.skill4.mon[i].life = 0;
                            snowBoss.skill4.mon[i].xPos = -1000;
                            snowBoss.skill4.mon[i].yPos = -1000;
                        }

                        itemCount = 0;
                    }

                }
            }

        }
        if (hero.life == 0&&GetAsyncKeyState(VK_RETURN))
        {
            currentStage = 0;
        }
        if (currentStage == 3 && snowBoss.life&& GetAsyncKeyState(VK_RETURN))
        {
            currentStage = 0;
        }
        InvalidateRect(hWnd, NULL, false);
        break;
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            for (int i = 0; i < bubbleCount; i++) {
                if (hero.bubble[i].status == -100) {
                    hero.bubble[i].status = 1; //날라가는 중
                    hero.bubble[i].xPos = hero.heroX;
                    hero.bubble[i].yPos = hero.heroY;
                    hero.bubble[i].direction = hero.direction;
                    break;
                }
            }
        }
        else if (wParam == 0x5A &&currentStage == 3) {//'z'
            if (hero.skillZ.coolTime == 0) {
                hero.skillZ.toggle = 1;
                hero.skillZ.coolTime = 2000;
                int temp;
                for (int i = 0; i < 20; i++) {
                    temp = rand() % 4;
                    if (temp == 0) { //왼쪽 시작
                        hero.skillZ.bubble[i].xPos = 0;
                        hero.skillZ.bubble[i].yPos = (rand() % 600) + 100;
                        hero.skillZ.bubble[i].direction = RIGHT;
                        hero.skillZ.bubble[i].status = 1;
                    }
                    else if (temp == 1) {//오른쪽 시작
                        hero.skillZ.bubble[i].xPos = MAP_ROW;
                        hero.skillZ.bubble[i].yPos = (rand() % 600) + 100;
                        hero.skillZ.bubble[i].direction = LEFT;
                        hero.skillZ.bubble[i].status = 1;
                    }
                    else if (temp == 2) {//위쪽시작
                        hero.skillZ.bubble[i].xPos = (rand() % 1100) + 100;
                        hero.skillZ.bubble[i].yPos = 0;
                        hero.skillZ.bubble[i].direction = DOWN;
                        hero.skillZ.bubble[i].status = 1;
                    }
                    else if (temp == 3) {//아래 시작
                        hero.skillZ.bubble[i].xPos = (rand() % 1100) + 100;
                        hero.skillZ.bubble[i].yPos = MAP_COL;
                        hero.skillZ.bubble[i].direction = UP;
                        hero.skillZ.bubble[i].status = 1;
                    }
                }
            }
        }
        break;
    case WM_KEYUP:
        if (wParam == 0x58) { //거대 풍선 'x'
            if (hero.skillX.count >= 700) {
                for (int i = 0; i < bubbleCount; i++) {
                    if (hero.bubble[i].status == -100) {
                        hero.bubble[i].status = 1; //날라가는 중
                        hero.bubble[i].xPos = hero.heroX;
                        hero.bubble[i].yPos = hero.heroY;
                        hero.bubble[i].direction = hero.direction;
                        hero.bubble[i].bigBubble = 1;
                        break;
                    }
                }
                hero.skillX.coolTime = 2000;
            }
            hero.skillX.count = 0;
            hero.skillX.toggle = 0;
        }
        break;
    case WM_MOUSEMOVE:
        cur.x = LOWORD(lParam);
        cur.y = HIWORD(lParam);
        break;
    case WM_LBUTTONDOWN:
        if (currentStage == 0)
        {
            if (LOWORD(lParam) > 740 && LOWORD(lParam) < 1230 && HIWORD(lParam) > 580 && HIWORD(lParam) < 680)
            {
                currentStage = 1;
                bossrdCount = 0;
                bubbleCount = 1;
                hero.status = ALIVE;
                hero.direction = 0;
                hero.spriteCount = 0;
                objCount = 0;
                hero.life = 3;
                hero.dieCount = 0;
                hero.resurrectionCount = 0;
                for (int i = 0; i < BUBBLE_MAX; i++)
                {
                    hero.bubble[i].xPos = -100;
                    hero.bubble[i].yPos = -100;
                    hero.bubble[i].bigBubble = -100;
                    hero.bubble[i].status = -100;
                }
                for (int i = 0; i < 20; i++) {
                    hero.skillZ.bubble[i].xPos = -100;
                    hero.skillZ.bubble[i].yPos = -100;
                }
                snowBoss.shouldDraw = false;

                for (int j = 0; j < MONSTEROFNUMBER; j++) {
                    monster[j].xPos = (rand() % 1180);
                    monster[j].life = 3;
                    monster[j].status = 0;
                    monster[j].direction = RIGHT;
                }
                monster[0].yPos = 120;
                monster[1].yPos = 170;
                monster[2].yPos = 280;
                monster[3].yPos = 330;
                monster[4].yPos = 450;
                monster[5].yPos = 490;
                monster[6].yPos = 600;
                monster[7].yPos = 650;
                for (int j = 0; j < 29; j++)
                {
                    for (int k = 2; k < 19; k += 4)
                    {
                        if (j == 0 && (k == 2 || k == 10 || k == 18)) continue;
                        else if (j == 28 && (k == 6 || k == 14)) continue;
                        object[objCount].x = j * 40;
                        object[objCount].y = k * 40;
                        object[objCount].shouldDraw = true;
                        object[objCount++].type = rand() % 6 + 1;

                    }
                }
                for (int i = 140; i < 150; i++)
                {
                    object[i].shouldDraw = false;
                }
                hero.heroX = 1140;
                hero.heroY = 60;
                stageChangeCount = 0;
            }
            if (LOWORD(lParam) > 125 && LOWORD(lParam) < 405 && HIWORD(lParam) > 134 && HIWORD(lParam) < 220)
            {
                heroSelected = BAZZI;
            }
            if (LOWORD(lParam) > 125 && LOWORD(lParam) < 405 && HIWORD(lParam) > 239 && HIWORD(lParam) < 325)
            {
                heroSelected = DAO;
            }
            if (LOWORD(lParam) > 125 && LOWORD(lParam) < 405 && HIWORD(lParam) > 350 && HIWORD(lParam) < 436)
            {
                heroSelected = DIGENIE;
            }
            if (LOWORD(lParam) > 125 && LOWORD(lParam) < 405 && HIWORD(lParam) > 462 && HIWORD(lParam) < 548)
            {
                heroSelected = UNI;
            }
            switch (heroSelected)
            {
            case BAZZI:
                hero.heroSprite = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/bazzi.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                hero.speed = 1;
                hero.bubbleSpeed = 2;

                break;
            case DAO:
                hero.heroSprite = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/dao.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                hero.speed = 2;
                hero.bubbleSpeed = 1;
                break;
            case UNI:
                hero.heroSprite = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/uni.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                hero.speed = 2;
                hero.bubbleSpeed = 1;
                break;
            case DIGENIE:
                hero.heroSprite = (HBITMAP)LoadImage(g_hinst, TEXT("BMP/digenie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
                bubbleCount++;
                hero.speed = 1;
                hero.bubbleSpeed = 1;
                break;
            }
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
