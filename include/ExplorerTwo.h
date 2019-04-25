#ifndef EXPLORERTWO_H
#define EXPLORERTWO_H
#include "VirtualExplorer.h"
#include "Harta.h"

class ExplorerTwo : public VirtualExplorer
{
    int linpos;
    int colpos;
    int freeze;

    public:
        friend class Harta;
        ExplorerTwo();
        int getlinpos();
        int getcolpos();
        void modifylinpos(int);
        void modifycolpos(int);
        int** movecheck(Harta);
        void MoveDecider(Harta&);
        void Move(int,int,Harta);
        virtual ~ExplorerTwo();
};

#endif // EXPLORERTWO_H
