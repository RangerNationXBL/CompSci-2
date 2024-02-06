/*
Suppose we wish to read student data in the form

Jane Lee 100 98 97 100
Aaron X. Schmidt 37 42 49 54
Frank von Tardy 2 3 10 7
...
There is no need to use getline. Instead, use one while loop to process all of the lines in the file. 
Inside that loop, use two smaller loops: the first to read the name, and the second to add up the scores 
for that student. To read the name, use get to read until you encounter a digit, adding each character to 
the student’s name. To add the scores, write a second loop that processes the rest of the line. Use the 
one-character look-ahead technique from the section "Reading Text Input" to read and sum the numbers.

Print the name and total score for each student.
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   cout << "Input file: " << endl;
   string input_file_name;
   cin >> input_file_name;

   ifstream in;
   in.open(input_file_name);

   char ch;
   while (in.get(ch))
   {
      // Add the characters before the first digit
      // to the student's name.
      string student = "";
      while (in && !isdigit(ch))
      {
         student = student + ch;
         in.get(ch);
      }
      student = student.substr(0, student.length() - 1); // remove space at end

      int total = 0;

      // Add all of the numbers in the rest of the line.
      // Use the one-character look-ahead from the section "Reading Text Input"
      // Stop when the last character read is a '\n'

      /* Your code goes here */
    try
    {
        while(in && ch != '\n'){
            int score = 0;
            while(in && isdigit(ch)){
                score = score * 10 + (ch - '0');
                in.get(ch);
            }
            total = total + score;
            if(in && ch != '\n'){
            in.get(ch);
            }
        }
    
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
     cout << student << ": " << total << endl;
    }

   return 0;
}