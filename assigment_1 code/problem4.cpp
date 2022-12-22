#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class ADT_LinkedList
{
private:
	Node* head = NULL;
public:
	void Insert(int value);

	void SetHead(Node* head);
	Node* GetHead();

	void ConnectLists(Node* otherList);
	void FindCommonItems(Node* otherList);

	void DisplayList();
};

void ADT_LinkedList::Insert(int value)
{
	Node* node = new Node();
	node->data = value;
	node->next = NULL;
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		Node* ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = node;
	}
}

void ADT_LinkedList::SetHead(Node* head)
{
	this->head = head;
}

Node* ADT_LinkedList::GetHead()
{
	return this->head;
}

void ADT_LinkedList::ConnectLists(Node* otherList)
{
	if (head == NULL)
	{
		cout << "1st Linked List must not be Empty..." << endl;
		return;
	}

	Node* ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	Node* temp = otherList;
	if (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next != NULL)
			temp = temp->next;
		else
		{
			cout << "There is not 3rd Index in other Linked List..." << endl;
			return;
		}
	}
	else
	{
		cout << "There is not 3rd Index in other Linked List..." << endl;
		return;
	}

	ptr->next = temp;	//	Connect 1st-LL last node with 3rd index of 2nd-LL
}

void ADT_LinkedList::FindCommonItems(Node* otherList)
{
	Node* ptr1 = head;
	Node* ptr2;
	cout << "Common Elements\n[ ";
	while (ptr1 != NULL)
	{
		ptr2 = otherList;
		while (ptr2 != NULL)
		{
			if (ptr1->data == ptr2->data)
			{
				cout << ptr1->data << " ";
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	cout << "]" << endl;
}

void ADT_LinkedList::DisplayList()
{
	Node* ptr = head;
	cout << "[ ";
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << "]" << endl;
}

int main()
{
	ADT_LinkedList obj1;
	obj1.Insert(1);
	obj1.Insert(3);
	obj1.Insert(5);
	obj1.Insert(7);
	obj1.Insert(9);
	obj1.Insert(15);
	obj1.Insert(20);
	cout << "List Number-1" << endl;
	obj1.DisplayList();
	cout << endl;

	ADT_LinkedList obj2;
	obj2.Insert(2);
	obj2.Insert(4);
	obj2.Insert(6);
	obj2.Insert(8);
	obj2.Insert(10);
	obj2.Insert(12);
	obj2.Insert(24);
	cout << "List Number-2" << endl;
	obj2.DisplayList();
	cout << endl;

	obj1.ConnectLists(obj2.GetHead());

	cout << "\nAfter Connecting Linked List" << endl;
	obj1.DisplayList();
	cout << endl;

	obj1.FindCommonItems(obj2.GetHead());

	system("PAUSE");
	return 0;
}

