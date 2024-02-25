#include "clock.h"
#include "worldclock.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    Clock localClock;

    cout << "Local Time: " << localClock.get_time() << endl;
    WorldClock newYorkClock(3);

    cout  << "New York Time: " << newYorkClock.get_time() << endl;

    Clock clock;

    clock.set_alarm(8,38);
    while(true){
        string current_time = clock.get_time();
        cout << "Current time: " << current_time << endl;
        if(current_time.find("\u23F0") != string::npos){
            cout << "Alarm! It's time!" << endl;
            break;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}