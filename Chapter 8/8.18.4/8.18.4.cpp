#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream in_file;
   ofstream out_file; // It was the wrong Stream.

   in_file.open("input.txt");
   int total = 0;
   int n;
   while (in_file >> n) { total = total + n; }

   out_file.open("output.txt");
   out_file << "Total: " << total << endl;

   return 0;
}