#include <iostream>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int baseLength){
    if(baseLength <= 0){
        return;
    }
    DrawTriangle(baseLength - 2);
    for(int i = 0; i < 9 - (baseLength / 2); i++){
        cout << " ";
    }
    for(int i = 0; i < baseLength; i++){
        cout << "*";
    }
    cout << endl;

}

int main() {
   int baseLength;
   
   cin >> baseLength;
   DrawTriangle(baseLength);
   return 0;
}