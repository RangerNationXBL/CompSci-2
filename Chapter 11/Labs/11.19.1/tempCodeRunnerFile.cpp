#include <iostream>

using namespace std;

// TODO: Write recursive PrintNumPattern() function
void PrintNumPattern(int num1, int num2){
    if(num1 < 0){
        cout << num1 << " ";
        return;
    }
    cout << num1 << " ";
    PrintNumPattern(num1 - num2, num2);

    if(num1 != 0){
        cout << num1 << " ";
        PrintNumPattern(num1 + num2, num2);
    }
}

int main() {
    int num1;
    int num2;

    cin >> num1;
    cin >> num2;
    PrintNumPattern(num1, num2);

    return 0;
}