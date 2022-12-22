#include <iostream>
#include <string>
using namespace std;

#define IS_DIGIT(c)		(c >= '0' && c <= '9')

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
		if (!IsEmpty())	//	if Top == NULL
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

class Calculator
{
private:
	string expr;
	int Precedence(char opt)	//	BODMAS
	{
		if (opt == '+' || opt == '-')
		{
			return 1;
		}
		else if (opt == '*' || opt == '/')
		{
			return 2;
		}
		else if (opt == '^')
		{
			return 3;
		}
		else
		{
			return 0;
		}
	}
	void ConvertToPostfix()
	{
		Stack<char> stack;
		string result;

		for (int i = 0; i < expr.length(); i++)
		{
			if (IS_DIGIT(expr[i]))
			{
				result += expr[i];
			}
			else if (expr[i] == '(')
			{
				stack.Push('(');
			}
			else if (expr[i] == ')')
			{
				while (!stack.IsEmpty() && stack.Peek() != '(')
				{
					result += stack.Peek();
					stack.Pop();
				}
				if (stack.Peek() == '(')
				{
					stack.Pop();
				}
			}
			else
			{
				while (!stack.IsEmpty() && Precedence(expr[i]) <= Precedence(stack.Peek()))
				{
					result += stack.Peek();
					stack.Pop();
				}
				stack.Push(expr[i]);
			}
		}
		while (!stack.IsEmpty())
		{
			result += stack.Peek();
			stack.Pop();
		}
		expr = result;
	}
	int GetResult(int lhs, int rhs, char opt)
	{
		int result = 0;
		if (opt == '+')
			result = lhs + rhs;
		else if(opt == '-')
			result = lhs - rhs;
		else if(opt == '*')
			result = lhs * rhs;
		else if(opt == '/')
			result = lhs / rhs;
		else if(opt == '^')
			result = lhs ^ rhs;
		return result;
	}
public:
	Calculator()
	{
		expr = "";
	}
	Calculator(string data)
	{
		this->expr = data;
	}
	int EvaluteExpression()
	{
		if (expr == "")
		{
			cout << "Calculator::EvaluteExpression(), `expr` is empty !!!" << endl;
		}
		else
		{
			Stack<int> stack;
			ConvertToPostfix();

			int lhs, rhs;
			for (int i = 0; i < expr.length(); i++)
			{
				if (IS_DIGIT(expr[i]))
				{
					stack.Push(expr[i] - '0');
				}
				else
				{
					lhs = stack.Peek();
					stack.Pop();
					rhs = stack.Peek();
					stack.Pop();
					stack.Push(GetResult(rhs, lhs, expr[i]));
				}
			}
			int result_value = stack.Peek();
			stack.Pop();
			return result_value;
		}
		return 0;
	}
	void SetExpression(string expr)
	{
		this->expr = expr;
	}
	string GetExpression()
	{
		return this->expr;
	}
};

int main()
{
	Calculator* calculator = new Calculator();
	string Expression = "(7+(6*3+2)-(6/3))";
	calculator->SetExpression(Expression);
	int Result = calculator->EvaluteExpression();
	cout << Expression << " = " << Result << endl;
	
	system("PAUSE");
	return 0;
}
