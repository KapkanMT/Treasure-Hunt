#include "ExplorerOne.h"

ExplorerOne::ExplorerOne()
{
    linpos=1;
    colpos=1;
    freeze=0;
}

int ExplorerOne::getlinpos()
{
    return linpos;
}

int ExplorerOne::getcolpos()
{
    return colpos;
}

void ExplorerOne::modifylinpos(int i)
{
    this->linpos=i;
}

void ExplorerOne::modifycolpos(int i)
{
    this->colpos=i;
}

int** ExplorerOne::movecheck(Harta h)
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

void ExplorerOne::Move(int i,int j,Harta h)
{
    int lin=getlinpos();
    int col=getcolpos();
    h.Modify(i+lin,j+col);
}

void ExplorerOne::MoveDecider(Harta &h)
{
    int l,m;
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
            h.statusModifier(h.getStatusHolder(),1,1);
            delete this;
            return;
        }

        for (int k=0;k<4;k++)
        {
            switch (k)
            {
                case 0:l=0;m=1;
                break;
                case 1:l=1;m=0;
                break;
                case 2:l=0;m=-1;
                break;
                case 3:l=0;m=-1;
                break;
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
                        h.statusModifier(h.getStatusHolder(),2,1);
                        delete this;
                    }
                    h.ModifyE1(lin,col);
                    return;
                }
            }
        }
    }

}

ExplorerOne::~ExplorerOne()
{
    this->freeze=1;
}
