/*
Plan:
-asimptota verticala
-asimptota orizontala
-axe
-minim maxim
Evaluator:
-restrictii fiecare semn1
*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include<winbgim.h>
#include<string.h>
#include<math.h>

#define NMAX 200
#define EPSILON 0.0001

using namespace std;

double MIN,MAX;
int STANGA=250, DREAPTA=1100, TOP=150, BOTTOM=600;
char vect[256];

void click(int &coordxclick, int &coordyclick );
void clickpeGrafic(double &A, double &B, int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic, char fun[256],char capatst[256],char capatdr[256]);
double f(double x);
void aflareminsimax();
void graficfunctie(double A, double B, int culoarefunctie);
void graficnou(double A, double B, int widget,int height,int limba,int culoarerama, int culoaregrafic);
void desenarefunctie(double A, double B,int limba,int culoarerama, int culoaregrafic);
void buton_iesire(int width, int height);
void buton_inapoi(int width, int height);
void fereastraalegeri(int width, int height);
void fereastraprincipala(int width, int height,int ok,int poza,int limba);
void fullscreen(int &width, int &height);
void schimbaresunet(int ok);
void explicatiigrafic(int width,int height,int limba);
void schimbareculoarebuton(int a, int b, int c, int d);
void fereastraGrafic(int width, int height,int ok,int poza,int limba);
void fereastraContact(int width, int height,int ok,int poza,int limba);
void clickpeContact(double A, double B,int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256]);
void clickpefereastrapr(double A, double B,int ok, int poza,int &limba,int culoarerama, int culoaregrafic, char fun[256],char capatst[256],char capatdr[256]);
void clickpefereastraalegeri(double A, double B, int &ok, int &poza, int &limba, int &culoarerama, int &culoaregrafic, char fun[256],char capatst[256],char capatdr[256]);

struct lista{
    char info;
    char inf;
    lista *urm;
    lista *varf;
}*infixata;

double operatie (char r, double x, double y);
double operatie_speciala (char r, double x);
int prioritatecaracter(char a);
void transformarefunctie(char *functie);
double transformaredininfixinpostifx(double x);

void push(lista *&varf, char element);
void push2(lista *&varf, double element);
void pop(lista *&varf );
char top(lista *&varf);
void pune_in_stiva(char *vect);
bool esteVidaS(lista *&Stiva);
void stiva_vida(lista *&Stiva);

double calculareintegralafunctiei(double A, double B, double(*f)(double));

bool discontinuitate(double x);

int main()
{
    int height, width;
    char fun[257],capatst[257],capatdr[257];
    int ok=1;
    int poza=1;
    int limba=1;
    int culoarerama=1;
    int culoaregrafic=1;
    double A,B;
    fullscreen(width, height);
    fereastraalegeri(width,height);
    clickpefereastraalegeri(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
    getch();
    closegraph();
    return 0;
}

double calculareintegralafunctiei(double A, double B, double(*f)(double))
{
    if((B-A)<EPSILON)
        return (B-A)*((*f)(A)+(*f)(B))/2.0;

    else {
            double punctint;
            punctint=(A+B)/2.0;
            return calculareintegralafunctiei(A,punctint,f)+calculareintegralafunctiei(punctint,B,f);
            }
}

bool discontinuitate(double x)
{
        if((floor(f(x-EPSILON))!=floor(f(x+EPSILON)))||(floor(f(x-EPSILON))!=floor(f(x)))||(floor(f(x+EPSILON))!=floor(f(x))))return 1;//punct de discontinuitate
                else return 0;//continuu in x
}

void push(lista *&varf, char element)
{
lista *Stiva;
Stiva=new lista;
Stiva->inf=element;
Stiva->urm = varf;
varf=Stiva;
}

void push2(lista *&varf, double element)
{
lista *Stiva;
Stiva=new lista;
Stiva->inf=element;
Stiva->urm = varf;
varf=Stiva;
}

void pop(lista *&varf )
{
    lista *Stiva=varf;
    varf=varf->urm;
    delete Stiva;

}

char top(lista *&varf)
{
    char element=varf->inf;
    lista *Stiva=varf;
    return element;
}

void pune_in_stiva(char *vect)
{
stiva_vida(infixata);
char *p,val;
p=strtok(vect," ");
while(p)
    {
        strcpy((char*)val,p);
        push(infixata,val);
        p=strtok(NULL," ");
    }
}

bool esteVidaS(lista *&Stiva)//stiva
{
    if(top(Stiva))return 0;
        else return 1;
}

void stiva_vida(lista *&Stiva)
{
    Stiva->varf=NULL;
}

void fereastraalegeri(int width, int height)
{
    initwindow(width,height,"Fereastra principala",-4,-4);
    readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/4," Alegeti:");

    buton_iesire(width, height);

    setfillstyle(0,BLACK);
    bar(width/10,height/3,width/10+200,height/3+200);//fundal
    readimagefile("image1_1.jpg",width/10+50,height/3+10,width/10+150,height/3+80);//imagine de fundal
    readimagefile("Backgrf.jpg",width/10+50,height/3+110,width/10+150,height/3+180);//imagine de fundal

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+100,height/3+230,"Poza fundal");

    bar(width/10+440,height/3,width/10+640,height/3+200);//limba
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+540,height/3+60,"Romana");
    rectangle(width/10+470,height/3+40,width/10+615,height/3+70);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+540,height/3+140,"English");
    rectangle(width/10+470,height/3+120,width/10+615,height/3+150);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+545,height/3+230,"Limba");

    bar(width/10+220,height/3,width/10+420,height/3+200);//sunet
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+315,height/3+60," Sunet inchis");
    rectangle(width/10+245,height/3+40,width/10+400,height/3+70);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+319,height/3+140,"Sunet deschis");
    rectangle(width/10+240,height/3+120,width/10+400,height/3+150);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+310,height/3+230,"Sunet");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/2+250," OK! ");
    rectangle(width/2-52,height/2+226,width/2+50,height/2+260);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR,  2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+760,height/3+230,"Culori rama");
    outtextxy(width/10+760,height/3+250,"grafic");

    bar(width/10+660,height/3,width/10+860,height/3+200);//culori rama

    setfillstyle(1,RED);
    bar(width/10+680,height/3+40,width/10+750,height/3+90);
    setfillstyle(1,YELLOW);
    bar(width/10+770,height/3+40,width/10+840,height/3+90);
    setfillstyle(1,CYAN);
    bar(width/10+680,height/3+110,width/10+750,height/3+160);
    setfillstyle(1,GREEN);
    bar(width/10+770,height/3+110,width/10+840,height/3+160);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR,  2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+980,height/3+230,"Culori grafic");

    setfillstyle(1,BLACK);
    bar(width/10+880,height/3,width/10+1080,height/3+200);//culori grafic

    setfillstyle(1,RED);
    bar(width/10+900,height/3+40,width/10+970,height/3+90);
    setfillstyle(1,YELLOW);
    bar(width/10+990,height/3+40,width/10+1060,height/3+90);
    setfillstyle(1,CYAN);
    bar(width/10+900,height/3+110,width/10+970,height/3+160);
    setfillstyle(1,GREEN);
    bar(width/10+990,height/3+110,width/10+1060,height/3+160);

    buton_iesire(width, height);
}

void clickpefereastraalegeri(double A, double B, int &ok, int &poza,int &limba, int &culoarerama, int &culoaregrafic, char fun[256],char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    int height, width;
    fullscreen(width,height);
    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);
    while(true)
    {

    click(coordx,coordy);
    if(coordx>=(width/2-52)&&coordx<=(width/2+50)&&coordy>=(height/2+226)&&coordy<=(height/2+260))//click pe ok
        {
            a=width/2-52; b=height/2+226; c=width/2+50; d=height/2+260;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            closegraph();
            fereastraprincipala(width,height,ok,poza,limba);
            clickpefereastrapr(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
    else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//click pe exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
    else if(coordx>=(width/10+245)&&coordx<=(width/10+400)&&coordy>=(height/3+40)&&coordy<=(height/3+70))
        {//sunet inchis
            a=width/10+245; b=height/3+40; c=width/10+400; d=height/3+70;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            PlaySound(NULL,0,0);
            ok=0;
        }
     else if(coordx>=(width/10+240)&&coordx<=(width/10+400)&&coordy>=(height/3+120)&&coordy<=(height/3+150))
        {//sunet deschis
            a=width/10+240; b=height/3+120; c=width/10+400; d=height/3+150;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
            ok=1;
        }
    else if(coordx>=(width/10+50)&&coordx<=(width/10+150)&&coordy>=(height/3+10)&&coordy<=(height/3+80))//poza mate
        {
            a=width/10+50; b=height/3+10; c=width/10+150; d=height/3+80;
            schimbaresunet(ok);
            poza=1;
        }
    else if(coordx>=(width/10+50)&&coordx<=(width/10+150)&&coordy>=(height/3+110)&&coordy<=(height/3+180))//poza craciun
        {
            a=width/10+50; b=height/3+110; c=width/10+150; d=height/3+180;
            schimbaresunet(ok);
            poza=0;
        }
    else if(coordx>=(width/10+470)&&coordx<=(width/10+615)&&coordy>=(height/3+40)&&coordy<=(height/3+70))//buton romana
    {
        a=width/10+470; b=height/3+40; c=width/10+615; d=height/3+70;
        schimbareculoarebuton(a,b,c,d);
        rectangle(a,b,c,d);
        schimbaresunet(ok);
        limba=1;
    }

    else if(coordx>=(width/10+470)&&coordx<=(width/10+615)&&coordy>=(height/3+120)&&coordy<=(height/3+150))//buton engleza
    {
        a=width/10+470; b=height/3+120; c=width/10+615; d=height/3+150;
        schimbareculoarebuton(a,b,c,d);
        rectangle(a,b,c,d);
        schimbaresunet(ok);
        limba=0;
    }
    else if(coordx>=(width/10+680)&&coordx<=(width/10+750)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//rama rosu
        {
        schimbaresunet(ok);
        culoarerama=1;
        }
    else if(coordx>=(width/10+770)&&coordx<=(width/10+840)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//rama galben
    {
        schimbaresunet(ok);
        culoarerama=2;
    }
    else if(coordx>=(width/10+680)&&coordx<=(width/10+750)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//rama cyan
    {
        schimbaresunet(ok);
        culoarerama=3;
    }
    else if(coordx>=(width/10+770)&&coordx<=(width/10+840)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//rama verde
    {
        schimbaresunet(ok);
        culoarerama=4;
    }

    else if(coordx>=(width/10+900)&&coordx<=(width/10+970)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//functie rosu
        {
        schimbaresunet(ok);
        culoaregrafic=1;
    }
    else if(coordx>=(width/10+990)&&coordx<=(width/10+1060)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//functie galben
    {
        schimbaresunet(ok);
        culoaregrafic=2;
    }
    else if(coordx>=(width/10+900)&&coordx<=(width/10+970)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//functie cyan
    {
        schimbaresunet(ok);
        culoaregrafic=3;
    }
    else if(coordx>=(width/10+990)&&coordx<=(width/10+1060)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//functie verde
    {
        schimbaresunet(ok);
        culoaregrafic=4;
    }

    }
}

void click(int &coordxclick, int &coordyclick )
{//functie pentru click
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}

double f(double x)
{
    return sin(x);
    //return transformaredininfixinpostifx(x);
}

void aflareminsimax(double A, double B)
{//aflare min max
    int i;
    double x,y;
    MIN=100000001;
    MAX=-MIN;
    for(i=0;i<=(DREAPTA-STANGA);i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);//functia introdusa de la la fereastra in casuta de text
        MAX=max(MAX,y);//noul max in y
        MIN=min(MIN,y);//noul min in y
    }
}

void graficfunctie(double A, double B, int culoaregrafic)
{//trasare linie grafic pt toate punctele
    int i;
    double x,y,xecran,yecran,xpunctactual,ypunctactual;
    double valoriy[NMAX];
    double k=0;
    //double maximgl,minimgl;
    //maximgl=-100000001;
    //minimgl=100000001;
    x=A;
    y=(int)(f(A));
    aflareminsimax(A,B);
    xecran=(DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A);
    yecran=(BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        //if(x==0)
        //if((A>0&&B>0)||(A<0&&B<0)-DOAR OY
             //else if(A<0&&B>0)-OX SI OY
        y=f(x);
        valoriy[k]=y;
        k++;
        xpunctactual=(int)((DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A));
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));

        if(culoaregrafic==1)setcolor(RED);
            else if(culoaregrafic==2)setcolor(YELLOW);
            else if(culoaregrafic==3)setcolor(CYAN);
            else if(culoaregrafic==4)setcolor(GREEN);

        line(xecran,yecran,xpunctactual,ypunctactual);

        if(discontinuitate(x)==1)
        {0
            setcolor(COLOR(18,18,18));
            line(xecran,TOP+2,xecran,BOTTOM-2);
        }

        xecran=xpunctactual;
        yecran=ypunctactual;
    }
    /*
    int k=0;
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));
        vectpunctactual[i]=ypunctactual;
        k++;
        yecran=ypunctactual;
    }

    for(i=0;i<=k;i++)
    {
        maximgl=max(maximgl,vectpunctactual[i]);
        minimgl=min(minimgl,vectpunctactual[i]);
    }

    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));
        if(ypunctactual==maximgl)//e de fapt minim
            {
                setcolor(COLOR(41,27,54));
                line(STANGA,ypunctactual,DREAPTA,ypunctactual);
            }

        if(ypunctactual==minimgl)//e de fapt maxim
            {
                setcolor(COLOR(42,35,80));
                line(STANGA,ypunctactual,DREAPTA,ypunctactual);
            }
        yecran=ypunctactual;
    }
*/
}
void explicatiigrafic(int width, int height, int limba)
{
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    if(limba==1)
    {
        outtextxy(width/2+550,height/4+130,"w/UP: Zoom in");
        outtextxy(width/2+550,height/4+160,"s/DOWN: Zoom out");
        outtextxy(width/2+550,height/4+190,"a/<-: Stanga");
        outtextxy(width/2+550,height/4+220,"d/->: Dreapta");
    }
        else  {
                outtextxy(width/2+550,height/4+130,"w/UP: Zoom in");
                outtextxy(width/2+550,height/4+160,"s/DOWN: Zoom out");
                outtextxy(width/2+550,height/4+190,"a/<-: Left");
                outtextxy(width/2+550,height/4+220,"d/->: Right");
        }
}
void graficnou(double A, double B, int width, int height,int limba,int culoarerama, int culoaregrafic)
{
    double valoareintegrala;
    if(culoaregrafic==1)setcolor(RED);
        else if(culoaregrafic==2)setcolor(YELLOW);
        else if(culoaregrafic==3)setcolor(CYAN);
        else if(culoaregrafic==4)setcolor(GREEN);

    graficfunctie(A,B,culoaregrafic);

    explicatiigrafic(width,height,limba);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1) outtextxy(width/2,height/4-50,"Reprezentarea functiei:");
        else  outtextxy(width/2,height/4-50,"Graph reprezentation:");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)
    {
        outtextxy(width/4+250,height-100,"Integrala:");
        valoareintegrala=calculareintegralafunctiei(A,B,&f);
        char charintegrala[256];
        sprintf(charintegrala," %lf",valoareintegrala);
        outtextxy(width/4+430, height-100,charintegrala);
    }
        else  {
                outtextxy(width/4+250,height-100,"Integrala:");
                valoareintegrala=calculareintegralafunctiei(A,B,&f);
                char charintegrala[256];
                sprintf(charintegrala," %lf",valoareintegrala);
                outtextxy(width/4+430, height-100,charintegrala);
            }

    char car;
    do
        {
            car = getch();
            if(car==KEY_RIGHT||car=='d')//dr
                {
                    cleardevice();
                    A+=2;
                    B+=2;

                    if(culoarerama==1)setcolor(RED);
                        else if(culoarerama==2)setcolor(YELLOW);
                        else if(culoarerama==3)setcolor(CYAN);
                        else if(culoarerama==4)setcolor(GREEN);

                    rectangle(STANGA,TOP,DREAPTA,BOTTOM);

                    setcolor(DARKGRAY);
                    line(STANGA,height/2,DREAPTA, height/2);//axa ox
                    line(width/2,TOP,width/2,BOTTOM);//axa oy

                    explicatiigrafic(width,height,limba);

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 4 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);

                    if(limba==1) outtextxy(width/2,height/4-50,"Reprezentarea functiei:");
                        else  outtextxy(width/2,height/4-50,"Graph reprezentation:");

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 3 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);

                    if(limba==1)
                        {
                            outtextxy(width/4+250,height-100,"Integrala:");
                            valoareintegrala=calculareintegralafunctiei(A,B,&f);
                            char charintegrala[256];
                            sprintf(charintegrala,"%lf",valoareintegrala);
                            outtextxy(width/4+430, height-100,charintegrala);
                        }
                    else  {
                            outtextxy(width/4+250,height-100,"Integrala:");
                            valoareintegrala=calculareintegralafunctiei(A,B,&f);
                            char charintegrala[256];
                            sprintf(charintegrala,"%lf",valoareintegrala);
                            outtextxy(width/4+430, height-100,charintegrala);
                            }

                    graficfunctie(A,B,culoaregrafic);
                }
            else if(car==KEY_LEFT||car=='a')//st
            {
                cleardevice();
                A-=2;
                B-=2;

                if(culoarerama==1)setcolor(RED);
                    else if(culoarerama==2)setcolor(YELLOW);
                    else if(culoarerama==3)setcolor(CYAN);
                    else if(culoarerama==4)setcolor(GREEN);

                rectangle(STANGA,TOP,DREAPTA,BOTTOM);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(width/2,TOP,width/2,BOTTOM);//axa oy

                explicatiigrafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1) outtextxy(width/2,height/4-50,"Reprezentarea functiei:");
                    else  outtextxy(width/2,height/4-50,"Graph reprezentation:");

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                        }

                graficfunctie(A,B,culoaregrafic);
                }
            else if(car=='w'||car==KEY_UP)//ZOOM -
            {
                cleardevice();
                A+=2;
                B-=2;

               if(culoarerama==1)setcolor(RED);
                    else if(culoarerama==2)setcolor(YELLOW);
                    else if(culoarerama==3)setcolor(CYAN);
                    else if(culoarerama==4)setcolor(GREEN);

                rectangle(STANGA,TOP,DREAPTA,BOTTOM);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(width/2,TOP,width/2,BOTTOM);//axa oy

                explicatiigrafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1) outtextxy(width/2,height/4-50,"Reprezentarea functiei:");
                    else  outtextxy(width/2,height/4-50,"Graph reprezentation:");

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }


                graficfunctie(A,B,culoaregrafic);
            }
            else if(car=='s'||car==KEY_DOWN)//ZOOM +
            {
                cleardevice();
                A-=2;
                B+=2;

                if(culoarerama==1)setcolor(RED);
                    else if(culoarerama==2)setcolor(YELLOW);
                    else if(culoarerama==3)setcolor(CYAN);
                    else if(culoarerama==4)setcolor(GREEN);

                rectangle(STANGA,TOP,DREAPTA,BOTTOM);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(width/2,TOP,width/2,BOTTOM);//axa oy

                explicatiigrafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1) outtextxy(width/2,height/4-50,"Reprezentarea functiei:");
                        else  outtextxy(width/2,height/4-50,"Graph reprezentation:");

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        outtextxy(width/4+250,height-100,"Integrala:");
                        valoareintegrala=calculareintegralafunctiei(A,B,&f);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }

                graficfunctie(A,B,culoaregrafic);
            }
        }
    while(car!=13);
}

