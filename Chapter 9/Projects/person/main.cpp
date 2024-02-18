#include <iostream>
#include "Person.h"
using namespace std;

int main(){

    Person alice("Alice");
    Person bob("Bob");
    Person charlie("Charlie");

    alice.beFriend(bob);
    alice.beFriend(charlie);

    cout << "Alice Friends: " << alice.get_friend_name() << endl;
    cout << "Bool: " << alice.isFriend(bob) << endl;

    return 0;
}