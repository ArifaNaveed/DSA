#include<iostream>
using namespace std;

// linked list, inserting new nodes at the start of list
class Node {
	public:
		int data;
		Node *Next;
		
	Node(int value) {
		data = value;
		Next = NULL;
	}
};


int main() {
Node *Head = new Node(23); 
// our first node

int arr[3] = {27,34,45};

for (int i=0; i<3; i++) {
	if (Head == NULL) {
		Node *Head = new Node(arr[i]);
// creates first node if it is not there
	}
	
	else {
		Node *Temp = new Node(arr[i]);
		Temp->Next = Head;
// we have first node, so add its address to new node's next by this our new node
// points to existing node 
		Head = Temp;
// now, make the new node as head (first node): node added in start :)
	}
}


// print this (explained in earlier files)
Node *print = Head;
while (print) {
	cout << print->data << " ";
	print = print->Next;
}

}