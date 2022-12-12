/*
Plan:
-limba
-integrala
-zoom
-stanga
-dreapta
-asimptota verticala
-asimptota orizontala
-puncte de discontinuitate
Evaluator:
-restrictii fiecare semn
*/
///Ana-Maria
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<graphics.h>
#include<winbgim.h>
#include<cstring>
#include<math.h>
#define NMAX 200
double A,B;
double MIN,MAX;
int STANGA=250, DREAPTA=1100, TOP=150, BOTTOM=600;

using namespace std;


void click(int &coordxclick, int &coordyclick );
double f(double x);
void aflareminsimax();
void graficfunctie();
void graficnou(int widget,int height);
void desenarefunctie();
void buton_iesire(int width, int height);
void buton_inapoi(int width, int height);
void fereastraalegeri(int width, int height);
void fereastraprincipala(int width, int height,int ok,int poza);
void fullscreen(int &width, int &height);
void schimbaresunet(int ok);
void schimbareculoarebuton(int a, int b, int c, int d);
void fereastraGrafic(int width, int height,int ok,int poza);
void fereastraContact(int width, int height,int ok,int poza);
void clickpeGrafic(int width, int height,int ok,int poza, char fun[256],char capatst[256],char capatdr[256]);
void clickpeContact(int width, int height,int ok,int poza,char fun[256],char capatst[256],char capatdr[256]);
void clickpefereastrapr(int ok, int poza,char fun[256],char capatst[256],char capatdr[256]);
void clickpefereastraalegeri(int &ok, int &poza,char fun[256],char capatst[256],char capatdr[256]);

struct lista{
    char info;
    char inf;
    lista *urm;
    lista *varf;
}*nod;

int prioritatecaracter(char *a[]);
void transformarefunctie(char *functie, lista *&infixata);
void transformaredininfixinpostifx(lista *&infixata, lista*&value, lista*&operatori);


void push(lista *&varf, char element);
void pop(lista *&varf );
char top(lista *&varf);
bool esteVidaS(lista *&Stiva);
void stiva_vida(lista *&Stiva);


int main()
{
    int height, width;
    char fun[257],capatst[257],capatdr[257];
    int ok=1;
    int poza=1;
    cin>>A>>B;

    lista *postfixata;
    postfixata=new lista;
    //stiva_vida(postfixata);
    fullscreen(width, height);
    fereastraalegeri(width,height);
    clickpefereastraalegeri(ok,poza,fun,capatst,capatdr);
    getch();
    closegraph();
    return 0;
}

void push(lista *&varf, char element)
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


bool esteVidaS(lista *&Stiva)//stiva
{
return top(Stiva);
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
    bar(width/10+200,height/3,width/10+400,height/3+200);//fundal
    readimagefile("image1_1.jpg",width/10+250,height/3+10,width/10+350,height/3+80);//imagine de fundal
    readimagefile("Backgrf.jpg",width/10+250,height/3+110,width/10+350,height/3+180);//imagine de fundal
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+300,height/3+230,"Poza fundal");

    bar(width/10+640,height/3,width/10+840,height/3+200);//limba
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+740,height/3+60,"Romana");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+740,height/3+140,"English");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+745,height/3+230,"Limba");

    bar(width/10+420,height/3,width/10+620,height/3+200);//sunet
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+515,height/3+60," Sunet inchis");
    rectangle(width/10+445,height/3+40,width/10+600,height/3+70);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 2 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+519,height/3+140,"Sunet deschis");
    rectangle(width/10+440,height/3+120,width/10+600,height/3+150);

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/10+510,height/3+230,"Sunet");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2-30,height/2+250," OK! ");
    rectangle(width/2-82,height/2+226,width/2+20,height/2+260);

    buton_iesire(width, height);
}

