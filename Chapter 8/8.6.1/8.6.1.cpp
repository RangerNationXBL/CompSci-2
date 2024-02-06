/*
When reading data from a text file, it is common to see numbers such as 12,345, $20, or 195*.

Write a function that cleans a string containing digits by removing any characters that are not 
a digit or a - sign. Then convert to an integer and return the result.

*/

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

/**
   Cleans a string containing an integer and converts it.
   @param number a string containing an integer and possibly extraneous 
      characters
   @return the value of the number inside the string
*/
int clean(string number)
{
    int output = 0;
    bool isNegative = false;
    for (int i = 0; i < number.length(); i++){
        if(number[i] == '-' && i == 0){
            isNegative = true;
        }
        else if (isdigit(number[i])){
            output = (output * 10)+ (int)(number[i] -'0');
        }
    }
        return isNegative? -output : output;
}

int main()
{
   string str;
   cin >> str;
   
   cout << clean(str);  
 
   return 0;  
}