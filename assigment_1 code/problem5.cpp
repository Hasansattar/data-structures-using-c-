#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next, * prev;
};

class DoublyLinkedList
{
private:
	Node* head = NULL, * tail = NULL;
public:
	void insertNodeAtBeginning(int data);
	void insertNodeInMiddle(int key, int data);
	void insertNodeAtEnd(int data);

	bool deleteFirstNode();
	bool deleteNode(int key);
	bool deleteLastNode();

	bool Search(int key);

	void Display();
};

void DoublyLinkedList::insertNodeAtBeginning(int data)
{
	Node* node = new Node();
	node->data = data;
	node->next = head;
	if (head != NULL)
		head->prev = node;

	node->prev = NULL;
	head = node;
}
void DoublyLinkedList::insertNodeInMiddle(int key, int data)
{
	Node* node = new Node();
	node->data = data;

	Node* temp = head;
	while (temp != NULL && temp->data != key)
		temp = temp->next;

	if (temp == NULL)	//	It means we are at the end;
	{
		printf("Unable insert based on key value...\n");
		return;
	}

	node->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = node;
	temp->next = node;
	node->prev = temp;

}
void DoublyLinkedList::insertNodeAtEnd(int data)
{
	Node* node = new Node;
	node->data = data;

	if (head == NULL)
	{
		head = node;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = node;
	node->next = NULL;

}

bool DoublyLinkedList::deleteFirstNode()
{
	Node* node = head;
	if (node == NULL)
		return false;
	head = head->next;
	delete node;
	return true;
}
bool DoublyLinkedList::deleteNode(int key)
{
	Node* prev = NULL;
	Node* ptr = head;

	while (ptr != NULL)
	{
		if (ptr->data == key)
		{
			if (ptr == head)
			{
				head = head->next;
				delete ptr;
				ptr = head;
				return true;
			}
			else
			{
				prev->next = ptr->next;
				delete ptr;
				ptr = prev->next;
				return true;
			}
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
			return true;
		}
	}
	return false;
}
bool DoublyLinkedList::deleteLastNode()
{
	if (head == NULL)
		return false;

	if (head->next == NULL)
	{
		delete head;
		return true;
	}

	Node* temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;

	delete temp->next;
	temp->next = NULL;
	return true;
}

bool DoublyLinkedList::Search(int key)
{
	Node* ptr = head;
	int iterations_taken = 1;
	bool flag = false;
	while (ptr != NULL)
	{
		if (ptr->data == key)
		{
			printf("Value[%d] found in list...\n"
				"Total Iterations Taken[%d]...\n", key, iterations_taken);
			flag = true;
			break;
		}
		ptr = ptr->next;
		iterations_taken++;
	}
	return flag;

}

void DoublyLinkedList::Display()
{
	Node* ptr = head;
	printf("[ ");
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("]\n");

}

void InsertMenu()
{
	cout << "***************************************" << endl;
	cout << "\t\t1. Insert At Head" << endl;
	cout << "\t\t2. Insert On Key" << endl;
	cout << "\t\t3. Insert At Tail" << endl;
	cout << "***************************************" << endl;
}

void DeleteMenu()
{
	cout << "***************************************" << endl;
	cout << "\t\t1. Delete At Head" << endl;
	cout << "\t\t2. Delete On Key" << endl;
	cout << "\t\t3. Delete At Tail" << endl;
	cout << "***************************************" << endl;
}

void MainMenu()
{
	cout << "***************************************" << endl;
	cout << "\t\t1. Insert" << endl;
	cout << "\t\t2. Delete" << endl;
	cout << "\t\t3. Search" << endl;
	cout << "\t\t4. Display" << endl;
	cout << "\t\t5. Exit" << endl;
	cout << "***************************************" << endl;
}

int main()
{
	DoublyLinkedList* doubly_linked_list = new DoublyLinkedList();
	int choice, choice2;
	int key, value;
	do
	{
		MainMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice < 0 || choice > 5)
		{
			cout << "Invalid choice..." << endl;
			cout << "Enter your choice b/w (1-5): ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			InsertMenu();
			cout << "Enter your choice: ";
			cin >> choice2;
			while (choice2 < 0 || choice2 > 3)
			{
				cout << "Invalid choice..." << endl;
				cout << "Enter your choice b/w (1-5): ";
				cin >> choice2;
			}
			switch (choice2)
			{
			case 1:
				cout << "Enter Value: ";
				cin >> value;
				doubly_linked_list->insertNodeAtBeginning(value);
				break;
			case 2:
				cout << "Enter Value: ";
				cin >> value;
				cout << "Enter Key: ";
				cin >> key;
				doubly_linked_list->insertNodeInMiddle(key, value);
				break;
			case 3:
				cout << "Enter Value: ";
				cin >> value;
				doubly_linked_list->insertNodeAtEnd(value);
				break;
			}
			break;
		case 2:
			DeleteMenu();
			cout << "Enter your choice: ";
			cin >> choice2;
			while (choice2 < 0 || choice2 > 3)
			{
				cout << "Invalid choice..." << endl;
				cout << "Enter your choice b/w (1-5): ";
				cin >> choice2;
			}
			switch (choice2)
			{
			case 1:
				if (!doubly_linked_list->deleteFirstNode())
					cout << "List is Empty" << endl;
				else
					cout << "Element Removed from head" << endl;
				break;
			case 2:
				cout << "Enter key to delete: ";
				cin >> key;
				if (!doubly_linked_list->deleteNode(key))
					cout << "List is Empty" << endl;
				else
					cout << "Element Removed from head" << endl;
				break;
			case 3:
				if (!doubly_linked_list->deleteLastNode())
					cout << "List is Empty" << endl;
				else
					cout << "Element Removed from tail" << endl;
				break;
			}
			break;
		case 3:
			cout << "Enter Key for searching: ";
			cin >> key;
			if (!doubly_linked_list->Search(key))
				cout << "No Node found..." << endl;
			break;
		case 4:
			doubly_linked_list->Display();
			break;
		default:
			cout << "Program Terminated..." << endl;
			break;
		}
	} while (choice != 5);

	system("PAUSE");
	return 0;
}
