// Chapter 7 Pointers: Define and Use.
#include <iostream>
using namespace std;

// & address of variable.
// * dereferencing of pointer

void printNumber(int* numberPtr){
	cout << *numberPtr << endl;
}

void printLetter(char* charPtr){
	cout << *charPtr << endl;
}

void print(void* ptr, char type){
	switch(type){
		case 'i': 
			cout << *((int*)ptr) << endl;
			break;
		case 'c': 
			cout << *((char*)ptr) << endl;
			break;
	}
}

int main (){

	int number = 5;
	char letter = 'a';
	//printNumber(&number);
	//printLetter(&letter);
	print(&number, 'i');
	print(&letter, 'c');

	int luckyNumbers[5];
	//cout << luckyNumbers << endl;
	//cout << &luckyNumbers << endl;
	//cout << luckyNumbers[2] << endl;
	//cout << *(luckyNumbers + 2) << endl;

	for(int i = 0; i <= 4; i++){
		cout << "number: ";
		cin >> luckyNumbers[i];
	}

	for(int i = 0; i <= 4; i++){
		cout << *(luckyNumbers + i) << " ";
	}

	

}


/* int main(){

	int n = 5; // initialized variable
	
	cout << &n << endl; // display memory address of n
	
	int * ptr = &n; // asigning ptr to memory location of n

	cout << ptr << endl; // printing memory location of ptr

	cout << *ptr << endl; // dereferencing pointer to show value
	
	*ptr = 10; 	// changing the value of n
	
	cout << *ptr << endl;

	cout << n << endl;

	int v;
	int* ptr2 = &v;	
	*ptr2 = 7;
	cout << "v = " << v << endl;




	return 0;
} */