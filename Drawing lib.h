#include "TXLib.h";
/**
    *\brief This structure create shoot
    *
    * This function creates a bullet to hit the aircraft
    *
    **/
struct Bullet
{
    int test;
    int x;
    int y;
    bool condition;

    Bullet(int initX, int initY)
    {
        x = initX;
        y = initY;
    }

    void paint()    //создание пули
    {
        txSetFillColour(RGB(255, 69, 0));
        txCircle(x, y, 5);
        txSetFillColour(TX_WHITE);
    }
};
/**
    *\brief This structure create plane
    *\param[in] x X-coordinate of a plane
    *\param[in] y Y-coordinate of a plane
    *\param[in] condition Condition of a plane
    *
    * This function creates a plane
    *
    **/
struct Plane
{
    int x;
    int y = 20;
    int condition = 0;

    Plane(int initX, int initY)
    {
        x = initX;
        y = initY;
    }
    void paint()    //создание самолёта
    {
        txSetColour(TX_BLACK);
        txSetFillColour(RGB(105, 105, 105));
        POINT plane[22] = {{x, y}, {x+15, y+15}, {x+60, y+15}, {x+30, y-10}, {x+20, y-10}, {x+20, y-15}, {x+30, y-15}, {x+95, y+15}, {x+110, y+15}, {x+120, y+20},
            {x+110, y+25}, {x+95, y+25}, {x+30, y+55}, {x+20, y+55}, {x+20, y+50}, {x+30, y+50}, {x+60, y+25}, {x+15, y+25}, {x, y+40}, {x, y+30}, {x+10, y+20}, {x, y+10}
        };
        txPolygon (plane, 22);
    }
};
/**
    *\brief This structure create boom
    *\param[in] x X-coordinate of a boom
    *\param[in] y Y-coordinate of a boom
    *
    * This function creates a boom, when shoot hits the plane
    *
    **/
struct Boom
{
    int x;
    int y;

    Boom(int initX, int initY)
    {
        x = initX;
        y = initY;
    }

    void paint()    //создание взрыва
    {
        txSetColour(RGB(128, 0, 0));
        txSetFillColour(RGB(244, 164, 96));
        POINT boom[14] = {{x, y}, {x+10, y-20}, {x+10, y}, {x+35, y-10}, {x+15, y-10}, {x+35, y+20}, {x+10, y+20}, {x+20, y+40}, {x, y+20}, {x-20, y+40}, {x-10, y+20},
            {x-50, y+20}, {x-10, y}, {x-20, y-20}};
        txPolygon (boom, 14);
        txSetFillColour(TX_WHITE);
    }
};
 /**
    *\brief This structure create base
    *\param[in] x X-coordinate of a base
    *\param[in] y Y-coordinate of a base
    *
    * This function creates a base, where shoots go away
    *
    **/
struct Base
{
    int x;
    int y;

    Base(int initX, int initY)
    {
        x = initX;
        y = initY;
    }

    void paint()    //создание каретки
    {
        txRectangle(x, y, x+12, y+50);
        txRectangle(x-31, y+50, x+44, y+75);
        txCircle(x-19, y+87, 12);
        txCircle(x+31, y+87, 12);

    }
};
/**
    *\brief This structure create background
    *\param[in] x X-coordinate of a background
    *\param[in] y Y-coordinate of a background
    *
    * This function creates background
    *
    **/
struct Background
{
    int x;
    int y;

    Background(int initX, int initY)
    {
        x = initX;
        y = initY;
    }

    void paint()    //создание заднего фона
    {
            txSetFillColour(RGB(173, 216, 230));
            txRectangle(0, 0, 800, 374);

            txSetFillColour(RGB(154, 205, 50));
            txRectangle(0, 376, 800, 600);

            txSetColour(TX_BLACK);
            txLine(0, 375, 800, 375);

            txSetColour(TX_GREEN);
            x = 125;
            y = 425;
            txSetFillColour(RGB(50, 205, 50));
            POINT tree[15] = {{x, y}, {x, y-12}, {x-75, y-12}, {x-12, y-100}, {x-62, y-100}, {x, y-162}, {x-37, y-162}, {x+12, y-212}, {x+50, y-162}, {x+12, y-162},
                {x+75, y-100}, {x+25, y-100}, {x+87, y-12}, {x+12, y-12}, {x+12, y}};
            txPolygon(tree, 15);
            txSetFillColour(TX_WHITE);

            txSetColour(TX_GREEN);
            x = 675;
            y = 525;
            txSetFillColour(RGB(50, 205, 50));
            POINT tree1[15] = {{x, y}, {x, y-12}, {x-75, y-12}, {x-12, y-100}, {x-62, y-100}, {x, y-162}, {x-37, y-162}, {x+12, y-212}, {x+50, y-162}, {x+12, y-162},
                {x+75, y-100}, {x+25, y-100}, {x+87, y-12}, {x+12, y-12}, {x+12, y}};
            txPolygon(tree1, 15);
            txSetFillColour(TX_WHITE);

            x = 300;
            y = 125;
            txSetColour(TX_BLACK);
            txSetFillColour(TX_WHITE);
            txCircle(x, y, 25);
            txCircle(x - 37, y, 12);
            txCircle(x + 37, y, 12);

            x = 550;
            y = 200;
            txSetColour(TX_BLACK);
            txSetFillColour(TX_WHITE);
            txCircle(x, y, 25);
            txCircle(x - 37, y, 12);
            txCircle(x + 37, y, 12);

            x = 675;
            y = 75;
            txSetColour(TX_BLACK);
            txSetFillColour(TX_WHITE);
            txCircle(x, y, 25);
            txCircle(x - 37, y, 12);
            txCircle(x + 37, y, 12);

    }
};

