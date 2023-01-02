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
double minim, maxim;
char fun[256];
int STANGA=250, DREAPTA=1100, TOP=150, BOTTOM=600;
char vect[256];
int k,k2,v[50], contorev;

struct nod{
    double info;
    char inf;
    nod *urm;
};

nod *infixata,*postfixata,*S,*p,*varf,*prim,*ultim;

//stive:
void push(nod *&varf, char element);
void push2(nod *&varf, double element);
void pop(nod *&varf );
bool esteVidaS(nod *&Stiva);
void stivaVida(nod *&S);

//cozi:
void eliminare(nod *&postfixata);
void inserare(nod *&postfixata, char element);
bool esteVidaC(nod *&prim);
void coadaVida(nod *&prim);

//dimensiuni:
void fullscreen(int &width, int &height);


//ferestre:
void fereastra_cu_graficul_desenat(double A, double B,int limba,int culoarerama, int culoaregrafic);
void fereastra_de_alegeri(int width, int height);
void fereastra_principala(int width, int height,int ok,int poza,int limba);
void fereastra_Grafic(int width, int height,int ok,int poza,int limba);
void fereastra_Contact(int width, int height,int ok,int poza,int limba);
void explicatii_grafic(int width,int height,int limba);
void buton_iesire(int width, int height);
void buton_inapoi(int width, int height);


//click:
void click(int &coordxclick, int &coordyclick );
void schimbare_sunet(int ok);
void schimbare_culoare_buton(int a, int b, int c, int d);
void click_pe_Grafic(double &A, double &B, int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic, char capatst[256],char capatdr[256]);
void click_pe_Contact(double A, double B,int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256]);
void click_pe_fereastra_pr(double A, double B,int ok, int poza,int &limba,int culoarerama, int culoaregrafic, char fun[256],char capatst[256],char capatdr[256]);
void click_pe_fereastra_de_alegeri(double A, double B, int &ok, int &poza, int &limba, int &culoarerama, int &culoaregrafic, char fun[256],char capatst[256],char capatdr[256]);


//functie:
double functie(double x);
double calculare_integrala_functiei(double A, double B, double(*f)(double));
bool discontinuitate(double x);
void aflare_min_si_max();
void aflare_min_max_din_interval(double A, double B, double &minim, double &maxim);
void desenare_grafic_functie(double A, double B, int culoarefunctie);
void redesenare_grafic(double A, double B, int widget,int height,int limba,int culoarerama, int culoaregrafic);
double operatie (char r, double x, double y);
double operatie_speciala (char r, double x);
int prioritate_caracter(char a);
void transformare_functie(char *functie);
void transformare_din_infix_in_postinfx();
double calculare_f_din_postf(double x);


//evaluator:
void evaluator();
void evaluare_interval(int width, int height,double A, double B);
void mesaj_evaluator(int width, int height);


int main()
{
    int height, width;
    char capatst[257],capatdr[257];
    int ok=1;
    int poza=1;
    int limba=1;
    int culoarerama=1;
    int culoaregrafic=1;
    double A,B;
    A=B=0;
    fullscreen(width, height);
    fereastra_de_alegeri(width,height);
    click_pe_fereastra_de_alegeri(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
    getch();
    closegraph();
    return 0;
}


//stive
void push(nod *&varf, char element)
{
nod *Stiva;
Stiva=new nod;
Stiva->inf=element;
Stiva->urm = varf;
varf=Stiva;
}

void push2(nod *&varf, double element)
{
nod *Stiva;
Stiva=new nod;
Stiva->info=element;
Stiva->urm = varf;
varf=Stiva;
}

void pop(nod *&varf )
{
    nod *Stiva=varf;
    varf=varf->urm;
    delete Stiva;

}

bool esteVidaS(nod *&Stiva)//stiva
{
    if(Stiva==NULL)return 1;
        else return 0;
}

void stivaVida(nod *&S)
{
    S=NULL;
}


//cozi
void eliminare(nod *&postfixata)
{
    nod *q;
    q=postfixata;
    postfixata=postfixata->urm;
    delete q;
 }

void inserare(nod *&postfixata, char element)
{
  nod *q =new nod;
  q->inf=element;
  q->urm=NULL;
  if(postfixata==NULL)
    postfixata=q;
  else
  {
    nod *p=postfixata;
    while(p->urm!=NULL)
      p=p->urm;
    p->urm=q;
  }
}

bool esteVidaC(nod *&prim)//coada
{
    if(prim==NULL)
    return 1;
else
    return 0;
}

void coadaVida(nod *&prim)
{
    prim=NULL;
}


//dimensiuni:
void fullscreen(int &width, int &height)
{
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
}


//ferestre
void fereastra_de_alegeri(int width, int height)
{
    initwindow(width,height,"Fereastra principala",-4,-4);
    readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    char t[256];
    strcpy(t,"Alegeti:");
    outtextxy(width/2,height/4,t);

    buton_iesire(width, height);

    setfillstyle(0,BLACK);
    bar(width/10,height/3,width/10+200,height/3+200);//fundal
    readimagefile("image1_1.jpg",width/10+50,height/3+10,width/10+150,height/3+80);//imagine de fundal
    readimagefile("Backgrf.jpg",width/10+50,height/3+110,width/10+150,height/3+180);//imagine de fundal

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Poza fundal");
    outtextxy(width/10+100,height/3+230,t);

    bar(width/10+440,height/3,width/10+640,height/3+200);//limba
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Romana");
    outtextxy(width/10+540,height/3+60,t);
    rectangle(width/10+470,height/3+40,width/10+615,height/3+70);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"English");
    outtextxy(width/10+540,height/3+140,t);
    rectangle(width/10+470,height/3+120,width/10+615,height/3+150);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Limba");
    outtextxy(width/10+545,height/3+230,t);

    bar(width/10+220,height/3,width/10+420,height/3+200);//sunet
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t," Sunet inchis");
    outtextxy(width/10+315,height/3+60,t);
    rectangle(width/10+245,height/3+40,width/10+400,height/3+70);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Sunet deschis");
    outtextxy(width/10+319,height/3+140,t);
    rectangle(width/10+240,height/3+120,width/10+400,height/3+150);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Sunet");
    outtextxy(width/10+310,height/3+230,t);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t," OK! ");
    outtextxy(width/2,height/2+250,t);
    rectangle(width/2-52,height/2+226,width/2+50,height/2+260);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR,  2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Culori rama");
    outtextxy(width/10+760,height/3+230,t);
    strcpy(t,"grafic");
    outtextxy(width/10+760,height/3+250,t);

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
    strcpy(t,"Culori grafic");
    outtextxy(width/10+980,height/3+230,t);

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