void desenarefunctie(double A, double B, int limba,int culoarerama,int culoaregrafic)
{//desenare grafic
    int height, width;
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"Fereastra",-4,-4);

    if(culoarerama==1)setcolor(RED);
        else if(culoarerama==2)setcolor(YELLOW);
        else if(culoarerama==3)setcolor(CYAN);
        else if(culoarerama==4)setcolor(GREEN);

    rectangle(STANGA,TOP,DREAPTA,BOTTOM);

    setcolor(DARKGRAY);
    line(STANGA,height/2,DREAPTA, height/2);//axa ox
    line(width/2,TOP,width/2,BOTTOM);//axa oy

    if(culoaregrafic==1)setcolor(RED);
        else if(culoaregrafic==2)setcolor(YELLOW);
        else if(culoaregrafic==3)setcolor(CYAN);
        else if(culoaregrafic==4)setcolor(GREEN);

    graficnou(A,B,width,height,limba,culoarerama,culoaregrafic);//graficul efectiv
}

void buton_iesire(int width, int height)
{//Butonul "Exit"
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/16+10,height/5-120,"Exit");//setari pentru formare buton exit
    rectangle(width/16-31,height/5-145,width/10,height/5-114);
}

void buton_inapoi(int width, int height)
{//Butonul "Back"
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+51,height/5-120,"Back");//setari pentru formare buton back
    rectangle(width/10+10,height/5-145,width/10+90,height/5-114);
}

