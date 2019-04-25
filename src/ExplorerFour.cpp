#include "ExplorerFour.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ExplorerFour::ExplorerFour()
{
    linpos=15;
    colpos=1;
    freeze=0;
}

int ExplorerFour::getlinpos()
{
    return linpos;
}

int ExplorerFour::getcolpos()
{
    return colpos;
}

void ExplorerFour::modifylinpos(int i)
{
    this->linpos=i;
}

void ExplorerFour::modifycolpos(int i)
{
    this->colpos=i;
}

int** ExplorerFour::movecheck(Harta h)
{
    int lin=getlinpos();
    int col=getcolpos();
    int i,j,k;
    int** movelist=new int*[9];
    for (i=0;i<9;i++)
    {
        movelist[i]=new int[i];
    }
    k=0;
    movelist[0][0]=movelist[0][1]=2;

    for(i=-1;i<=1;i++)
        for (j=-1;j<=1;j++)
    {
        if ((h.harta[lin+i][col+j]==0) || (h.harta[lin+i][col+j]==4))
        {
            movelist[k][0]=i;
            movelist[k][1]=j;
            k++;
        }
    }
    return movelist;
}

void ExplorerFour::Move(int i,int j,Harta h)
{
    int lin=getlinpos();
    int col=getcolpos();
    h.Modify(i+lin,j+col);
}

void ExplorerFour::MoveDecider(Harta &h)
{
    int l,m,s=0,x;
    int** movelist=new int*[9];
    if (freeze==0)
    {
        for (int i=0;i<1;i++)
        {
            movelist[i]=new int[i];
        }

        int lin=getlinpos();
        int col=getcolpos();
        movelist=movecheck(h);
        if (movelist[0][0]==2)
        {
            h.statusModifier(h.getStatusHolder(),1,4);
            delete this;
            return;
        }

        x = rand()%8;
        for (int k=0;k<4;k++)
        {
            if (s==0)
            {
                switch (x)
                {
                    case 0:l=0;m=1;s++;
                    break;
                    case 1:l=1;m=0;s++;
                    break;
                    case 2:l=0;m=-1;s++;
                    break;
                    case 3:l=0;m=-1;s++;
                    break;
                }
            }
            else if (s!=0)
            {
                    switch (x)
                {
                    case 0:l=-1;m=-1;s--;
                    break;
                    case 1:l=-1;m=1;s--;
                    break;
                    case 2:l=1;m=-1;s--;
                    break;
                    case 3:l=1;m=1;s--;
                    break;
                }
            }

            for (int i=0;i<8;i++)
            {
                if ((movelist[i][0]==l) & (movelist[i][1]==m))
                {
                    h.Modify(lin,col);
                    lin=lin+l;
                    col=col+m;
                    modifycolpos(col);
                    modifylinpos(lin);
                    if (h.harta[lin][col]==4)
                    {
                        h.statusModifier(h.getStatusHolder(),2,4);
                        delete this;
                    }
                    h.ModifyE4(lin,col);
                    return;
                }
            }
        }
    }
}

ExplorerFour::~ExplorerFour()
{
    freeze=1;
}
