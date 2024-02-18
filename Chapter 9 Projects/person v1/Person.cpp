#include "Person.h"

Person::Person(std::string personName) : name(personName){}

void Person::beFriend(Person p) {
    if (!isFriend(p)) {
        if (!friendName.empty()) {
            friendName += " ";
        }
        friendName += p.get_name();
    }
}

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
std::string Person::get_friend_name(){ return friendName; }

std::string Person::get_name(){ return name; }

bool Person::isFriend(Person p) {
    return friendName.find(p.get_name()) != std::string::npos;
}