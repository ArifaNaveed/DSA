#include<iostream>
using namespace std;

// inserting Node at the specific position
class Node {
	public:
		int data;
		Node *Next;
		
	Node (int value) {
		data = value;
		Next = NULL;
	}
};


int main() {
	int arr[4] = {12,22,33,44};
	Node *Head = NULL;

// inserting nodes in start
	for (int i=0; i<4; i++) {
		if (Head == NULL) {
			Head = new Node(arr[i]);
		}
		
		else {
			Node *Temp = new Node(arr[i]);
			Temp->Next = Head;
			Head = Temp;
		}
	}
	
// print your linked list
	Node *print = Head;
	while (print) {
		cout << print->data << " " ;
		print = print->Next;
	}
	cout << endl;
	
// get specific position from user
	int position, value;
	cout << "Enter position: ";
	cin >> position;
	position--;
// run your loop 1 less than given position

	cout << "Enter value: ";
	cin >> value;

// create new node first	
	Node *NewNode = new Node(value); 

// store head address to another node
	Node *Store = Head;
	
// handle 1st position manually
	if (position == 1) {
		NewNode->Next = Head;
		Head = NewNode;
	}
	
	else {
// by this loop, we access node at position-1 
	while (--position) {
		Store = Store->Next;
	}
	
	NewNode->Next = Store->Next;
	Store->Next = NewNode;
}
	print = Head;
	while (print) {
		cout << print->data << " ";
		print = print->Next;
	}
	
	
	return 0;
}