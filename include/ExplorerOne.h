#ifndef EXPLORERONE_H
#define EXPLORERONE_H
#include "VirtualExplorer.h"
#include "Harta.h"

class ExplorerOne : public VirtualExplorer
{

    int linpos;
    int colpos;
    int freeze;

    public:
        friend class Harta;
        ExplorerOne();
        int getlinpos();
        int getcolpos();
        void modifylinpos(int);
        void modifycolpos(int);
        int** movecheck(Harta);
        void MoveDecider(Harta&);
        void Move(int,int,Harta);
        virtual ~ExplorerOne();
};

#endif // EXPLORERONE_H
