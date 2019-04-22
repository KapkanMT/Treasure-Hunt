#ifndef HARTA_H
#define HARTA_H
#include <iostream>

using namespace std;

class Harta
{
    int **harta;

    public:
        friend class ExplorerOne;
        Harta();
        virtual ~Harta();
        friend ostream & operator << (ostream &out,const Harta &h);
        void Modify(int,int);
        int** getHarta();

};

#endif // HARTA_H
