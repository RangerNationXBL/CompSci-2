#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
    
private:
    string name;
    vector<Person*> friends;

public:
    Person(string personName) : name(personName) {}

    void befriend(Person *p){
        friends.push_back(p);
    }

    void unFriend(Person *p){
        for(auto it = friends.begin(); it!= friends.end(); it++){
            if(*it == p){
                friends.erase(it);
                break;
            }
        }
    }
    string getFriendNames(){
        string friendNames;
        for(auto freindPtr : friends){
            friendNames += freindPtr->name + " ";
    
        }
    return friendNames;
    }

    int getFriendCount(){
        return friends.size();
    }
};

int main(){
    Person alice("Alice");
    Person bob("Bob");
    Person charlie("Charlie");

    alice.befriend(&bob);
    alice.befriend(&charlie);

    bob.befriend(&alice);

    string aliceFriends = alice.getFriendNames();
    cout << "Alice's friends are: " << aliceFriends << endl;

    alice.unFriend(&bob);
    aliceFriends = alice.getFriendNames();
    cout << "Alice's friends are: " << aliceFriends << endl;

    cout << "Alice's Friends: " << alice.getFriendNames() << endl;
    cout << "Alice's Friend count: " << alice.getFriendCount() << endl;

    return 0;
}