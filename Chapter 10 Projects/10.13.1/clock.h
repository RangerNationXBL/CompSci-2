#ifndef CLOCK_H
#define CLOCK_H

#include <string>
using namespace std;

class Clock{

private:
    int alarm_hour;
    int alarm_minute;
    bool alarm_set;

public:
    Clock();
    virtual ~Clock();
    int get_hours() const;
    int get_minutes() const;
    string get_time();
    void set_alarm(int hours, int minutes);
};

#endif //  CLOCK_H