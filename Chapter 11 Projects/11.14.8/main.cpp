// =================================================================
// NAME: Chris Brown
// FILE: Hanoi.cpp
// PROFESSOR: Dr. Kocher
// DATE: 03-01-2024
// =================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct MoveState {
    int disks;
    int from;
    int to;
    int step;

    MoveState(int d, int f, int t, int s) : disks(d), from(f), to(t), step(s) {}
};

class Hanoi{
private:
    int moveNumber;
    vector<int> towers[3];

public:
    Hanoi(int n) : moveNumber(0) {
        for (int d = n; d > 0; --d) {
            towers[0].push_back(d);
        }
    }

    void move_single_disk(int from, int to) {
        int last = towers[from].size() - 1; // Corrected indexing
        int disks = towers[from][last];
        towers[from].pop_back();
        towers[to].push_back(disks);
    }

    void move(int disks, int from, int to) {
        stack<MoveState> moves;
        moves.push(MoveState(disks, from, to, 0));

        while (!moves.empty()) {
            MoveState current = moves.top();
            moves.pop();

            if (current.disks == 0) continue;
            if (current.step == 0) {
                int other = 3 - current.from - current.to;
                moves.push(MoveState(current.disks - 1, other, current.to, 0));
                moves.push(MoveState(1, current.from, current.to, 1));
                moves.push(MoveState(current.disks - 1, current.from, other, 0));
            } else {
                move_single_disk(current.from, current.to);
                ++moveNumber;
                print();
                current.step = 0;
            }
        }
    }

    void print() const {
        cout << "Move " << moveNumber << ":" << endl;
        int maxHeight = 5; // Assumption.
        for (int row = maxHeight - 1; row >= 0; --row) {
            for (int i = 0; i < 3; ++i) {
                if (i > 0) cout << " ";
                if (row < towers[i].size()) {
                    int disk = towers[i][row];
                    cout << " " << disk << " ";
                } else {
                    cout << " | ";
                }
            }
            cout << endl;
        }
    }

    const vector<int>& getTower(int towerIndex) const {
        return towers[towerIndex];
    }
};

int main(){

    Hanoi puzzle(5);
    puzzle.print();
    puzzle.move(5, 0, 2);
    return 0;
}