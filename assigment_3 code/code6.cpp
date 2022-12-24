#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int value;
	Node* lhs, * rhs;
};

bool XorGate(bool A, bool B);
bool NorGate(bool A, bool B);
bool OrGate(bool A, bool B);
bool NandGate(bool A, bool B);
bool AndGate(bool A, bool B);
bool NotGate(bool A);

class BST
{
private:
	Node* Tree;

	void applyAndGate(Node* n, int& result)
	{
		if (n == NULL)
		{
			return;
		}
		if (result == -1)
		{
			result = n->value;
		}
		else
		{
			result = AndGate(result, n->value);
		}
		applyAndGate(n->lhs, result);
		applyAndGate(n->rhs, result);
	}

	void applyXorGate(Node* n, int& result)
	{
		if (n == NULL)
		{
			return;
		}
		if (result == -1)
		{
			result = n->value;
		}
		else
		{
			result = XorGate(result, n->value);
		}
		applyXorGate(n->lhs, result);
		applyXorGate(n->rhs, result);
	}

	void preOrderTraversal(Node* n)
	{
		if (n == NULL)
		{
			return;
		}
		cout << n->value << " ";
		preOrderTraversal(n->lhs);
		preOrderTraversal(n->rhs);
	}
public:
	BST()
	{
		Tree = NULL;
	}
	void Insert(int value)
	{
		Node* node = new Node();
		node->value = value;
		node->lhs = NULL;
		node->rhs = NULL;

		if (Tree == NULL)
		{
			Tree = node;
		}
		else
		{
			Node* temp = Tree;
			Node* prev = NULL;
			while (temp != NULL)
			{
				if (value < temp->value)
				{
					prev = temp;
					temp = temp->lhs;
				}
				else if (value >= temp->value)
				{
					prev = temp;
					temp = temp->rhs;
				}
				else
				{
					printf("Duplicate not allowed...\n");
					return;
				}
			}
			if (value < prev->value)
				prev->lhs = node;
			else if (value >= prev->value)
				prev->rhs = node;
		}
	}

	void preOrderTraversal()
	{
		preOrderTraversal(Tree);
	}

	int applyAndGate()
	{
		int result = -1;
		applyAndGate(Tree, result);
		return result;
	}

	int applyXorGate()
	{
		int result = -1;
		applyXorGate(Tree, result);
		return result;
	}
};

int main()
{
	BST* bst = new BST();
	int value = 101;
	stack<int> s;
	while (value > 0)
	{
		s.push(value % 10);
		value /= 10;
	}

	while (!s.empty())
	{
		cout << "BST::Insert(" << s.top() << ")" << endl;
		bst->Insert(s.top());
		s.pop();
	}

	cout << "BST::applyAndGate() = ";
	cout << bst->applyAndGate() << endl;

	cout << "BST::applyXorGate() = ";
	cout << bst->applyXorGate() << endl;

	system("PAUSE");
	return 0;
}

bool NotGate(bool A)
{
	return !A;
}

bool AndGate(bool A, bool B)
{
	return (A & B);
}

bool NandGate(bool A, bool B)
{
	return NotGate(AndGate(A, B));
}

bool OrGate(bool A, bool B)
{
	return (A | B);
}

bool NorGate(bool A, bool B)
{
	return NotGate(OrGate(A, B));
}

bool XorGate(bool A, bool B)
{
	return (A ^ B);
}
