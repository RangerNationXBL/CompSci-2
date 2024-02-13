#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool compareStrings(const char* a, const char* b){
    return strcmp(a, b) < 0;
}

int main() {
    char bigArray[1000]; 
    char* arrayOfLines[100]; 
    int numberOfLines = 0; 
    int totalChars = 0; 
    char inputChar; 

    // Keep reading characters until bigArray is full or we have 100 lines
    while (totalChars < 999 && numberOfLines < 100) {
        cin.get(inputChar);

        // If we reach the end of the file/input, stop reading
        if (cin.eof()) {
            bigArray[totalChars] = '\0'; 
            break;
        }

        // Handle newline character by terminating the current line
        if (inputChar == '\n') {
            bigArray[totalChars] = '\0';
        } else {
            bigArray[totalChars] = inputChar;
        }

        // If it's the start of a new line or the very first character, save its position
        if (totalChars == 0 || bigArray[totalChars - 1] == '\0') {
            arrayOfLines[numberOfLines++] = &bigArray[totalChars];
        }

        totalChars++;

        // If we've reached the buffer's end, ensure the last character is '\0'
        if (totalChars == 999) {
            bigArray[totalChars] = '\0';
            // Break if EOF is exactly at 999 characters, to avoid skipping the termination
            if (cin.eof()) break;
        }
    }

    cout << "Lines in the order they were entered: " << endl;
    for(int i = 0; i < numberOfLines; i++) {
        cout << arrayOfLines[i] << endl;
    }


    sort(arrayOfLines, arrayOfLines + numberOfLines, compareStrings);

    cout << "\nLines in sorted order: " << endl;
    for(int i = 0; i < numberOfLines; i++) {
        cout << arrayOfLines[i] << endl;
    }

    cout << "\nLines in reverse order: " << endl;
    for (int i = numberOfLines - 1; i >= 0; --i) {
        cout << arrayOfLines[i] << endl;
    }

    return 0;
}
