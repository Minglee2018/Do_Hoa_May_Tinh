#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>

using namespace std;
void Intoado(int x,int y)
{
    for(int i =0; i<=x; i+=20)
        putpixel(i,0,4),putpixel(i+1,0,4),putpixel(i+2,0,4),putpixel(i+3,0,4);
    for(int i=0; i<=y; i+=20)
        putpixel(0,i,4),putpixel(0,i+1,4),putpixel(0,i+2,4),putpixel(0,i+3,4);
}

void VeNen(int x1,int x2,int y1,int y2,int color)
{
    for(int i=y1; i<=y2; i++)
        for(int j=x1; j<=x2;j++)
            putpixel(j,i,color);
}

void put2pixel(int xc, int yc, int x, int y, int color,int type)
{
    if(type==1)
    {
        putpixel(-x + xc, -y + yc, color); // trái trên cùng
    }
    else
    {
        putpixel(x + xc, -y + yc, color); // phải trên cùng
    }
}
void HinhTron1(int xc, int yc, int r, int color,int type)
{
    int x = 0; int y = r;
    int f = 1 - r;
    put2pixel(xc, yc, x, y, color, type);
    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put2pixel(xc, yc, x, y, color, type);
    }
}
void put8pixel(int xc, int yc, int x, int y, int color,int type)
{
    if(type==1)
    {
       putpixel(x + xc, -y + yc, color); // phải trên cùng
       putpixel(y + xc, -x + yc, color); // bên phải trên
    }
    else if(type==2)
    {
        putpixel(-x + xc, -y + yc, color); // trái trên cùng
        putpixel(-y + xc, -x + yc, color); // bên trái trên
    }
    else if(type==3)
    {
        putpixel(-y + xc, x + yc, color); // bên trái dưới
        putpixel(-x + xc, y + yc, color); // trái dưới cùng
    }
    else if(type==4)
    {
        putpixel(x + xc, y + yc, color); // phải dưới cùng
        putpixel( y + xc, x + yc, color); // bên phải dưới
    }
    else if(type==5)
    {

        putpixel(x + xc, y + yc, color); // phải dưới cùng
        putpixel(-x + xc, y + yc, color); // trái dưới cùng
        putpixel(x + xc, -y + yc, color); // phải trên cùng
        putpixel(-x + xc, -y + yc, color); // trái trên cùng
        putpixel( y + xc, x + yc, color); // bên phải dưới
        putpixel(-y + xc, x + yc, color); // bên trái dưới
        putpixel(y + xc, -x + yc, color); // bên phải trên
        putpixel(-y + xc, -x + yc, color); // bên trái trên
    }
}


void HinhTron(int xc, int yc, int r, int color,int type)
{
    int x = 0; int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color, type);
    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, color, type);
    }
}

void Line(int range1,int range2, int u,int color,int type)
{
    if (type==1)
        for(int i = range1; i<=range2; i++)
            putpixel(i,u,color);
    else
        for(int i=range1; i<=range2; i++)
            putpixel(u,i,color);
}

void Tomaunuatren(int x,int y,int mauto,int maubien)
{
    int x1,x2;
    do
    {
        x1 = x, x2 = x;
        while(getpixel(x1-1,y)!=maubien) x1--;
        while(getpixel(x2+1,y)!=maubien) x2++;
        for(int i=x1; i<=x2; i++)
            putpixel(i,y,mauto);
        while(getpixel(x1,y+1)==maubien) x1++;
        if(x1<=x2) x = x1,y++;
    }while(x1<=x2);
}

void Tomaunuaduoi(int x,int y,int mauto,int maubien)
{
    int x1,x2;
    do
    {
        x1 = x, x2 = x;
        while(getpixel(x1-1,y)!=maubien) x1--;
        while(getpixel(x2+1,y)!=maubien) x2++;
        for(int i=x1; i<=x2; i++)
            putpixel(i,y,mauto);
        while(getpixel(x1,y-1)==maubien) x1++;
        if(x1<=x2) x = x1,y--;
    }while(x1<=x2);
}

