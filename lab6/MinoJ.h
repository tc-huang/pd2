#ifndef MINO_J_H
#define MINO_J_H
#include <iostream>
#include "Mino.h"
using namespace std;

class MinoJ: public Mino
{
    public:
        MinoJ();
        virtual void paint();
};

#endif