/*
Plan:
-limba
-buton de sunet
-inchis deschis sunet
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
double A,B;
double MIN,MAX;
int STANGA=250, DREAPTA=1100, TOP=150, BOTTOM=600;
using namespace std;

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

void fereastraprincipala(int width, int height)
{//fereastra 1
    ///Emilia
    int window1=initwindow(width,height,"Fereastra principala",-4,-4);
    setcurrentwindow(window1);
    ///Ana-Maria
    PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal
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

    ///Emilia
    buton_iesire(width, height);
}

void fullscreen(int &width, int &height)
{//preluare dimensiuni ecran
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
}

void schimbaresunet()
{//sunet buton->sunet fundal
    PlaySound("sunet_buton.wav",NULL,SND_ASYNC);
    delay(100);
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

void fereastraGrafic(int width, int height)
{//fereastra 2
    initwindow(width,height,"Fereastra",-4,-4);
    readimagefile("image1_1.jpg",0,0,width,height);//poza fundal fereastra noua
    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2+10,height/4-40,"Introduceti intervalul  aici:");
    rectangle(width/2-320,height/4-10,width/4+655,height/4+50);//text 1

    settextstyle(8, HORIZ_DIR, 4 );
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/3+40,"Introduceti functia aici:");
    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);//text 2

    settextstyle(8, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(width/2,height/2+35,"Evaluator functie");
    rectangle(width/2-379,height/2+70,width/2+376,height/2+250);//text 3

    setcolor(WHITE);
    buton_inapoi(width, height);
    buton_iesire(width, height);
}

void fereastraContact(int width, int height)
{//fereastra 3
    initwindow(width,height,"Fereastra",-4,-4);

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

void clickpeGrafic(int width, int height,int a, int b, int c, int d, int window1)
{
    int coordx, coordy;
    clearmouseclick(WM_LBUTTONUP);
    click(coordx,coordy);

    if(coordx>=width/10+10&&coordx<=width/10+90&&coordy>=height/5-145&&coordy<=height/5-114)//back
        {
            a=width/10+10; b=height/5-145; c=width/10+90; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            closegraph(window1);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            exit(1);
        }
else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/4-10)&&coordy<=(height/4+50))
        {
            //daca se apasa caseta cu "Introduceti intervalul aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/4-10; c=width/4+655; d=height/4+50;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            //trebuie continuat cu o casuta de text
        }
else if(coordx>=(width/2-320)&&coordx<=(width/4+655)&&coordy>=(height/3+70)&&coordy<=(height/3+130))
        {
            //daca se apasa caseta cu "Introduceti functia aici:"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-320; b=height/3+70; c=width/4+655; d=height/3+130;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            //trebuie continuat cu o casuta de text
        }
else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&coordy>=(height/2+70)&&coordy<=(height/2+250))
        {
            //daca se apasa caseta cu "Evaluator functie"
            //se schimba culoare dreptunghiului in galben la click
            a=width/2-379; b=height/2+70; c=width/2+376; d=height/2+250;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            //trebuie continuat cu o casuta de text
        }

    getch();
    closegraph();
}

void clickpeContact(int width, int height,int a, int b, int c, int d, int window1)
{
    int coordx, coordy;
    clearmouseclick(WM_LBUTTONUP);
    click(coordx,coordy);
    if(coordx>=width/10+10&&coordx<=width/10+90&&coordy>=height/5-145&&coordy<=height/5-114)//back
        {
            a=width/10+10; b=height/5-145; c=width/10+90; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            closegraph(window1);
            setcurrentwindow(window1);
        }
else if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//exit
        {
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            schimbaresunet();
            exit(1);
        }
        getch();
        closegraph();
}

int main()
{
    int height, width;
    int coordx, coordy;
    int i,a,b,c,d;
    int window1;
    char s[256];
/*
    cout<<"Introduce valorile intervalului in care doresti sa observi reprezentarea graficului:"<<endl;
    cout<<endl;
    cout<<"Capatul din stanga al intervalului este A, cu valoarea: ";
    cin>>A;
    cout<<endl;
    cout<<"Capatul din dreapta al intervalului este B, cu valoarea: ";
    cin>>B;

    if(strstr(s,"sin"))
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return 1;
                }
        else if(strstr(s,"cos"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return 1;
                }
        }
            else if(strstr(s,"tg"))
            {
                for(i=0;i<=strlen(s)-1;i++)
                    {
                        return 1;
                    }
            }
                else if(strstr(s,"ctg"))
                {
                    for(i=0;i<=strlen(s)-1;i++)
                        {
                            return 1;
                        }
                }
                    else if(strstr(s,"log"))
                    {
                        for(i=0;i<=strlen(s)-1;i++)
                            {
                                return 1;
                            }
                    }
                        else if(strstr(s,"rad"))
                        {
                            for(i=0;i<=strlen(s)-1;i++)
                                {
                                    return 1;
                                }
                        }
*/
    fullscreen(width, height);
    fereastraprincipala(width, height);

    click(coordx,coordy);
    if(coordx>=width/16-31&&coordx<=width/10&&coordy>=height/5-145&&coordy<=height/5-114)//click pe exit
        {
            clearmouseclick(WM_LBUTTONUP);
            click(coordx,coordy);
            a=width/16-31; b=height/5-145; c=width/10; d=height/5-114;
            schimbareculoarebuton(a,b,c,d);
            rectangle(a,b,c,d);
            schimbaresunet();
            exit(1);
        }
    else if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12))
            {//daca se face click pe primul buton: "Grafic"
                a=width/2-100; b=height/2-40; c=width/2+98; d=height/2+12;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet();
                clearmouseclick(WM_LBUTTONUP);
                fereastraGrafic(width, height);
                clearmouseclick(WM_LBUTTONUP);
                clickpeGrafic(width,height,a,b,c,d,window1);
            }
        ///Ana-Maria
    else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {
            //daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                a=width/2-119; b=height/2+110; c=width/2+117; d=height/2+165;
                schimbareculoarebuton(a,b,c,d);
                schimbaresunet();
                fereastraContact(width, height);
                clickpeContact(width,height,a,b,c,d,window1);
            }
                ///Ana-Maria
    else if(coordx>=(width-80)&&coordx<=(width-30)&&
                    coordy>=(height/5-145)&&coordy<=(height/5-115))//steag-daca se apasa setarea de limba
            {
                schimbaresunet();
                readimagefile("engleza.jpg",width-80,(height/5-145),width-30,(height/5-115));//se schimba imaginea->engleza
            }

    getch();
    closegraph();
    return 0;
}
