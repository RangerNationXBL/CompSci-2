#include <iostream>
using namespace std;

#include "critter.h"

/**
A FastCritter moves twice as fast as a regular critter.
*/

class FastCritter : public Critter
{
public:
    void move(int steps);
};

void FastCritter::move(int steps){
    Critter::move(steps * 2);
}
int main()
{
    FastCritter speedy;
    speedy.move(10);
    cout << speedy.get_history() << endl;
    cout << "Expected: [move to 20]\n" << endl;
    speedy.move(-1);
    cout << speedy.get_history() << endl;
    cout << "Expected: [move to 20, move to 18]" << endl;

    return 0;
}