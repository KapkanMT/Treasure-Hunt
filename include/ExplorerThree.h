#ifndef EXPLORERTHREE_H
#define EXPLORERTHREE_H
#include "VirtualExplorer.h"
#include "Harta.h"

class ExplorerThree : public VirtualExplorer
{
    int linpos;
    int colpos;
    int freeze;

    public:
        friend class Harta;
        ExplorerThree();
        int getlinpos();
        int getcolpos();
        void modifylinpos(int);
        void modifycolpos(int);
        int** movecheck(Harta);
        void MoveDecider(Harta&);
        void Move(int,int,Harta);
        virtual ~ExplorerThree();
};

#endif // EXPLORERTHREE_H
