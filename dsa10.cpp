#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *Next;
		
	Node (int value) {
		data = value;
		Next = nullptr;
	}	
};

Node *Head, *Tail = nullptr;
int size = 0;  // to track total no of nodes in our list
int takeinput() {
	int pos;
	cout << "Enter position: ";
	cin >> pos;
	return pos;
}

// make functions for inssertion and deletion

// insert node at the start
void push_front(int value) {
	Node *Temp = new Node(value);
	
	if  (Head == nullptr) {
		Head = Tail = Temp;	
	}
		
	else {
		Temp->Next = Head;
		Head = Temp;
		Tail = Head;
	}
	size ++;
}

// insert node in the end of list
void push_back(int value) {
	Node *Temp = new Node(value);
	
	if (Head == nullptr) {
		Head = Tail = Temp;
	}
	
	else {
		Node *Store = Head;
		while (Store->Next != nullptr) {
			Store = Store->Next;
		}
		Store->Next = Temp;	
	}
	size ++;
}


// insert node at specific position
void insert_at(int value) {
	int position = takeinput();
	if (Head == nullptr || position+1 > size) {
		cout << "List is empty or can't access " << position << " position";
		cout << endl;
		return;
	}
	else if (position == 1) {
		push_front(value);
		cout << "Node Created" << endl;
		return;
	}
	
	else {
	position--;
// cuz we have to access node less than the position eneterd by user

	Node *Store = Head;
	while (--position) {
		Store = Store->Next;
	}
	Node *Temp = new Node(value);
	Temp->Next = Store->Next;
	Store->Next = Temp;
	cout << "Node Created" << endl;
	}
	size ++;
}


// delete node from the start (1st Node)
void pop_back() {
	size --;
	if (Head == nullptr) {
		cout << "Linked List is empty" << endl;
		return;
	}
	
	Node *Store = Head;
	Store = Store->Next;
	delete Head;
	Head = Store;
	
	cout << endl;
	cout << "Deleted";
	cout << endl;
}


// delete node from the end
void pop_front() {
	size --;
	if (Head == nullptr) {
		cout << "Linked List is empty" << endl;
		return;
	}
	
	Node *Store = Head;
	Node *Temp = nullptr;
	
	while (Store->Next != nullptr) {
		Temp = Store; // 2nd last node
		Store = Store->Next; // last node
	}
	Temp->Next = nullptr; 
// remove link of last node from list by making second last node points to null
	delete Store; // delete last node, no memory leak
}


// delete from specific position
void delete_from() {
	
	int position = takeinput();
	// same insertion at specific logic goes here
	if (Head == nullptr) {
		cout << "Linked List is empty" << endl;
		return;
	}
	
	else {
		if (position > size) {
			cout << "Linked List size is " << size << endl;
			cout << "Position out of Range" << endl;
		}
		return;
	}
	
	if (position == 1) {
		pop_back();  // function manages size
	}
	
	else {
		size --;
		Node *Store = Head;
		Node *Temp = nullptr;
		
		while(--position) {
			Temp = Store;
			Store = Store->Next;
		}
		Temp->Next = Store->Next;
		delete Store;
// we want to delete node from 3rd position, temp has 2nd node, store has 3rd node
// to maintain your linked list, give 4th node address to 2nd node then delete 3rd.
	}
}


// Fill linked list 
Node* ArrayFill(int arr[], int index, int sizes) {
	if (index == sizes) {
		return NULL;
	}
	size ++;
	
	Node *Temp = new Node(arr[index]);
	Temp->Next = ArrayFill(arr, index+1, sizes);
	return Temp;
}

//function to print our linked list
void print_list() {
	if (Head == NULL) {
		cout << "Linked List is empty" << endl;
		return;
	}
	
	Node *print = Head;
	while(print) {
		cout << print->data << " ";
		print = print->Next;
	}
}

//////////////////////////       MAIN FUNCTION        //////////////////////////

int main() {
	int arr[4] = {12,23,1,3};
	
// Fill your linked list
	Head = ArrayFill(arr, 0, 4);
	
	cout << "Linked List: " << endl;
	print_list();
	cout << endl;
	cout << endl;
	
//	delete_from(3); // 3rd node will be no more it is 23
//	pop_back();   // 1st node would be no more there that is 3
//	pop_front();  // last node would be no more there that is 2
	
	int choice, val;
	char ch;
	
	do {
	cout << "1. Insert Node: Start" << endl;
	cout << "2. Insert Node: End" << endl;
	cout << "3. Insert Node: Nth Position" << endl;
	cout << "4. Delete Fisrt Node" << endl;
	cout << "5. Delete Last Node" << endl;
	cout << "6. Delete Node: Nth Position" << endl;
	
	cout << "Choice:";
   	cin >> choice;
   
	switch(choice) {
		case 1:
			cout << "Enter value for Node: ";
			cin >> val;
			push_front(val);
			break;
			
		case 2:
			cout << "Enter value for Node: ";
			cin >> val;
			push_back(val);
			break;
			
		case 3:
			cout << "Enter value for Node: ";
			cin >> val;
			insert_at(val);
			break;
			
		case 4:
			pop_back();
			break;
			
		case 5:
			pop_front();
			break;
			
		case 6:
			delete_from();
			break;
			
		default:
			cout << "Invalid Input" << endl;
			break;
	}
	cout << endl;
	print_list();
	cout << endl;
	
	cout << "Continue? (Y/N) ";
	cin >> ch;
	cout << endl;
}
while (ch == 'Y' || ch == 'y');

	return 0;
}