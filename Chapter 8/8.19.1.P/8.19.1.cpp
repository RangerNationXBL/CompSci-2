/*
Write a program that reads a file one character at a time and prints out how many characters are 
uppercase letters, lowercase letters, digits, white space, and something else.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
   cout << "Input file: " << endl;
   string input_file_name;
   cin >> input_file_name;

   /* Your code goes here */
   ifstream in(input_file_name.c_str());
   if(!in){return 1;}

   int uppercase = 0;
   int lowercase = 0;
   int digits = 0;
   int whitespace = 0;
   int other = 0;
   char ch;

   while(in.get(ch)){
        if(isupper(ch)){uppercase++;}
        else if(islower(ch)){lowercase++;}
        else if(isdigit(ch)){digits++;}
        else if(isspace(ch)){whitespace++;}
        else{other++;}
   }

   cout << "Uppercase: " << uppercase << endl;
   cout << "Lowercase: " << lowercase << endl;
   cout << "Digits: " << digits << endl;
   cout << "Whitespace: " << whitespace << endl;
   cout << "Other: " << other << endl;
   
   return 0;
}