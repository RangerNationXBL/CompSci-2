#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, char> genCipher(const std::string& key){
    std::unordered_map<char, char> cipher;

    std::string uniqueKey = "";
    /* Stripping the keyword of duplicate letters.*/
    for(char c : key){
        if(std::find(uniqueKey.begin(), uniqueKey.end(), c) == uniqueKey.end()){
            uniqueKey += c;
        }
    }

    /* Append the remaining alphabet letters in reverse order. */
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string reAlphabet = "";

    std::cout << alphabet << std::endl;

    for(char c : alphabet){
        if(uniqueKey.find(c) == std::string::npos){
            reAlphabet += c;
        }
    }

    std::reverse(reAlphabet.begin(), reAlphabet.end());
    std::cout << reAlphabet << std::endl;
    return cipher;
}

int main(){
    std::unordered_map<char, char> cipher = genCipher("keyWord");
    for(const auto& pair : cipher){
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}