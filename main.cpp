/*
Plan:
-limba
-interval
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
///Ana-Maria
#include<iostream>
#include<windows.h>
#include<graphics.h>
#include<winbgim.h>
#include<cstring>
#define MIN 100000001

using namespace std;

void click(int &coordxclick, int &coordyclick )//functie pentru click
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}

int f(int x)//functia in care se va forma functia dupa ce este preluata ca sir de caractere
{
    if(x!=0)
        return 1;//neterminata
    else return 0;
}

void aflareminsimax(int A, int B, int DREAPTA,int STANGA)//aflare min max
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

void graficfunctie(int A,int B,int punctmax,
            int punctmin,int DREAPTA,int STANGA,int BOTTOM,int TOP)//trasare linie grafic pt toate punctele
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
    int A,B,STANGA,DREAPTA,TOP,BOTTOM;
    int height, width;
    int coordx, coordy;
    int i;
    char s[256];

    cout<<"Introduce valorile intervalului in care doresti sa observi reprezentarea graficului:"<<endl;
    cout<<endl;
    cout<<"Capatul din stanga al intervalului este A, cu valoarea: ";
    cin>>A;
    cout<<endl;
    cout<<"Capatul din dreapta al intervalului este B, cu valoarea: ";
    cin>>B;
    cout<<endl;
    cout<<"Scrie functia sub forma de sir de caractere: ";
    cin.get();
    cin.get(s,256);

    if(strstr(s,"sin"))
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return 1;/*trebuie continuat cu functia pentru cazul cu sin*/
                }
        else if(strstr(s,"cos"))
        {
            for(i=0;i<=strlen(s)-1;i++)
                {
                    return 1;/*trebuie continuat cu functia pentru cazul cu cos*/
                }
        }
            else if(strstr(s,"tg"))
            {
                for(i=0;i<=strlen(s)-1;i++)
                    {
                        return 1;/*trebuie continuat cu functia pentru cazul cu tg*/
                    }
            }
                else if(strstr(s,"ctg"))
                {
                    for(i=0;i<=strlen(s)-1;i++)
                        {
                            return 1;/*trebuie continuat cu functia pentru cazul cu ctg*/
                        }
                }
                    else if(strstr(s,"log"))
                    {
                        for(i=0;i<=strlen(s)-1;i++)
                            {
                                return 1;/*trebuie continuat cu functia pentru cazul cu log*/
                            }
                    }
                        else if(strstr(s,"rad"))
                        {
                            for(i=0;i<=strlen(s)-1;i++)
                                {
                                    return 1;/*trebuie continuat cu functia pentru cazul cu rad*/
                                }
                        }


    ///Emilia
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height);

    ///Ana-Maria
    //coordonate ecran
    STANGA=0;
    DREAPTA=width;
    TOP=0;
    BOTTOM=height;

    PlaySound("sound2.wav",NULL,SND_ASYNC);//sunet de fundal

    readimagefile("image1_1.jpg",0,0,width,height);//imagine de fundal
    readimagefile("romana.jpg",width-80,(height/5-140),width-30,(height/5-115));//steag->romana

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
    settextstyle(8, HORIZ_DIR, 3 );
    outtextxy(width/16,height/8,"Exit");//setari pentru formare buton exit
    /*dreptunghi exit*/

    ///Ana-Maria
    click(coordx,coordy);
    if(coordx>=(width/2-100)&&coordx<=(width/2+98)&&coordy>=(height/2-40)&&coordy<=(height/2+12))
        {//daca se face click pe primul buton: "Grafic"
            setcolor(YELLOW);
            rectangle(width/2-100, height/2-40, width/2+98,height/2+12);//schimbare buton in galben la click

            initwindow(width,height);

            readimagefile("image1_1.jpg",0,0,width,height);//poza fundal fereastra noua

            ///Emilia+Ana-Maria
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

            ///Emilia
            setcolor(WHITE);
            settextstyle(8, HORIZ_DIR, 3 );
            outtextxy(width-141,height/16-5,"Exit");//buton exit
            /*dreptunghi exit*/

            ///Ana-Maria
            clearmouseclick(WM_LBUTTONUP);
            click(coordx,coordy);
            if(coordx>=(width/3-379)&&coordx<=(width/4+376)&&
               coordy>=(height/3-10)&&coordy<=(height/4+15))
                 {//daca se apasa caseta cu "Introduceti functia aici:"
                  //se schimba culoare dreptunghiului in galben la click
                    setcolor(YELLOW);
                    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);
                    /*trebuie continuat cu o casuta de text*/
                 }
                 else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&
                         coordy>=(height/2+20)&&coordy<=(height/2+250))
                        {//daca se apasa caseta cu "Evaluator functie"
                         //se schimba culoare dreptunghiului in galben la click
                            setcolor(YELLOW);
                            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
                            /*trebuie continuat cu o casuta de text*/
                        }
                        ///Emilia
                        else if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                                    exit(1);//daca se apasa pe butonul de exit
                                    /*dreptunghi exit*/
            getch();
            closegraph();
        }
        ///Ana-Maria
        else if(coordx>=(width/2-119)&&coordx<=(width/2+117)&&
                coordy>=(height/2+110)&&coordy<=(height/2+165))
            {//daca se apasa butonul de "Contact"
            //se schimba culoare dreptunghiului in galben la click
                setcolor(YELLOW);
                rectangle(width/2-119, height/2+110, width/2+117,height/2+165);

                initwindow(width,height);

                readimagefile("image1_1.jpg",0,0,width,height);//imagine fundal

                settextstyle(8, HORIZ_DIR, 5);
                outtextxy(width/2-350,height/2-200,"Proiectul a fost realizat de:");//text 1

                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-180,height/2-70,"Ursache Ana-Maria");//text 2

                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-30,height/2+8,"si");//text 3

                settextstyle(8, HORIZ_DIR, 4);
                outtextxy(width/2-160,height/2+80,"Galatanu Emilia");//text 4

                ///Emilia
                settextstyle(8, HORIZ_DIR, 3 );
                outtextxy(width-1310,height/16-5,"Exit");//buton exit
                /*dreptunghi exit*/

                ///Emilia
                clearmouseclick(WM_LBUTTONUP);
                click(coordx,coordy);
                if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                        exit(1);//daca se apasa butonul de exit
                getch();
                closegraph();
            }
                ///Ana-Maria
                else if(coordx>=(width-80)&&coordx<=(width-30)&&
                        coordy>=(height/5-140)&&coordy<=(height/5-115))//daca se apasa setarea de limba
                        readimagefile("engleza.jpg",width-80,(height/5-140),width-30,(height/5-115));//se schimba imaginea->engleza

                else if(coordx>=(width/16)&&coordx<=(width/10)&&
                        coordy>=(height/5-140)&&coordy<=(height/5-115))
                                exit(1);//daca se apasa exit
                                /*dreptunghi exit*/
    getch();
    closegraph();
    return 0;
}
