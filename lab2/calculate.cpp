#include "calculate.h"
#include<cmath>

Rating::Rating(){}
Rating::Rating(int ra, int rb, int k) : RA(ra), RB(rb), K(k){}

int Rating::getRA() { return RA; }
int Rating::getRB() { return RB; }
int Rating::getK() { return K; }

void Rating::setRnK(int ra, int rb, int k)
{
    RA = ra;
    RB = rb;
    K = k;
}

double Rating::getEA()
{
    return 1.0 / (1.0 + pow(10.0, (RB - RA) / 400.0));
}

double Rating::getEB()
{
    return 1.0 / (1.0 + pow(10.0, (RA - RB) / 400.0));
}

void Rating::calculateR(double scoreA)
{
    double EA, EB;
    EA = getEA();
    EB = getEB();
    RA = round(RA + K * (scoreA - EA));
    RB = round(RB + K * ((1 - scoreA) - EB));
}