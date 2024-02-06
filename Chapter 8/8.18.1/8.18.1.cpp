#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string input_file_name;
    cout << "Input file: " << endl;
    cin >> input_file_name;
    ifstream infile(input_file_name.c_str());
    if(!infile.is_open()){
        exit(1);
    }
    ofstream outfile("sentences.txt");
    string word;
    string testChar;
    while(infile >> word){
        if(word.length() >= 2){
            testChar = word.substr(word.length() - 2);
        }
        cout << word << testChar << endl;
        outfile << word;
        if(word.back() == ',' && infile.peek() == '\"'){
            outfile << " ";
        }else if(word.back() == '.' || word.back() == '!' || word.back() == '?'){
            outfile << endl;
        }else if(word.back() == '\"'){
            if(word.length() >= 2 && word.substr(word.length() -2) == ",\""){
                outfile << " ";
            }else{
                outfile << endl;
            }
        }else{
            outfile << " ";
        }
    }

    infile.close();
    outfile.close();
   return 0;
}