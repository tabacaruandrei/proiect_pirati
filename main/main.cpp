#include<iostream>
#include<cstring>
#include<graphics.h>
#include<winbgim.h>
using namespace std;

void *p;
int click, area;

// de pus in structuri

/*
char* f1="fig_1.jpg";
char* f2="fig_2.jpg";
char* f3="fig_3.jpg";
char* fb="fig_b.jpg";*/

int cx[50],cy[50],mx[50],my[50]; // x, y, marime x, marime y
// 1 - fig 1; 2 - fig 2; 3 - fig 3; 4 - fig busola; 5 - cadran 1; 6 - cadran 2; 7 - cadran 3; 8 - cadran 4; 9 - tabla joc

//retinem un vector pt rotire
char f1[12]="fig_1_1.jpg", f2[12]="fig_2_1.jpg", f3[12]="fig_3_1.jpg", f4[12]="fig_b_1.jpg";

int i,j; // in caz ca am for-uri

struct
{
    int x,y;
}m/*,c,s(size)*/; // mouse

/*void areaclick(void *p, int i)
{
    int area = imagesize(cx[i], cy[i], cx[i]+mx[i], cy[i]+my[i]);
    p = malloc(area);
}*/

void meniu()
{
    //lucrat de Victoria
    //readimagefile("fundal.jpg",0,0,1500,600);
    //setcolor(BLACK);
    cleardevice();
    settextstyle(8,0,3);
    settextjustify(1,1);
    rectangle(500,100,700,150);
    outtextxy(600,130,"START");
    rectangle(500,175,700,225);
    outtextxy(600,205,"NIVELURI");
    rectangle(500,250,700,300);
    outtextxy(600,280,"DESPRE");
    rectangle(500,325,700,375);
    outtextxy(600,355,"REGULI");
    rectangle(500,400,700,450);
    outtextxy(600,430,"EXIT");
}

void desen()
{
    //lucrat de amandoi
    //initwindow(1500,600);
    cleardevice();
    readimagefile("fundal.jpg",0,0,1900,1280);
    readimagefile("tabla_joc.jpg",400,0,934,533);
    cx[9]=400;
    cy[9]=0;
    mx[9]=534;
    my[9]=533;
    cx[5]=450;
    cy[5]=50;
    mx[5]=200;
    my[5]=200;
    cx[6]=450;
    cy[6]=50;
    mx[6]=200;
    my[6]=200;
    cx[7]=450;
    cy[7]=50;
    mx[7]=200;
    my[7]=200;
    cx[8]=450;
    cy[8]=50;
    mx[8]=200;
    my[8]=200;
    readimagefile("ex.jpg",100,200,373,528);
    readimagefile("fig_1_1.jpg",1000,100,1200,300);
    cx[1]=1000;
    cy[1]=100;
    mx[1]=200;
    my[1]=200;
    readimagefile("fig_2.jpg",1000,350,1200,550);
    cx[2]=1000;
    cy[2]=350;
    mx[2]=200;
    my[2]=200;
    readimagefile("fig_3.jpg",1250,100,1450,300);
    cx[3]=1250;
    cy[3]=100;
    mx[3]=200;
    my[3]=200;
    readimagefile("fig_b.jpg",1250,350,1450,550);
    cx[4]=1250;
    cy[4]=350;
    mx[4]=200;
    my[4]=200;
    //rectangle(1250,50,1450,150);
}

void transparenta()
{
    for(int m=0;m<=0+mx[i];m++)
    {
        for(int n=0;n<=0+my[i];n++)
        {
            if(getpixel(m+cx[i],n+cy[i])==15)
                putpixel(m+cx[i],n+cy[i],getpixel(m+450,n+50));
        }
    }
}

/*
void mutare()
{
    // preluat din modelul razboi in 8 dat de domnul Patrut
    if(m.x>=cx[1] && m.x<=cx[1]+mx[1] && m.y>=cy[1] && m.y<=cy[1]+my[1])
    {
        getimage(cx[1], cy[1], cx[1]+mx[1], cy[1]+my[1], p);

        putimage(600, 200, p, 0);
        readimagefile("fundal.jpg",cx[1],cy[1],cx[1]+mx[1],cy[1]+my[1]);
        cx[1]=600;
        cy[1]=200;

    }
}
*/

void select()
{
    if(m.x>=cx[1] && m.x<=cx[1]+mx[1] && m.y>=cy[1] && m.y<=cy[1]+my[1])
    {
        i=1;
    }
    if(m.x>=cx[2] && m.x<=cx[2]+mx[2] && m.y>=cy[2] && m.y<=cy[2]+my[2])
    {
        i=2;
    }
    if(m.x>=cx[3] && m.x<=cx[3]+mx[3] && m.y>=cy[3] && m.y<=cy[3]+my[3])
    {
        i=3;
    }
    if(m.x>=cx[4] && m.x<=cx[4]+mx[4] && m.y>=cy[4] && m.y<=cy[4]+my[4])
    {
        i=4;
    }
    if(m.x>=cx[5] && m.x<=cx[5]+mx[5] && m.y>=cy[5] && m.y<=cy[5]+my[5])
    {
        i=5;
    }
    if(m.x>=cx[6] && m.x<=cx[6]+mx[6] && m.y>=cy[6] && m.y<=cy[6]+my[6])
    {
        i=6;
    }
    if(m.x>=cx[7] && m.x<=cx[7]+mx[7] && m.y>=cy[7] && m.y<=cy[7]+my[7])
    {
        i=7;
    }
    if(m.x>=cx[8] && m.x<=cx[8]+mx[8] && m.y>=cy[8] && m.y<=cy[8]+my[8])
    {
        i=8;
    }
}

