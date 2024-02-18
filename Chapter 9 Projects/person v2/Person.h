// Person.h
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

    int get_friend_count();

};

#endif