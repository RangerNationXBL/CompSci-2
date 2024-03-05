// =================================================================
// NAME: Chris Brown
// FILE: main.cpp
// PROFESSOR: Dr. Kocher
// DATE: 03-01-2024
// =================================================================
#include "Hanoi.h"
int main(){

    Hanoi puzzle(5);
    puzzle.print();
    puzzle.move(5, 0, 2);
    return 0;
}