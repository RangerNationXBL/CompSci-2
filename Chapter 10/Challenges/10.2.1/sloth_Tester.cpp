#include <iostream>
using namespace std;

#include "critter.h"

/**
    A sloth eats and sleeps.
*/
class Sloth : public Critter
{
public:
    Sloth();
    void act();

private:
    bool eating;
   /* Your code goes here */
};

Sloth::Sloth() : Critter() {eating = true;}

void Sloth::act()
{
    if(eating){
        add_history("eat");
        eating = false;
        }else{
        add_history("sleep");
        eating = true;
    }
}

int main()
{
    Sloth sloth;
    sloth.act();
    cout << sloth.get_history() << endl;
    cout << "Expected: [eat]\n" << endl;
    sloth.act();
    cout << sloth.get_history() << endl;
    cout << "Expected: [eat, sleep]\n" << endl;
    sloth.act();
    cout << sloth.get_history() << endl;
    cout << "Expected: [eat, sleep, eat]\n" << endl;
    sloth.act();
    cout << sloth.get_history() << endl;
    cout << "Expected: [eat, sleep, eat, sleep]" << endl;

    return 0;
}