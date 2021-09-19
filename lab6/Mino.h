#ifndef MINO_H
#define MINO_H

#include<iostream>
using namespace std;

class Mino
{
    public:
        Mino(int mri = 1);
        Mino& turn();
        virtual void paint() = 0;
    
    protected:
        int rotate_index, max_ri;
};

#endif  //  MINO_H