void fereastraprincipala(int width, int height,int ok, int poza,int limba)
{//fereastra 1

    initwindow(width,height,"Fereastra principala",-4,-4);
    if(poza==1)
        readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal
    else
        readimagefile("Backgrf.jpg",0,0,width,height);//imagine de fundal

    if(ok==1)
    {
        readimagefile("sunetdeschis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);//sunet
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    }
    else
    {
        readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
        PlaySound(NULL,0,0);
    }
    if(limba==1)
        readimagefile("romana.jpg",width-80,height/5-145,width-30,(height/5-115));//steag->romana
    else   readimagefile("engleza.jpg",width-80,(height/5-145),width-30,(height/5-115));

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    if(limba==1)
        outtextxy(width/2,height/4,"Graficul functiei");//setari titlu
        else outtextxy(width/2,height/4,"Function's graphic");//setari titlu


    settextstyle(8, HORIZ_DIR, 6);
    if(limba==1)
        {
            outtextxy(width/2,height/2,"Grafic");
            rectangle(width/2-100,height/2-40,width/2+98,height/2+12);//setari a doua linie de text
        }
        else {
                outtextxy(width/2,height/2,"Graphic");
                rectangle(width/2-119,height/2-40,width/2+118,height/2+12);//setari a doua linie de text
            }

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(width/2,height/2+150,"Contact");
    rectangle(width/2-119,height/2+110,width/2+117,height/2+165);//setari a treia linie de text

    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fullscreen(int &width, int &height)
{//preluare dimensiuni ecran
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
}

void schimbaresunet(int ok)
{  /// sunet buton->sunet fundal
    PlaySound("sunet_buton.wav",NULL,SND_ASYNC);
    delay(100);
    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);
}

void schimbareculoarebuton(int a, int b, int c, int d)
{//galben la apasare->delay->alb
    setcolor(YELLOW);
    rectangle(a,b,c,d);
    delay(120);
    setcolor(WHITE);
    rectangle(a,b,c,d);
}

void fereastraGrafic(int width, int height,int ok,int poza,int limba)
{//fereastra 2

    initwindow(width,height,"Fereastra",-4,-4);

    if(poza==1)
        readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal
    else
        readimagefile("Backgrf.jpg",0,0,width,height);//imagine de fundal

    if(ok==1)
    {
        readimagefile("sunetdeschis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);//sunet
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    }
    else
    {
        readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
        PlaySound(NULL,0,0);
    }

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1) outtextxy(width/2+10,height/4-40,"Introduceti intervalul  aici:");
        else   outtextxy(width/2+10,height/4-40,"Write the interval:");

    setfillstyle(0,BLACK);
    bar(width/2-320,height/4-10,width/4+320,height/4+50);//text 1
    bar(width/4+340,height/4-10,width/4+655,height/4+50);
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)outtextxy(width/2-400,height/4+33,"Stanga:");
        else outtextxy(width/2-395,height/4+33,"Left:");

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

     if(limba==1) outtextxy(width/2+400,height/4+33,":Dreapta");
        else outtextxy(width/2+400,height/4+33,":Right");

    rectangle(width/2-320,height/4-10,width/4+320,height/4+50);//st
    rectangle(width/4+340,height/4-10,width/4+655,height/4+50);//dr

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1) outtextxy(width/2,height/3+40,"Introduceti functia aici:");
        else   outtextxy(width/2,height/3+40,"Write the funtion");

    setfillstyle(0,BLACK);
    bar(width/2-320,height/3+70,width/4+655,height/3+130);//text 2
    setcolor(WHITE);
    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);//text 2

    settextstyle(8, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)outtextxy(width/2,height/2+35,"Evaluator functie");
        else outtextxy(width/2,height/2+35,"Function evaluation");

    setfillstyle(0,BLACK);
    bar(width/2-379,height/2+70,width/2+376,height/2+250);//text 3
    setcolor(WHITE);
    rectangle(width/2-379,height/2+70,width/2+376,height/2+250);//text 3

    settextstyle(8, HORIZ_DIR, 3);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2+500,height/2," OK! ");//buton spre functie
    setcolor(WHITE);
    rectangle(width/2+460,height/2-18,width/2+540,height/2+7);

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fereastraContact(int width, int height,int ok,int poza,int limba)
{//fereastra 3
    initwindow(width,height,"Fereastra",-4,-4);

    if(poza==1)
        readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal
    else
        readimagefile("Backgrf.jpg",0,0,width,height);//imagine de fundal

    if(ok==1)
    {
        readimagefile("sunetdeschis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);//sunet
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    }
    else
    {
        readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
        PlaySound(NULL,0,0);
    }

    settextstyle(8, HORIZ_DIR, 5);
    if(limba==1)  outtextxy(width/2-350,height/2-200,"Proiectul a fost realizat de:");//text 1
        else  outtextxy(width/2-350,height/2-200,"The project was made by:");//text 1

    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(width/2-180,height/2-70,"Ursache Ana-Maria");//text 2

    settextstyle(8, HORIZ_DIR, 4);
    if(limba==1) outtextxy(width/2-30,height/2+8,"si");//text 3
        else outtextxy(width/2-30,height/2+8,"and");//text 3

    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(width/2-160,height/2+80,"Galatanu Emilia");//text 4

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void clickpefereastrapr(double A, double B, int ok, int poza, int &limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    int height, width;
    fullscreen(width,height);

    while(true)
    {

    click(coordx,coordy);
    if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//click pe exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
    else if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12)&&limba==1)
            {//daca se face click pe primul buton: "Grafic"
                a=width/2-100; b=height/2-40; c=width/2+98; d=height/2+12;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                clearmouseclick(WM_LBUTTONUP);
                fereastraGrafic(width,height,ok,poza,limba);
                clickpeGrafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
            }
    else if(coordx>=(width/2-119)&&coordx<=(width/2+118)&&coordy>=(height/2-40)&&coordy<=(height/2+12)&&limba==0)
            {//daca se face click pe "Graph"
                a=width/2-119; b=height/2-40; c=width/2+118; d=height/2+12;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                clearmouseclick(WM_LBUTTONUP);
                fereastraGrafic(width,height,ok,poza,limba);
                clickpeGrafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
            }
    else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
            //daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                a=width/2-119; b=height/2+110; c=width/2+117; d=height/2+165;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                fereastraContact(width, height,ok,poza,limba);
                clickpeContact(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
            }
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115)&&limba==1)//steag-daca se apasa setarea de limba
            {
                schimbaresunet(ok);
                readimagefile("engleza.jpg",width-80,(height/5-145),width-30,(height/5-115));
                limba=0;//se schimba imaginea->engleza
            }
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115)&&limba==0)//steag-daca se apasa setarea de limba
            {
                schimbaresunet(ok);
                readimagefile("romana.jpg",width-80,height/5-145,width-30,(height/5-115));//steag->romana
                limba=1;//se schimba imaginea->romana
            }
    else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }
    }
}

