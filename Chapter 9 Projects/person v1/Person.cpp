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

#include "Person.h"

/* Constructor */
Person::Person(std::string personName) : name(personName){}

/* Add Friend */
void Person::beFriend(Person p) {
    if (!isFriend(p)) {
        if (!friendName.empty()) {
            friendName += " ";
        }
        friendName += p.get_name();
    }
}
/* Remove Friend */
void Person::unFriend(Person p){
    std::size_t pos = friendName.find(p.get_name());
    if(pos != std::string::npos){
        friendName.erase(pos, p.get_name().length());
    }
    if(pos > 0 && friendName[pos - 1] == ' '){
        friendName.erase(pos - 1, 1);
    }
    if(pos + p.get_name().length() < friendName.length() && friendName[pos + p.get_name().length()] == ' '){
        friendName.erase(pos + p.get_name().length(), 1);
    }
}

/* Get the name of friend */
std::string Person::get_friend_name(){ return friendName; }

/* Get the name of person */
std::string Person::get_name(){ return name; }

/* Are they a friend ?*/
bool Person::isFriend(Person p) {
    return friendName.find(p.get_name()) != std::string::npos;
}