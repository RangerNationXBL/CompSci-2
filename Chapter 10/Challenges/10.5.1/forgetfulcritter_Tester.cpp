#include <iostream>
using namespace std;

#include "critter.h"

/**
A ForgetfulCritter can't remember its history.
*/
class ForgetfulCritter : public Critter
{
public:
    void add_history(string event);
    void move(int steps);
};
void ForgetfulCritter::add_history(string event)
{
    Critter::add_history("?");
}
void ForgetfulCritter::move(int steps){
    int position = position + steps;
    add_history("move to" + to_string(position));
}

int main()
{
    ForgetfulCritter dopey;
    dopey.add_history("eat");
    cout << dopey.get_history() << endl;
    cout << "Expected: [?]\n" << endl;
    dopey.move(10);
    cout << dopey.get_history() << endl;
    cout << "Expected: [?, ?]" << endl;

    return 0;
}