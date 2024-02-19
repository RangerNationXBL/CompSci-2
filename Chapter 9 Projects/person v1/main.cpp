/*
 * NAME: Chris Brown
 * CLASS: Computer Science 2
 * PROFFESSOR: Dr. Tracy Kocher
 * DATE: 01/30/2024
 * FILE: main.cpp
 * 
 * PROMPT: Reimplement the Person class so that the collection of friends are stored
 * in a vector.
 */

#include <iostream>
#include "Person.h"
using namespace std;

int main(){

    /* Create the instances */
    Person alice("Alice");
    Person bob("Bob");
    Person charlie("Charlie");

    /* Add Friends */
    alice.beFriend(bob);
    alice.beFriend(charlie);

    cout << "Alice Friends: " << alice.get_friend_name() << endl;
    cout << endl;

    /* Remove friend */
    alice.unFriend(charlie);
    cout << "Alice Removed a friend." << endl;
    cout << endl;
    cout << "Alice Friends: " << alice.get_friend_name() << endl;

    // cout << "Bool: " << alice.isFriend(bob) << endl;

    return 0;
}

