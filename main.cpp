/*
Plan:
-limba
-interval
-text pe pag de functie
-buton sunet
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
#include<windows.h>
#include<graphics.h>
#include<winbgim.h>
#include<cstring>
#define MIN 100000001
using namespace std;
void click(int &coordxclick, int &coordyclick )
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}
int f(int x)
{
    if(x!=0)
        return  0;
    else return 0;
}
void aflareminsimax(int A, int B, int DREAPTA,int STANGA)
{
    int i,x,y,punctmin,punctmax;
    for(i=0;i<=(DREAPTA-STANGA);i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);
        if((-1)*MIN>y)punctmax=(-1)*MIN;
                else punctmax=y;
        if(MIN>y)punctmin=MIN;
                else punctmin=y;
    }
}

void graficfunctie(int A,int B,int punctmax,int punctmin,int DREAPTA,int STANGA,int BOTTOM,int TOP)
{
    int x,y,xecran,yecran,xpunctactual,ypunctactual,i;
    x=A;
    y=f(x);
    aflareminsimax(A,B,DREAPTA,STANGA);
    xecran=((DREAPTA-STANGA)*x/(B-A))+(B*STANGA-A*DREAPTA)/(B-A);
    yecran=((BOTTOM-TOP)*y/(punctmax-punctmin))+(punctmax*TOP-punctmin*BOTTOM)/(punctmax-punctmin);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        xpunctactual=(int)((DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A));
        ypunctactual=(int)((BOTTOM-TOP)*y/(punctmax-punctmin)+(punctmax*TOP-punctmin*BOTTOM)/(punctmax-punctmin));
        line(xecran,yecran,xpunctactual,ypunctactual);
        xecran=xpunctactual;
        yecran=ypunctactual;
    }
}

int main()
{
    int STANGA,DREAPTA,TOP,BOTTOM;
    int coordx, coordy;
    char s[256];
    int i,A,B;
    cin.getline(s,256);
    if(strstr(s,"sin"))
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return;
                }
        else if(strstr(s,"cos"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return;
                }
        }
        else if(strstr(s,"tg"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return;
                }
        }
        else if(strstr(s,"ctg"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return;
                }
        }
        else if(strstr(s,"log"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return;
                }
        }

    cin>>A>>B;
    int height, width;
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height);
    STANGA=0;
    DREAPTA=width;
    TOP=0;
    BOTTOM=height;
    PlaySound("sound2.wav",NULL,SND_ASYNC);
    readimagefile("image1_1.jpg",0,0,width,height);
    readimagefile("romana.jpg",width-80,(height/5-140),width-30,(height/5-115));
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
    settextstyle(8, HORIZ_DIR, 3 );
    outtextxy(width/16,height/8,"Exit");
    click(coordx,coordy);
    if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12))
        {
            setcolor(YELLOW);
            rectangle(width/2-100, height/2-40, width/2+98,height/2+12);
            initwindow(width,height);
            readimagefile("image1_1.jpg",0,0,width,height);
            settextstyle(8, HORIZ_DIR, 4 );
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(width/4,height/4-10,"Introduceti functia aici:");
            rectangle(width/3-379,height/3-10,width/4+376,height/4+15);
            settextstyle(8, HORIZ_DIR, 5 );
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            outtextxy(width/2,height/2-20,"Evaluator functie");
            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
            setcolor(WHITE);
            settextstyle(8, HORIZ_DIR, 3 );
            outtextxy(width-141,height/16-5,"Exit");
            clearmouseclick(WM_LBUTTONUP);
            click(coordx,coordy);
            if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&coordy>=(height/2-10)&&coordy<=(height/2+15))
                 {
                    setcolor(YELLOW);
                    rectangle(width/2-379,height/2-10,width/2+376,height/2+15);
                 }
                 else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&coordy>=(height/2+20)&&coordy<=(height/2+250))
                        {
                            setcolor(YELLOW);
                            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
                        }
                        else if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                                    exit(1);
            getch();
            closegraph();
        }
        else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
                setcolor(YELLOW);
                rectangle(width/2-119, height/2+110, width/2+117,height/2+165);
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
                settextstyle(8, HORIZ_DIR, 3 );
                outtextxy(width-1310,height/16-5,"Exit");
                click(coordx,coordy);
                if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                        exit(1);
                getch();
                closegraph();
            }
                else if(coordx>=(width-80)&&coordx<=(width-30)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                        readimagefile("engleza.jpg",width-80,(height/5-140),width-30,(height/5-115));
                        else if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                                exit(1);
    getch();
    closegraph();
    return 0;
}