void fereastra_cu_graficul_desenat(double A, double B, int limba,int culoarerama,int culoaregrafic)
{
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
    line(DREAPTA-7,height/2-7,DREAPTA,height/2);
    line(DREAPTA-7,height/2+7,DREAPTA,height/2);

    if(culoaregrafic==1)setcolor(RED);
        else if(culoaregrafic==2)setcolor(YELLOW);
        else if(culoaregrafic==3)setcolor(CYAN);
        else if(culoaregrafic==4)setcolor(GREEN);

    redesenare_grafic(A,B,width,height,limba,culoarerama,culoaregrafic);//graficul efectiv
}

void fereastra_principala(int width, int height,int ok, int poza,int limba)
{
    char t[256];
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
    {
        strcpy(t,"Graficul functiei");
        outtextxy(width/2,height/4,t);//setari titlu
    }
        else {
                strcpy(t,"Function's graphic");
                outtextxy(width/2,height/4,t);//setari titlu
            }

    settextstyle(8, HORIZ_DIR, 6);
    if(limba==1)
        {
            strcpy(t,"Grafic");
            outtextxy(width/2,height/2,t);
            rectangle(width/2-100,height/2-40,width/2+98,height/2+12);//setari a doua linie de text
        }
        else {
                strcpy(t,"Graphic");
                outtextxy(width/2,height/2,t);
                rectangle(width/2-119,height/2-40,width/2+118,height/2+12);//setari a doua linie de text
            }

    settextstyle(8, HORIZ_DIR, 6);
    strcpy(t,"Contact");
    outtextxy(width/2,height/2+150,t);
    rectangle(width/2-119,height/2+110,width/2+117,height/2+165);//setari a treia linie de text

    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fereastra_Grafic(int width, int height,int ok,int poza,int limba)
{
    char t[256];
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

    if(limba==1)
        {
            strcpy(t,"Introduceti intervalul aici:");
            outtextxy(width/2+10,height/4-40,t);
        }
        else   {
                strcpy(t,"Write the interval:");
                outtextxy(width/2+10,height/4-40,t);
                }

    setfillstyle(0,BLACK);
    bar(width/2-320,height/4-10,width/4+320,height/4+50);//text 1
    bar(width/4+340,height/4-10,width/4+655,height/4+50);
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)
    {
        strcpy(t,"Stanga:");
        outtextxy(width/2-400,height/4+33,t);
    }
        else {
                strcpy(t,"Left:");
                outtextxy(width/2-395,height/4+33,t);
            }

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

     if(limba==1) {
                    strcpy(t,":Dreapta");
                    outtextxy(width/2+400,height/4+33,t);
                    }
        else {
                strcpy(t,":Right");
                outtextxy(width/2+400,height/4+33,t);
            }

    rectangle(width/2-320,height/4-10,width/4+320,height/4+50);//st
    rectangle(width/4+340,height/4-10,width/4+655,height/4+50);//dr

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1) {
                strcpy(t,"Introduceti functia aici:");
                outtextxy(width/2,height/3+40,t);
                }
        else   {
                strcpy(t,"Write the funtion");
                outtextxy(width/2,height/3+40,t);
                }

    setfillstyle(0,BLACK);
    bar(width/2-320,height/3+70,width/4+655,height/3+130);//text 2
    setcolor(WHITE);
    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);//text 2

    settextstyle(8, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1){
                strcpy(t,"Evaluator functie");
                outtextxy(width/2,height/2+35,t);
                }
        else {
                strcpy(t,"Function evaluation");
                outtextxy(width/2,height/2+35,t);
            }

    setfillstyle(0,BLACK);
    bar(width/2-550,height/2+70,width/2+550,height/2+250);//text 3
    setcolor(WHITE);
    rectangle(width/2-550,height/2+70,width/2+550,height/2+250);//text 3

    settextstyle(8, HORIZ_DIR, 3);
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    strcpy(t," OK! ");
    outtextxy(width/2+500,height/2,t);//buton spre functie
    setcolor(WHITE);
    rectangle(width/2+460,height/2-18,width/2+540,height/2+7);

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fereastra_Contact(int width, int height,int ok,int poza,int limba)
{
    char t[256];
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
    if(limba==1)
        {
            strcpy(t,"Proiectul a fost realizat de:");
            outtextxy(width/2-350,height/2-200,t);//text 1
            }
        else  {
                strcpy(t,"The project was made by:");
                outtextxy(width/2-350,height/2-200,t);//text 1
        }

    settextstyle(8, HORIZ_DIR, 4);

    strcpy(t,"Ursache Ana-Maria");
    outtextxy(width/2-180,height/2-70,t);//text 2

    settextstyle(8, HORIZ_DIR, 4);
    if(limba==1)
        {
            strcpy(t,"si");
            outtextxy(width/2-30,height/2+8,t);//text 3
        }
        else {
                strcpy(t,"and");
                outtextxy(width/2-30,height/2+8,t);//text 3
        }

    settextstyle(8, HORIZ_DIR, 4);

    strcpy(t,"Galatanu Emilia");
    outtextxy(width/2-160,height/2+80,t);//text 4

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void explicatii_grafic(int width, int height, int limba)
{
    char t[256];
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    if(limba==1)
    {
        strcpy(t,"w/UP: Zoom in");
        outtextxy(width/2+550,height/4+130,t);
        strcpy(t,"s/DOWN: Zoom out");
        outtextxy(width/2+550,height/4+160,t);
        strcpy(t,"a/<-: Stanga");
        outtextxy(width/2+550,height/4+190,t);
        strcpy(t,"d/->: Dreapta");
        outtextxy(width/2+550,height/4+220,t);
    }
        else  {
                strcpy(t,"w/UP: Zoom in");
                outtextxy(width/2+550,height/4+130,t);
                strcpy(t,"s/DOWN: Zoom out");
                outtextxy(width/2+550,height/4+160,t);
                strcpy(t,"a/<-: Left");
                outtextxy(width/2+550,height/4+190,t);
                strcpy(t,"d/->: Right");
                outtextxy(width/2+550,height/4+220,t);
        }
}


void buton_iesire(int width, int height)
{
    char t[256];
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Exit");
    outtextxy(width/16+10,height/5-120,t);//setari pentru formare buton exit
    rectangle(width/16-31,height/5-145,width/10,height/5-114);
}

void buton_inapoi(int width, int height)
{
    char t[256];
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    strcpy(t,"Back");
    outtextxy(width/10+51,height/5-120,t);//setari pentru formare buton back
    rectangle(width/10+10,height/5-145,width/10+90,height/5-114);
}


//click-uri
void click(int &coordxclick, int &coordyclick )
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}

