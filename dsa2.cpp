#include<iostream>
using namespace std;
int main() {
	int rows = 3, cols = 4;
	int **ptr = new int*[rows];
// craetes int array of pointers in heap because of * so it only have memory space not values yet. 
	
	for (int i=0 ; i<rows ; i++) {
		ptr[i] = new int[cols];  
// array of integers in heap memory(new) then also each time it creartes array of size 4 cuz cols = 4
// and above rows (array of pointers) stores each column array 0th index address respectively.
	}
	
	cout << "Enter your array\n";
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cin >> ptr[i][j];
		}
	}
	
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	
		for (int j=0; j<rows; j++) {
			delete[] ptr[j];
		}
// deletes the full column array (hsving size 4) by just getting the address of 0th index
// total we have 3 column arrays cuz of 3 rows.

	delete[] ptr;
// deletes the row array pointer by just getting the aaddress of 0th index it deletes other 2 memory slots too
}