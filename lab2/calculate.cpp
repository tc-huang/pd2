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
    return pow((1 + pow(10, (RB - RA) / 400)), -1);
}

double Rating::getEB()
{
    return pow((1 + pow(10, (RA - RB) / 400)), -1);
}

void Rating::calculateR(double scoreA)
{
    double EA, EB;
    EA = getEA();
    EB = getEB();

    RA = round(RA + K * (scoreA - EA));
    RB = round(RB + K * ((1 - scoreA) - EB));
}