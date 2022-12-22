/*
	Code taken from
	https://www.codespeedy.com/program-for-tower-of-hanoi-using-stack-in-cpp/#:~:text=C%2B%2B%20Program%3A%20Tower%20of%20Hanoi%20using%20stack&text=We%20have%20used%20the%20inbuilt,for%20the%20number%20of%20disks.
*/
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node* next;
};

template <class T>
class Stack
{
private:
	Node<T>* Top;
public:
	Stack()
	{
		Top = NULL;	// Initialize Top to NULL
	}

	bool Push(T value)
	{
		Node<T>* node = new Node<T>();
		if (node == NULL)	//	If memory alloc() failed.
		{
			return false;
		}
		node->data = value;
		node->next = Top;
		Top = node;
		return true;
	}

	T Pop()
	{
		if (IsEmpty())	//	if Top == NULL
		{
			return NULL;
		}
		Node<T>* node = Top;
		Top = Top->next;
		T result_value = node->data;
		delete node;
		return result_value;
	}

	bool IsEmpty()
	{
		return (Top == NULL);
	}

	void Display()
	{
		Node<T>* node = Top;
		cout << "[ ";
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
		cout << "]";
		cout << endl;
	}

	T Peek()
	{
		return Top->data;
	}
};

int TransferDisk(Stack<int>& stack_1, Stack<int>& stack_2)
{
	if (stack_2.IsEmpty())
	{
		stack_2.Push(stack_1.Peek());
		stack_1.Pop();
		return 1;
	}
	else if (stack_1.IsEmpty())
	{
		stack_1.Push(stack_2.Peek());
		stack_2.Pop();
		return 2;
	}
	else 
	{
		if (stack_2.Peek() > stack_1.Peek())
		{
			stack_2.Push(stack_1.Peek());
			stack_1.Pop();
			return 1;
		}
		else {
			stack_1.Push(stack_2.Peek());
			stack_2.Pop();
			return 2;
		}
	}
}

int main()
{
	Stack<int> source, auxiliary, destination;
	int input = 0;
	cin >> input;
	for (int i = input; i >= 1; i--)
	{
		source.Push(i);
	}

	int x = pow(2, input) - 1;
	int i = 1;

	if (input % 2 == 0)
	{
		while (i <= x) 
		{
			if (i % 3 == 1) 
			{
				int y = TransferDisk(source, auxiliary);
				if (y == 1) 
				{
					cout << "Move the disk " << auxiliary.Peek() << " from source to auxiliary" << endl;
				}
				else
				{
					cout << "Move the disk " << source.Peek() << " from auxiliary to source" << endl;
				}
			}
			else if (i % 3 == 2) {
				int y = TransferDisk(source, destination);
				if (y == 1) {
					cout << "Move the disk " << destination.Peek() << " from source to destination" << endl;
				}
				else
					cout << "Move the disk " << source.Peek() << " from destination to source" << endl;
			}
			else 
			{
				int y = TransferDisk(auxiliary, destination);
				if (y == 1) 
				{
					cout << "Move the disk " << destination.Peek() << " from auxiliary to destination" << endl;
				}
				else
				{
					cout << "Move the disk " << auxiliary.Peek() << " from destination to auxiliary" << endl;
				}
			}
			i++;
		}
	}
	else 
	{
		while (i <= x) 
		{
			if (i % 3 == 1) 
			{
				int y = TransferDisk(source, destination);
				if (y == 1) 
				{
					cout << "Move the disk " << destination.Peek() << " from source to destination" << endl;
				}
				else
				{
					cout << "Move the disk " << source.Peek() << " from destination to source" << endl;
				}
			}
			else if (i % 3 == 2) 
			{
				int y = TransferDisk(source, auxiliary);
				if (y == 1) 
				{
					cout << "Move the disk " << auxiliary.Peek() << " from source to auxiliary" << endl;
				}
				else
				{
					cout << "Move the disk " << source.Peek() << " from auxiliary to source" << endl;
				}
			}
			else 
			{
				int y = TransferDisk(auxiliary, destination);
				if (y == 1) 
				{
					cout << "Move the disk " << destination.Peek() << " from auxiliary to destination" << endl;
				}
				else
				{
					cout << "Move the disk " << auxiliary.Peek() << " from destination to auxiliary" << endl;
				}
			}
			i++;
		}
	}

	while (!destination.IsEmpty())
	{
		cout << destination.Peek() << endl;
		destination.Pop();
	}

	system("PAUSE");
	return 0;
}
