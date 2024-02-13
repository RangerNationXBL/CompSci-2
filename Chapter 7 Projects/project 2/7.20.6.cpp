#include <iostream>
using namespace std;

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

    // Print the lines in reverse order
    for (int i = numberOfLines - 1; i >= 0; --i) {
        // Using cout to print strings terminated by '\0'
        cout << arrayOfLines[i] << endl;
    }

    return 0;
}