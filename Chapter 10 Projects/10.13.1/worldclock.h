#ifndef WORLDCLOCK_H
#define WORLDCLOCK_H

#include "clock.h"

class WorldClock : public Clock {
private:
    int offset;

public:
    WorldClock(int offset_hours);
    int get_hours() const;
};

#endif //  WORLDCLOCK_H


