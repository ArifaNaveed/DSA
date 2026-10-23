#include<iostream>
using namespace std;

// Doubly Linked List: Structure Explanation
class Node {
	public:
		int data;
		Node *Prev; // to hold prev node address
		Node *Next; // to hold next node address
		
	Node (int val) {
		data = val;
		Next = NULL;
		Prev = NULL;
	}	
};


// recursion
Node* ArrayFill(int arr[], int size, int idx, Node* self) {
	if (idx == size) {
		return NULL;
	}
	
	Node *Temp = new Node(arr[idx]);
	Temp->Prev = self;
	Temp->Next = ArrayFill(arr, size, idx+1, Temp);
	return Temp;
}

// print linked list
void PrintList(Node &Pri) {
	Node *Print = &Pri;
	
	while (Print) {
		cout << Print->data << " ";
		Print = Print->Next;
	}
}


/////////////////////////    Main Function    ////////////////////////
int main() {
	int arr[5] = {2, 4, 6, 8, 10};
	
	// 2 nodes
	Node *Head = new Node(1);
	Node *Second = new Node(3);
	
	// connect both of them
	Head->Next = Second;   // head will point to second (next node)
	Second->Prev = Head;   // second will also points to head (prev node)
	
	Node *NewNodes = ArrayFill (arr, 5, 0, Second);
	Second->Next = NewNodes;  
	// linked existing onw with new nodes, second's next have address of first new node
	
	cout << "Our Linked List: " << endl;
	PrintList(*Head);
	cout << endl;
	
	
	return 0;
}