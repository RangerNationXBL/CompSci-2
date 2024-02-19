#include "van.h"

Van::Van(int max_passengers) : miles_driven(0), capacity(max_passengers) {}

void Van::board(string name){
    if(passengers.size() < capacity){
        passengers.push_back(name);
    }
}

void Van::drive(double distance){
    miles_driven += distance;
    passengers.clear();
}

vector<string> Van::get_passengers() const{
    return passengers;
}

double Van::get_miles_driven() const{
    return miles_driven;
}

