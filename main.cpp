/*
Plan:
-limba
-click
-sunet dechis in functie de ok
-poate integrala, zoom, stanga dreapta
Grafic:
-asimptota verticala
-asimptota orizontala
-grafic efectiv cu linii
-transformare sir caractere->functie
-puncte de discontinuitate
Evaluator:
-restrictii fiecare semn
-stive?
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

///Ana-Maria
void click(int &coordxclick, int &coordyclick );
double f(double x);
void aflareminsimax();
void graficfunctie();
void desenarefunctie();

///Emilia
void buton_iesire(int width, int height);
void buton_inapoi(int width, int height);

///Ana-Maria
void fereastraalegeri(int width, int height);
void fereastraprincipala(int width, int height,int ok);
void fullscreen(int &width, int &height);
void schimbaresunet(int ok);
void schimbareculoarebuton(int a, int b, int c, int d);
void fereastraGrafic(int width, int height,int ok);
void fereastraContact(int width, int height,int ok);
void clickpeGrafic(int width, int height,int ok);
void clickpeContact(int width, int height,int ok);
void clickpefereastrapr(int ok);
void clickpefereastraalegeri(int &ok);

int prioritatecaracter(char a[]);
void transformarefunctie(char *functie, Coada infixata);
void transformaredininfixinpostifx();

///Emilia+ Ana-Maria
char top(Stiva S);
bool esteVidaS(Stiva S);
bool esteVidaC(Coada C);
void StivaVida(Stiva S);
void push(Stiva &S, char element);
void pop(Stiva &S);
void inserare(Coada C, char element);
void eliminare(Coada C);

//Ana-Maria
struct nod{
    char valoare;
    nod* succ;
};

struct Stiva{
    nod* varf;
};

struct Coada{
    nod* prim;
    nod* ultim;
};

int main()
{
    int height, width;
    int coordx, coordy;
    int i,a,b,c,d;
    char s[256];
    int ok=1;

    Coada infixata;
    infixata=new Coada;
    infixata=esteVidaC(infixata);
    Stiva postfixata;
    postfixata=new Stiva;
    postfixata=esteVidaS(postfixata);
    Stiva S;
    S=new Stiva;
    S=esteVidaS(S);

    fullscreen(width, height);
    fereastraalegeri(width,height);
    clickpefereastraalegeri(ok);
    getch();
    closegraph();
    return 0;
}

bool esteVidaS(Stiva S)
{
    if(top(S)==NULL)
        return 1;
    else
        return 0;
}

bool esteVidaC(Coada C)
{
    if(C.prim==NULL && C.ultim==NULL)
        return 1;
    else
        return 0;
}

void StivaVida(Stiva S)
{
    S.varf=NULL;
}

void push(Stiva &S, char element)
{
    nod *q;
    q=new nod;
    q->valoare=element;
    q->succ=S;
    S=q;
}

void pop(Stiva &S)
{
    nod *q;
    q=new nod;
    q=S;
    S=S->succ;
    delete q;
}

char top(Stiva S)
{
    char element;
    if(S.varf!=NULL)
        element=S.varf->valoare;
    return element;
}

void eliminare(Coada C)
{
    nod *q;
    q=new nod;
    q=C.prim;
    C.prim=C.prim->succ;
    delete q;
    if(esteVidaC(C))
        C.ultim=NULL;
}

void inserare(Coada C, char element)
{
    nod *q;
    q=new nod;
    q->valoare=element;
    q->succ=NULL;
    if(C.ultim==NULL)
        {
            C.ultim=q;
            C.prim=q;
        }
    else
        {
            C.ultim->succ=q;
            C.ultim=q;
        }
}

void fereastraalegeri(int width, int height)
{
    initwindow(width,height,"Fereastra principala",-4,-4);
    ///Ana-Maria
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

void clickpefereastraalegeri(int &ok)
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
            fereastraprincipala(width,height,ok);
            clickpefereastrapr(ok);
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
    //de continuat cu toate butoanele
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
    graficfunctie();//graficul efectiv
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

void fereastraprincipala(int width, int height,int ok)
{//fereastra 1
    ///Emilia
    initwindow(width,height,"Fereastra principala",-4,-4);

    ///Ana-Maria
    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    else PlaySound(NULL,0,0);

    readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal
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

    readimagefile("sunetdeschis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);//sunet

    ///Emilia
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fullscreen(int &width, int &height)
{//preluare dimensiuni ecran
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
}

void schimbaresunet(int ok)
{//sunet buton->sunet fundal
    PlaySound("sunet_buton.wav",NULL,SND_ASYNC);
    delay(100);
    if(ok==1)PlaySound("sound2.wav",NULL,SND_ASYNC);
}

void schimbareculoarebuton(int a, int b, int c, int d)
{//galben la apasare->delay->alb
    setcolor(YELLOW);
    rectangle(a,b,c,d);
    delay(120);
    setcolor(WHITE);
    rectangle(a,b,c,d);
}

void fereastraGrafic(int width, int height,int ok)
{//fereastra 2

    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    else PlaySound(NULL,0,0);

    initwindow(width,height,"Fereastra",-4,-4);
    readimagefile("image1_1.jpg",0,0,width,height);//poza fundal fereastra noua
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2+10,height/4-40,"Introduceti intervalul  aici:");
    setfillstyle(0,BLACK);
    bar(width/2-320,height/4-10,width/4+655,height/4+50);//text 1
    setcolor(WHITE);
    rectangle(width/2-320,height/4-10,width/4+655,height/4+50);//text 1

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

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fereastraContact(int width, int height,int ok)
{//fereastra 3
    initwindow(width,height,"Fereastra",-4,-4);

    if(ok==1)
        PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
    else PlaySound(NULL,0,0);

    readimagefile("image1_1.jpg",0,0,width,height);//imagine fundal

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

void clickpefereastrapr(int ok)
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
                fereastraGrafic(width, height,ok);
                clickpeGrafic(width,height,ok);
            }
        ///Ana-Maria
    else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
            //daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                a=width/2-119; b=height/2+110; c=width/2+117; d=height/2+165;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet(ok);
                fereastraContact(width, height,ok);
                clickpeContact(width,height,ok);
            }
                ///Ana-Maria
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

void clickpeGrafic(int width, int height,int ok)
{
    int coordx, coordy;
    int a,b,c,d;
    char car, sir[2];
    int x;
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
            fereastraprincipala(width, height,ok);
            clickpefereastrapr(ok);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            exit(1);
        }
else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/4-10)&&coordy<=(height/4+50))
        {
            //daca se apasa caseta cu "Introduceti intervalul aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/4-10; c=width/4+655; d=height/4+50;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            x=a+30;
            car = getch();
            sir[0]=car;
            sir[1]=NULL;
        while (car!=13)
            {
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x+=textwidth(sir);
                car = getch();
                }
            else{
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x-=textwidth(sir);
                car = getch();
                }
            }
        }
else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/3+70)&&coordy<=(height/3+130))
        {
            //daca se apasa caseta cu "Introduceti functia aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/3+70; c=width/4+655; d=height/3+130;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            x=a+30;
            car = getch();
            sir[0]=car;
            sir[1]=NULL;
        while (car!=13)
            {
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x+=textwidth(sir);
                car = getch();
                }
            else{
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x-=textwidth(sir);
                car = getch();
                }
            }
        }
else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&coordy>=(height/2+70)&&coordy<=(height/2+250))
        {
            //daca se apasa caseta cu "Evaluator functie"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-379; b=height/2+70; c=width/2+376; d=height/2+250;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet(ok);
            x=a+30;
            car = getch();
            sir[0]=car;
            sir[1]=NULL;
        while (car!=13)
            {
            if(car!=8)
                {
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x+=textwidth(sir);
                car = getch();
                }
            else{
                settextstyle(8, HORIZ_DIR, 4 );
                outtextxy(x,b+30,&car);
                x-=textwidth(sir);
                car = getch();
                }
            }

    }
    else if(coordx>=(width/16-31)&&coordx<=(width/16)&&
                    coordy>=(height/5-100)&&coordy<=(height/5-70))
            {
                readimagefile("sunetinchis1.jpeg",width/16-31,height/5-100,width/16,height/5-70);
                PlaySound(NULL,0,0);
            }
    }
}

void clickpeContact(int width, int height,int ok)
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
            fereastraprincipala(width, height,ok);
            clickpefereastrapr(ok);
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

void transformarefunctie(char *functie, Coada infixata)
{
    char fposibile[][20]={"sin","cos","ln","tg","ctg","rad"};
    char matrice[NMAX][NMAX];
    int i,j,nr=0,nr2;
    int ok=0;
    for(i=0;i<=strlen(functie)-1;i++)
    {
        matrice[nr][0]=0;
        nr2=0;
        if(isdigit(functie[i])!=0)
        {
            while(isdigit(functie[i]!=0))
            {
                matrice[nr][nr2]=functie[i];
                i++;
                nr2++;
            }
            matrice[nr][nr2]=0;
            i--;
        }
        else if(strchr("+-*^xe()",functie[i]))
                {
                    matrice[nr][nr2]=functie[i];
                    nr2++;
                    matrice[nr][nr2]=0;
                }
        else for(j=0;j<6;j++)
            if(ok==0)
                if(strstr(functie+1,fposibile[j])==functie+i)
                    {
                        strcpy(matrice[nr],fposibile[j]);
                        i=i+strlen(fposibile[j])-1;
                        ok=1;
                    }
        inserare(infixata,matrice[nr]);
        nr++;
    }
}

void transformaredininfixinpostifx(Stiva postfixata)
{
    int i,nr=0;
    char sirdetransfer[NMAX][NMAX];
    char operatori[]="+-*^x()sclt";
    bool ok;
    while(esteVida(infixata)==0)
    {
        ok=0;
        strcpy(sirdetransfer[nr],infixata.prim->valoare);
        eliminare(infixata);
        for(i=0;ok!=0&&operatori[i];i++)
            if(strchr(sirdetransfer[nr],operatori[i]))ok=1;
        if(ok==0)push(postfixata,sirdetransfer[nr]);
        if(ok!=0)
            {
                if(strchr(sirdetransfer[nr],')'))
                {
                    while(strchr(top(S),'('))
                    {
                        push(postfixata,top(S));
                        pop(S);
                    }
                    pop(S);
                }
            else {
                     while(esteVidaS(S)==0&&strchr(top(S)'(')&&
                                prioritatecaracter(top(S))>=prioritatecaracter(sirdetransfer[nr]))
                        {
                            push(postfixata,top(S));
                            pop(S);
                        }
                    push(S,sirdetransfer[nr]);
                  }
            }
        nr++;
    }
}

int prioritatecaracter(char a[])
{
    if(strchr(a,'+')||strchr(a,'-'))return 1;
        else if(strchr(a,'*')||strchr(a,'/'))return 2;
                else if(strchr(a,'^')return 3;
                        else if(strchr("sclt",a[0]))return 4;
                                else if(strchr(a,'(')||strchr(a,')'))return 5;
}
