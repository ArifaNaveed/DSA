#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node *Next;
	
	Node(int value) {
		data = value;
		Next = NULL;
	}	
};

// inserting an array (at the end) to our existing linked list
int main() {
	Node *Head = new Node(3);
	Node *Node1 = new Node(5);
	Head->Next = Node1;
// now node 1 is linked to head
		
	int array[4] = {23,34,45,56};
	
	for (int i=0; i<4; i++) { 
		if (Head == NULL) {
			Node *Head = new Node(array[i]);
		}
		
		else {
// to insert new node at the end, access the last node of list
			Node *Tail = Head;
			
			while (Tail->Next != NULL) {
				Tail = Tail->Next;
			}
			
			Node *Temp = new Node(array[i]);
			Tail->Next = Temp;
// here Tail is our last node, now it's Next has the address of new node.
	    }
	}
	
// printing our linked list: EXPLAINED IN PREVIOUS CODE
		Node *head = Head;
		while (head) {
			cout << head->data << " ";
			head = head->Next;
		}
	return 0;
}