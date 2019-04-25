#include <iostream>
#ifndef VIRTUALEXPLORER_H
#define VIRTUALEXPLORER_H
#include "Harta.h"

using namespace std;
//Explorer1:dreapta,jos,stanga,sus
//Explorer2:random,are sansa sa nu se miste
//Explorer3:diagonal,daca nu in alta directie
//Explorer4:fie diagonal,fie pe o linie/coloana

class VirtualExplorer
{
    public:
        virtual int getlinpos()=0;//ia linia
        virtual int getcolpos()=0;//ia coloana
        virtual void modifylinpos(int)=0;//modifica linia
        virtual void modifycolpos(int)=0;//modifica coloana
        virtual int** movecheck(Harta)=0;//se uita in jur si cauta o pozitie vacanta
        virtual void Move(int,int,Harta)=0;//misca exploratorul
        virtual void MoveDecider(Harta&)=0;//decide unde se misca,depinde de explorator

};

#endif // VIRTUALEXPLORER_H
