/**
 * NAME: Chris Brown
 * DATE: 2/6/2024
 * FILE: crypt.cpp
 * DESCRIPTION:
 * This is a program that encrypts and decrypts a message from a file.
 * USAGE: ./crypt (-e|-d) -k <key> <input_file> <output_file>
 * ARGUMENTS: 
 * -e: Encrypts a message.
 * -d: Decrypts a message.
 * -k <key>: The key used to encrypt or decrypt the message.
 * input_file: The input file.
 * output_file: The output file.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Generate a cipher using the given key.
 * @param key The key used to generate the cipher.
 * @return The cipher generated using the given key.
 */
std::unordered_map<char, char> genCipher(const std::string& key) {
    std::unordered_map<char, char> cipher;

    std::string uniqueKey = "";
    /* Stripping the keyword of duplicate letters.*/
    for (char c : key) {
        if (std::find(uniqueKey.begin(), uniqueKey.end(), c) == uniqueKey.end()) {
            uniqueKey += c;
        }
    }

    /* Append the remaining alphabet letters in reverse order. */
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string reAlphabet = "";

    for (char c : alphabet) {
        if (uniqueKey.find(c) == std::string::npos) {
            reAlphabet += c;
        }
    }
    /* Reverse the order of the alphabet */
    std::reverse(reAlphabet.begin(), reAlphabet.end());

    for (size_t i = 0; i < uniqueKey.length(); i++) {
        cipher[alphabet[i]] = uniqueKey[i];
    }

    for (size_t i = 0; i < reAlphabet.length(); i++) {
        cipher[alphabet[i + uniqueKey.length()]] = reAlphabet[i];
    }
    return cipher;
}

/**
 * @brief Returns the first key in the map that matches the given value.
 * @param map The map to search.
 * @param value The value to match.
 * @return The first key in the map that matches the given value, or the given value if no match is found.
 */
char getKeys(const std::unordered_map<char, char>& map, char value) {
    for (const auto& pair : map) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return value;
}

/**
 * @brief Processes a file
 * @param inFile The input file
 * @param outFile The output file
 * @param key The key used for encryption/decryption
 * @param decrypt A boolean indicating whether to decrypt or encrypt
 */
void processFile(const std::string& inFile, const std::string& outFile, std::string key, bool decrypt) {
    // Get the streams
    std::ifstream in(inFile);
    std::ofstream out(outFile);

    // Check for fstream errors
    if (!in.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }
    if (!out.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    // Generate the cipher
    std::unordered_map<char, char> cipher = genCipher(key);

    // Read the input file character by character
    char ch;
    while (in.get(ch)) {
        if (std::isalpha(ch)) {
            // Transform the character based on whether we are decrypting or not
            char transformed = decrypt ? cipher[ch] : getKeys(cipher, ch);
            out << transformed;
        } else {
            out << ch;
        }
    }

    // Close the streams
    in.close();
    out.close();
}

/* Seriously.... My whole time spent placing cout to try and find the problem.. 
    It was a misplaced pointer. char *argv[] <<---- Error was there.
    */
/**
 * @brief Main function of the program.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of arguments passed to the program.
 * @return 0 on success, non-zero on failure.
 */
int main(int argc, char* argv[]) {
    // Checking to see how many arguments were passed in. for this one we will need 5 at least.
    // Depends if I want to include additional functionalities in the future.

    if (argc < 5) {
        std::cerr << "Usage: ./crypt (-e|-d) -k <key> <input_file> <output_file>" << std::endl;
        return 1;
    }

    // Set the varables. I know what I need to get from the command line. That was provided.
    std::string operation = argv[1];                ///< Operation to be performed. Either encryption or decryption.
    std::string key = "";                           ///< Key used for encryption/decryption.
    std::string input_file = "";                    ///< Input file name.
    std::string output_file = "";                   ///< Output file name.

    for (int i = 2; i < argc; i++) {                ///< Iterate through all arguments.
        std::string arg = argv[i];                  ///< Current argument.
        if (arg.substr(0, 2) == "-k") {             ///< Check if the argument is a key.
            key = arg.substr(2);                    ///< Extract the key from the argument.
        } else if (arg == "-e" || arg == "-d") {    ///< Check if the argument is an operation.
            operation = arg;                        ///< Set the operation.
        } else if (input_file == "") {              ///< Check if the input file is set.
            input_file = arg;
        } else {                                    ///< Check if the output file is set.
            output_file = arg;
        }
    }

    // Error Checking.
    if (operation != "-e" && operation != "-d") {
        std::cerr << "Operation must be -e or -d" << std::endl;
        return 1;
    }
    if (key.empty()) {
        std::cerr << "Key cannot be empty" << std::endl;
        return 1;
    }
    if (input_file.empty() || output_file.empty()) {
        std::cerr << "Input and output files cannot be empty" << std::endl;
        return 1;
    }

    bool decrypt = (operation == "-d");
    processFile(input_file, output_file, key, decrypt);

    std::cout << "Operation has completed successfully" << std::endl;
    std::cout << key << std::endl;

    return 0;
}