// Video presentation of the program I wrote in CS-1 Short version.
#include <iostream>

int cBinary(int x, int y){
	if(x == 0){
		return 0; // If its zero no calculation is needed, its going to be zero
	}else{
		int lastBit = x % 10; // Starting the first bit
		int decimalValue = lastBit * (1 << y); // Left shift bitwise operator
		return decimalValue + cBinary(x / 10, y + 1); // Calling the function within the function.
	}
}

// 00000001 + 0
// 00000010 + 1
// 00000100 + 2
// 00001000 = 3 = 8

int cDecimal(int x){
	if(x == 0){
		return 0;
	}else{
		int binary = x % 2 + 10 * cDecimal(x / 2); // This is reversing the whole calcualtions above.
		return binary;
	}
}

int main(){
	std::cout << cBinary(11111111, 0) << " = " << cDecimal(cBinary(11111111, 0)) << std::endl;
	// std::cout << cBinary(11111111, 0) << std::endl;
	// std::cout << cDecimal(255) << std::endl;
	return 0;
}