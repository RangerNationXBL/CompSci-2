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

    /* Create instances of Person Alice, Bob, and Charlie*/
    Person alice("Alice");
    Person bob("Bob");
    Person charlie("Charlie");

    /* Add friends to alice */
    alice.beFriend(&bob);
    alice.beFriend(&charlie);

    /* Get all of alice's friends and count them */
    vector<Person*> aliceFriends = alice.get_friend_names();
    string aliceName = alice.get_name();
    int aliceFriendCOunt = alice.get_friend_count();

    /* Output alices friends and count */
    cout << aliceName << "'s friends" << endl;
    for (Person* alice : aliceFriends){
        cout << alice->get_name() << endl;
    }

    cout << aliceName << " has " << aliceFriendCOunt << " friend(s)." << endl;
    cout << endl;
    cout << "*** Alice has ejected a friend ***" << endl;
    cout << endl;

    /* Remove a friend from Alice */
    alice.unFriend(&charlie);
    aliceFriends = alice.get_friend_names();
    aliceName = alice.get_name();
    aliceFriendCOunt = alice.get_friend_count();

    cout << aliceName << "'s friends" << endl;
    for (Person* alice : aliceFriends){
        cout << alice->get_name() << endl;
    }
    cout << aliceName << " has " << aliceFriendCOunt << " friend(s)." << endl;
    return 0;

}

