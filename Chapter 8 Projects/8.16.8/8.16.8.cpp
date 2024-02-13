#include <iostream>
#include <fstream>
#include <map>
#include <cctype> // For tolower function
#include <iomanip> 

using namespace std;

int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    map<char, int> letterCount;
    char ch;

    // Initialize the map for all alphabet letters with 0
    for(char c = 'a'; c <= 'z'; ++c) {
        letterCount[c] = 0;
    }

    // Count the frequency of each letter in the file
    while (inputFile >> noskipws >> ch) {
        if (isalpha(ch)) {
            ch = tolower(ch); // Convert to lowercase
            letterCount[ch]++;
        }
    }

    inputFile.close();

    int totalLetters = 0;
    for (const auto &pair : letterCount) {
        totalLetters += pair.second;
    }

    // New output here.

    cout << "+-------+--------------+-------+--------------+-------+--------------+-------+--------------+" << endl;
    cout << fixed << setprecision(2);
    
    int columnCounter = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        double frequency = 100.0 * letterCount[c] / totalLetters;
        cout << "|   " << setw(2) << c << "  |    " << setw(6) << frequency << "%   ";
        columnCounter++;
        if (columnCounter == 4) {
            cout << "|" << endl;
            cout << "+-------+--------------+-------+--------------+-------+--------------+-------+--------------+" << endl;
            columnCounter = 0;
        }
    }
    /* If there are less than four, fill with space? */
    if (columnCounter != 0) {
        for (int i = columnCounter; i < 4; ++i) {
            cout << "|       |              |";
        }
        cout << "|" << endl;
        cout << "+-------+--------------+-------+--------------+-------+--------------+-------+--------------+" << endl;
    }

    /* Commented the old output*/

/*     cout << "Letter Frequencies:" << endl;
    cout << "A\tB\tC\tD\tE\tF\tG\tH\tI\tJ\tK\tL\tM\tN\tO\tP\tQ\tR\tS\tT\tU\tV\tW\tX\tY\tZ" << endl;

    for (const auto &pair : letterCount) {
        double frequency = 100.0 * pair.second / totalLetters;
        cout << fixed << setprecision(2) << frequency << "%\t";
    } */

    cout << endl;

    return 0;
}

