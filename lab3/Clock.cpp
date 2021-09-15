#include "Clock.h"

Clock::Clock(){
    setstart(0);
}
Clock::Clock(clock_t s){
    setstart(s);
}

void Clock::start(){
    setstart(clock());
}

void Clock::setstart(clock_t ts){
    start_ts = (ts > 0)? ts : clock();
}

clock_t Clock::getstart(){
    return start_ts;
}

double Clock::getElapsedTime(){
    return static_cast<double>(clock() - getstart()) / CLOCKS_PER_SEC;
}