void schimbare_sunet(int ok)
{
    PlaySound("sunet_buton.wav",NULL,SND_ASYNC);
    delay(100);
    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);
}

void schimbare_culoare_buton(int a, int b, int c, int d)
{
    setcolor(YELLOW);
    rectangle(a,b,c,d);
    delay(120);
    setcolor(WHITE);
    rectangle(a,b,c,d);
}

void click_pe_fereastra_de_alegeri(double A, double B, int &ok, int &poza,int &limba, int &culoarerama, int &culoaregrafic, char fun[256],char capatst[256],char capatdr[256])
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
            schimbare_culoare_buton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbare_sunet(ok);
            closegraph();
            fereastra_principala(width,height,ok,poza,limba);
            click_pe_fereastra_pr(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
    else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//click pe exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbare_culoare_buton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbare_sunet(ok);
            exit(1);
        }
    else if(coordx>=(width/10+245)&&coordx<=(width/10+400)&&coordy>=(height/3+40)&&coordy<=(height/3+70))
        {//sunet inchis
            a=width/10+245; b=height/3+40; c=width/10+400; d=height/3+70;
            schimbare_culoare_buton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbare_sunet(ok);
            PlaySound(NULL,0,0);
            ok=0;
        }
     else if(coordx>=(width/10+240)&&coordx<=(width/10+400)&&coordy>=(height/3+120)&&coordy<=(height/3+150))
        {//sunet deschis
            a=width/10+240; b=height/3+120; c=width/10+400; d=height/3+150;
            schimbare_culoare_buton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbare_sunet(ok);
            PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
            ok=1;
        }
    else if(coordx>=(width/10+50)&&coordx<=(width/10+150)&&coordy>=(height/3+10)&&coordy<=(height/3+80))//poza mate
        {
            a=width/10+50; b=height/3+10; c=width/10+150; d=height/3+80;
            schimbare_sunet(ok);
            poza=1;
        }
    else if(coordx>=(width/10+50)&&coordx<=(width/10+150)&&coordy>=(height/3+110)&&coordy<=(height/3+180))//poza craciun
        {
            a=width/10+50; b=height/3+110; c=width/10+150; d=height/3+180;
            schimbare_sunet(ok);
            poza=0;
        }
    else if(coordx>=(width/10+470)&&coordx<=(width/10+615)&&coordy>=(height/3+40)&&coordy<=(height/3+70))//buton romana
    {
        a=width/10+470; b=height/3+40; c=width/10+615; d=height/3+70;
        schimbare_culoare_buton(a,b,c,d);
        rectangle(a,b,c,d);
        schimbare_sunet(ok);
        limba=1;
    }

    else if(coordx>=(width/10+470)&&coordx<=(width/10+615)&&coordy>=(height/3+120)&&coordy<=(height/3+150))//buton engleza
    {
        a=width/10+470; b=height/3+120; c=width/10+615; d=height/3+150;
        schimbare_culoare_buton(a,b,c,d);
        rectangle(a,b,c,d);
        schimbare_sunet(ok);
        limba=0;
    }
    else if(coordx>=(width/10+680)&&coordx<=(width/10+750)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//rama rosu
        {
        schimbare_sunet(ok);
        culoarerama=1;
        }
    else if(coordx>=(width/10+770)&&coordx<=(width/10+840)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//rama galben
    {
        schimbare_sunet(ok);
        culoarerama=2;
    }
    else if(coordx>=(width/10+680)&&coordx<=(width/10+750)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//rama cyan
    {
        schimbare_sunet(ok);
        culoarerama=3;
    }
    else if(coordx>=(width/10+770)&&coordx<=(width/10+840)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//rama verde
    {
        schimbare_sunet(ok);
        culoarerama=4;
    }

    else if(coordx>=(width/10+900)&&coordx<=(width/10+970)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//functie rosu
        {
        schimbare_sunet(ok);
        culoaregrafic=1;
    }
    else if(coordx>=(width/10+990)&&coordx<=(width/10+1060)&&coordy>=(height/3+40)&&coordy<=(height/3+90))//functie galben
    {
        schimbare_sunet(ok);
        culoaregrafic=2;
    }
    else if(coordx>=(width/10+900)&&coordx<=(width/10+970)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//functie cyan
    {
        schimbare_sunet(ok);
        culoaregrafic=3;
    }
    else if(coordx>=(width/10+990)&&coordx<=(width/10+1060)&&coordy>=(height/3+110)&&coordy<=(height/3+160))//functie verde
    {
        schimbare_sunet(ok);
        culoaregrafic=4;
    }
    }
}

void click_pe_fereastra_pr(double A, double B, int ok, int poza, int &limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256])
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
            schimbare_culoare_buton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbare_sunet(ok);
            exit(1);
        }
    else if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12)&&limba==1)
            {//daca se face click pe primul buton: "Grafic"
                a=width/2-100; b=height/2-40; c=width/2+98; d=height/2+12;
                schimbare_culoare_buton(a,b,c,d);
                schimbare_sunet(ok);
                clearmouseclick(WM_LBUTTONUP);
                fereastra_Grafic(width,height,ok,poza,limba);
                click_pe_Grafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,capatst,capatdr);
            }
    else if(coordx>=(width/2-119)&&coordx<=(width/2+118)&&coordy>=(height/2-40)&&coordy<=(height/2+12)&&limba==0)
            {//daca se face click pe "Graph"
                a=width/2-119; b=height/2-40; c=width/2+118; d=height/2+12;
                schimbare_culoare_buton(a,b,c,d);
                schimbare_sunet(ok);
                clearmouseclick(WM_LBUTTONUP);
                fereastra_Grafic(width,height,ok,poza,limba);
                click_pe_Grafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,capatst,capatdr);
            }
    else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
            //daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                a=width/2-119; b=height/2+110; c=width/2+117; d=height/2+165;
                schimbare_culoare_buton(a,b,c,d);
                schimbare_sunet(ok);
                fereastra_Contact(width, height,ok,poza,limba);
                click_pe_Contact(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
            }
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115)&&limba==1)//steag-daca se apasa setarea de limba
            {
                schimbare_sunet(ok);
                readimagefile("engleza.jpg",width-80,(height/5-145),width-30,(height/5-115));
                limba=0;//se schimba imaginea->engleza
            }
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115)&&limba==0)//steag-daca se apasa setarea de limba
            {
                schimbare_sunet(ok);
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

void click_pe_Grafic(double &A, double &B, int width, int height,int ok,int poza, int limba, int culoarerama, int culoaregrafic,char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    int i;
    char car, sir[256];
    int x;
    fun[0]='\0';
    capatst[0]='\0';
    capatdr[0]='\0';
    fullscreen(width,height);

    while(true)
    {
    click(coordx,coordy);
    if(coordx>=width/10+10&&coordx<=width/10+90&&coordy>=height/5-145&&coordy<=height/5-114)//back
        {
            a=width/10+10; b=height/5-145; c=width/10+90; d=height/5-114;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            closegraph();
            fereastra_principala(width, height,ok,poza,limba);
            click_pe_fereastra_pr(A,B,ok,poza,limba,culoarerama, culoaregrafic,fun,capatst,capatdr);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            exit(1);
        }
    else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }
    else if(coordx>=(width/2+460)&&coordx<=(width/2+540)&&coordy>=(height/2-18)&&coordy<=(height/2+7))//buton spre functie
        {
        if(k2==1&&k==0)
            {
            a=width/2+460; b=height/2-18; c=width/2+540; d=height/2+7;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            fereastra_cu_graficul_desenat(A,B,limba,culoarerama,culoaregrafic);
            closegraph();
            }
        }

else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/3+70)&&coordy<=(height/3+130))
        {
            //daca se apasa caseta cu "Introduceti functia aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/3+70; c=width/4+655; d=height/3+130;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            x=a+30;
            i=0;
            do
            {
            car = getch();
            if(car!=8)
                {
                sir[0]=car;
                sir[1]='\0';
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                fun[i]=sir[0];
                fun[i+1]='\0';
                i++;
                }
            else if(car==8)
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                i--;
                setcolor(WHITE);
                }
            }
            while(car!=13);

            if(car==13)
                if(k==0)
                {
                    a=width/2-550; b=height/2+70; c=width/2+550; d=height/2+250;
                    schimbare_culoare_buton(a,b,c,d);
                    schimbare_sunet(ok);
                    mesaj_evaluator(width,height);
                }

            click_pe_Grafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,capatst,capatdr);
        }

    else if(coordx>=(width/2-320)&&coordx<=(width/4+320)&&coordy>=(height/4-10)&&coordy<=(height/4+50))//stanga
        {

            a=width/2-320; b=height/4-10; c=width/4+320; d=height/4+50;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            x=a+30;
            i=0;
            do
            {
            car = getch();
            if(car!=8)
                {
                sir[0]=car;
                sir[1]='\0';
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                capatst[i]=sir[0];
                capatst[i+1]='\0';
                i++;
                }
            else if(car==8)
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                i--;
                setcolor(WHITE);
                }
            }
            while(car!=13);
        double A=atof((char*)capatst);
        click_pe_Grafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,capatst,capatdr);
        }
    else if(coordx>=(width/4+340)&&coordx<=(width/4+655)&&coordy>=(height/4-10)&&coordy<=(height/4+50))//dreapta
        {
            a=width/4+340; b=height/4-10; c=width/4+655; d=height/4+50;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
           x=a+30;
            i=0;
            do
            {
            car = getch();
            if(car!=8)
                {
                sir[0]=car;
                sir[1]='\0';
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x+=textwidth(sir);
                capatdr[i]=sir[0];
                capatdr[i+1]='\0';
                i++;
                }
            else if(car==8)
                {
                setcolor(BLACK);
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,sir);
                x-=textwidth(sir);
                i--;
                setcolor(WHITE);
                }
            }
            while(car!=13);

        double B=atof((char*)capatdr);
        if(car==13)
                {
                    a=width/2-550; b=height/2+70; c=width/2+550; d=height/2+250;
                    schimbare_culoare_buton(a,b,c,d);
                    schimbare_sunet(ok);
                    evaluare_interval(width,height,A,B);
                }
        click_pe_Grafic(A,B,width,height,ok,poza,limba,culoarerama,culoaregrafic,capatst,capatdr);
        }
    }
}

