#ifndef MINO_Z_H
#define MINO_Z_H

#include <iostream>
#include "Mino.h"
using namespace std;

class MinoZ: public Mino
{
    public:
        MinoZ();
        virtual void paint();
};

#endif