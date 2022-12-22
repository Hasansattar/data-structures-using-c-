#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next, *prev;
};

class DoubleEndedQueue
{
private:
	Node* Head, *Tail;
	int Limit, CurrentSize;

	bool CanInsert()
	{
		if (Limit == -1 || CurrentSize < Limit)
			return true;
		return false;
	}
public:
	DoubleEndedQueue()
	{
		Head = Tail = NULL;
		Limit = -1;	//	-1 means no limit
		CurrentSize = 0;
	}

	void SetLimit(int limit)
	{
		this->Limit = limit;
	}

	void InsertAtHead(int data)
	{
		if (!CanInsert())
		{
			cout << "DoubleEndedQueue::InsertAtHead(), Queue size is full !!!" << endl;
			return;
		}
		Node* node = new Node();
		if (node == NULL)
		{
			cout << "Unable to allocate() memory for `Node` !!!" << endl;
		}
		else
		{
			node->data = data;
			if (Head == NULL)
			{
				node->next = node->prev = NULL;
				Head = Tail = node;
			}
			else
			{
				node->next = Head;
				Head->prev = node;
				Head = node;
			}
			if (Limit != -1)
			{
				CurrentSize++;
			}
		}
	}
	
	void InsertAtTail(int data)
	{
		if (!CanInsert())
		{
			cout << "DoubleEndedQueue::InsertAtTail(), Queue size is full !!!" << endl;
			return;
		}
		Node* node = new Node();
		if (node == NULL)
		{
			cout << "Unable to allocate() memory for `Node` !!!" << endl;
		}
		else
		{
			node->data = data;
			if (Tail == NULL)
			{
				Head = Tail = node;
			}
			else
			{
				node->prev = Tail;
				Tail->next = node;
				Tail = node;
			}
			if (Limit != -1)
			{
				CurrentSize++;
			}
		}
	}

	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			cout << "DoubleEndedQueue::Queue is empty !!!" << endl;
		}
		else
		{
			Node* node = Head;
			Head = Head->next;

			if (Head == NULL)
			{
				Tail = NULL;
			}
			else
			{
				Head->prev = NULL;
			}
			delete node;
			if (Limit != -1)
			{
				CurrentSize--;
			}
		}
	}

	void DeleteFromTail()
	{
		if (IsEmpty())
		{
			cout << "DoubleEndedQueue::Queue is empty !!!" << endl;
		}
		else
		{
			Node* node = Tail;
			Tail = Tail->prev;

			if (Tail == NULL)
			{
				Head = NULL;
			}
			else
			{
				Tail->next = NULL;
			}
			delete node;
			if (Limit != -1)
			{
				CurrentSize--;
			}
		}
	}

	int GetHead()
	{
		if (IsEmpty())
			return -1;
		return Head->data;
	}

	int GetTail()
	{
		if (IsEmpty())
			return -1;
		return Tail->data;
	}

	int GetSize()
	{
		return this->CurrentSize;
	}

	bool IsEmpty()
	{
		return (Head == NULL);
	}

	void Display()
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

void Menu()
{
	cout << "**********************************************" << endl;
	cout << "\t1. Insert At Head" << endl;
	cout << "\t2. Insert At Tail" << endl;
	cout << "\t3. Remove From Head" << endl;
	cout << "\t4. Remove From Tail" << endl;
	cout << "\t5. Total Cars" << endl;
	cout << "\t6. Display" << endl;
	cout << "\t7. Exit" << endl;
	cout << "**********************************************" << endl;
}

int main()
{
	DoubleEndedQueue* double_ended_queue = new DoubleEndedQueue();
	double_ended_queue->SetLimit(5);

	int choice = 0;
	do
	{
		Menu();
		do
		{
			cout << "Enter Choice Between (1-7): ";
			cin >> choice;
		} while (choice < 1 || choice > 7);
		switch (choice)
		{
		case 1:
			double_ended_queue->InsertAtHead(double_ended_queue->GetSize());
			break;
		case 2:
			double_ended_queue->InsertAtTail(double_ended_queue->GetSize());
			break;
		case 3:
			double_ended_queue->DeleteFromHead();
			break;
		case 4:
			double_ended_queue->DeleteFromTail();
			break;
		case 5:
			cout << double_ended_queue->GetSize() << endl;
			break;
		case 6:
			double_ended_queue->Display();
			cout << endl;
			break;
		case 7:
			cout << "You Exit the program...\n";
			break;
		}
	} while (choice != 7);

	system("PAUSE");
	return 0;
}