void click_pe_Contact(double A, double B, int width, int height,int ok,int poza,int limba,int culoarerama, int culoaregrafic,char fun[256],char capatst[256],char capatdr[256])
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
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
            closegraph();
            fereastra_principala(width, height,ok,poza,limba);
            click_pe_fereastra_pr(A,B,ok,poza,limba,culoarerama,culoaregrafic,fun,capatst,capatdr);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbare_culoare_buton(a,b,c,d);
            schimbare_sunet(ok);
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


//functie:
double functie(double x)
{
    return 2*x*sin(x);
    //return calcularefdinpostf(x);
}

double calculare_integrala_functiei(double A, double B, double(*f)(double))
{
    if((B-A)<EPSILON)
        return (B-A)*((*f)(A)+(*f)(B))/2.0;

    else {
            double punctint;
            punctint=(A+B)/2.0;
            return calculare_integrala_functiei(A,punctint,f)+calculare_integrala_functiei(punctint,B,f);
            }
}

bool discontinuitate(double x)
{
        if((floor(functie(x-EPSILON))!=floor(functie(x+EPSILON)))||(floor(functie(x-EPSILON))!=floor(functie(x)))||(floor(functie(x+EPSILON))!=floor(functie(x))))return 1;//punct de discontinuitate
                else return 0;//continuu in x
}

