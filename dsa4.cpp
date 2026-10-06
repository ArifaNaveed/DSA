#include<iostream>
using namespace std;

// linked list : user define data type in C++
class Node {
	public:
		int data;
		Node * Next;
		
		Node(int value) {
			data = value;
			Next = NULL;
		}
};

int main () {
	Node * Head = new Node(3);
	Node * Temp1 = new Node(4);
	
	// to link both head and temp
	Head->Next = Temp1;
	
	// to print linked list, while loop because we don't know size of our linked list
	Node * CTemp = Head;
	
	// condition is valid if CTemp (pointer) is not a NULL pointer
	while(CTemp) {
		cout << CTemp->data << " ";
		CTemp = CTemp->Next;
	}
	cout << endl;
	
	
	// here's the 4,5 nodes linked to each other
	
	Node * Temp2 = new Node(23);
	Temp1->Next = Temp2;
	
	Node * Temp3 = new Node(12);
	Temp2->Next = Temp3;
	
	Node * Temp4 = new Node(67);
	Temp3->Next = Temp4;
	
	Node * Temp5 = new Node(45);
	Temp4->Next = Temp5;
	
	// utilizing declared variables here (CTemp and Head)
	CTemp = Head;
	
	while(CTemp) {
		cout << CTemp->data << " ";
		CTemp = CTemp->Next;
	}
		
	// better approach here is to make an array of new values (you want to insert)
	// and insert it using for loop : Next Code
	
	return 0;
}