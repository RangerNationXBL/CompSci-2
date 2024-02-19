#include <iostream>
using namespace std;

#include "van.h"
void print(vector<string> v);

int main()
{
   Van van1(8);
   van1.board("Fred");
   van1.board("Ann");
   van1.board("Lee");
   print(van1.get_passengers());
   cout << "Expected: [Fred, Ann, Lee]\n" << endl;
   van1.board("Tim");
   van1.board("Joe");
   van1.board("Pat");
   van1.board("May");
   van1.board("Sue");
   van1.board("Sally");
   print(van1.get_passengers());
   cout << "Expected: [Fred, Ann, Lee, Tim, Joe, Pat, May, Sue]\n" << endl;
   van1.drive(10);
   print(van1.get_passengers());
   cout << "Expected: []" << endl;
   cout << van1.get_miles_driven() << endl;
   cout << "Expected: 10" << endl;
   van1.board("Sally");
   print(van1.get_passengers());
   cout << "Expected: [Sally]\n" << endl;
   van1.drive(12);
   print(van1.get_passengers());
   cout << "Expected: []" << endl;
   cout << van1.get_miles_driven() << endl;
   cout << "Expected: 22" << endl;
   
   return 0;
}

void print(vector<string> v)
{
   cout << "[";
   if (v.size() > 0)
   {
      cout << v[0];
      for (int i = 1; i < v.size(); i++)
         { cout << ", " << v[i]; }
   }
   cout << "]" << endl;
}