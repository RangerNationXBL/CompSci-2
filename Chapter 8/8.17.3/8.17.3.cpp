#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int bit_counts[8];
    for (int i = 0; i < 8; i++) { bit_counts[i] = 0; }

    fstream infile;
    string filename;
    cin >> filename;


    infile.open(filename, ios::binary | ios::in);

    
    if (!infile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    unsigned char byte; 

   
    while (infile.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {

        for (int i = 0; i < 8; i++) {
          
            if (byte & 1) {
            
                bit_counts[i]++;
            }
     
            byte = byte >> 1;
        }
    }

    infile.close();

    // Print the count of set bits for each position
    for (int i = 0; i < 8; i++) {
        cout << i << ": " << bit_counts[i] << endl;
    }

    return 0;
}
