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
void click(int &coordxclick, int &coordyclick )//functie prin care observam daca se apasa click stanga de la mouse
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}//Ana-Maria
int main()
{
    //Ana-Maria Ursache
    int coordx, coordy;//coordonate unui punct in care se va face click
    initwindow(800,800);//fereastra
    readimagefile("image1_1.jpg",0,0,800,800);//imagine de fundal

    setcolor(WHITE); //culoare text
    settextstyle(5, HORIZ_DIR, 6);//fontul si stilul textului
    outtextxy(200,190,"Graficul functiei");//text
    rectangle(180,180,590,260);//dreptunghi

    setcolor(WHITE);//culoare text
    settextstyle(7, HORIZ_DIR, 3);//fontul si stilul textului
    outtextxy(355,340,"Grafic");//text
    rectangle(339,330,440,370);//dreptunghi

    setcolor(WHITE);//culoare text
    settextstyle(7, HORIZ_DIR, 3);//fontul si stilul textului
    outtextxy(350,440,"Contact");//text
    rectangle(330,430,460,470);//dreptunghi

    click(coordx,coordy);//click
    if(coordx>=339&&coordx<=440&&coordy>=330&&coordy<=370)//daca se apasa pe "Grafic"
        {
            initwindow(800,800);//Ana-Maria
            //Emilia
            ...
            //Emilia
            getch();
            closegraph();
        }
        else if(coordx>=330&&coordx<=460&&coordy>=430&&coordy<=470)//daca se apasa pe "Contact"
            {
                initwindow(800,800);
                settextstyle(7, HORIZ_DIR, 5);//fontul si stilul textului
                outtextxy(100,200,"Proiectul a fost realizat de:");//text
                settextstyle(7, HORIZ_DIR, 4);//fontul si stilul textului
                outtextxy(200,350,"Ursache Ana-Maria");//text
                settextstyle(7, HORIZ_DIR, 3);//fontul si stilul textului
                outtextxy(380,400,"si");//text
                settextstyle(7, HORIZ_DIR, 4);//fontul si stilul textului
                outtextxy(250,450,"Galatanu Emilia");//text
                getch();
                closegraph();
            }
    getch();
    closegraph();
    return 0;
}
