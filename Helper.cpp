#include "Drawing lib.h"
#include "TXLib.h"

int main()
{
    Background background = Background(125, 425); //Цифры в скобках - точка отсчёта для рисования фона(вершина первой елки)
    Base gun = Base(840, 20); //Цифры в скобках - точка отсчёта для рисования базы(вершина дула)
    Plane plane = Plane(840, 200); //Цифры в скобках - точка отсчёта для рисования самолета(вершина хвост самолёта)
    Bullet shot = Bullet(840, 350); //Цифры в скобках - точка отсчёта для рисования пули(центр пули)

    txCreateWindow(1024, 600);
    txSetColour(TX_BLACK);
    background.paint();
    txTextOut(0,0, "Example of background");

    txSetColour(TX_WHITE);
    txTextOut(800,0, "Example of base gun");
    gun.paint();

    txSetColour(TX_WHITE);
    txTextOut(800,160, "Example of plane");
    plane.paint();

    txSetColour(TX_WHITE);
    txTextOut(800,300, "Example of shot");
    shot.paint();
}
