#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;
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

	void Pop()
	{
		if (!IsEmpty())	//	if !(Top == NULL)
		{
			Node<T>* node = Top;
			Top = Top->next;
			delete node;
		}
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

#define LOWER(c)		(c >= 'a' && c <= 'z')
#define UPPER(c)		(c >= 'A' && c <= 'Z')
#define IS_ALPHA(c)		(LOWER(c) || UPPER(c))

string sequenceMutation(string sequence) 
{
	Stack<string> stack;
	string word = "";
	for (int i = 0; sequence[i] != '\0'; i++)
	{
		if (IS_ALPHA(sequence[i]))
		{
			word += sequence[i];
		}
		else
		{
			if (word != "")
			{
				stack.Push(" ");
				stack.Push(word);
			}
			word = "";
		}
	}
	stack.Push(word);
	word = "";
	while (!stack.IsEmpty())
	{
		word += stack.Peek();
		stack.Pop();
	}
	return word;
}

int main()
{
	string Sequence = "Hurray! Live for assignment.";
//	cout << "Enter Something: ";
//	getline(cin, Sequence);
	cout << sequenceMutation(Sequence) << endl;

	system("PAUSE");
	return 0;
}
