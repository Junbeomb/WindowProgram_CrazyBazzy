#include "Widget.h"
#include "Hero.h"
#include "Object.h"
#include "Boss.h"
#include "MonsterClass.h"
#include "globals.h"
#include "Sprite.h"
#include "Item.h"
#include "Bubble.h"
#include "Map.h"


Widget widget;

Boss bossH;
vector<Object> objects;
vector<MonsterClass> monsters;
vector<Item> items;
vector<Bubble> bubbles;

Hero hero;
Map map;

HINSTANCE g_hinst;
Sprite sprite;
LPCTSTR lpszClass = L"windows_program1";
LPCTSTR lpszWindowName = L"Crazzy Bazzy";


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE  hPrevInstance, LPSTR IpszCMDParam, int nCmdShow) {
    HWND hWnd;
    MSG Message;
    WNDCLASSEX WndClass;
    g_hinst = hInstance;
    sprite.SetgInst(g_hinst);

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
    static HDC memDC;
    static HBITMAP hBitmap, oldBitmap;
    static RECT rectView;
    static POINT cur;
    //주인공
    static int reduceCount;
    static int bubbleCount;

    //스테이지용
    static int itemCount;
    static bool itemUPDOWN;
    static int stageChangeCount;

    switch (iMsg) {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
 
        ShowCursor(false);
        SetTimer(hWnd, main, 10, NULL);
        currentStage = 0;
        hero.SetSpeed(1);
        heroSelected = BAZZI;

        break;
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        memDC = CreateCompatibleDC(hDC);
        hBitmap = CreateCompatibleBitmap(hDC, rectView.right, rectView.bottom);
        oldBitmap = (HBITMAP)SelectObject(memDC, hBitmap);

        //그리기 시작
        switch (currentStage)
        {
        case 0:
            map.DrawBoard(memDC, sprite.map0);
            break;
        case 1:
            map.DrawBoard(memDC, sprite.map1);
            for (int i = 0; i < objects.size(); ++i) {
                objects[i].DrawObjectUP(memDC, sprite, hero);
            }
            for (int i = 0; i < monsters.size(); ++i) {
                monsters[i].DrawMonster(memDC, sprite.monImage);
            }
            hero.DrawHero(memDC);
            for (int i = 0; i < objects.size(); ++i) {
                objects[i].DrawObjectDOWN(memDC, sprite, hero);
            }
            for (int i = 0; i < items.size(); ++i) {
                items[i].DrawItem(memDC);
            }
            for (int i = 0; i < bubbles.size(); ++i) {
                bubbles[i].DrawBubble(memDC,hero,sprite);
            }
            widget.DrawHeart(memDC, hero, bossH, sprite);
            break;
        case 2:
            map.DrawBoard(memDC, sprite.map2);
            for (int i = 0; i < objects.size(); ++i) {
                objects[i].DrawObjectUP(memDC, sprite, hero);
            }
            for (int i = 0; i < monsters.size(); ++i) {
                monsters[i].DrawMonster(memDC, sprite.monImage);
            }
            hero.DrawHero(memDC);
            for (int i = 0; i < objects.size(); ++i) {
                objects[i].DrawObjectDOWN(memDC, sprite, hero);
            }
            for (int i = 0; i < items.size(); ++i) {
                items[i].DrawItem(memDC);
            }
            for (int i = 0; i < bubbles.size(); ++i) {
                bubbles[i].DrawBubble(memDC, hero, sprite);
            }
            widget.DrawHeart(memDC, hero, bossH, sprite);
            break;
        case 3:
            map.DrawBoard(memDC, sprite.bossMap);
           /* bossH.DrawBossSkill3(memDC, sprite);
            bossH.DrawBoss(memDC, sprite);
            bossH.DrawBossSkill2(memDC, sprite);
            bossH.DrawBossSkill4(memDC, sprite);
            hero.DrawHero(memDC);
            bossH.DrawBossSkill1(memDC, sprite);
            RoundRect(memDC, 8, 8, 1132, 32, 5, 5);
            hBrush = CreateSolidBrush(RGB(255, 0, 0));
            oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
            RoundRect(memDC, 10, 10, 10 + bossH.GetLife() * 28, 30, 5, 5);
            SelectObject(memDC, oldBrush);
            DeleteObject(hBrush);
            DeleteObject(oldBrush);*/
            for (int i = 0; i < items.size(); ++i) {
                items[i].DrawItem(memDC);
            }
            for (int i = 0; i < bubbles.size(); ++i) {
                bubbles[i].DrawBubble(memDC, hero, sprite);
            }

            widget.DrawHeart(memDC, hero, bossH, sprite);
            widget.DrawSkillIcon(memDC, hero, sprite);
            break;
        default:
            break;
        }
        widget.DrawCursor(memDC, cur, sprite);
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
                    for (int i = 0; i < items.size(); i++) {
                        items[i].y++;
                    }
                    itemUPDOWN = false;
                }
                else
                {
                    for (int i = 0; i < items.size(); i++) {
                        items[i].y--;
                    }
                    itemUPDOWN = true;
                }
            }

            //보스랑 히어로 충돌
            if (sqrt(pow((hero.X - (bossH.GetxPos() + 125)), 2) + pow(((hero.Y) - (bossH.GetyPos() + 125)), 2)) < 130 && bossH.GetLife() > 0) {
                hero.SetLife(hero.GetLife() - 1);
                hero.status = 2;
            }

            //skill4몬스터랑 히어로 충돌
            for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                if (bossH.skill4.mon[i].status == 1 && bossH.skill4.mon[i].count > 35) {
                    if (sqrt(pow((hero.X - (bossH.skill4.mon[i].X + 50)), 2) + pow(((hero.Y) - (bossH.skill4.mon[i].Y + 50)), 2)) < 40 ) {
                        hero.SetLife(hero.GetLife() - 1);
                        hero.status = 2;
                        break;
                    }
                }
            }

            //방향키 및 오브젝트 충돌처리
            if (hero.status != 10) {//대쉬가 아닐때만
                if (GetAsyncKeyState(VK_UP)) {
                    hero.direction = UP;
                    hero.Y -= hero.GetSpeed();
                }
                else if (GetAsyncKeyState(VK_LEFT)) {
                    hero.direction = LEFT;
                    hero.X -= hero.GetSpeed();
                }
                else if (GetAsyncKeyState(VK_DOWN)) {
                    hero.direction = DOWN;
                    hero.Y += hero.GetSpeed();
                }
                else if (GetAsyncKeyState(VK_RIGHT)) {
                    hero.direction = RIGHT;
                    hero.X += hero.GetSpeed();
                }
            }
            else if (hero.status == 10) {
                hero.dashCount--;
                if (hero.dashCount == 0) {
                    hero.status = 0;
                    hero.dashCoolTime = 30;
                }
                if (hero.direction == LEFT) {
                    hero.X -= 10;
                }
                else if (hero.direction == RIGHT) {
                    hero.X += 10;
                }
                else if (hero.direction == UP) {
                    hero.Y -= 10;
                }
                else if (hero.direction == DOWN) {
                    hero.Y += 10;
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
            if (hero.GetLife() == 0) { //게임 끝

            }
            else {
                hero.dieCount++;
                if (hero.dieCount >= 100)hero.status = 3;
            }
        }
        else if (hero.status == 3) {
            hero.resurrectionCount++;
            if (GetAsyncKeyState(VK_UP)) {
                hero.direction = UP;
                hero.Y -= hero.GetSpeed();
            }
            else if (GetAsyncKeyState(VK_LEFT))
            {
                hero.direction = LEFT;
                hero.X -= hero.GetSpeed();
            }
            else if (GetAsyncKeyState(VK_DOWN))
            {
                hero.direction = DOWN;
                hero.Y += hero.GetSpeed();
            }
            else if (GetAsyncKeyState(VK_RIGHT))
            {
                hero.direction = RIGHT;
                hero.X += hero.GetSpeed();
            }
            if (hero.resurrectionCount > 100) {
                hero.status = 0;
                hero.dieCount = 0;
                hero.resurrectionCount = 0;
            }
        }


        //화면밖으로 나가지 못하게하는 충돌처리
        if (hero.X < 20)hero.X = 20;
        if (hero.X > 1140)hero.X = 1140;
        if (hero.Y < 20)hero.Y = 20;
        if (hero.Y > 740)hero.Y = 740;

        //장애물 충돌 확인
        for (int i = 0; i < objects.size(); ++i) {
            if (objects[i].x<hero.X + 18 && 
                objects[i].y<hero.Y + 18 && 
                objects[i].x + 40>hero.X - 18 && 
                objects[i].y + 40>hero.Y - 18){

                //이전 위치로
                hero.X = hero.beforeX;
                hero.Y = hero.beforeY;
            }
        }

        hero.beforeX = hero.X;
        hero.beforeY = hero.Y;

        
        for (int i = 0; i < bubbles.size(); i++) { //주인공 일반 공격
            if (bubbles[i].GetStatus() == 1) {
                if (bubbles[i].GetDirection() == LEFT) {
                    if (not bubbles[i].GetBigBubble())
                        bubbles[i].SetXY(bubbles[i].GetX() - (5 + (5 * hero.GetBubbleSpeed())), bubbles[i].GetY());
                    else
                        bubbles[i].SetXY(bubbles[i].GetX() - 10, bubbles[i].GetY());
                }
                else if (bubbles[i].GetDirection() == RIGHT) {
                    if (not bubbles[i].GetBigBubble())
                        bubbles[i].SetXY(bubbles[i].GetX() + (5 + (5 * hero.GetBubbleSpeed())), bubbles[i].GetY());
                    else
                        bubbles[i].SetXY(bubbles[i].GetX() + 10, bubbles[i].GetY());
                }
                else if (bubbles[i].GetDirection() == UP) {
                    if (not bubbles[i].GetBigBubble())
                        bubbles[i].SetXY(bubbles[i].GetX(), bubbles[i].GetY() - (5 + (5 * hero.GetBubbleSpeed())));
                    else
                        bubbles[i].SetXY(bubbles[i].GetX(), bubbles[i].GetY() - 10);
                }
                else if (bubbles[i].GetDirection() == DOWN) {
                    if (not bubbles[i].GetBigBubble())
                        bubbles[i].SetXY(bubbles[i].GetX(), bubbles[i].GetY() + (5 + (5 * hero.GetBubbleSpeed())));
                    else
                        bubbles[i].SetXY(bubbles[i].GetX(), bubbles[i].GetY() + 10);
                }

                //보스와 충돌
                if (bubbles[i].GetX() > bossH.GetxPos() &&
                    bubbles[i].GetX() < bossH.GetxPos() + BOSS_WIDTH &&
                    bubbles[i].GetY() + 25 > bossH.GetyPos() &&
                    bubbles[i].GetY() + 25 < bossH.GetyPos() + BOSS_HEIGHT &&
                    currentStage == 3) {

                    bubbles[i].SetStatus(2);//bubble 터지는 중
                    bubbles[i].SetDieCount(30);

                    if (bossH.GetLife() > 0 && not bubbles[i].GetBigBubble()) bossH.SetLife(bossH.GetLife() - 1);
                    else if (bossH.GetLife() > 0 && bubbles[i].GetBigBubble() && bossH.GetLife() > 0) bossH.SetLife(bossH.GetLife() - 5);
                }
                // 보스 skill4monster 충돌
                for (int j = 0; j < BOSS_MONSTER_MAX; j++) { 
                    if (bossH.skill4.mon[j].status == 1 && bossH.skill4.mon[j].count>35) { 
                        if (not bubbles[i].GetBigBubble() && 
                            bubbles[i].GetX() > bossH.skill4.mon[j].X && 
                            bubbles[i].GetX() < bossH.skill4.mon[j].X + 100 && 
                            bubbles[i].GetY() - 15 > bossH.skill4.mon[j].Y && 
                            bubbles[i].GetY() - 15 < bossH.skill4.mon[j].Y + 100) {

                            bubbles[i].SetStatus(2);
                            bubbles[i].SetDieCount(30);
                            bossH.skill4.mon[j].life--;
                            break;
                        }
                        else if (bubbles[i].GetBigBubble() && 
                            bubbles[i].GetX() > bossH.skill4.mon[j].X && 
                            bubbles[i].GetX() < bossH.skill4.mon[j].X + 100 && 
                            bubbles[i].GetY() - 15 > bossH.skill4.mon[j].Y && 
                            bubbles[i].GetY() - 15 < bossH.skill4.mon[j].Y + 100) {

                            bossH.skill4.mon[j].life--;
                            break;
                        }
                    }
                }
                //몬스터와 충돌
                for (int j = 0; j < monsters.size(); j++) { 
                    if (monsters[j].status != 0) continue;
                    
                    if (monsters[j].CollisionCheck(bubbles[i].GetX(), bubbles[i].GetY(), 50, 60)) {
                        bubbles[i].SetStatus(2); //bubble 터지는 중
                        bubbles[i].SetDieCount(30);
                        monsters[j].Damaged();
                    }
                }

                //맵 밖으로 나가면
                if (bubbles[i].GetX() < 0 || bubbles[i].GetX()> MAP_ROW || bubbles[i].GetY()< 0 || bubbles[i].GetY() > MAP_COL) {
                    bubbles[i].SetXY(bubbles[i].GetX() - 100,bubbles[i].GetY() - 100);
                    bubbles[i].SetStatus(-100);
                    bubbles[i].SetBigBubble(false);
                }
                for (int j = 0; j < objects.size(); ++j) {

                    if (objects[j].x<bubbles[i].GetX() + 5 && objects[j].y<bubbles[i].GetY() + 5 && objects[j].x + 40>bubbles[i].GetX() - 5 && objects[j].y + 40>bubbles[i].GetY() - 5) {
                        bubbles[i].SetStatus(2);//bubble 터지는 중
                        bubbles[i].SetDieCount(30);
                        Item tItem;
                        switch (objects[j].GetType())
                        {
                        case BLOCK1:
                        case BLOCK2:
                            tItem.x = objects[j].x;
                            tItem.y = objects[j].y;
                            tItem.SetType(rand() % 4 + 1);
                            items.push_back(tItem);
                            objects.erase(objects.begin() + j);
                            --j;

                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            else if (bubbles[i].GetStatus() == 2) { //bubble 터지는 중
                bubbles[i].SetDieCount(bubbles[i].GetDieCount() - 1);
                if (bubbles[i].GetDieCount() == 0) {
                    bubbles.erase(bubbles.begin() + i);
                    --i;
                }
            }
        }

        //if (hero.skillZ.toggle == 1) { //'z'
        //    if (hero.skillZ.coolTime == 10) {//쿨타임 10초일때 초기화
        //        hero.skillZ.toggle = 0;
        //    }
        //    for (int i = 0; i < 20; i++) {
        //        if (hero.skillZ.bubble[i].status == 1) {
        //            if (hero.skillZ.bubble[i].direction == LEFT) {
        //                hero.skillZ.bubble[i].xPos -= 10;
        //            }
        //            else if (hero.skillZ.bubble[i].direction == RIGHT) {
        //                hero.skillZ.bubble[i].xPos += 10;
        //            }
        //            else if (hero.skillZ.bubble[i].direction == UP) {
        //                hero.skillZ.bubble[i].yPos -= 10;
        //            }
        //            else if (hero.skillZ.bubble[i].direction == DOWN) {
        //                hero.skillZ.bubble[i].yPos += 10;
        //            }
        //        }
        //        else if (hero.skillZ.bubble[i].status == 2) { //터지는 중
        //            hero.skillZ.bubble[i].dieCount--;
        //            if (hero.skillZ.bubble[i].dieCount == 0) {
        //                hero.skillZ.bubble[i].xPos = -100;
        //                hero.skillZ.bubble[i].yPos = -100;
        //                hero.skillZ.bubble[i].status = -100;
        //            }
        //        }
        //        if (hero.skillZ.bubble[i].xPos < 0 || hero.skillZ.bubble[i].xPos> MAP_ROW || hero.skillZ.bubble[i].yPos < 0 || hero.skillZ.bubble[i].yPos > MAP_COL) { //맵 밖으로 나가면
        //            hero.skillZ.bubble[i].xPos = -100;
        //            hero.skillZ.bubble[i].yPos = -100;
        //            hero.skillZ.bubble[i].status = -100;
        //        }
        //        if (hero.skillZ.bubble[i].status != 2 && sqrt(pow(hero.skillZ.bubble[i].xPos - (bossH.GetxPos() + 125), 2) + pow(hero.skillZ.bubble[i].yPos - (bossH.GetyPos() + 125), 2)) < 100) {
        //            hero.skillZ.bubble[i].status = 2; //보스 충돌
        //            hero.skillZ.bubble[i].dieCount = 30;
        //            if (bossH.GetLife() > 0)bossH.SetLife(bossH.GetLife() - 1);
        //        }
        //        for (int j = 0; j < BOSS_MONSTER_MAX; j++) {
        //            if (bossH.skill4.mon[j].status == 1 && bossH.skill4.mon[j].count > 30) {
        //                if (hero.skillZ.bubble[i].status != 2 && sqrt(pow(hero.skillZ.bubble[i].xPos - (bossH.skill4.mon[j].xPos + 50), 2) + pow(hero.skillZ.bubble[i].yPos - (bossH.skill4.mon[j].yPos + 50), 2)) < 100) {
        //                    hero.skillZ.bubble[i].status = 2;
        //                    hero.skillZ.bubble[i].dieCount = 30;
        //                    bossH.skill4.mon[j].life--;
        //                    break;
        //                }
        //            }
        //        }
        //    }
        //}

        if (hero.skillX.coolTime != 0) { //skillX 쿨타임 = 20 초
            hero.skillX.coolTime--;
        }
        if (hero.skillZ.coolTime != 0) { //skillZ 쿨타임 = 20 초
            hero.skillZ.coolTime--;
        }



        //아이템 습득
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].x<hero.X + 20 && items[i].y<hero.Y + 20 && items[i].x + 40>hero.X - 20 && items[i].y + 40>hero.Y - 20)
            {

                switch (items[i].GetType()) {
                    case SPEED:
                        if (hero.GetSpeed() < 6)
                            hero.SetSpeed(hero.GetSpeed()+1);
                        break;
                    case BALLOON:
                        if (bubbleCount < 10)bubbleCount++;
                    case POTION:
                        if (hero.GetBubbleSpeed() < 3) 
                            hero.SetBubbleSpeed(hero.GetBubbleSpeed()+1);
                        break;
                    case MAXPOTION:
                        hero.SetBubbleSpeed(3);
                        break;
                }

                items.erase(items.begin() + i);
                --i;
            }
        }

        //몬스터 이동
        for (int j = 0; j < monsters.size(); j++) {
            //animation
            monsters[j].anicount++;
            if (monsters[j].anicount >= monsters[j].aniSpeed * 4) { //aniSpeed가 100일 때는 400
                monsters[j].anicount = 0;
            }

            if (monsters[j].status == 0) { //살아있을 때
                monsters[j].Move();
                if (hero.status == ALIVE && monsters[j].CollisionCheck(hero.X,hero.Y,50,55)) hero.Damaged();
            }
            else if (monsters[j].status == 1) {//죽는 중
                monsters[j].dieCount++;
                if (monsters[j].dieCount >= 200) {
                    monsters.erase(monsters.begin() + j);
                    --j;
                }
            }

        }
        //스테이지 변경
        if (monsters.empty()) {
            if (currentStage == 1) {
                stageChangeCount++;
                //2초 동안 win 로고 나오게
                if (stageChangeCount == 200) {
                    currentStage = 2;
                    stageChangeCount = 0;

                    objects.clear();

                    for (int j = 1; j < 29; j += 2)
                    {
                        for (int k = 1; k < 19; k += 2)
                        {
                            Object tObject;
                            tObject.SetXY(j * 40, k * 40);

                            if (j == 1 || j == 27 || k == 1 || k == 17)tObject.SetType(TREE);
                            else if (j >= 9 && j <= 19 && k >= 7 && k <= 11) {
                                if ((j == 13 || j == 15) && k == 9) continue;

                                int random = rand() % 2;
                                if (random == 0)tObject.SetType(BLOCK1);
                                else tObject.SetType(BLOCK2);
                            }
                            else {
                                int random = rand() % 3;
                                if (random == 1)tObject.SetType(HOUSE1);
                                else if (random == 2)tObject.SetType(HOUSE2);
                                else tObject.SetType(HOUSE3);
                            }
                            objects.push_back(tObject);
                        }
                    }

                    monsters.clear();

                    for (int j = 0; j < MONSTEROFNUMBER; ++j) {
                        MonsterClass tMon;
                        tMon.xPos = (rand() % 800);
                        tMon.life = 3;
                        tMon.status = 0;
                        tMon.direction = UP;

                        monsters.push_back(tMon);
                    }

                    monsters[0].xPos = 75;
                    monsters[1].xPos = 155;
                    monsters[2].xPos = 235;
                    monsters[3].xPos = 315;
                    monsters[4].xPos = 395;
                    monsters[5].xPos = 715;
                    monsters[6].xPos = 795;
                    monsters[7].xPos = 875;
                    monsters[8].xPos = 955;
                    monsters[9].xPos = 1035;

                    hero.X = 14 * 40 + 20;
                    hero.Y = 10 * 40 - 20;
                }
            }
            else if(currentStage == 2){
                stageChangeCount++;
                if (stageChangeCount == 200) {
                    currentStage = 3;
                    stageChangeCount = 0;

                    objects.clear();

                    hero.X = 14 * 40 + 20;
                    hero.Y = 18 * 40 - 20;

                    for (int i = 0; i < 10; i++)
                    {
                        Item tItem;
                        tItem.SetXY(3 * i * 40, 17 * 40);
                        tItem.sprite = sprite.items;
                        switch (i) {
                        case 0:case 1:case 2:
                            tItem.SetType(SPEED);
                            break;
                        case 3:case 4:
                            tItem.SetType(MAXPOTION);
                            break;
                        case 5:case 6:
                            tItem.SetType(POTION);
                            break;
                        case 7:case 8:case 9:
                            tItem.SetType(BALLOON);
                            break;
                        }
                        items.push_back(tItem);
                    }


                    bossH.SetxPos(600);
                    bossH.SetyPos(0);
                    bossH.SetLife(40);
                    bossH.SetDirection(DEFAULT);
                    bossH.SetStatus(0);
                    bossH.SetCount(0);
                    bossH.SetSpriteCount(0);
                    bossH.SetSkillMotionSpriteCount(0);
                    bossH.SetShouldDraw(true);

                    for (int i = 0; i < SKILL1NUMBER; i++) {
                        bossH.skill1[i].skill1Toggle = 0;
                        bossH.skill1[i].skill1Count = 0;
                        bossH.skill1[i].skill1SpriteCount = 0;
                        bossH.skill1[i].skill1Xpos = -1000;
                        bossH.skill1[i].skill1Ypos = -1000;
                        bossH.skill1[i].skill1Direction = 0;
                        bossH.skill1[i].skill1DeadCount = 0;
                    }
                    bossH.skill2.skill2Toggle = 0;
                    bossH.skill2.skill2Count = 0;
                    bossH.skill2.skill2SpriteCount = 0;
                    bossH.skill2.skill2SpreadCount = 0;
                    bossH.skill2.skill2BombSpriteCount = 0;
                    for (int i = 0; i < 4; i++) {
                        bossH.skill2.skill2Xpos[i] = -1000;
                        bossH.skill2.skill2Ypos[i] = -1000;
                    }
                    bossH.skill3.skill3Toggle = 0;
                    bossH.skill3.skill3Count = 0;
                    bossH.skill3.skill3SpriteCount = 0;
                    bossH.skill3.skill3SpreadCount = 0;
                    bossH.skill3.skill3BombSpriteCount = 0;
                    for (int i = 0; i < BOSS_MONSTER_MAX; i++) {
                        bossH.skill4.mon[i].count = 0;
                        bossH.skill4.mon[i].status = 0;
                        bossH.skill4.mon[i].life = 0;
                        bossH.skill4.mon[i].X = -1000;
                        bossH.skill4.mon[i].Y = -1000;
                    }

                    itemCount = 0;
                }
            }
        }


        //보스
        if (currentStage == 3){
            //bossH.BossAlgorithm();
        }

        //if (hero.GetLife() == 0 && GetAsyncKeyState(VK_RETURN)) {
        //    currentStage = 0;
        //}
        //if (currentStage == 3 && bossH.GetLife() && GetAsyncKeyState(VK_RETURN)) {
        //    currentStage = 0;
        //}
        InvalidateRect(hWnd, NULL, false);
        break;
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            Bubble tBubble;
            tBubble.SetStatus(1); //날라가는 중.
            tBubble.SetXY(hero.X, hero.Y);
            tBubble.SetDirection(hero.direction);
            bubbles.push_back(tBubble);
        }
        else if (wParam == 0x5A && currentStage == 3) {//'z'
            if (hero.skillZ.coolTime != 0)  break;

            hero.skillZ.toggle = 1;
            hero.skillZ.coolTime = 2000;
            int temp;
            for (int i = 0; i < 20; i++) {
                temp = rand() % 4;
                Bubble tBubble;

                tBubble.SetStatus(1);
                if (temp == 0) { //왼쪽 시작
                    tBubble.SetXY(0, (rand() % 600) + 100);
                    tBubble.SetDirection(RIGHT);
                }
                else if (temp == 1) {//오른쪽 시작
                    tBubble.SetXY(MAP_ROW, (rand() % 600) + 100);
                    tBubble.SetDirection(LEFT);
                }
                else if (temp == 2) {//위쪽시작
                    tBubble.SetXY((rand() % 1100) + 100, 0);
                    tBubble.SetDirection(DOWN);
                }
                else if (temp == 3) {//아래 시작
                    tBubble.SetXY((rand() % 1100) + 100, MAP_COL);
                    tBubble.SetDirection(UP);
                }
                bubbles.push_back(tBubble);
            }
        }
        break;
    case WM_KEYUP:
        if (wParam == 0x58) { //거대 풍선 'x'
            if (hero.skillX.count < 700) break;

            Bubble tBubble;
            tBubble.SetStatus(1);
            tBubble.SetXY(hero.X,hero.Y);
            tBubble.SetDirection(hero.direction);
            tBubble.SetBigBubble(true);

            hero.skillX.coolTime = 2000;
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
                bubbleCount = 1;
                hero.status = ALIVE;
                hero.direction = 0;
                hero.spriteCount = 0;

                hero.SetLife(3);
                hero.dieCount = 0;
                hero.resurrectionCount = 0;

                for (int i = 0; i < 8; ++i) {
                    MonsterClass tMon;
                    tMon.xPos = (rand() % 1180);
                    tMon.life = 3;
                    tMon.status = 0;
                    tMon.direction = RIGHT;

                    monsters.push_back(tMon);
                }

                monsters[0].yPos = 120;
                monsters[1].yPos = 170;
                monsters[2].yPos = 280;
                monsters[3].yPos = 330;
                monsters[4].yPos = 450;
                monsters[5].yPos = 490;
                monsters[6].yPos = 600;
                monsters[7].yPos = 650;

                for (int j = 0; j < 29; j++) {
                    for (int k = 2; k < 19; k += 4) {
                        if (j == 0 && (k == 2 || k == 10 || k == 18)) continue;
                        else if (j == 28 && (k == 6 || k == 14)) continue;
                        Object tObject;
                        tObject.SetType(rand() % 6 + 1);
                        tObject.SetXY(j * 40, k * 40);
                        objects.push_back(tObject);
                    }
                }
                hero.X = 1140;
                hero.Y = 60;
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
                hero.SetSprite(sprite.bazziSprite);
                hero.SetSpeed(1);
                hero.SetBubbleSpeed(2);

                break;
            case DAO:
                hero.SetSprite(sprite.daoSprite);
                hero.SetSpeed(2);
                hero.SetBubbleSpeed(1);
                break;
            case UNI:
                hero.SetSprite(sprite.uniSprite);
                hero.SetSpeed(2);
                hero.SetBubbleSpeed(1);
                break;
            case DIGENIE:
                hero.SetSprite(sprite.digenieSprite);
                hero.SetSpeed(1);
                hero.SetBubbleSpeed(1);
                bubbleCount++;
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
