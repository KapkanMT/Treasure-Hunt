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
    return out;
}

int** Harta::getHarta()
{
    return harta;
    cout<<"Mesaj special ";
}

void Harta::Modify(int i,int j)
{
    harta[i][j]=1;
}

Harta::~Harta()
{
    for (int i=0;i<16;i++)
    {
        delete[] harta[i];
    }
    delete[] harta;
}
