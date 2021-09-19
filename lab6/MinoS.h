#ifndef MINO_S_H
#define MINO_S_H

#include <iostream>
#include "Mino.h"
using namespace std;

class MinoS:public Mino
{
    public:
        MinoS();
        virtual void paint();
};
#endif