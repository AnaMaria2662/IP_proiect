/*
Plan:
-limba
-sunet??
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
//#include<windows.h>
//#include<mmsystem.h>
#include <graphics.h>
#include <winbgim.h>
#define MIN 100000001
#define STANGA width/2-500
#define DREAPTA width/2+500
#define TOP height/5+100
#define BOTTOM height/2+200
using namespace std;
//click Ana-Maria
void click(int &coordxclick, int &coordyclick )
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}
//functia sinus neterminata Ana-Maria
int sinus(int x)
{
    if(x!=0)
        return 1;//functia noastra
    else return 0;
}
//aflare min si max Ana-Maria
void aflareminsimax()
{
    int i,x,y,punctmin,punctmax;
    for(i=0;i<=(DREAPTA-STANGA);i++)
    {
        x=A+i*(B-A)/DREAPTA-STANGA);
        y=f(x);
        if((-1)*MIN>y)punctmax=(-1)*MIN;
                else punctmax=y;
        if(MIN>y)punctmin=MIN;
                else punctmin=y;
    }
}
//trasare graficul functiei introduse Ana-Maria
void graficfunctie()
{
    int x,y,xecran,yecran,xpunctactual,ypunctactual,i;
    x=A;
    y=f(x);
    aflareminsimax();
    xecran=(DREAPTA-STANGA)*x/(B-A))+(B*STANGA-A*Dreapta)/(B-A);
    yecran=(BOTTOM-TOP)*y/(punctmax-punctmin))+(PUNCTMAX*TOP-punctmin*BOTTOM)/(punctmax-punctmin);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        xpunctactual=(int)((DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A));
        ypunctactual=(int)((BOTTOM-TOP)*y/(punctmax-punctmin)+(punctmax*TOP-punctmin*BOTTOM)/(punctmax-punctmin));
        line(xecran,yecran,xpunctactual,ypunctctual);
        xecran=xpunctactual;
        yecran=ypunctactual;
    }
}
int main()
{
    int A,B,coordx, coordy, height, width;
    //interval Ana-Maria
    cout<<"Introduceti capetele intervalului in care doriti sa observati graficul functiei:";
    cin>>A>>B;
    cout<<"Intervalul este:"<<"["<<A<<","<<B<<"]";
    delay(500);

    //window initialization Emilia
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height);

    //sunet Ana-Maria
    //PlaySound(TEXT("sound2.wav"),NULL,SND_ASYNC);

    //background image Ana-Maria
    readimagefile("image1_1.jpg",0,0,width,height);

    //imagine pt limba romana Ana-Maria
    readimagefile("romana.jpg",width-80,(height/5-140),width-30,(height/5-115));

    //text Ana-Maria+Emilia
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/4,"Graficul functiei");
    rectangle(width/2-428,height/2-253,width/2+425,height/2-172);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(width/2,height/2,"Grafic");
    rectangle(width/2-100,height/2-40,width/2+98,height/2+12);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(width/2,height/2+150,"Contact");
    rectangle(width/2-119,height/2+110,width/2+117,height/2+165);

    //buttons Ana-Maria
    click(coordx,coordy);
    if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&
                    coordy>=(height/2-40)&&coordy<=(height/2+12))
        {//Emilia
            initwindow(width,height);
            readimagefile("image1_1.jpg",0,0,width,height);
            settextstyle(8, HORIZ_DIR, 6 );
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(width/2,height/4-10,"Introduceti functia aici:");
            rectangle(width/2-379,height/3-10,width/2+376,height/4+15);
            settextstyle(8, HORIZ_DIR, 5 );
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(width/2,height/2-20,"Evaluator functie");
            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
            getch();
            closegraph();
        }
        //Ana-Maria
        else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                    coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
                initwindow(width,height);
                readimagefile("image1_1.jpg",0,0,width,height);
                settextstyle(8, HORIZ_DIR, 5);
                outtextxy(width/2-350,height/2-200,"Proiectul a fost realizat de:");
                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-180,height/2-70,"Ursache Ana-Maria");
                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-30,height/2+8,"si");
                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-160,height/2+80,"Galatanu Emilia");
                getch();
                closegraph();
            }
                //pentru limba engleza Ana-Maria
                else if(coordx>=(width-80)&&coordx<=(width-30)&&
                            coordy>=(height/5-140)&&coordy<=(height/5-115))
                        readimagefile("engleza.jpg",width-80,(height/5-140),width-30,(height/5-115));

    getch();
    closegraph();
    return 0;
}