void clickpefereastraalegeri(int &ok, int &poza,char fun[256],char capatst[256],char capatdr[256])
{
    int coordx, coordy;
    int a,b,c,d;
    int height, width;
    fullscreen(width,height);

    while(true)
    {

    click(coordx,coordy);
    if(coordx>=(width/2-82)&&coordx<=(width/2+20)&&coordy>=(height/2+226)&&coordy<=(height/2+260))//click pe ok
        {
            a=width/2-82; b=height/2+226; c=width/2+20; d=height/2+260;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            closegraph();
            fereastraprincipala(width,height,ok,poza);
            clickpefereastrapr(ok,poza,fun,capatst,capatdr);
        }
    else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//click pe exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
    else if(coordx>=(width/10+445)&&coordx<=(width/10+600)&&coordy>=(height/3+40)&&coordy<=(height/3+70))
        {//sunet inchis
            a=width/10+445; b=height/3+40; c=width/10+600; d=height/3+70;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            PlaySound(NULL,0,0);
            ok=0;
        }
     else if(coordx>=(width/10+440)&&coordx<=(width/10+600)&&coordy>=(height/3+120)&&coordy<=(height/3+150))
        {//sunet deschis
            a=width/10+440; b=height/3+120; c=width/10+600; d=height/3+150;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet(ok);
            PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
            ok=1;
        }
    else if(coordx>=(width/10+250)&&coordx<=(width/10+350)&&coordy>=(height/3+10)&&coordy<=(height/3+80))
        {
            a=width/10+250; b=height/3+10; c=width/10+350; d=height/3+80;
            schimbaresunet(ok);
            poza=1;
        }
    else if(coordx>=(width/10+250)&&coordx<=(width/10+350)&&coordy>=(height/3+110)&&coordy<=(height/3+180))
        {
            a=width/10+250; b=height/3+110; c=width/10+350; d=height/3+180;
            schimbaresunet(ok);
            poza=0;
        }
    //de continuat cu toate butoanele de limba
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
{//functia in care se va forma functia dupa ce este preluata ca sir de caractere
    if(x!=0)
        return x*sin(1.0*x);
    else return 0;
}

void aflareminsimax()
{//aflare min max
    int i;
    double x,y;
    MIN=100000001;
    MAX=-MIN;
    for(i=0;i<=(DREAPTA-STANGA);i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);//functia introdusa de la la fereastra in casuta de text
        MAX=max(MAX,y);//noul max
        MIN=min(MIN,y);//noul min
    }
}

void graficfunctie()
{//trasare linie grafic pt toate punctele
    int i;
    double x,y,xecran,yecran,xpunctactual,ypunctactual;
    x=A;
    y=(int)(f(A));
    aflareminsimax();
    xecran=(DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A);
    yecran=(BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN);
    for(i=0;i<=DREAPTA-STANGA;i++)
    {
        x=A+i*(B-A)/(DREAPTA-STANGA);
        y=f(x);
        xpunctactual=(int)((DREAPTA-STANGA)*x/(B-A)+(B*STANGA-A*DREAPTA)/(B-A));
        ypunctactual=(int)((BOTTOM-TOP)*y/(MAX-MIN)+(MAX*TOP-MIN*BOTTOM)/(MAX-MIN));
        line(xecran,yecran,xpunctactual,ypunctactual);
        xecran=xpunctactual;
        yecran=ypunctactual;
    }
}

void graficnou(int width, int height)
{
    setcolor(YELLOW);
    graficfunctie();
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/4-50,"Reprezentarea functiei:");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/4+50,height-100,"Integrala in xmin:");

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 3 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2+210,height-100,"Integrala in xmax:");
    char car;
    do
        {
            car = getch();
            if(car==KEY_RIGHT||car=='d')//dr
                {
                    setcolor(BLACK);
                    graficfunctie();
                    A+=50;
                    B+=50;

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 4 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);
                    outtextxy(width/2,height/4-50,"Reprezentarea functiei:");

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 3 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);
                    outtextxy(width/4+50,height-100,"Integrala in xmin:");

                    setcolor(WHITE);
                    settextstyle(8, HORIZ_DIR, 3 );
                    settextjustify(CENTER_TEXT,CENTER_TEXT);
                    outtextxy(width/2+210,height-100,"Integrala in xmax:");
                    setcolor(YELLOW);
                    graficfunctie();
                }
            else if(car==KEY_LEFT||car=='a')//st
            {
                setcolor(BLACK);
                graficfunctie();
                A-=50;
                B-=50;
                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 4 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);
                outtextxy(width/2,height/4-50,"Reprezentarea functiei:");

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);
                outtextxy(width/4+50,height-100,"Integrala in xmin:");

                setcolor(WHITE);
                settextstyle(8, HORIZ_DIR, 3 );
                settextjustify(CENTER_TEXT,CENTER_TEXT);
                outtextxy(width/2+210,height-100,"Integrala in xmax:");
                setcolor(YELLOW);
                graficfunctie();
                }
        }
    while(car!=13);
}

