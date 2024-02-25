#include "clock.h"
#include <ctime>
#include <sstream>

using namespace std;

Clock::Clock() : alarm_hour(0), alarm_minute(0), alarm_set(false) {}
Clock::~Clock() {}

int Clock::get_hours() const {
    time_t current_time = time(0);
    tm* local_time = localtime(&current_time);
    return local_time->tm_hour;
}

int Clock::get_minutes() const {
    time_t current_time = time(0);
    tm* local_time = localtime(&current_time);
    return local_time->tm_min;
}

string Clock::get_time(){
    int hours = get_hours();
    int minutes = get_minutes();
    ostringstream oss;
    oss << hours << ":" << minutes;

    if(alarm_set && hours >= alarm_hour && minutes >= alarm_minute){
        oss << " \u23F0";
        alarm_set = false;
    }
    return oss.str();
}

void Clock::set_alarm(int hours, int minutes){
    alarm_hour = hours;
    alarm_minute = minutes;
    alarm_set = true;
}