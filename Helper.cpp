#include "Drawing lib.h"
#include "TXLib.h"

int main()
{
    Background background = Background(125, 425); //����� � ������� - ����� ������� ��� ��������� ����(������� ������ ����)
    Base gun = Base(840, 20); //����� � ������� - ����� ������� ��� ��������� ����(������� ����)
    Plane plane = Plane(840, 200); //����� � ������� - ����� ������� ��� ��������� ��������(������� ����� �������)
    Bullet shot = Bullet(840, 350); //����� � ������� - ����� ������� ��� ��������� ����(����� ����)

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