void aflare_min_si_max(double A, double B)
{
    int i;
    double x,y;
    MIN=100000001;
    MAX=-MIN;
    for(i=0;i<=(DREAPTA-STANGA);i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=functie(x);//functia introdusa de la la fereastra in casuta de text
        MAX=max(MAX,y);//noul max in y
        MIN=min(MIN,y);//noul min in y
    }
}

void aflare_min_max_din_interval(double A, double B, double &minim, double &maxim)
{
    minim=100000001;
    maxim=-minim;
    double i;
    double x,y,ypunctactual;
    x=A;
    y=(int)(functie(x));
    aflare_min_si_max(A,B);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=functie(x);
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));
        minim=min(minim,ypunctactual);
        maxim=max(maxim,ypunctactual);
    }
}

void desenare_grafic_functie(double A, double B, int culoaregrafic)
{
    int i;
    double x,y,xecran,yecran,xpunctactual,ypunctactual;

    aflare_min_max_din_interval(A,B,minim,maxim);

    x=A;
    y=(int)(functie(A));
    aflare_min_si_max(A,B);
    xecran=(DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A);
    yecran=(BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=functie(x);
        xpunctactual=(int)((DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A));
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));

        if(discontinuitate(x)==1)
        {
            setcolor(COLOR(18,18,18));
            line(xecran,TOP+2,xecran,BOTTOM-2);
        }

        if(ypunctactual==minim)
        {
            setcolor(WHITE);
            line(xecran,yecran,xpunctactual,ypunctactual);
        }
    else if(ypunctactual==maxim)
        {
            setcolor(WHITE);
            line(xecran,yecran,xpunctactual,ypunctactual);
        }
   else {
        if(culoaregrafic==1)setcolor(RED);
            else if(culoaregrafic==2)setcolor(YELLOW);
            else if(culoaregrafic==3)setcolor(CYAN);
            else if(culoaregrafic==4)setcolor(GREEN);

        line(xecran,yecran,xpunctactual,ypunctactual);
        }
        xecran=xpunctactual;
        yecran=ypunctactual;
    }
}