void desenarefunctie()
{//desenare grafic
    int height, width;
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"Fereastra",-4,-4);

    setcolor(RED);
    rectangle(STANGA,TOP,DREAPTA,BOTTOM);
    line(STANGA,height/2,DREAPTA, height/2);//axa ox
    line(width/2,TOP,width/2,BOTTOM);//axa oy

    setcolor(YELLOW);
    graficnou(width,height);//graficul efectiv
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

void fereastraprincipala(int width, int height,int ok, int poza)
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

    readimagefile("romana.jpg",width-80,height/5-145,width-30,(height/5-115));//steag->romana

    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 8 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/4,"Graficul functiei");//setari titlu

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(width/2,height/2,"Grafic");
    rectangle(width/2-100,height/2-40,width/2+98,height/2+12);//setari a doua linie de text

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

void fereastraGrafic(int width, int height,int ok,int poza)
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
    outtextxy(width/2+10,height/4-40,"Introduceti intervalul  aici:");
    setfillstyle(0,BLACK);
    bar(width/2-320,height/4-10,width/4+320,height/4+50);//text 1
    bar(width/4+340,height/4-10,width/4+655,height/4+50);
    setcolor(WHITE);
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2-400,height/4+33,"Stanga:");
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2+400,height/4+33,":Dreapta");
    rectangle(width/2-320,height/4-10,width/4+320,height/4+50);//st
    rectangle(width/4+340,height/4-10,width/4+655,height/4+50);//dr


    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/3+40,"Introduceti functia aici:");
    setfillstyle(0,BLACK);
    bar(width/2-320,height/3+70,width/4+655,height/3+130);//text 2
    setcolor(WHITE);
    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);//text 2

    settextstyle(8, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/2+35,"Evaluator functie");
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

void fereastraContact(int width, int height,int ok,int poza)
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
    outtextxy(width/2-350,height/2-200,"Proiectul a fost realizat de:");//text 1

    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(width/2-180,height/2-70,"Ursache Ana-Maria");//text 2

    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(width/2-30,height/2+8,"si");//text 3

    settextstyle(8, HORIZ_DIR, 4);
    outtextxy(width/2-160,height/2+80,"Galatanu Emilia");//text 4

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void clickpefereastrapr(int ok, int poza, char fun[256],char capatst[256],char capatdr[256])
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
    else if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12))
            {//daca se face click pe primul buton: "Grafic"
                a=width/2-100; b=height/2-40; c=width/2+98; d=height/2+12;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                clearmouseclick(WM_LBUTTONUP);
                fereastraGrafic(width,height,ok,poza);
                clickpeGrafic(width,height,ok,poza,fun,capatst,capatdr);
            }
    else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
            //daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                a=width/2-119; b=height/2+110; c=width/2+117; d=height/2+165;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                fereastraContact(width, height,ok,poza);
                clickpeContact(width,height,ok,poza,fun,capatst,capatdr);
            }
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115))//steag-daca se apasa setarea de limba
            {
                schimbaresunet(ok);
                readimagefile("engleza.jpg",width-80,(height/5-145),width-30,(height/5-115));//se schimba imaginea->engleza
            }
    else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }
    }
}


