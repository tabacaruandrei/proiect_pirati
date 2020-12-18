#include<iostream>
#include<cstring>
#include<graphics.h>
#include<winbgim.h>
using namespace std;

int area;
int click;
void *p;
/*
char* f1="fig_1.jpg";
char* f2="fig_2.jpg";
char* f3="fig_3.jpg";
char* fb="fig_b.jpg";*/

int cx[50],cy[50],mx[50],my[50]; // x, y, marime x, marime y

//retinem un vector pt rotire
char f1[12]="fig_1_1.jpg", f2[12]="fig_2_1.jpg", f3[12]="fig_3_1.jpg", f4[12]="fig_b_1.jpg";

int i,j; // in caz ca am for-uri

struct
{
    int x,y;
}m; // mouse

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
    readimagefile("ex.jpg",100,200,373,528);
    readimagefile("fig_1_1.jpg",1100,200,1250,350);
    cx[1]=1100;
    cy[1]=200;
    mx[1]=150;
    my[1]=150;
    readimagefile("fig_2.jpg",1100,400,1250,550);
    readimagefile("fig_3.jpg",1300,200,1450,350);
    readimagefile("fig_b.jpg",1300,400,1450,550);
    rectangle(1250,50,1450,150);
}



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
    }

}

void reguli()
{
    // lucrat de Victoria
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
    area = imagesize(1100, 200, 1250, 350);
    p = malloc(area);

    // sa combin do ... while(!click)-urile intr-unul singur
    // pun operatiile in voiduri tip clickmeniu, de ex clickdesen

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            m.x=mousex(); m.y=mousey();
            mutare();
            //model pentru butonul de intoarcere; momentan nu apare
            if(m.x>=1250 && m.x<=1450 && m.y>=50 && m.y<=150)
            {
                click=true;
                meniu();
            }
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
