#include "van.h"
#include <algorithm>

// Implement the member functions here
Van::Van(int max_passengers) : miles_driven(0), passengers(0), capacity(max_passengers){}

void Van::board(int boarding_passengers){
   int passengers_to_board = std::min(boarding_passengers, capacity - passengers);
   passengers += passengers_to_board;
}

void Van::drive(double distance){
   miles_driven += distance;
   passengers = 0;
}

int Van::get_passengers() const{
   return passengers;
}

double Van::get_miles_driven() const{
   return miles_driven;
}
