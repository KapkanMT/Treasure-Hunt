#ifndef EXPLORERFOUR_H
#define EXPLORERFOUR_H
#include "VirtualExplorer.h"
#include "Harta.h"

class ExplorerFour : public VirtualExplorer
{

    int linpos;
    int colpos;
    int freeze;

    public:
        friend class Harta;
        ExplorerFour();
        int getlinpos();
        int getcolpos();
        void modifylinpos(int);
        void modifycolpos(int);
        int** movecheck(Harta);
        void MoveDecider(Harta&);
        void Move(int,int,Harta);
        virtual ~ExplorerFour();
};

#endif // EXPLORERFOUR_H
