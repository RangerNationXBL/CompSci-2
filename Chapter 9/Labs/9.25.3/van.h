#ifndef VAN_H
#define VAN_H
/**
   This class models a shuttle van.
*/
class Van
{
public:
   /**
      Constructs a van with a given capacity.
      @param max_passengers the maximum number of passengers that this
      van can hold
   */
   Van(int max_passengers);

   /**
      Boards passengers up to the capacity of this van.
      @param boarding_passengers the number of passengers attempting
      to board
   */
   void board(int boarding_passengers);

   /**
      Drives the van and discharges the passengers.
      @param distance the distance driven
   */
   void drive(double distance);

   /**
      Gets the number of passengers in this van.
      @return the number of passengers
   */
   int get_passengers() const;

   /**
      Gets the number of miles that this van has driven.
      @return the number of miles
   */
   double get_miles_driven() const;

private:
   double miles_driven;
   int passengers;
   int capacity;
};

#endif