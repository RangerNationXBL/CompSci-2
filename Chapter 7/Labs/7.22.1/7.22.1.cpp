#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int numWords;
    cin >> numWords;

    vector<string> words(numWords);
    vector<int> freqs(numWords, 0);

    for(int i = 0; i < numWords; ++i) {
        cin >> words[i];
    }

    for(int i = 0; i < numWords; ++i) {
        int count = 0; // Initialize count for each word
        for(int j = 0; j < numWords; ++j) {
            if(words[i] == words[j]) {
                ++count;
            }
        }
        cout << words[i] << " - " << count << endl;
    }

    return 0;
}
