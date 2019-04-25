#include "ExplorerThree.h"

ExplorerThree::ExplorerThree()
{
    linpos=15;
    colpos=15;
    freeze=0;
}

int ExplorerThree::getlinpos()
{
    return linpos;
}

int ExplorerThree::getcolpos()
{
    return colpos;
}

void ExplorerThree::modifycolpos(int i)
{
    this->colpos=i;
}

void ExplorerThree::modifylinpos(int i)
{
    this->linpos=i;
}

int** ExplorerThree::movecheck(Harta h)
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

void ExplorerThree::Move(int i,int j,Harta h)
{
    int lin=getlinpos();
    int col=getcolpos();
    h.Modify(i+lin,j+col);
}

void ExplorerThree::MoveDecider(Harta &h)
{
    int l,m,cond=0;
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
            h.statusModifier(h.getStatusHolder(),1,3);
            delete this;
            return;
        }
        for (int k=0;k<4;k++)
        {
            switch (k)
            {
                case 0:l=-1;m=-1;
                break;
                case 1:l=-1;m=1;
                break;
                case 2:l=1;m=-1;
                break;
                case 3:l=1;m=1;
                break;
            }

            for (int i=0;i<8;i++)
            {
                if ((movelist[i][0]==l) & (movelist[i][1]==m))
                {
                    cond=1;
                    h.Modify(lin,col);
                    lin=lin+l;
                    col=col+m;
                    modifycolpos(col);
                    modifylinpos(lin);
                    if (h.harta[lin][col]==4)
                    {
                        h.statusModifier(h.getStatusHolder(),2,3);
                        delete this;
                    }
                    h.ModifyE3(lin,col);
                    return;
                }
            }
        }
    }
}

ExplorerThree::~ExplorerThree()
{
    this->freeze=1;
}
