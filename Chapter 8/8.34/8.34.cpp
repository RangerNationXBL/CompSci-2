#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string fileName;
    cin >> fileName;

    ifstream in(fileName);

    string line;
    string title, rating, showtime;
    vector<string> titles, ratings, showtimes;

    while(getline(in, line)) {
        stringstream ss(line);
        getline(ss, showtime, ',');
        getline(ss, title, ',');
        getline(ss, rating, ',');

        titles.push_back(title.substr(0, 45));
        ratings.push_back(rating);
        showtimes.push_back(showtime);
    }
    in.close();

    for(size_t i = 0; i < titles.size(); i++) {
        cout << left << setw(45) << titles[i] << "| ";
        cout << right << setw(5) << ratings[i] << " | ";
        cout << showtimes[i];
        while(i < titles.size() - 1 && titles[i] == titles[i + 1]) {
            cout << " " << showtimes[i + 1];
            i++;
        }
        cout << endl;
    }

   

   return 0;
}
