#include<iostream>
using namespace std;

// array insertion in linked list using recursion 
class Node {
	public:
		int data;
		Node *Next;
		
	Node(int val) {
		data = val;
	}
};


// MAIN GOAL: Recursive Function
Node* ArrayFill(int arr[], int index, int size) {
// first identify the base condition
	if (index == size) {
		return NULL;
	}
	
// function will call itself until base condition met.
	Node *Temp = new Node(arr[index]);
	Temp->Next = ArrayFill(arr, index+1, size);
	return Temp;
}


// Print Function
void printlist(Node &Head) {
	Node *Print = &Head;
	
	while (Print) {
		cout << Print->data << " ";
		Print = Print->Next;
	}
}


int main() {
	int size = 4;
	int arr[size] = {23,34,45,56};
	
	// fill linked list through recursive function
	Node *Head;
	Head = ArrayFill(arr, 0, size);
	
	
	// print 
	printlist(*Head);
	
	return 0;
}