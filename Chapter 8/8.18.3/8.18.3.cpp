/*
This program is supposed to read from an input file and compute the total of 
the numbers it contains. However, it doesn't even compile. Fix it so that it works correctly.
*/

#include <iostream>
#include <fstream>
using namespace std;

double sum(ifstream& in)   /* Fix this code line */
{
   double total = 0;
   double input;
   while (in >> input) { total = total + input; }
   return total;
}

int main()
{
   string filename;
   cin >> filename;
   ifstream in(filename);
   cout << sum(in) << endl;

   return 0;
}