#include <iostream>
#include "Harta.h"
#include "ExplorerOne.h"

using namespace std;

int main()
{
    Harta h;
    ExplorerOne Ex1;
    VirtualExplorer *Explorer1=&Ex1;
    for(int i=1;i<=15;i++)
    {
        Explorer1->MoveDecider();
        cout<<"Mesaj";
    }
    cout<<h;

    return 0;
}
