#include "Drawing lib.h"
#include "TXLib.h"


const int PLANE_STEP = 5;
const int SHOT_STEP = 10;
const int GUN_STEP = 5;
const int START_FOR_PLANE = 1;
const int PLANE_HIGHT = 70;
const int PLANE_WEGHT = 120;

//необходимо наличие библиотек "The main project.h" и "TXLib.h" в папке с исходником


int main()
{
    txCreateWindow(800, 600);
    Background background = Background(125, 425);
    Base gun = Base(400, 500);
    Plane plane = Plane(0, 20);
    Bullet shot = Bullet(700, 400);
    shot.x = gun.x + 6;
    shot.y = gun.y;
    int location;
    int kol = 0;
    int kol1 = 0;
    int a = 0;
    int bullets;

    while(txMouseButtons() !=1)
    {
            txBegin();
            txRectangle(0, 0, 200, 60);
            txRectangle(0, 0, 800, 600);
            txSetFillColour(RGB(30, 144, 255));
            txRectangle(250, 250, 550, 350);
            txSetFillColour(RGB(186, 85, 211));
            txTextOut(370, 290, "START");
            txEnd();
    }

    cout<<"Scoreboard: ";

    while(txMouseButtons() !=3)
    {
        txBegin();
        background.paint();
        txSetFillColour(TX_BLACK);
        txRectangle(0, 0, 90, 30);
        txSetFillColour(TX_WHITE);
        txSetColour(TX_BLACK);
        txTextOut(450, 550, "Hold the space bar to shoot");
        gun.paint();


        if((plane.x > 0) and (plane.x < 800))   //условие полёта самолёта
        {
            txBegin();
            plane.paint();
            plane.x = plane.x + PLANE_STEP;
            txEnd();
        }
        else
        {
            plane.x = START_FOR_PLANE;
        }


        if(GetAsyncKeyState(VK_LEFT))   //движение каретки влево
        {
            txBegin();
            gun.x = gun.x - GUN_STEP;
            txEnd();
        }


        if(GetAsyncKeyState(VK_RIGHT))  //движение каретки вправо
        {
            txBegin();
            gun.x = gun.x + GUN_STEP;
            txEnd();
        }


        shot.paint();
        if(GetAsyncKeyState(VK_SPACE) and (shot.y > 10))
        {
            shot.y = shot.y - SHOT_STEP;
            if((shot.y < plane.y + PLANE_HIGHT) and (shot.y > plane.y) and (shot.x > plane.x) and (shot.x < plane.x + PLANE_WEGHT))
            {
                Boom boom = Boom(plane.x +50, plane.y);
                boom.paint();
                plane.condition = 1;
                a = a+1;
            }
        }
        else
        {
            shot.x = gun.x + 6;
            shot.y = gun.y;
            kol1 = kol1 + 1;
            a = 0;
        }


        if ((plane.condition == 1) and (a == 1))
        {
            kol = kol + 1;
            cout<<'\b' << ' ' << '\b';
            cout<< kol;
            plane.condition = 0;
        }

        txEnd();
        txSleep(10);
        txClear();

    }
}

