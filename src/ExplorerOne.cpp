#include "ExplorerOne.h"

ExplorerOne::ExplorerOne()
{
    linpos=1;
    colpos=1;
}

int** ExplorerOne::movecheck(Harta h)//TREBUIE SA TRIMIT HARTA PRIN FUNCTIE
{
    ExplorerOne Ex1();
    int i,j,k,l;
    int** movelist=new int*[9];
    for (i=0;i<1;i++)
    {
        movelist[i]=new int[i];
    }
    k=0;
    l=0;

    movelist[0][0]=movelist[0][1]=2;
    cout<<h.harta[linpos]<<" "<<h.harta[colpos]<<"\n";

    for(i=-1;i<=1;i++)
        for (j=-1;j<=1;j++)
    {
        cout<<i<<j;
        if (h.harta[linpos+i][colpos+j]==0)
        {
            movelist[k][l]=i;
            movelist[k][l+1]=j;
            k++;
        }
        cout<<" Mesaj\n";
    }
    return movelist;
}

void ExplorerOne::Move(int i,int j)
{
    ExplorerOne Ex1;
    h.Modify(i+Ex1.linpos,j+Ex1.linpos);
}

void ExplorerOne::MoveDecider(Harta &h)
{
    int l,m;
    int** movelist=new int*[9];

    for (int i=0;i<1;i++)
    {
        movelist[i]=new int[i];
    }

    ExplorerOne Ex1;
    movelist=Ex1.movecheck();

    if (movelist[0][0]==2)
    {
        cout<<"/nExplorerOne a ramas blocat!";
        throw;
    }

    for (int k=0;k<3;k++)
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
            cout<<"Mesaj";
            if (movelist[i][0]==l & movelist[i][1]==m)
            {
                cout<<"Mesaj";
                h.Modify(l,m);
                Ex1.linpos=Ex1.linpos+l;
                Ex1.colpos=Ex1.colpos+m;
                throw;

            }
        }

    }

}

ExplorerOne::~ExplorerOne()
{

}
