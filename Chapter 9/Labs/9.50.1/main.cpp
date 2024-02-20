#include <iostream>
#include "GVDie.h"
using namespace std;

int RollingForPair(GVDie d1, GVDie d2, int val) {
	/* Type your code here */
	int rolls = 0;
	while(true){
		d1.Roll();
		d2.Roll();
		rolls++;
		if(d1.GetValue() == val && d2.GetValue() == val){
			break;
		}
	}
	return rolls;
}

int main() {
	GVDie d1 = GVDie();
	GVDie d2 = GVDie();
	d1.SetSeed(15); // Create a GVDie object with seed value 15
    d2.SetSeed(15); // Create a GVDie object with seed value 15
	int rolls;
	int val;

	cin >> val;
	rolls = RollingForPair(d1, d2, val);
	cout << "It took " << rolls << " rolls to get a pair of " << val << "'s."; 

	return 0;
}