void atasare()
{
    transparenta();
    if(m.x>=450 && m.x<=450+mx[i] && m.y>=50 && m.y<=50+my[i])
    {
        getimage(cx[i], cy[i], cx[i]+mx[i], cy[i]+my[i], p);
        readimagefile("fundal.jpg",cx[i],cy[i],cx[i]+mx[i],cy[i]+my[i]);
        putimage(450, 50, p, 0);
        cx[i]=450;
        cy[i]=50;
    }
}

void rotire()
{
    //lucrat de Andrei
    //1100, 200, 1250, 350
    if(m.x>=cx[1] && m.x<=cx[1]+mx[1] && m.y>=cy[1] && m.y<=cy[1]+my[1])
    {
        //rotarea e memorata prin numere; 1 - normal, 2 - dreapta, 3 - jos, 4 - stanga
        if(f1[strlen(f1)-5]=='4')
            f1[strlen(f1)-5]='0';
        f1[strlen(f1)-5]++;
        readimagefile(f1,cx[1],cy[1],cx[1]+mx[1],cy[1]+my[1]);
        if(m.x>=cx[9] && m.x<=cx[9]+mx[9] && m.y>=cy[9] && m.y<=cy[9]+my[9])
            transparenta();
    }
}

void reguli()
{
    // lucrat de Victoria
    cleardevice();
    settextstyle(8,0,2);
    settextjustify(1, 1);
    outtextxy(600, 100, "Pasul 1");
    outtextxy(600, 150, "Alege un nivel");
    outtextxy(600, 200, "Pasul 2");
    outtextxy(600, 250, "Aranjati cele patru piese ale puzzle-ului pe tabla de joc astfel incat toate imaginile");
    outtextxy(600, 300, "sa fie acoperite, cu exceptia celor afisate in provocare");
    outtextxy(600, 350, "Pasul 3");
    outtextxy(600, 400, "Exista o singura solutie pentru fiecare provocare.");
}

void despre()
{
    // lucrat de Victoria
    cleardevice();
    settextstyle(8, 0, 3);
    settextjustify(1, 1);
    outtextxy(600, 80, "Categorie:  Jocuri compacte");
    outtextxy(600, 160, "Varsta:  6+");
    outtextxy(600, 240, "Numar de niveluri:  20");
    outtextxy(600, 320, "Numar jucatori:  1");
    outtextxy(600, 400, "Instrumeste disponibile:");
    outtextxy(600, 480, "1 tabla de joc, 4 piese de puzzle, 1 brosura cu 20 de provocari");
}

void clickmeniu()
{
    if(m.x>=500 && m.x<=700)
    {
        if(m.y>=100 && m.y<=150)
        {
            desen();
            click=true;
        }
        if(m.y>=175 && m.y<=225)
        {
            //niveluri();
            click=true;
        }
        if(m.y>=250 && m.y<=300)
        {
            despre();
            click=true;
        }
        if(m.y>=325 && m.y<=375)
        {
            reguli();
            click=true;
        }
    }
}

int main()
{
    //declaram fereastra de inceput
    initwindow(1500,600);
    meniu();

    // in lucru
    // trebuie gasita o modalitate prin care iesim din meniu si intram in alta fereastra dupa click
    do{
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        { // ideea lui Leonard
            clearmouseclick(WM_LBUTTONDOWN);
            m.x=mousex(); m.y=mousey();
            clickmeniu();
            if(m.x>=500 && m.x<=700 && m.y>=400 && m.y<=450)
            {
                return 0;
            }
        }
    }while(!click);
    click=false;

    // scot vectori x, y, marime pentru figurile de puzzle

    area = imagesize(1000, 200, 1250, 350);
    p = malloc(area);


    // sa combin do ... while(!click)-urile intr-unul singur
    // pun operatiile in voiduri tip clickmeniu, de ex clickdesen
    // daca n-am nevoie ulterior de m.x, m.y, las mousex() si mousey()

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            m.x=mousex(); m.y=mousey();
            int i;
            select();
            //model pentru butonul de intoarcere; momentan nu apare
            /*if(m.x>=1250 && m.x<=1450 && m.y>=50 && m.y<=150)
            {
                click=true;
                meniu();
            }*/
        }
        if(ismouseclick(WM_MBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_MBUTTONDOWN);
            m.x=mousex(); m.y=mousey();
            atasare();
        }
        if(ismouseclick(WM_RBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_RBUTTONDOWN);
            m.x=mousex(); m.y=mousey();
            rotire();
        }
    }while(!click);
    click=false;

    getch();
    closegraph();
    return 0;
}
