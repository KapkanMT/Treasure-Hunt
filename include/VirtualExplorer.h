#include <iostream>
#ifndef VIRTUALEXPLORER_H
#define VIRTUALEXPLORER_H
#include "Harta.h"

using namespace std;


class VirtualExplorer
{
    public:
        virtual int getlinpos()=0;
        virtual int getcolpos()=0;
        virtual void modifylinpos(int)=0;
        virtual void modifycolpos(int)=0;
        virtual int** movecheck(Harta)=0;
        virtual void Move(int,int,Harta)=0;
        virtual void MoveDecider(Harta&)=0;

};

#endif // VIRTUALEXPLORER_H
