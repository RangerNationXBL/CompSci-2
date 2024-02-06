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

/**
 * @brief Main function is the entry point for the program.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
*/
int main(int argc, char *argv[]){
    // Checking to see how many arguments were passed in. for this one we will need 5 at least.
    // Depends if I want to include additional functionalities in the future.

    if(argc < 5){
        std::cerr << "Usage:./crypt (-e|-d) -k <key> <input_file> <output_file>" << std::endl;
        return 1;
    }

    // Set the varables. I know what I need to get from the command line. That was provided.
    std::string operation = argv[1]; // -e or -d
    std::string key = ""; // I will set this with a for loop later.
    std::string input_file = ""; // Input file name.
    std::string output_file = ""; // Output file name.

    for(int i = 2; i < argc; i++){  // Starting at 2 because I check 1 in variables.
        std::string arg = argv[i]; // Setting a variable for each condition.
        if(arg.substr(0, 2) == "-k"){
            key = arg.substr(2); // Reading 3 characters from the argument. -k = 0 and 1.
            }else if (arg == "-e" || arg == "-d"){ // Checking to see what the operation is.
            // Nothing to be done here, its already set.
            }else if (input_file == ""){ // Checking to see if the input file is set.
            input_file = arg;
            }else{
                output_file = arg;
            }
    }

    // Error Checking.
    if(operation!= "-e" && operation!= "-d"){
        std::cerr << "Operation must be -e or -d" << std::endl;
        return 1;
    }
    if(key.empty()){
        std::cerr << "Key cannot be empty" << std::endl;
        return 1;
    }
    if(input_file.empty() || output_file.empty()){
        std::cerr << "Input and output files cannot be empty" << std::endl;
        return 1;
    }

    bool decrypt = operation == "-d";
    // Function to encrypt or decrypt a message. Not implemented yet.

    std::cout << "Operation has completed successfully" << std::endl;

    return 0;
}