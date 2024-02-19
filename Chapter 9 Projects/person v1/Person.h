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

#pragma once

#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person{
private:
    std::string name;
    std::string friendName;
public:
    Person(std::string personName);

    
    void beFriend(Person p);
    
    void unFriend(Person p);
    
    std::string get_friend_name();
    
    std::string get_name();
    
    bool isFriend(Person p);

};

#endif