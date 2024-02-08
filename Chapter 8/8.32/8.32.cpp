/*
Given a text file containing the availability of food items, write a program that reads the information 
from the text file and outputs the available food items. The program should first read the name of the text 
file from the user. The program then should read the text file, line by line. If a food is available, the program 
should output the available food item in the following format: name (category) -- description

Assume the text file contains the category, name, description, and availability of at least one food item, separated by a tab character ('\t').

Hints: Use the find() function to find the index of a tab character in each row of the text file. Use the substr() 
function to extract the text separated by the tab characters.

Ex: If the input of the program is:

food.txt
and the contents of food.txt are:

Sandwiches    Ham sandwich    Classic ham sandwich    Available
Sandwiches    Chicken salad sandwich  Chicken salad sandwich  Not available
Sandwiches    Cheeseburger    Classic cheeseburger    Not available
Salads    Caesar salad    Chunks of romaine heart lettuce dressed with lemon juice    Available
Salads    Asian salad Mixed greens with ginger dressing, sprinkled with sesame    Not available
Beverages    Water   16oz bottled water  Available
Beverages    Coca-Cola   16oz Coca-Cola  Not available
Mexican food    Chicken tacos   Grilled chicken breast in freshly made tortillas    Not available
Mexican food    Beef tacos  Ground beef in freshly made tortillas   Available
Vegetarian    Avocado sandwich    Sliced avocado with fruity spread   Not available
the output of the program is:

Ham sandwich (Sandwiches) -- Classic ham sandwich
Caesar salad (Salads) -- Chunks of romaine heart lettuce dressed with lemon juice
Water (Beverages) -- 16oz bottled water
Beef tacos (Mexican food) -- Ground beef in freshly made tortillas
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string fileName;
    cin >> fileName;

    ifstream in(fileName);
    string line;

    while(getline(in, line)) {
        size_t pos1 = line.find_first_of('\t');
        if(pos1 != string::npos) {
            string category = line.substr(0, pos1);
            size_t pos2 = line.find('\t', pos1 + 1);
            if(pos2 != string::npos){
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                size_t pos3 = line.find('\t', pos2 + 1);
                if(pos3!= string::npos){
                    string description = line.substr(pos2 + 1, pos3 - pos2 - 1);
                    string availability = line.substr(pos3 + 1);
                    if(availability == "Available") {
                        cout << name << " (" << category << ") -- " << description << endl;
                    }
                }
            }
        }
    }

    return 0;
}