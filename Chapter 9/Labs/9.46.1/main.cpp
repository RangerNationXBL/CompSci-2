#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
   Triangle triangle1;
   Triangle triangle2;

   // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())

   double base1, height1;
   cin >> base1 >> height1;
   triangle1.SetBase(base1);
   triangle1.SetHeight(height1);
      
   // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())

   double base2, height2;
   cin >> base2 >> height2;
   triangle2.SetBase(base2);
   triangle2.SetHeight(height2);

   cout << "Triangle with smaller area:" << endl;

   // TODO: Determine smaller triangle (use GetArea())
   //       and output smaller triangle's info (use PrintInfo())

   double area1 = triangle1.GetArea();
   double area2 = triangle2.GetArea();
   if(area1 < area2){
    triangle1.PrintInfo();
   }else if(area2 > area1){
    triangle2.PrintInfo();
   }else{
   triangle2.PrintInfo();
   }
    
   return 0;
}