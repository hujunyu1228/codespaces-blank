#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int toint(float a){return ((int)(a*10+5))/10;}
void Setpos(float x,float y){COORD pos;pos.X=toint(y*2),pos.Y=toint(x);SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
void Color(int a)
{
    if(a%12==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a%12==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a%12==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a%12==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a%12==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a%12==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a%12==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    if(a%12==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a%12==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
    if(a%12==9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
    if(a%12==10) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a%12==11) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);
}
struct node
{
    float x,y,z;
    float vx,vy,vz;
    float r,m;
    bool life;
}Sun[1000001];
void Push(int a,int b)
{
    float Ax=Sun[a].x-Sun[b].x,Ay=Sun[a].y-Sun[b].y,Dis=sqrt(Ax*Ax+Ay*Ay)*1.0;
    if(Dis<=20) return;//未撞: Dis>=Sun[a].r||Dis>=Sun[b].r||

    float ac=Sun[a].m*Sun[b].m/(Dis*Dis)*1.0,afx=0,afy=0;
    if(abs(Ay)<=1) Ay=1;
    float d=abs(Ax/Ay*1.0);
    afy=sqrt(ac/(1+d*d))*1.0,afx=sqrt(ac/(1+d*d))*d*1.0;
    if(Ax>0) afx*=-1;if(Ay>0) afy*=-1;
    if(abs(Ay)>1) Sun[a].vx+=afx/Sun[a].m*10.0;
    Sun[a].vy+=afy/Sun[a].m*10.0;
    if(abs(Ay)>1) Sun[b].vx-=afx/Sun[b].m*10.0;
    Sun[b].vy-=afy/Sun[b].m*10.0;
}
int b,T,More=10,Speed=15;
void Move()
{
    for(int i=1;i<=b;i++)
    {
        Setpos(Sun[i].x/More*1.0,Sun[i].y/More*1.0);cout<<"  ";
        Sun[i].x+=Sun[i].vx*More/10.0;Sun[i].y+=Sun[i].vy*More/10.0;
        if(Sun[i].x>=40*More) Sun[i].x=40*More,Sun[i].vx=0;
        if(Sun[i].x<=1) Sun[i].x=1,Sun[i].vx=-0;
        if(Sun[i].y>=40*More) Sun[i].y=40*More,Sun[i].vy=0;
        if(Sun[i].y<=1) Sun[i].y=1,Sun[i].vy=0;
        Setpos(Sun[i].x/More*1.0,Sun[i].y/More*1.0);Color(i);cout<<"●";
    }
    for(int i=1;i<=b;i++)
    for(int j=i+1;j<=b;j++) Push(i,j);
}
int rand(int a){return rand()%a;}
void Start(int a) {b++;Sun[a].x=rand(40)*More,Sun[a].y=rand(40)*More,Sun[a].vx=(rand(41)-20)*More/100.0,Sun[a].vy=(rand(41)-20)*More/100.0,Sun[a].m=1000;}//(rand(20)+1)*100;}
int main()
{
    system("mode con cols=82 lines=42");
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));

//  自己改速度与放大倍数（出界会速度清零），白的是三体行星，还有三个太阳。 

    for(int i=1;i<=100;i++) Start(i);
    while(1)
    {
        Setpos(3,5);Color(0);cout<<"三 体 模 型 0.5     (  n*太阳 (质点)  )"; 
        T++;
        Move();
        Sleep(Speed);
    }
}