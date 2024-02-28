#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Plant {
protected:
    string name;
    int cost;

public:
    Plant(string name, int cost) : name(name), cost(cost) {}

    virtual ~Plant() {}

    virtual void PrintInfo(int number) {
        cout << "Plant " << number << " Information:" << endl;
        cout << "   Plant name: " << name << endl;
        cout << "   Cost: " << cost << endl;
    }
};

class Flower : public Plant {
private:
    bool annual;
    string color;

public:
    Flower(string name, int cost, bool annual, string color) : Plant(name, cost), annual(annual), color(color) {}

    void PrintInfo(int number) override {
        Plant::PrintInfo(number);
        cout << "   Annual: " << boolalpha << annual << endl;
        cout << "   Color of flowers: " << color << endl;
    }
};

void PrintVector(const vector<Plant*>& myGarden) {
    int count = 1;
    for (const auto& plant : myGarden) {
        plant->PrintInfo(count++);
        cout << endl;
    }
}

int main() {
    vector<Plant*> myGarden;
    int plantCount = 1;

    while (true) {
        string type, name, color;
        int cost;
        bool annual;

        cin >> type;
        if (type == "-1") {
            break;
        } else if (type == "plant") {
            cin >> name >> cost;
            myGarden.push_back(new Plant(name, cost));
        } else if (type == "flower") {
            cin >> name >> cost >> boolalpha >> annual >> color;
            myGarden.push_back(new Flower(name, cost, annual, color));
        } else {
            cerr << "Invalid input: " << type << endl;
            break;
        }
    }

    PrintVector(myGarden);

    // Clean up allocated memory
    for (auto& plant : myGarden) {
        delete plant;
    }

    return 0;
}
