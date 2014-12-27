#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>

using namespace std;
int n=28;

void gotoxy(short x, short y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}

class UsualCell
{
public:

    virtual int CreateCell()
    {
        return 15;
    }

};


class DoubleStep:public UsualCell
{
public:
    int CreateCell()
    {
        return 22;
    }
};


class StepBack:public UsualCell
{
public:
    int CreateCell()
    {
        return 35;
    }
};


class Dosmth:public UsualCell
{
public:
    int CreateCell()
    {
        return 127;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("CLS");
    int MyWibor;

    UsualCell *Array[n];
    UsualCell *ptr;


    for (int i=0; i<n; i++)
    {
        MyWibor=rand()%4;

        switch (MyWibor)
        {
        case 1:
            ptr=new DoubleStep;
            break;
        case 2:
            ptr=new StepBack;
            break;
        case 3:
            ptr=new Dosmth;
            break;
        default:
            ptr=new UsualCell;
            break;
        }

        Array[i]=ptr;
    }
    char *A = new char [n];
    for (int i=0; i<n; i++)
    {
        A[i]=(char)Array[i]->CreateCell();

    };
    cout<<endl;
    int kolp=0,h=0,r=n,high=10,start=0;
    while (r>0)
    {
        r=(r-h);
        h++;
        kolp+=1;

    }

    gotoxy(start,high);
    r=start+2;
    cout<<"->"<<A[0];

    for (int i=1; i<n; i++)
    {


        if(i%4==0)
        {
            cout<<endl;
            high+=2;
            gotoxy(r,high);
        }
        cout<<A[i];


    };
    cout<<" ->";


    for (int i=0; i<n; i++) delete Array[i];

    cin.get();
    cin.get();

}
