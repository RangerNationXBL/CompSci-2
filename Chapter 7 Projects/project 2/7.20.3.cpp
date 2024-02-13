#include <iostream>
using namespace std;

int main() {
    const int M = 1000;
    const int N = 100;

    char buffer[M];
    char* lines[N];
    
    int charCount = 0;
    int lineCount = 0;
    char c;

    while (cin.get(c) && charCount < 1000) {
        if (c == '\n') {
            buffer[charCount] = '\0';
            lines[lineCount++] = &buffer[charCount+1]; 
            if (lineCount == 100) {
                break;
            }
        } else {
            buffer[charCount] = c;
        }
        charCount++;
    }
    buffer[charCount] = '\0';

    for (int i = lineCount - 1; i >= 0; --i) {
        cout << lines[i] << endl;
    }
    
    return 0;
}
