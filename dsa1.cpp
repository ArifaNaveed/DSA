#include<iostream>
using namespace std;
int main() {
	int array[2][3][3];
	cout << "Enter values for 3D array\n";
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				cin >> array[i][j][k];
			}
		}
	}
	
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				cout << array[k][j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
}