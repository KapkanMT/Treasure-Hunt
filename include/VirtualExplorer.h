#include <iostream>
#ifndef VIRTUALEXPLORER_H
#define VIRTUALEXPLORER_H

using namespace std;


class VirtualExplorer
{
    int linpos;
    int colpos;
    public:
        VirtualExplorer();
        virtual int** movecheck()=0;
        virtual void Move()=0;
        virtual void MoveDecider()=0;
        virtual ~VirtualExplorer()=0;
};

#endif // VIRTUALEXPLORER_H