void Loang(int x,int y,int mauto, int maubien)
{
    int mauhientai = getpixel(x,y);
    if(mauhientai!=mauto && mauhientai!=maubien)
    {
        putpixel(x,y,mauto);
        Loang(x-1,y,mauto,maubien);
        Loang(x,y-1,mauto,maubien);
        Loang(x+1,y,mauto,maubien);
        Loang(x,y+1,mauto,maubien);
    }
}

int main()
{
   initwindow(1000,600);
   VeNen(0,1000,0,200,9);
   VeNen(0,1000,200,400,2);
   VeNen(0,1000,400,600,8);
// xac dinh toa do
   // Intoado(1000,600);
// banh xe so 1
    HinhTron(300,440,90,15,5);
    Tomaunuatren(300,440,7,15);
    Tomaunuaduoi(300,440,7,15);
    HinhTron(300,440,50,8,5);
    Loang(300,440,15,8);

// banh xe so 2
   HinhTron(600,440,90,15,5);
   Tomaunuatren(600,440,7,15);
   Tomaunuaduoi(600,440,7,15);
   HinhTron(600,440,50,8,5);
   Loang(600,440,15,8);
// noc oto
    HinhTron(450,240,130,14,5);
    Tomaunuaduoi(450,220,4,14);
    Tomaunuatren(450,220,4,14);
    HinhTron(450,240,120,15,1);
    HinhTron(450,240,120,15,2);
    Line(320,580,240,15,1);
    Line(120,240,440,15,2);
    Line(120,240,460,15,2);
    Loang(420,230,14,15);
    Loang(480,230,14,15);
// than oto
    HinhTron(580,400,160,15,1);
    HinhTron(320,400,160,15,2);
    Line(160,200,440,15,1);
    Line(400,500,440,15,1);
    Line(700,740,440,15,1);

    Line(400,440,160,15,2);
    Line(400,440,740,15,2);
    HinhTron(300,440,100,15,1);
    HinhTron(300,440,100,15,2);

    HinhTron(600,440,100,15,1);
    HinhTron(600,440,100,15,2);
//To mau than oto
    Tomaunuatren(450,240,13,15);
    Tomaunuatren(450,340,13,15);
    Tomaunuatren(720,340,13,15);
// mat troi
    // vien trong
    HinhTron(70,200,80,15,1);
    HinhTron(70,200,80,15,2);
    //vien ngoai
    HinhTron(70,200,90,15,1);
    HinhTron(70,200,90,15,2);
    Line(0,160,200,15,1);
    Line(140,200,0,15,2);
    Loang(40,120,14,15);
    Loang(60,180,4,15);
// ve may 1
    HinhTron(180,60,45,14,5);
    Loang(180,60,15,14);
    HinhTron(210,70,50,14,5);
    Loang(240,70,15,14);
    HinhTron(255,60,45,14,5);
    Loang(260,60,15,14);
// ve may 2
    HinhTron(780,60,45,14,5);
    Loang(780,60,15,14);
    HinhTron(820,70,48,14,5);
    Loang(840,70,15,14);
// chim
    HinhTron(920,140,25,15,1);
    HinhTron(970,140,25,15,2);
// hinh pokeman
    HinhTron(680,320,30,15,5);
    Loang(680,320,14,15);
    for(int i = 315; i<=325; i++)
        Line(680,710,i,15,1);
// ve co
    HinhTron(100,600,30,10,1);
    HinhTron(160,600,30,10,2);

    HinhTron(400,600,30,10,1);
    HinhTron(460,600,30,10,2);

    HinhTron(700,600,30,10,1);
    HinhTron(760,600,30,10,2);

    HinhTron(900,600,30,10,1);
    HinhTron(960,600,30,10,2);
// hoa 1
    HinhTron(50,550,7,15,5);    Loang(50,550,14,15);
    HinhTron(50,570,7,15,5);    Loang(50,570,14,15);

    HinhTron(70,550,7,15,5);    Loang(70,550,14,15);
    HinhTron(70,570,7,15,5);    Loang(70,570,14,15);
    HinhTron(60,560,10,10,5);
    Tomaunuaduoi(60,560,4,10);
    Tomaunuatren(60,560,4,10);
    Line(570,600,60,10,2);

    getch();
}
