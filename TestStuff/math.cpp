#include <iostream>
using namespace std;

int main(){
    char ch;
    double price;
    if (cin >> price){

    }else{
        cin.unget();
    }
    cout << price;
    return 0;
}