void clickpeGrafic(int width, int height,int ok,int poza,char fun[256],char capatst[256],char capatdr[256])
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
            fereastraprincipala(width, height,ok,poza);
            clickpefereastrapr(ok,poza,fun,capatst,capatdr);
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
            desenarefunctie();
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

            clickpeGrafic(width,height,ok,poza,fun,capatst,capatdr);
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
        clickpeGrafic(width,height,ok,poza,fun,capatst,capatdr);
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

        clickpeGrafic(width,height,ok,poza,fun,capatst,capatdr);
        }
    }
}
void clickpeContact(int width, int height,int ok,int poza,char fun[256],char capatst[256],char capatdr[256])
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
            fereastraprincipala(width, height,ok,poza);
            clickpefereastrapr(ok,poza,fun,capatst,capatdr);
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



void transformarefunctie(char *functie, lista *&infixata)
{
    char fposibile[][20]={"sin","cos","ln","tg","ctg","rad"};
    char *vect[NMAX];
    int i,j,nr;
    int ok=0;
    for(i=0;i<=strlen(functie)-1;i++)
    {
        vect[0]=0;
        nr=0;
        if(isdigit(functie[i])!=0)
        {
            while(isdigit(functie[i]!=0))
            {
                vect[nr]=(char*)functie[i];
                i++;
                nr++;
            }
            vect[nr]=0;
            i--;
        }
        else if(strchr("+-*^/xe()",functie[i]))
                {
                    vect[nr]=(char*)functie[i];
                    nr++;
                    vect[nr]=0;
                }
        else for(j=0;j<6;j++)
            if(ok==0)
                if(strstr(functie+1,fposibile[j])==functie+i)
                    {
                        strcpy((char*)vect[nr],fposibile[j]);
                        i=i+strlen(fposibile[j])-1;
                        ok=1;
                    }
        push(infixata,*vect[nr]);
    }
}

void transformaredininfixinpostifx(lista *&infixata, lista *&value, lista *&operatori)
{
    char *c[256], *operator1[256], *valpr[256];
    c[0]=NULL;
    valpr[0]=NULL;
    while(esteVidaS(infixata)==0)
    {
        strcpy((char*)c,(char*)top(infixata));
        if(isdigit(*c[0]))
            push(value,*c[0]);
        else
            if(strchr("abcdefghijklmnopqrstuvwxyz",*c[0]))
                push(value,*c[0]);
            else
                if(strchr("(",*c[0]))
                   push(operatori,*c[0]);
                else
                    if(strchr(")",*c[0]))
                    {

                        while(top(operatori)!='(')
                        {
                        operator1[0]=NULL;
                        strcat(*operator1,(char*)top(*&value));
                        pop(value);
                        strcat(*operator1,(char*)top(*&operatori));
                        pop(operatori);
                        strcat(*operator1,(char*)top(*&value));
                        pop(value);
                        push(*&value,*(char*)operator1);
                        }
                 pop(operatori);
                 }
                 else
                    if(strchr("+-*^/sctl",*c[0]))
                    {
                    strcpy(*valpr,(char*)top(*&operatori));
                    while(esteVidaS(*&operatori)==0&&
                          prioritatecaracter(valpr)>=
                          prioritatecaracter(c))
                    {
                        operator1[0]=NULL;
                        strcat(*operator1,(char*)top(value));
                        pop(value);
                        strcat(*operator1,(char*)top(operatori));
                        pop(operatori);
                        strcat(*operator1,(char*)top(value));
                        pop(value);
                        push(*&value,*(char*)operator1);
                    }
                    }
    }
    while(esteVidaS(operatori)==0)
    {
        operator1[0]=NULL;
        strcat(*operator1,(char*)top(value));
        pop(value);
        strcat(*operator1,(char*)top(operatori));
        pop(operatori);
        strcat(*operator1,(char*)top(value));
        pop(value);
        push(*&value,*(char*)operator1);
    }
    //functia noastra este in top(value)
}


int prioritatecaracter(char *a[])
{
    if(strchr("+",*a[0])||strchr("-",*a[0]))return 1;
        else if(strchr("*",*a[0])||strchr("/",*a[0]))return 2;
                else if(strchr("^",*a[0]))return 3;
                        else if(strchr("sclt",*a[0]))return 4;
                                else if(strchr("(",*a[0])||strchr(")",*a[0]))return 5;
}
