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
        friend ostream & operator << (ostream &out,const Harta &h);//scrie harta
        int* & operator[](const int);//returneaza harta[i][j]
        void Modify(int,int);//modifica pozitia e care a fost un explorator cu 1
        int* getStatusHolder();//returneaza statusHolder
        void setStatusHolder(int*);//seteaza statusHolder
        void ModifyE1(int,int);//muta Explorator1 vizual
        void ModifyE2(int,int);//muta Explorator2 vizual
        void ModifyE3(int,int);//muta Explorator3 vizual
        void ModifyE4(int,int);//muta Explorator4 vizual
        int Randomgenspecial();//randomnr cu niste exceptii
        void treasureGenerator(int&,int&);//generaza comorile
        void statusModifier(int*,int,int);//modifca statusHolder

};

#endif // HARTA_H
