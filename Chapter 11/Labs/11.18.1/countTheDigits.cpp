#include <iostream>
using namespace std;

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int n){
    if(n < 10)
        return 1;
    else
        return 1 + DigitCount(n / 10);
}

int main() {
    int num;
    int digits;

    cin >> num;
    digits = DigitCount(num);
    cout << digits << endl;
    return 0;
}
