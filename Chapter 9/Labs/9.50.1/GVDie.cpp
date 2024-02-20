#include "GVDie.h"
#include <iostream>
using namespace std;

GVDie::GVDie() {
	srand(time(0)); //Unique seed
	myValue = rand() % 6 + 1;
}

void GVDie::Roll() {
	myValue = (rand() % 6) + 1;  //1 to 6
}

int GVDie::GetValue() {
	return myValue;
}

// set the random number generator seed for testing
void GVDie::SetSeed(int seed) {
	srand(seed);
} 