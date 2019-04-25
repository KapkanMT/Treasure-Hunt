#include <iostream>
#include "Harta.h"
#include "ExplorerOne.h"
#include "ExplorerTwo.h"
#include "ExplorerThree.h"
#include "ExplorerFour.h"


using namespace std;

int main()
{
    srand (time(NULL));
    int i,x1,x2,x3,x4,c=0;
    Harta h;
    cout<<h;
    ExplorerOne Ex1;
    ExplorerTwo Ex2;
    ExplorerThree Ex3;
    ExplorerFour Ex4;
    cout<<"\n"<<"Pentru a face procesu pas cu pas,scrieti un int"<<"\n";
    cout<<"Altfel,scrieti orice.";
    while (c<3)
    {
        cin>>i;
        cout<<"\n";
        Ex1.MoveDecider(h);
        Ex2.MoveDecider(h);
        Ex3.MoveDecider(h);
        Ex4.MoveDecider(h);
        cout<<"\n";
        cout<<"Explorer1=6:"<<Ex1.getlinpos()<<" "<<Ex1.getcolpos()<<"\n";
        cout<<"Explorer2=7:"<<Ex2.getlinpos()<<" "<<Ex2.getcolpos()<<"\n";
        cout<<"Explorer3=8:"<<Ex3.getlinpos()<<" "<<Ex3.getcolpos()<<"\n";
        cout<<"Explorer4=9:"<<Ex3.getlinpos()<<" "<<Ex4.getcolpos()<<"\n";
        cout<<h;
        if (h.getStatusHolder()[0]!=0 & x1==0)
        {
            x1==1;
            c++;
        }
        if (h.getStatusHolder()[1]!=0 & x2==0)
        {
            x2==1;
            c++;
        }
        if (h.getStatusHolder()[2]!=0 & x3==0)
        {
            x3==1;
            c++;
        }
        if (h.getStatusHolder()[3]!=0 & x4==0)
        {
            x4==1;
            c++;
        }

    }
    return 0;
}
