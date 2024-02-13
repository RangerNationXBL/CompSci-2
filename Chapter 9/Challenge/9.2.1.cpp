/*
Implement a class Bug that models a bug climbing up a pole. Each time the up member function is called, 
the bug climbs 10 cm. Whenever it reaches the top of the pole (at 100 cm), it slides back to the bottom. 
Also implement a member function reset that starts the Bug at the bottom of the pole and a member function 
get_position that returns the current position.
*/

#include <iostream>
using namespace std;

class Bug
{
public:
   int get_position() const;
   void reset();
   void up();
private:
   int position = 0;
};

int Bug::get_position() const
{
   return position;
}

void Bug::reset()
{
   position = 0;
}

void Bug::up()
{
   position += 10;
   if(position == 100)
   {
    this->reset();
   }
}

int main()
{
   Bug bugsy;
   Bug itsy_bitsy;
   bugsy.reset();
   itsy_bitsy.reset();
   bugsy.up();
   bugsy.up();
   cout << bugsy.get_position() << endl;
   cout << "Expected: 20\n" << endl;
   itsy_bitsy.up();
   itsy_bitsy.up();
   itsy_bitsy.up();
   cout << itsy_bitsy.get_position() << endl;
   cout << "Expected: 30\n" << endl;
   for (int i = 1; i <= 8; i++) { bugsy.up(); }
   cout << bugsy.get_position() << endl;
   cout << "Expected: 0\n" << endl;
   bugsy.up();
   cout << bugsy.get_position() << endl;
   cout << "Expected: 10" << endl;
   
   return 0;
}