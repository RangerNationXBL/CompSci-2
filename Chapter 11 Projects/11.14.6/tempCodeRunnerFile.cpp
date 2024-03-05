cout << "Enter a string: ";
    string input;
    getline(cin, input);
    cout << input << " is ";
    if (!is_palindrome(input)) { cout << "not "; }
    cout << "a palindrome." << endl;
    return 0;