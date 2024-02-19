#include <iostream>
using namespace std;

#include "ball.h"

int main()
{
   Ball ball1(6, 4);
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 0 0\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 1 1\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 2 2\n" << endl;
   ball1.move();
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 4 4\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 5 3\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 6 2\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 5 1\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 4 0\n" << endl;
   ball1.move();
   cout << ball1.get_x() << " " << ball1.get_y() << endl;
   cout << "Expected: 3 1\n" << endl;

   Ball ball2(10, 10);
   for (int i = 1; i <= 12; i++) { ball2.move(); }
   cout << ball2.get_x() << " " << ball2.get_y() << endl;
   cout << "Expected: 8 8" << endl;
   
   return 0;
}