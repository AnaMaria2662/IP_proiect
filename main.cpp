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
#include<mmsystem.h>
#include<graphics.h>
#include<winbgim.h>
#include<cstring>
#define MIN 100000001
#define STANGA 500
#define DREAPTA 1000
#define TOP 0
#define BOTTOM 0
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
//functia  neterminata Ana-Maria
int f(int x)
{
    if(x!=0)
        return  0;//functia noastra
    else return 0;
}
//aflare min si max Ana-Maria
void aflareminsimax(int A, int B)
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

//trasare graficul functiei introduse Ana-Maria
void graficfunctie(int A, int B,int punctmax, int punctmin)
{
    int x,y,xecran,yecran,xpunctactual,ypunctactual,i;
    x=A;
    y=f(x);
    aflareminsimax(A,B);
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
    //Ana-Maria
    char s[256];
    int i;
    if(strstr(s,"sin"))
            for(i=0;i<=strlen(s)-1;i++)
                {

                }
    int A,B,coordx, coordy, height, width;
    cout<<"Introduceti capetele intervalului in care doriti sa observati graficul functiei:";
    cin>>A>>B;
    cout<<"Intervalul este:"<<"["<<A<<","<<B<<"]";
    delay(500);

    //window initialization Emilia
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height);

    //sunet Ana-Maria
    PlaySound("sound2.wav",NULL,SND_ASYNC);

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

    //Emilia
    settextstyle(8, HORIZ_DIR, 3 );
    outtextxy(width/16,height/8,"Exit");
    click(coordx,coordy);
    if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
        exit(1);

    //buttons Ana-Maria
    click(coordx,coordy);
    if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&
                 coordy>=(height/2-40)&&coordy<=(height/2+12))
        {   setcolor(YELLOW);
            rectangle(width/2-100, height/2-40, width/2+98,height/2+12);
            //Emilia
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

            //Ana-Maria
            clearmouseclick(WM_LBUTTONDOWN);
            click(coordx,coordy);
            if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&
                 coordy>=(height/2-10)&&coordy<=(height/2+15))
                 {
                    setcolor(YELLOW);
                    rectangle(width/2-379,height/2-10,width/3+376,height/4+15);
                    //aici trebuie sa facem caseta de text
                 }
                 else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&
                                coordy>=(height/2+20)&&coordy<=(height/2+250))
                        {
                            setcolor(YELLOW);
                            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
                            //aici trebuie sa scriem ce tine de evaluator
                        }
            settextstyle(8, HORIZ_DIR, 3 );
            outtextxy(width-141,height/16-5,"Exit");
            click(coordx,coordy);
            if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                exit(1);
            getch();
            closegraph();
        }
        //Ana-Maria
        else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                    coordy>=(height/2+110)&&coordy<=(height/2+165))
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
                outtextxy(width-1410,height/16-5,"Exit");
                click(coordx,coordy);
                if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                        exit(1);
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
