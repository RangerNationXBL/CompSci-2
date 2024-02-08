/*
Given a set of text files containing synonyms for different words, complete the program to output the synonyms 
for a specific word. Each text file contains synonyms for the word specified in the file’s name, and each row 
within the file lists the word’s synonyms that begin with the same letter, separated by a space.

The program should read a word and a letter from the user and open the text file associated with the input word. 
The program then should output all the synonyms that begin with the input letter, one synonym per line. If no synonyms 
that begin with the input letter are found, the program should output a message indicating so.

Ex: If the input of the program is:

educate c
the program opens the file educate.txt, which contains:

brainwash brief
civilize coach cultivate
develop discipline drill
edify enlighten exercise explain
foster
improve indoctrinate inform instruct
mature
nurture
rear
school
train tutor
then the program outputs:

civilize
coach
cultivate
Ex: If the input of the program is:

educate a
then the program outputs:

No synonyms for educate begin with a.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    string word, letter;
    iss >> word >> letter;

    ifstream in(word + ".txt");

    string line;
    bool found = false;

    while(getline(in, line)) {
        istringstream lineStream(line);
        string firstWord;
        lineStream >> firstWord;

        if(firstWord[0] == letter[0]) {
            found = true;
            cout << firstWord << endl;
            string synonym;
            
            while(lineStream >> synonym) {
                cout << synonym << endl;
            }
        }
    }
    in.close();

    if(!found) {
        cout << "No synonyms for " << word << " begin with " << letter << "." << endl;
    }

   return 0;
}
