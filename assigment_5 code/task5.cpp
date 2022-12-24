#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std; 

#define GetParent(x)		(i-1)/2
#define GetLeftChild(x)		(2*i+1)
#define GetRightChild(x)	(2*i+2)

void swap(int* lhs, int* rhs)
{
	int *temp = lhs;
	lhs = rhs;
	rhs = temp;
}

class Heap
{
private:
	int* nodes;
	int size, current_size;
	void Heapify(int i);
public:
	Heap();
	void SetLimit(int s);
	void InsertKey(int key);
	void DeleteRoot();
	void Print();
	bool IsEmpty();
	int Top();
};

void Heap::Heapify(int i)
{
	int lhs = GetLeftChild(i);
	int rhs = GetRightChild(i);
	int smallest = i;
	if (lhs < current_size && nodes[lhs] < nodes[smallest])
	{
		smallest = lhs;
	}
	if (rhs < current_size && nodes[rhs] < nodes[smallest])
	{
		smallest = rhs;
	}
	if (smallest != i)
	{
		swap(nodes[i], nodes[smallest]);
		Heapify(smallest);
	}
}

Heap::Heap()
{
	nodes = NULL;
	size = current_size = -1;
}

void Heap::SetLimit(int s)
{
	nodes = new int[s];
	size = s;
	current_size = 0;
}

void Heap::DeleteRoot()
{
	if (current_size == 0)
	{
		cout << "No element found in heap " << endl;
		return;
	}
	int last_element = nodes[current_size-1];
	nodes[0] = last_element;
	current_size--;
	Heapify(0);
}

void Heap::InsertKey(int key)
{
	if (size == -1)
	{
		cout << "Heap::SetLimit(size), where `size` is -1..." << endl;
		return;
	}
	if (size == current_size )
	{
		cout << "Unable to insert " << key << " !!!" << endl;
		return;
	}
	nodes[current_size] = key;
	for (int i = current_size; i != 0 && nodes[GetParent(i)] > nodes[i]; i = GetParent(i))
	{
		swap(nodes[i], nodes[GetParent(i)]);
	}
	current_size++;
}

void Heap::Print()
{
	cout << "[ ";
	for (int i = 0; i < current_size; i++)
	{
		cout << nodes[i] << " ";
	}
	cout << "]" << endl;
}

bool Heap::IsEmpty()
{
	return current_size == 0;
}

int Heap::Top()
{
	return nodes[0];
}

int main()  
{
	Heap heap;

	int size = 0;
	do
	{
		cout << "Enter Size: ";
		cin >> size;
	} while (size < 0);
	heap.SetLimit(size);
	
	#define MAXIMUM_NUMBER	1000
	cout << "Generating " << size << " random numbers" << endl;
	int x;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		x = rand() % MAXIMUM_NUMBER + 1;
		cout << x << " ";
		heap.InsertKey(x);
	}

	cout << endl;
	cout << "Heap::Print() " << endl;
	heap.Print();
	cout << endl;

	while (!heap.IsEmpty())
	{
		cout << "Deleting: " << heap.Top() << endl;
		heap.DeleteRoot();
	}

	cout << endl;
	cout << "Heap::Print() " << endl;
	heap.Print();
	cout << endl;

	system("PAUSE");
	return 0;  
}
