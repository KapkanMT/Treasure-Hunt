#ifndef HARTA_H
#define HARTA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Harta
{
    int **harta;
    int *statusHolder;

    public:
        friend class ExplorerOne;
        friend class ExplorerTwo;
        friend class ExplorerThree;
        friend class ExplorerFour;
        Harta();
        virtual ~Harta();
        friend ostream & operator << (ostream &out,const Harta &h);
        int* & operator[](const int);
        void Modify(int,int);
        int* getStatusHolder();
        void setStatusHolder(int*);
        void ModifyE1(int,int);
        void ModifyE2(int,int);
        void ModifyE3(int,int);
        void ModifyE4(int,int);
        int Randomgenspecial();
        void treasureGenerator(int&,int&);
        void statusModifier(int*,int,int);

};

#endif // HARTA_H
