#include <iostream>
using namespace std;

#include "van.h"

int main()
{
   Van van1(8);
   van1.board(3);
   cout << van1.get_passengers() << endl;
   cout << "Expected: 3\n" << endl;
   van1.board(6);
   cout << van1.get_passengers() << endl;
   cout << "Expected: 8\n" << endl;
   van1.drive(10);
   cout << van1.get_passengers() << endl;
   cout << "Expected: 0\n" << endl;
   cout << van1.get_miles_driven() << endl;
   cout << "Expected: 10\n" << endl;
   van1.board(6);
   cout << van1.get_passengers() << endl;
   cout << "Expected: 6\n" << endl;
   van1.drive(12);
   cout << van1.get_passengers() << endl;
   cout << "Expected: 0\n" << endl;
   cout << van1.get_miles_driven() << endl;
   cout << "Expected: 22" << endl;
   
   return 0;
}