#include <iostream>
#ifndef VIRTUALEXPLORER_H
#define VIRTUALEXPLORER_H

using namespace std;

class VirtualExplorer
{

    public:
        VirtualExplorer();
        virtual int movecheck()=0;
        virtual void Move(int,int)=0;
        virtual ~VirtualExplorer()=0;
};

#endif // VIRTUALEXPLORER_H
