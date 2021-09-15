#ifndef CLOCK_H
#define CLOCK_H
#include <ctime>
using namespace std;

class Clock{
public:
    Clock();
    Clock(clock_t s);

    void start();
    void setstart(clock_t start_ts);

    clock_t getstart();
    double getElapsedTime();
    
private:
    clock_t start_ts;
};

#endif // CLOCK_H
