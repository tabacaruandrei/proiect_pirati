#include <iostream>
#include<cstring>
#include<graphics.h>
#include<winbgim.h>
using namespace std;

int x,y;
int area;
int click;
void *p;
/*
char* f1="fig_1.jpg";
char* f2="fig_2.jpg";
char* f3="fig_3.jpg";
char* fb="fig_b.jpg";*/

void meniu()
{
    //lucrat de Victoria
    //readimagefile("fundal.jpg",0,0,1500,600);
    //setcolor(BLACK);
    settextstyle(8,0,3);
    settextjustify(1,1);
    rectangle(500,100,700,175);
    outtextxy(600,140,"START");
    rectangle(500,225,700,300);
    outtextxy(600,265,"NIVELURI");
    rectangle(500,350,700,425);
    outtextxy(600,390,"REGULI");
    rectangle(500,475,700,550);
    outtextxy(600,515,"EXIT");

}

void desen()
{
//lucrat de amandoi
initwindow(1500,600);
readimagefile("fundal.jpg",0,0,1900,1280);
readimagefile("tabla_joc.jpg",400,0,934,533);
readimagefile("ex.jpg",100,200,373,528);
readimagefile("fig_1.jpg",1100,200,1250,350);
readimagefile("fig_2.jpg",1100,400,1250,550);
readimagefile("fig_3.jpg",1300,200,1450,350);
readimagefile("fig_b.jpg",1300,400,1450,550);
}

void mutare()
{
    // preluat din modelul razboi in 8 dat de domnul Patrut
    if(x>=1100 && x<=1250 && y>=200 && y<=350)
    {
        getimage(1100, 200, 1250, 350, p);
        putimage(600, 200, p, 0);
        readimagefile("fundal.jpg",1100,200,1250,350);
        click=true;
    }
}

void rotire()
{
    // lucrat de Andrei
    if(x>=1100 && x<=1250 && y>=200 && y<=350)
    {
        readimagefile("fig_1_drp.jpg",1100,200,1250,350);
    }
}

void reguli()
{
    // lucrat de Victoria
    initwindow(1500,600);
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
    initwindow(1500,600);
    settextstyle(8, 0, 3);
    settextjustify(1, 1);
    outtextxy(600, 80, "Categorie:  Jocuri compacte");
    outtextxy(600, 160, "Varsta:  6+");
    outtextxy(600, 240, "Numar de niveluri:  20");
    outtextxy(600, 320, "Numar jucatori:  1");
    outtextxy(600, 400, "Instrumeste disponibile:");
    outtextxy(600, 480, "1 tabla de joc, 4 piese de puzzle, 1 brosura cu 20 de provocari");
}

int main()
{
//declaram fereastra de inceput
initwindow(1500,600);
meniu();

// in lucru
// trebuie gasita o modalitate prin care iesim din meniu si intram in alta fereastra dupa click
/*
if(ismouseclick(WM_LBUTTONDOWN))
{
if(x>=500 && x<=700 && y>=100 && y<=175)
        desen();
//if(x>=500 && x<=700 && y>=225 && y<=300)
//if(x>=500 && x<=700 && y>=350 && y<=425)
//if(x>=500 && x<=700 && y>=475 && y<=550)
}
*/
    do{
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex(); y=mousey();
            if(x>=500 && x<=700 && y>=100 && y<=175)
            {
                desen();
                click=true;
            }
            if(x>=500 && x<=700 && y>=225 && y<=300)
            {
                //niveluri();
                click=true;
            }
            if(x>=500 && x<=700 && y>=350 && y<=425)
            {
                reguli();
                click=true;
            }
            if(x>=500 && x<=700 && y>=475 && y<=550)
            {
                return 0;
            }
        }
    }while(!click);
click=false;

area = imagesize(1100, 200, 1250, 350);
p = malloc(area);

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex(); y=mousey();
            mutare();
        }
        if(ismouseclick(WM_RBUTTONDOWN) && !click)
        {
            clearmouseclick(WM_RBUTTONDOWN);
            x=mousex(); y=mousey();
            rotire();
        }
    }while(!click);
click=false;
 getch();
 closegraph();
 return 0;

}
