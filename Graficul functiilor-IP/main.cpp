/*
Plan:
-transformare in plan complet/full screen
-poza de la zona cu functia si evaluatorul
-limba
-sunet
-poate integrala, zoom, stanga dreapta
Grafic:
-punct minim
-punct maxim
-asimptota verticala
-asimptota orizontala
-grafic efectiv cu linii
-transformare sir caractere->functie
-puncte de discontinuitate
Evaluator:
-restrictii fiecare semn
-stive?
*/
#include<iostream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;
//Ana-Maria
void click(int &coordxclick, int &coordyclick )
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}
int main()
{
    //Ana-Maria Ursache
    int coordx, coordy;
    initwindow(800,800);
    readimagefile("image1_1.jpg",0,0,800,800);

    setcolor(WHITE);
    settextstyle(5, HORIZ_DIR, 6);
    outtextxy(200,190,"Graficul functiei");
    rectangle(180,180,590,260);

    setcolor(WHITE);
    settextstyle(7, HORIZ_DIR, 3);
    outtextxy(355,340,"Grafic");
    rectangle(339,330,440,370);

    setcolor(WHITE);
    settextstyle(7, HORIZ_DIR, 3);
    outtextxy(350,440,"Contact");
    rectangle(330,430,460,470);

    click(coordx,coordy);
    if(coordx>=339&&coordx<=440&&coordy>=330&&coordy<=370)
        {
            initwindow(800,800);
            ....//de facut urmatoarea fereastra
            getch();
            closegraph();
        }
        else if(coordx>=330&&coordx<=460&&coordy>=430&&coordy<=470)
            {
                initwindow(800,800);
                settextstyle(7, HORIZ_DIR, 5);
                outtextxy(100,200,"Proiectul a fost realizat de:");
                settextstyle(7, HORIZ_DIR, 4);
                outtextxy(200,350,"Ursache Ana-Maria");
                settextstyle(7, HORIZ_DIR, 3);
                outtextxy(380,400,"si");
                settextstyle(7, HORIZ_DIR, 4);
                outtextxy(250,450,"Galatanu Emilia");
                getch();
                closegraph();
            }
    getch();
    closegraph();
    return 0;
}
