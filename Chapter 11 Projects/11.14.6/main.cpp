// =================================================================
// NAME: Chris Brown
// FILE: main.cpp
// PROFESSOR: Dr. Kocher
// DATE: 03-04-2024
// =================================================================
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
    Tests whether a string is a palindrome. A palindrome
    is equal to its reverse, for example "rotor" or "racecar".
    @param s a string
    @return true if s is a palindrome
*/
bool is_palindrome(const string& s, int start, int end)
{
    // Separate case for shortest strings
    if (start >= end) { return true; }

    // Get first and last character, converted to lowercase 
    char first = tolower(s[start]);
    char last = tolower(s[end]);

    if (!isalpha(first)) {
        return is_palindrome(s, start + 1, end); // Skip non-letter characters
    } else if (!isalpha(last)) {
        return is_palindrome(s, start, end - 1); // Skip non-letter characters
    }

    if (first == last) {
        return is_palindrome(s, start + 1, end - 1); // Move both pointers inward
    } else {
        return false; // Characters don't match, not a palindrome
    }
}

bool is_palindrome(const string& s)
{
    return is_palindrome(s, 0, s.length() - 1);
}

int main()
{
    //First try your own, then the test will run.
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
    cout << input << " is ";
    if (!is_palindrome(input)) { cout << "not "; }
    cout << "a palindrome." << endl;

    vector<string> palindromes;
    
        // Palindromes to test as true
        palindromes.push_back("radar");
        palindromes.push_back("level");
        palindromes.push_back("madam");
        palindromes.push_back("racecar");
        palindromes.push_back("deified");
        palindromes.push_back("A man, a plan, a canal, Panama!");
        palindromes.push_back("Was it a car or a cat I saw?");
        palindromes.push_back("Evil is a name of a foeman, as I live.");

        // Palindromes to test as false
        palindromes.push_back("The quick brown fox jumped over the lazy dog.");
        palindromes.push_back("Not what you think!");
        palindromes.push_back("Hello, can I have that?");
        palindromes.push_back("Orange is not the brightest color.");
        palindromes.push_back("if only I had known.");

    for(const string& p : palindromes){
        cout << "Testing Palindromes" << endl;
        string input = p;
        cout << input << " is ";
        if (!is_palindrome(input)) { cout << "not "; }
        cout << "a palindrome." << endl;
        cout << endl;
    }
}
