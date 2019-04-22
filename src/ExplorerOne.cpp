#include "ExplorerOne.h"

ExplorerOne::ExplorerOne()
{
    linpos=1;
    colpos=1;
}

int ExplorerOne::movecheck()
{
    int i,j,k,l;
    int freemove[9][2];
    freemove[0][0]=0;
    k=0;
    l=0;
    for(i=-1;i<1;i++)
        for (j=-1;j<1;j++)
    {
        if (getHarta[linpos+i][colpos+j]==0)
        {
            freemove[k][l]=i;
            freemove[k][l+1]=j;
            k++;
        }
    }

    return freemove;
}

ExplorerOne::~ExplorerOne()
{

}
