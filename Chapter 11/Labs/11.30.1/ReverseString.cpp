#include <iostream>
using namespace std;

string ReverseString(string str){
    if(str.length() <= 1){
        return str;
    }else{
        return ReverseString(str.substr(1)) + str[0];
    }
}
   
int main() {
   string input, result;
   
   getline(cin, input);
   result = ReverseString(input);
   cout << "Reverse of \"" << input << "\" is \"" << result << "\"." << endl;
   
   return 0;
}
