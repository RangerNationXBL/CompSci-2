/*
Read student data in the form

Jane Lee 
100 98 97 100
Aaron X. Schmidt 
37 42 49 54
Frank von Tardy 
2 3 10 7
...
Use getline to read the name of the student. Then read the next line and convert it to an input string stream. 
Read the numbers from the input stream, adding them to the total.

Print the name and total score for each student.
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
   cout << "Input file: " << endl;
   string input_file_name;
   cin >> input_file_name;
   // Nothing can change above this line.

    ifstream in(input_file_name.c_str());
    if (!in){return 1;}

   // nothing can change below this line.
   string student;
   while (getline(in, student))
   {
    // nothing can change above this line

    string line;
    getline(in, line);
    istringstream iss(line);
    int score, total = 0;
    while(iss >> score){
        total += score;
    }

    // nothing can change below this line.

      cout << student << ": " << total << endl;
   }
   
   return 0;
}