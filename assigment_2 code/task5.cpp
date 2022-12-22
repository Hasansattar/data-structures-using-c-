#include<iostream>
#include <string>

using namespace std;

struct Node
{
	char value;
	Node* next;
};

class Queue
{
private:
	Node *Head, *Tail;
public:
	Queue()
	{
		Head = Tail = NULL;
	}

	bool IsEmpty()
	{
		return (Head == NULL);
	}

	void Push(char value)
	{
		Node* node = new Node;
		node->value = value;
		node->next = NULL;
		if (IsEmpty())
		{
			Head = Tail = node;
		}
		else
		{
			Tail->next = node;
			Tail = node;
		}
	}

	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty!!!\n";
			return;
		}
		Node* node = Head;
		Head = Head->next;
		delete node;
	}

	char Top()
	{
		return Head->value;
	}
};

int main()
{
	Queue queue;
	int total_senators = 0;
	cout << "Number of Senators: " << endl;
	cin >> total_senators;
	cin.ignore();

	string str;
	cout << "Enter your Input: " << endl;
	getline(cin, str);

	if (str.length() != total_senators)
	{
		cout << "Error!!!\n" << endl;
		return 0;
	}

	for (int i = 0; i < total_senators; i++)
	{
		queue.Push(str[i]);
	}

	char c;
	int oppositions = 0, governments = 0;
	for (int i = 0; i < total_senators; i++)
	{
		c = queue.Top();
		if (c == 'G' || c == 'g') 
		{
			governments++;
		}
		else if(c == 'O' || c == 'o')
		{
			oppositions++;
		}
		queue.Pop();
	}

	if (governments > oppositions)
	{
		cout << "Government\n";
		cout << "Because the number of votes of governmnet are greater then the number of votes of opposition.\n";
		cout << "Or the first vote is from government " << endl;
	}
	else
	{
		cout << "Opposition\n" << endl;
		cout << "Because the number of votes of opposition are greater then the number of votes of government.\n";
		cout << "Or the first vote is from oppostion\n";
	}

	system("PAUSE");
	return 0;
}
