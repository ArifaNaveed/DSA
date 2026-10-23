#include<iostream>
using namespace std;

// Deletion (first node, last node and specific one)
class Node {
	public:
		int data;
		Node *Next;
		
	Node (int val) {
		data = val;
		Next = NULL;
	}	
};

// Functions to perform operation on linked list
Node* ArrayFill(int arr[], int idx, int size) {
	if (size == idx) {
		return NULL;
	}
	
	Node *Temp = new Node(arr[idx]);
	Temp->Next = ArrayFill(arr, idx+1, size);
	return Temp;
}

void printlist(Node &Head) {
	Node *print = &Head;
	while (print) {
		cout << print->data << " ";
		print = print->Next;
	}
}

/////////////////////////    MAIN    ////////////////////////
int main() {
	int size = 4;
	int array[size] = {12,23,45,89};
	
	Node *Head = ArrayFill(array, 0, size);
	printlist(*Head);
	cout << endl;
	
	
////////////////////////////////////////////////////////////////////////////	
// First delete start node (that is Head)
	Node *Temp = Head->Next;
	delete Head;
	Head = Temp;
	
	
	printlist(*Head);
	cout << endl;
	
////////////////////////////////////////////////////////////////////////////	
// delete last node
	Node *Tail = Head;
	Node *Prev = NULL;
	
	while(Tail->Next != NULL) {
		Prev = Tail; // give us 2nd last node
		Tail = Tail->Next;  // gives us the last node
	}
	
	delete Tail;
	Prev->Next = NULL;    // make 2nd last node points to NULL cuz now it is our last node
	
	printlist(*Head);
	cout << endl;

	
////////////////////////////////////////////////////////////////////////////
// 	Refill linked list	: Head is upadted, previous linked list is no more 
	Head = ArrayFill(array, 0, size);
	printlist(*Head);
	cout << endl;
	
// specific node to delete, ask user (remember this code never works for position 1: head node) 
	int idx; 
	cout << "Enter node position to delete (not index) ";
	cin >> idx;
	idx --;
	
	Temp = Head;
	Prev = NULL;
	while (idx--) {
		Prev = Temp; 
		Temp = Temp->Next; // holds exact node enetered by user
	}
	
	// we have to maintain link between nodes
	Prev->Next = Temp->Next;  // prev will lost its connection to Temp (entered by user)
	delete Temp;
	
	printlist(*Head);
	cout << endl;
	
	return 0;
}

// This was just for deletion logic, I haven't managed any validation here