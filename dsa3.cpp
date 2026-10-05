#include<iostream>
using namespace std;
int main() {
	int L, B, W;
	cout << "Enter length: ";
	cin >> L;
	
	cout << "Enter 	Breadth: ";
	cin >> B;
	
	cout << "Enter Width: ";
	cin >> W;
	
	int ***ptr = new int**[L];
	
	for (int i=0; i<L; i++) {
		ptr[i] = new int*[B];
		
			for(int j=0; j<B; j++) {
				ptr[i][j] = new int[W];
			}
	}
	
	cout << "Enter Elements IN Array: ";
	
	for (int i=0; i<L; i++) {
		for (int j=0; j<B; j++) {
			for (int k=0; k<W; k++) {
			cin >> ptr[i][j][k];
		}
	  }
	}	
	
	for (int i=0; i<L; i++) {
		for (int j=0; j<B; j++) {
			for (int k=0; k<W; k++)  {
			cout << ptr[i][j][k] << " ";
		}
		cout << endl;
	  }
		cout << endl;
	}
	
		for (int j=0; j<L; j++) {
			for (int k=0; k<B; k++)  {
			delete[] ptr[j][k];
		}
		delete[] ptr[j];
	  }
	  delete[] ptr;
}