void clickpeGrafic(double &A, double &B, int width, int height,int ok,int poza, int limba, int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    char car, sir[256];
    int x;
    fun[0]=NULL;
    capatst[0]=NULL;
    capatdr[0]=NULL;
    fullscreen(width,height);

    while(true)
    {
    click(coordx,coordy);
    if(coordx>=width/10+10&&coordx<=width/10+90&&coordy>=height/5-145&&coordy<=height/5-114)//back
        {
            a=width/10+10; b=height/5-145; c=width/10+90; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            closegraph();
            fereastraprincipala(width, height,ok,poza,limba);
            clickpefereastrapr(A,B,ok,poza,limba,culoarerama, culoaregrafic,fun,capatst,capatdr);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
        else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&coordy>=(height/2+70)&&coordy<=(height/2+250))
        {
            //daca se apasa caseta cu "Evaluator functie"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-379; b=height/2+70; c=width/2+376; d=height/2+250;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            //pus evaluator

    }
    else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }
    else if(coordx>=(width/2+460)&&coordx<=(width/2+540)&&coordy>=(height/2-18)&&coordy<=(height/2+7))//buton spre functie
        {
            a=width/2+460; b=height/2-18; c=width/2+540; d=height/2+7;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            desenarefunctie(A,B,limba,culoarerama,culoaregrafic);
            closegraph();
        }

else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/3+70)&&coordy<=(height/3+130))
        {
            //daca se apasa caseta cu "Introduceti functia aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/3+70; c=width/4+655; d=height/3+130;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            x=a+30;
            do
            {
            car = getch();
            sir[0]=car;
            sir[1]=NULL;
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                strcat(fun,sir);
                }
            else
                if(strlen(sir)==0)
                    Beep(1000,500);
            else
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                sir[strlen(sir)-1]='\0';
                strcat(fun,sir);
                setcolor(WHITE);
                }
            }
            while(car!=13);
            clickpeGrafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }

    else if(coordx>=(width/2-320)&&coordx<=(width/4+320)&&coordy>=(height/4-10)&&coordy<=(height/4+50))
        {

            a=width/2-320; b=height/4-10; c=width/4+320; d=height/4+50;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
              x=a+30;
            do
            {car = getch();
            sir[0]=car;
            sir[1]=NULL;
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                strcat(capatst,sir);
                }
            else
                if(strlen(sir)==0)
                    Beep(1000,500);
                else
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                sir[strlen(sir)-1]='\0';
                strcat(capatst,sir);
                setcolor(WHITE);
                }
            }
            while(car!=13);
        double A=atof((char*)capatst);
        clickpeGrafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
    else if(coordx>=(width/4+340)&&coordx<=(width/4+655)&&coordy>=(height/4-10)&&coordy<=(height/4+50))
        {

            a=width/4+340; b=height/4-10; c=width/4+655; d=height/4+50;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
             x=a+30;
            do
            {car = getch();
            sir[0]=car;
            sir[1]=NULL;
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                strcat(capatdr,sir);
                }
            else
                if(strlen(sir)==0)
                    Beep(1000,500);
                else
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                sir[strlen(sir)-1]='\0';
                strcat(capatdr,sir);
                setcolor(WHITE);
                }
            }
            while(car!=13);
        double B=atof((char*)capatdr);
        clickpeGrafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
    }
}
void clickpeContact(double A, double B, int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    fullscreen(width, height);
    while(true)
    {

    click(coordx,coordy);
    if(coordx>=width/10+10&&coordx<=width/10+90&&coordy>=height/5-145&&coordy<=height/5-114)//back
        {
            a=width/10+10; b=height/5-145; c=width/10+90; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            closegraph();
            fereastraprincipala(width, height,ok,poza,limba);
            clickpefereastrapr(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }

    }
}

void transformarefunctie(char *fun)
{
    int i=0,nr=0;
    while(i<=strlen(fun)-1)
    {
        if(isdigit(fun[i])!=0)
        {
            while(isdigit(fun[i])!=0)
            {
                vect[nr]=fun[i];
                i++;
                nr++;
            }
        vect[nr]=' ';
        nr++;
        }
        else if(strchr("+-*^/)(",fun[i]))
                {
                    vect[nr]=fun[i];
                    nr++;
                    i=i+1;
                    vect[nr]=' ';
                    nr++;
                }
        else
            if(fun[i]=='x')
            {
                vect[nr]=fun[i];
                nr++;
                i++;
                vect[nr]=' ';
                nr++;
            }
    else
            {
                if(strchr("s",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    i=i+3;
                    vect[nr]=' ';
                    nr++;
                    }
                if(strchr("c",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    i=i+3;
                    vect[nr]=' ';
                    nr++;
                    }
                if(strchr("l",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    i=i+2;
                    vect[nr]=' ';
                    nr++;
                    }
                if(strchr("t",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    }
                if(strchr("g",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    }
                if(strchr("r",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;
                    }


        }
    }
}

double transformaredininfixinpostifx(double x)
{
    char  *operator1[256];
    lista *value,*operatori;
    stiva_vida(value);
    stiva_vida(operatori);

    while(esteVidaS(infixata)==0)
    {
        if(top(infixata)=='(')// (
                {
                    push(operatori,top(infixata));
                    pop(infixata);
                }

        else
             if(top(infixata)=='x')// x=necunoscuta
                 {
                     push(value,x);
                     pop(infixata);
                }

        else
            if(isdigit(top(infixata)))//cifre
            {
                char c=top(infixata);
                double val=atoi((char*)c);
                push(value,val);
                pop(infixata);
            }

        else
            if(strchr("+-/^*",top(infixata)!=0))//semne
                {
                    push(operatori,top(infixata));
                    pop(infixata);
                }

        else
            if(top(infixata)==')')// )
               {
                   push(operatori,top(infixata));
                   pop(infixata);
                   while(top(infixata)!='(')
                    {
                        if(strchr("+-/^*",top(infixata)!=0))
                           {
                               push(operatori,top(infixata));
                               pop(infixata);}
                               if(strchr("scltr",top(infixata)!=0))
                                    {
                                        push(operatori,top(infixata));
                                        pop(infixata);
                                    }
                        else
                            if(top(infixata)=='x')
                                {
                                    push(value,x);
                                    pop(infixata);
                                }
                            else
                                if(isdigit(top(infixata)))
                                    {
                                        char c=top(infixata);
                                        double val=atoi((char*)c);
                                        push(value,val);
                                        pop(infixata);
                                    }

                else
                    if(top(infixata)=='(')
                    while(top(operatori)!=')'&&esteVidaS(operatori)==0)
                    {
                        double valoare1, valoare2,answ;
                        valoare1=top(value);
                        pop(value);
                        valoare2=top(value);
                        pop(value);
                        char operator1=top(operatori);

                        if(operator1=='s'||operator1=='c'||operator1=='l'||operator1=='r'||operator1=='t')
                               {
                                   answ=operatie_speciala(operator1,valoare1);
                                   pop(operatori);
                                }
                        else {
                                answ=operatie(operator1, valoare1, valoare2);
                                pop(operatori);
                            }
                    push2(value,answ);}
                    }
               }
                else
                    {
                    while(esteVidaS(operatori)==0&&
                          prioritatecaracter(top(operatori))>=prioritatecaracter(top(infixata)))
                    {
                        double valoare1, valoare2,ans;
                        valoare1=top(value);
                        pop(value);
                        valoare2=top(value);
                        pop(value);
                        char operator1=top(operatori);
                        if(operator1=='s'||operator1=='c'||operator1=='l'||operator1=='r'||operator1=='t')
                               {
                                   ans=operatie_speciala(operator1,valoare1);
                                   pop(operatori);
                                }
                        else {
                                ans=operatie(operator1, valoare1, valoare2);
                                pop(operatori);
                            }
                        push(value,ans);}

                    push(operatori,top(infixata));
                    }
    while(esteVidaS(operatori)==0)
            {
                double valoare1, valoare2;
                valoare1=top(value);
                pop(value);
                valoare2=top(value);
                pop(value);
                char operator1=top(operatori);
                double ans=operatie(operator1, valoare1, valoare2);
                push(value,ans);
            }
    }
    return top(value);
}

double operatie (char r, double x, double y)
{
    if(r=='+')return x+y;
    if(r=='-')return x-y;
    if(r=='*')return x*y;
    if(r=='/')return x/y;
    if(r=='^')return pow(x,y);
}

double operatie_speciala (char r, double x)
{
    if(r=='s')return sin(x);
    if(r=='c')return cos(x);
    if(r=='l')return log(x);
    if(r=='r')return sqrt(x);
    if(r=='t')return tan(x);
}

int prioritatecaracter(char a)
{
    if(strchr("+",a)||strchr("-",a))return 1;
        else if(strchr("*",a)||strchr("/",a))return 2;
                else if(strchr("^",a))return 3;
                        else if(strchr("scltr",a))return 4;
                                else if(strchr("(",a)||strchr(")",a))return 5;
}
