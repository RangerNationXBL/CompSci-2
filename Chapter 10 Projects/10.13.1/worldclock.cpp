#include "worldclock.h"

WorldClock::WorldClock(int offset_hours) : offset(offset_hours) {}

int WorldClock::get_hours() const {
    int hours = Clock::get_hours() + offset;
    if(hours >= 24){
        hours -= 24;
    }
    return hours;
}