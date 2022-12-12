//Ana-Maria
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
