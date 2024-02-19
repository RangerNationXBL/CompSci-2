/*
 * NAME: Chris Brown
 * CLASS: Computer Science 2
 * PROFFESSOR: Dr. Tracy Kocher
 * DATE: 01/30/2024
 * FILE: Person.h
 * 
 * PROMPT: Reimplement the Person class so that the collection of friends are stored
 * in a vector.
 */

#pragma once

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

/* This is the definition of the class, the implementation is store in the Person.cpp file */

class Person{
private:
    std::string name;
    std::vector<Person*> friendNames;

public:
    Person(std::string personName);
    
    void beFriend(Person* p);
    
    void unFriend(Person* p);

    std::vector<Person*> get_friend_names();
    
    std::string get_name();
    
    bool isFriend(Person* p);

    int get_friend_count();

};

#endif