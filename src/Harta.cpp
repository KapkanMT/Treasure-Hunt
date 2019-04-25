#include "Harta.h"

using namespace std;

Harta::Harta()
{
    int i,j;
    harta=new int*[17];
    for(i=0;i<17;i++)
    {
        harta[i]=new int[17];
    }
    for (i=0;i<17;i++)
        for(j=0;j<17;j++)
        {
            if (i==0 || j==0 || i==16 || j==16)
                harta[i][j]=1;
            else
                harta[i][j]=0;
        }
    i=j=1;
    harta[1][1]=6;
    harta[1][15]=7;
    harta[15][15]=8;
    harta[15][1]=9;
    treasureGenerator(i,j);
    treasureGenerator(i,j);
    treasureGenerator(i,j);
    statusHolder=new int[4];
    for (i=0;i<4;i++)
    {
        statusHolder[i]=0;
    }
}

ostream & operator << (ostream &out,const Harta &h)
{
    int i,j;
    for(i=0;i<17;i++)
        {
            for(j=0;j<17;j++)
                out<<h.harta[i][j]<<" ";
                out<<"\n";
        }
    out<<"\n";
    for(i=0;i<4;i++)
    {
        if (h.statusHolder[i]==0)
        {
            out<<"Exploratorul"<<i+1<<" continua sa exploreze"<<"\n";
        }
        if (h.statusHolder[i]==1)
        {
            out<<"Exploratorul"<<i+1<<" a ramas blocat!"<<"\n";
        }
        if (h.statusHolder[i]==2)
        {
            out<<"Exploratorul"<<i+1<<" a gasit o comoara!"<<"\n";
        }
    }
    return out;
}


int* &Harta::operator[](const int i)
{
    return harta[i];
}

void Harta::ModifyE1(int i,int j)
{
    harta[i][j]=6;
}

void Harta::ModifyE2(int i,int j)
{
    harta[i][j]=7;
}

void Harta::ModifyE3(int i,int j)
{
    harta[i][j]=8;
}

void Harta::ModifyE4(int i,int j)
{
    harta[i][j]=9;
}

void Harta::Modify(int i,int j)
{
    harta[i][j]=1;
}

int* Harta::getStatusHolder()
{
    return statusHolder;
}

void Harta::setStatusHolder(int* statusHold)
{
    for (int i=0;i<4;i++)
    {
        this->statusHolder[i]=statusHold[i];
    }
}

int Harta::Randomgenspecial()
{
    int randomnr,offset;
    randomnr = rand()%16;
    offset = rand()%14+1;
    if (randomnr==0)
        randomnr=randomnr+offset;
    return randomnr;
}

void Harta::treasureGenerator(int &i,int &j)
{
    int x,y;
    x=Randomgenspecial();
    y=Randomgenspecial();
    if ((x==i) & (y==j))
    {
        x=abs(x-y+1);
        y=abs(y-x+1);
    }
    if ((x==1) & (y==1))
    {
        x=x+4;
        y=y+6;
    }
    if ((x==1) & (y==15))
    {
        x=x+3;
        y=y-7;
    }
    if ((x==15) & (y==15))
    {
        x=x-6;
        y=y-10;
    }
    if ((x==15) & (y==1))
    {
        x=x-3;
        y=y+12;
    }
    cout<<"Comoara:"<<x<<" "<<y<<"\n";
    harta[x][y]=4;
    i=x;
    j=y;
    return;
}

void Harta::statusModifier(int* statusHold,int number,int ExNumber)
{
    statusHold[ExNumber-1] = number;
    this->setStatusHolder(statusHold);
}

Harta::~Harta()
{
    for (int i=0;i<16;i++)
    {
        delete[] harta[i];
    }
    delete[] harta;
}
