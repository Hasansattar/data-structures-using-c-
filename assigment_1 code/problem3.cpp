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
	Node* Merge_Lists(Node* list1, Node* list2);
	void DisplayList();
};

void ADT_LinkedList::Insert(int value)
{
	if (value < 0)
	{
		cout << "Value cannot be less than 0" << endl;
		return;
	}

	cout << "Inserting Node: " << value << endl;

	Node* temp = new Node();
	temp->data = value;

	if (head == NULL || head->data < value)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		bool flag = false;
		Node* next = head;
		Node* prev = NULL;
		while (next->next != NULL)
		{
			if (next->data == value)
			{
				cout << "Node Already exists..." << endl;
				return;
			}
			prev = next;
			next = next->next;
			if (prev != NULL && next->data < value)
			{
				prev->next = temp;
				temp->next = next;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			next->next = temp;
			temp->next = NULL;
		}
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

Node* ADT_LinkedList::Merge_Lists(Node* list1, Node* list2)
{
	Node* ptr = new Node();
	Node* prev = ptr;

	while (list1 != NULL && list2 != NULL)
	{
		if (list1->data <= list2->data)
		{
			prev->next = list1;
			list1 = list1->next;
		}
		else {
			prev->next = list2;
			list2 = list2->next;
		}
		prev = prev->next;
	}

	if (list1 == NULL) 
		prev->next = list2;
	if (list2 == NULL)
		prev->next = list1;

	return ptr->next;

}

void ADT_LinkedList::DisplayList()
{
	Node* tmp = head;
	cout << "[ ";
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << "]" << endl;
}

int main()
{
	ADT_LinkedList obj1;
	obj1.Insert(10);
	obj1.Insert(1);
	obj1.Insert(5);
	obj1.Insert(20);
	obj1.Insert(15);
	cout << "List Number-1" << endl;
	obj1.DisplayList();
	cout << endl;

	ADT_LinkedList obj2;
	obj2.Insert(25);
	obj2.Insert(16);
	obj2.Insert(12);
	obj2.Insert(40);
	obj2.Insert(75);
	cout << "List Number-2" << endl;
	obj2.DisplayList();
	cout << endl;

	ADT_LinkedList obj3;
	obj3.SetHead( obj3.Merge_Lists(obj1.GetHead(), obj2.GetHead()));
	cout << "Merge List" << endl;
	obj3.DisplayList();
	cout << endl;

	system("PAUSE");
	return 0;
}
