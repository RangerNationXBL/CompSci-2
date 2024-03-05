// =================================================================
// NAME: Chris Brown
// FILE: Hanoi.h
// PROFESSOR: Dr. Kocher
// DATE: 03-01-2024
// =================================================================

#ifndef HANOI_H
#define HANOI_H

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
    Hanoi(int n);
    void move_single_disk(int from, int to);
    void move(int disks, int from, int to);
    void print() const;
    const vector<int>& getTower(int towerIndex) const;

};

#endif /* HANOI_H */