void redesenare_grafic(double A, double B, int width, int height,int limba,int culoarerama, int culoaregrafic)
{
    char t[256];
    double valoareintegrala;
    if(culoaregrafic==1)setcolor(RED);
        else if(culoaregrafic==2)setcolor(YELLOW);
        else if(culoaregrafic==3)setcolor(CYAN);
        else if(culoaregrafic==4)setcolor(GREEN);

    desenare_grafic_functie(A,B,culoaregrafic);

    explicatii_grafic(width,height,limba);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)
    {
        strcpy(t,"Reprezentarea functiei:");
        outtextxy(width/2,height/4-50,t);
    }
        else  {
                strcpy(t,"Graph reprezentation:");
                outtextxy(width/2,height/4-50,t);
                }

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);

    if(limba==1)
    {
        strcpy(t,"Integrala:");
        outtextxy(width/4+250,height-100,t);
        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
        char charintegrala[256];
        sprintf(charintegrala," %lf",valoareintegrala);
        outtextxy(width/4+430, height-100,charintegrala);
    }
        else  {
                strcpy(t,"Integral:");
                outtextxy(width/4+250,height-100,t);
                valoareintegrala=calculare_integrala_functiei(A,B,&functie);
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

                    explicatii_grafic(width,height,limba);

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 4 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);

                    if(limba==1)
                    {
                        strcpy(t,"Reprezentarea functiei:");
                        outtextxy(width/2,height/4-50,t);
                    }
                    else  {
                            strcpy(t,"Graph reprezentation:");
                            outtextxy(width/2,height/4-50,t);
                            }

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 3 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);

                    if(limba==1)
                        {
                            strcpy(t,"Integrala:");
                            outtextxy(width/4+250,height-100,t);
                            valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                            char charintegrala[256];
                            sprintf(charintegrala,"%lf",valoareintegrala);
                            outtextxy(width/4+430, height-100,charintegrala);
                        }
                    else  {
                            strcpy(t,"Integral:");
                            outtextxy(width/4+250,height-100,t);
                            valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                            char charintegrala[256];
                            sprintf(charintegrala,"%lf",valoareintegrala);
                            outtextxy(width/4+430, height-100,charintegrala);
                            }

                    desenare_grafic_functie(A,B,culoaregrafic);
                    setcolor(DARKGRAY);
                    line(STANGA,height/2,DREAPTA, height/2);//axa ox
                    line(DREAPTA-7,height/2-7,DREAPTA,height/2);
                    line(DREAPTA-7,height/2+7,DREAPTA,height/2);
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

                explicatii_grafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Reprezentarea functiei:");
                        outtextxy(width/2,height/4-50,t);
                    }
                    else  {
                            strcpy(t,"Graph reprezentation:");
                            outtextxy(width/2,height/4-50,t);
                            }

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Integrala:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        strcpy(t,"Integral:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                        }

                desenare_grafic_functie(A,B,culoaregrafic);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(DREAPTA-7,height/2-7,DREAPTA,height/2);
                line(DREAPTA-7,height/2+7,DREAPTA,height/2);
                }
            else if(car=='w'||car==KEY_UP)//ZOOM -
            {
                if((A+2)<(B-2))
                {
                cleardevice();
                A+=2;
                B-=2;

               if(culoarerama==1)setcolor(RED);
                    else if(culoarerama==2)setcolor(YELLOW);
                    else if(culoarerama==3)setcolor(CYAN);
                    else if(culoarerama==4)setcolor(GREEN);

                rectangle(STANGA,TOP,DREAPTA,BOTTOM);

                explicatii_grafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Reprezentarea functiei:");
                        outtextxy(width/2,height/4-50,t);
                    }
                    else  {
                            strcpy(t,"Graph reprezentation:");
                            outtextxy(width/2,height/4-50,t);
                            }

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Integrala:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        strcpy(t,"Integral:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }


                desenare_grafic_functie(A,B,culoaregrafic);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(DREAPTA-7,height/2-7,DREAPTA,height/2);
                line(DREAPTA-7,height/2+7,DREAPTA,height/2);
                }
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

                explicatii_grafic(width,height,limba);

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Reprezentarea functiei:");
                        outtextxy(width/2,height/4-50,t);
                    }
                    else  {
                            strcpy(t,"Graph reprezentation:");
                            outtextxy(width/2,height/4-50,t);
                            }

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);

                if(limba==1)
                    {
                        strcpy(t,"Integrala:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }
                else  {
                        strcpy(t,"Integral:");
                        outtextxy(width/4+250,height-100,t);
                        valoareintegrala=calculare_integrala_functiei(A,B,&functie);
                        char charintegrala[256];
                        sprintf(charintegrala,"%lf",valoareintegrala);
                        outtextxy(width/4+430, height-100,charintegrala);
                    }

                desenare_grafic_functie(A,B,culoaregrafic);

                setcolor(DARKGRAY);
                line(STANGA,height/2,DREAPTA, height/2);//axa ox
                line(DREAPTA-7,height/2-7,DREAPTA,height/2);
                line(DREAPTA-7,height/2+7,DREAPTA,height/2);
            }
        }
    while(car!=13);
}

