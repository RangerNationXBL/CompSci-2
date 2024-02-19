/*
 * NAME: Chris Brown
 * CLASS: Computer Science 2
 * PROFFESSOR: Dr. Tracy Kocher
 * DATE: 01/30/2024
 * FILE: Person.cpp
 * 
 * PROMPT: Reimplement the Person class so that the collection of friends are stored
 * in a vector.
 */

#include "Person.h"
#include "algorithm"

/* Class constructor initializes a person object with the given name. */
Person::Person(std::string personName) : name(personName){}

/* This method adds a friend to persons list of friends */
void Person::beFriend(Person* p) {
    if (!isFriend(p)) {
        friendNames.push_back(p);
    }
}

/* This method just unfriends that friend that is named. */
void Person::unFriend(Person* p){
    auto it = std::find(friendNames.begin(), friendNames.end(), p);
    if(it != friendNames.end()){
        friendNames.erase(it);
    }
}

/* This method grabs the vector of names to be displayed later */
std::vector<Person*> Person::get_friend_names(){
    return friendNames;
}

/* Method to retrieve the name of the person */
std::string Person::get_name(){ return name; }

/* Checking to see if a person is a friend */
bool Person::isFriend(Person* p) {
    return std::find(friendNames.begin(), friendNames.end(), p) != friendNames.end();
} 

/* Getting the count of how many friends are in the vector */
int Person::get_friend_count(){
    return friendNames.size();
}
