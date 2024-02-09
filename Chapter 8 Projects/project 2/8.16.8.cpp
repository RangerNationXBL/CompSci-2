#include <iostream>
#include <fstream>
#include <unordered_map>

struct {
    int totalChars;
    std::string fileName;
} Chars;

void displayFreqs(const std::unordered_map<char, int>& freqs) {
    
    std::cout << std::left << std::setw(4) << "Letter" << std::setw(6)
    << "count" << std::setw(8) << "Frequency" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << std::endl;

    for(const auto& pair : freqs){
        char letter = pair.first;
        int count = pair.second;
        float freq = static_cast<float>(count) / Chars.totalChars * 100.0f;

        std::cout << std::left << std::setw(4) << letter << std::setw(6)
        << count << std::setw(8) << std::fixed << std::setprecision(2) 
        << freq << "%" << std::endl;
    }
}

int main(){
    std::string fileName = "encrypted.txt";
    std::ifstream in(fileName);

    if(!in.is_open()){
        std::cerr << "Could not open file: " << fileName << std::endl;
        return 1;
    }

    std::unordered_map<char, int> freqs;

    Chars.totalChars = 0;

    char ch;
    while(in.get(ch)){
        Chars.totalChars++;

        if(std::isalpha(ch)){
            ch = std::toupper(ch);
            freqs[ch]++;
        }
    }

    in.close();
    displayFreqs(freqs);

    return 0;
}