void transformare_functie()
{
    int i=0,nr=0;
    while(i<=(strlen(fun)-1))
    {
        if(isdigit(fun[i])!=0)
        {
            while(isdigit(fun[i])!=0)
            {
                vect[nr]=fun[i];
                i++;
                nr++;
            }
        vect[nr]=' ';nr++;
        }
        else if(strchr("+-*^/)(",fun[i]))
                {
                    vect[nr]=fun[i];
                    nr++;i=i+1;
                    vect[nr]=' ';nr++;
                }
        else
            if(fun[i]=='x')
            {vect[nr]=fun[i];
            nr++;
            i++;
            vect[nr]=' ';nr++;}
    else
            {
                if(strchr("s",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;i=i+3;
                    vect[nr]=' ';nr++;
                    }
                if(strchr("c",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;i=i+3;
                    vect[nr]=' ';nr++;
                    }
                if(strchr("l",fun[i])!=0)
                    {
                    vect[nr]=fun[i];
                    nr++;i=i+2;
                    vect[nr]=' ';nr++;
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
for(i=0;i<=strlen(vect)-1;i++)
    if(vect[i]!=' ')
        inserare(infixata,vect[i]);
}

void transformare_din_infix_in_postinfx( )
{
    transformare_functie();
    while (esteVidaC(infixata)==0)
    {
        if(infixata->inf=='x')// x=necunoscuta
                 {
                     inserare(postfixata,'x');
                     eliminare(infixata);
                }

        else
            if(isdigit(infixata->inf))//cifre
            {
                inserare(postfixata,infixata->inf);
                eliminare(infixata);
            }
                else
                    if(infixata->inf==')')
                        {
                            while(S->inf!='(')
                                {
                                inserare(postfixata,S->inf);
                                pop(S);
                                }
                        pop(S); eliminare(infixata);
                        }
                    else
                        {
                            while (esteVidaS(S)==0&&S->inf!='('&&prioritate_caracter(S->inf)>= prioritate_caracter(infixata->inf))
                            {
                            inserare(postfixata,S->inf);
                            pop(S);
                            }
                        push(S,infixata->inf);
                        eliminare(infixata);
                        }
    }
    while (esteVidaS(S)==0)
    {
    inserare(postfixata,S->inf);
    pop(S);
    }
}

double calculare_f_din_postf(double x)
{
    double val;
    transformare_din_infix_in_postinfx();
    while(esteVidaC(postfixata)==0)
    {
        if(postfixata->inf=='x')// x=necunoscuta
                 {
                     push2(S,x);
                     eliminare(postfixata);
                }

        else
            if(isdigit(postfixata->inf))//cifre
            {   char c=postfixata->inf;
                val=c-'0';
                push2(S,val);
                eliminare(postfixata);
            }

        else
            if(strchr("+-/^*",postfixata->inf)!=0)
                        {double valoare1, valoare2,answ;
                        valoare1=S->info;
                        pop(S);
                        valoare2=S->info;
                        pop(S);
                        char operator1=postfixata->inf;
                        answ=operatie(operator1, valoare2, valoare1);
                        eliminare(postfixata);
                        push2(S,answ);
                        }
            else
                if(strchr("sclrt",postfixata->inf)!=0)
                    {
                    double valoare1,answ;
                    valoare1=S->info;
                    pop(S);
                    char operator1=postfixata->inf;
                    answ=operatie_speciala(operator1,valoare1);
                    eliminare(postfixata);
                    push2(S,answ);
                    }
                }

    double valoare=S->info;pop(S);
    return valoare;
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

int prioritate_caracter(char a)
{
    if(strchr("+",a)||strchr("-",a))return 1;
        else if(strchr("*",a)||strchr("/",a))return 2;
                else if(strchr("^",a))return 3;
                        else if(strchr("scltr",a))return 4;
                                else if(strchr("(",a)||strchr(")",a))return 5;
}

//evaluator:
void evaluator()
{
    int nr=0,ok=0,nr1=0,i;
    for(i=0; i<=strlen(fun)-1; i++)
    {
    if(fun[i]=='(')
        nr++;
    if(fun[i]==')')
        nr1++;
    if(fun[i]=='('&&fun[i+1]==')')
        {ok=1;v[++k]=ok;}
    if(fun[i]=='('&&fun[i+1]=='+')
        {ok=2;v[++k]=ok;}
    if(fun[i]=='('&&fun[i+1]=='-')
        {ok=3;v[++k]=ok;}
    if(fun[i]=='('&&fun[i+1]=='*')
        {ok=4;v[++k]=ok;}
    if(fun[i]=='('&&fun[i+1]=='/')
        {ok=5;v[++k]=ok;}
    if(fun[i]=='('&&fun[i+1]=='^')
        {ok=6;v[++k]=ok;}
    if(fun[i]==')'&&fun[i]=='(')
        {ok=7;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='s')
        {ok=8;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='c')
        {ok=9;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='l')
        {ok=10;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='r')
        {ok=11;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='t')
        {ok=12;v[++k]=ok;}
    if(fun[i]==')'&&fun[i+1]=='x')
        {ok=13;v[++k]=ok;}
    if(fun[i]==')'&&isdigit(fun[i+1]))
        {ok=14;v[++k]=ok;}
    if(fun[i]=='+'&&fun[i+1]=='+')
        {ok=15;v[++k]=ok;}
    if(fun[i]=='+'&&fun[i+1]=='-')
        {ok=16;v[++k]=ok;}
    if(fun[i]=='+'&&fun[i+1]=='*')
        {ok=17;v[++k]=ok;}
    if(fun[i]=='+'&&fun[i+1]=='/')
        {ok=18;v[++k]=ok;}
    if(fun[i]=='+'&&fun[i+1]=='^')
        {ok=19;v[++k]=ok;}
    if(fun[i]=='-'&&fun[i+1]=='+')
        {ok=20;v[++k]=ok;}
    if(fun[i]=='-'&&fun[i+1]=='-')
        {ok=21;v[++k]=ok;}
    if(fun[i]=='-'&&fun[i+1]=='*')
        {ok=22;v[++k]=ok;}
    if(fun[i]=='-'&&fun[i+1]=='/')
        {ok=23; v[++k]=ok;}
    if(fun[i]=='-'&&fun[i+1]=='^')
        {ok=24;v[++k]=ok;}
    if(fun[i]=='*'&&fun[i+1]=='+')
        {ok=25; v[++k]=ok;}
    if(fun[i]=='*'&&fun[i+1]=='-')
        {ok=26; v[++k]=ok;}
    if(fun[i]=='*'&&fun[i+1]=='*')
        {ok=27; v[++k]=ok;}
    if(fun[i]=='*'&&fun[i+1]=='/')
        {ok=28; v[++k]=ok;}
    if(fun[i]=='*'&&fun[i+1]=='^')
        {ok=29; v[++k]=ok;}
    if(fun[i]=='/'&&fun[i+1]=='+')
        {ok=30; v[++k]=ok;}
    if(fun[i]=='/'&&fun[i+1]=='-')
        {ok=31; v[++k]=ok;}
    if(fun[i]=='/'&&fun[i+1]=='*')
        {ok=32; v[++k]=ok;}
    if(fun[i]=='/'&&fun[i+1]=='/')
        {ok=33; v[++k]=ok;}
    if(fun[i]=='/'&&fun[i+1]=='^')
        {ok=34; v[++k]=ok;}
    if(fun[i]=='^'&&fun[i+1]=='+')
        {ok=35; v[++k]=ok;}
    if(fun[i]=='^'&&fun[i+1]=='-')
        {ok=36; v[++k]=ok;}
    if(fun[i]=='^'&&fun[i+1]=='*')
        {ok=37; v[++k]=ok;}
    if(fun[i]=='^'&&fun[i+1]=='/')
        {ok=38; v[++k]=ok;}
    if(fun[i]=='^'&&fun[i+1]=='^')
        {ok=39; v[++k]=ok;}
    if(strchr("sctlr",fun[i])&&strchr("sctlr",fun[i+1]))
        {ok=40; v[++k]=ok;}
    }
    if(strchr("-*/^",fun[0]))
        {ok=41; v[++k]=ok;}

    if(strchr("+-*/^",fun[strlen(fun)-2]))
        {ok=42; v[++k]=ok;}

    if(nr!=nr1)
        {ok=43; v[++k]=ok;}

    if(k==0)
        ok=44;
}

void evaluare_interval(int width, int height,double A, double B)
{
    char t[256];
    if(A>=B)//intervalul nu e bun
        {
            settextstyle(8, HORIZ_DIR, 3);
            strcpy(t,"Intervalul nu este bine ales");
            outtextxy(width/2,height/2+100+contorev,t);
            k2=0;
            contorev+=27;
        }
        else k2=1;
}

void mesaj_evaluator(int width, int height)
 {
    char t[256];
    settextstyle(8, HORIZ_DIR, 3);
    int i;
    evaluator();
    setcolor(WHITE);

 for(i=0;i<=k;i++)
    {
    if(v[i]==1){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de o paranteza inchisa");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==2){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de +");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==3){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de -");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==4){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de *");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==5){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de /");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==6){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de ^");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==7){
        strcpy(t,"Nu poate aparea o paranteza deschisa urmata de o paranteza inchisa");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==8){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de functia sinus");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==9){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de functia cosinus");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==10){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de functia logaritmica");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==11){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de functia radical");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==12){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de functia tangenta");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==13){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de constanta x");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==14){
        strcpy(t,"Nu poate aparea o paranteza inchisa urmata de un numar");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==15){
        strcpy(t,"Nu poate aparea simbolul + urmat de simbolul + ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==16){
        strcpy(t,"Nu poate aparea simbolul + urmat de simbolul - ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==17){
        strcpy(t,"Nu poate aparea simbolul + urmat de simbolul * ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==18){
        strcpy(t,"Nu poate aparea simbolul + urmat de simbolul / ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==19){
        strcpy(t,"Nu poate aparea simbolul + urmat de simbolul ^ ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==20){
        strcpy(t,"Nu poate aparea simbolul - urmat de simbolul + ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==21){
        strcpy(t,"Nu poate aparea simbolul - urmat de simbolul - ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==22){
        strcpy(t,"Nu poate aparea simbolul - urmat de simbolul * ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==23){
        strcpy(t,"Nu poate aparea simbolul - urmat de simbolul / ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==24){
        strcpy(t,"Nu poate aparea simbolul - urmat de simbolul ^ ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==25){
        strcpy(t,"Nu poate aparea simbolul * urmat de simbolul + ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==26){
        strcpy(t,"Nu poate aparea simbolul * urmat de simbolul - ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==27){
        strcpy(t,"Nu poate aparea simbolul * urmat de simbolul * ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==28){
        strcpy(t,"Nu poate aparea simbolul * urmat de simbolul / ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==29){
        strcpy(t,"Nu poate aparea simbolul * urmat de simbolul ^ ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==30){
        strcpy(t,"Nu poate aparea simbolul / urmat de simbolul + ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==31){
        strcpy(t,"Nu poate aparea simbolul / urmat de simbolul - ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==32){
        strcpy(t,"Nu poate aparea simbolul / urmat de simbolul * ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==33){
        strcpy(t,"Nu poate aparea simbolul / urmat de simbolul / ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==34){
        strcpy(t,"Nu poate aparea simbolul / urmat de simbolul ^ ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==35){
        strcpy(t,"Nu poate aparea simbolul ^ urmat de simbolul + ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==36){
        strcpy(t,"Nu poate aparea simbolul ^ urmat de simbolul - ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==37){
        strcpy(t,"Nu poate aparea simbolul ^ urmat de simbolul * ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==38){
        strcpy(t,"Nu poate aparea simbolul ^ urmat de simbolul / ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==39){
        strcpy(t,"Nu poate aparea simbolul ^ urmat de simbolul ^ ");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==40){
        strcpy(t,"Nu se pot folosi 2 astfel de simboluri lipite");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==41){
        strcpy(t,"Inceputul functiei nu este corect scris");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==42){
        strcpy(t,"Finalul functiei nu este corect scris");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    else if(v[i]==43){
        strcpy(t,"Numarul de paranteze deschise nu coincide cu nr. de paranteze inchise");
        if(contorev<=135){outtextxy(width/2,height/2+100+contorev,t);
                        contorev+=27;}}
    }

    if(k==0){
        strcpy(t,"Functia e bine scrisa");
        outtextxy(width/2,height/2+100+contorev,t);
        contorev+=27;}
 }
