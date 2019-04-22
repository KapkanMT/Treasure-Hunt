#ifndef HARTA_H
#define HARTA_H
#include <iostream>

using namespace std;

class Harta
{
    int **harta;

    public:
        Harta();
        virtual ~Harta();
        friend ostream & operator << (ostream &out,const Harta &h);
        int** getHarta();

};

#endif // HARTA_H
