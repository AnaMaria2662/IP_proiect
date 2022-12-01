/*
Plan:
-limba
-buton sunet
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

void click(int &coordxclick, int &coordyclick )//functie pentru click
{
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN))
        delay(20);
    getmouseclick(WM_LBUTTONDOWN, x, y);
    coordxclick=x;
    coordyclick=y;
}

double f(double x)//functia in care se va forma functia dupa ce este preluata ca sir de caractere
{
    if(x!=0)
        return x*sin(1.0*x);//neterminata, in loc de 1 ar fi functia noastra citita->evaluator
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

void graficfunctie()//trasare linie grafic pt toate punctele
{
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

int main()
{
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
    //trasare grafic
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);

    initwindow(width,height);

    setcolor(RED);
    rectangle(STANGA,TOP,DREAPTA,BOTTOM);
    line(STANGA,height/2,DREAPTA, height/2);//axa ox
    line(width/2,TOP,width/2,BOTTOM);//axa oy

    setcolor(YELLOW);
    graficfunctie();
    //trasare grafic
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


    ///Emilia
    height=GetSystemMetrics(SM_CYSCREEN);
    width=GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height);

    ///Ana-Maria
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
    //dreptunghi exit

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
            //dreptunghi exit

            ///Ana-Maria
            clearmouseclick(WM_LBUTTONUP);
            click(coordx,coordy);
            if(coordx>=(width/3-379)&&coordx<=(width/4+376)&&
               coordy>=(height/3-10)&&coordy<=(height/4+15))
                 {//daca se apasa caseta cu "Introduceti functia aici:"
                  //se schimba culoare dreptunghiului in galben la click
                    setcolor(YELLOW);
                    rectangle(width/2-320,height/3+70,width/4+655,height/3+130);
                    //trebuie continuat cu o casuta de text
                 }
                 else if(coordx>=(width/2-379)&&coordx<=(width/2+376)&&
                         coordy>=(height/2+20)&&coordy<=(height/2+250))
                        {//daca se apasa caseta cu "Evaluator functie"
                         //se schimba culoare dreptunghiului in galben la click
                            setcolor(YELLOW);
                            rectangle(width/2-379,height/2+20,width/2+376,height/2+250);
                            //trebuie continuat cu o casuta de text
                        }
                        ///Emilia
                        else if(coordx>=(width/16)&&coordx<=(width/10)&&coordy>=(height/5-140)&&coordy<=(height/5-115))
                                    exit(1);//daca se apasa pe butonul de exit
                                    //dreptunghi exit
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
                //dreptunghi exit

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
                        coordy>=(height/5-140)&&coordy<=(height/5-115))//steag-daca se apasa setarea de limba
                        readimagefile("engleza.jpg",width-80,(height/5-140),width-30,(height/5-115));//se schimba imaginea->engleza

                else if(coordx>=(width/16)&&coordx<=(width/10)&&
                        coordy>=(height/5-140)&&coordy<=(height/5-115))
                                exit(1);//daca se apasa exit
                                    //dreptunghi exit
    */
    getch();
    closegraph();
    return 0;
}
