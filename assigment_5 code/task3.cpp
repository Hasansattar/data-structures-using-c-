#include <iostream>
#include <vector>
using namespace std;

int N = 8, M = 7;
const int array_rows = 7, array_cols = 2;

class Graph
{
private:
	vector<int>* vertex;
	int** matrix;
	int rows, columns;
public:
	Graph();
	Graph(int rows, int columns);
	void ConvertToAdjacencyMatrix(int arr[][array_cols]);
	void ConvertToAdjacencyList();
	void DisplayAdjacencyMatrix();
	void DisplayAdjacencyList();
};

Graph::Graph()
{
	vertex = NULL;
	rows = columns = -1;
}

Graph::Graph(int r, int c)
{
	vertex = new vector<int>[r];
	matrix = new int* [r];
	for (int i = 0; i < r; i++)
	{
		matrix[i] = new int[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			matrix[i][j] = 0;
		}
	}
	rows = r;
	columns = c;
}

void Graph::ConvertToAdjacencyMatrix(int arr[][array_cols])
{
	if (rows == -1 || columns == -1)
	{
		cout << "Graph not Initialized..." << endl;
	}

	int v, lv;
	for (int i = 0; i < array_rows; i++)
	{
		v = arr[i][0] -1;
		lv = arr[i][1] - 1;

		matrix[v][lv] = 1;
		matrix[lv][v] = 1;
	}
}

void Graph::ConvertToAdjacencyList()
{
	for (int i = 0; i < rows; i++)
	{
		vertex[i].push_back(i+1);
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == 1)
			{
				vertex[i].push_back(j + 1);
			}
		}
	}
}

void Graph::DisplayAdjacencyMatrix()
{
	for (int i = 0; i <= columns; i++)
	{
		cout << "--";
	}
	cout << "\nx |";
	for (int i = 0; i < columns; i++)
	{
		cout << (i+1) << " ";
	}
	cout << endl;
	for (int i = 0; i <= columns; i++)
	{
		cout << "--";
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << (i + 1) << " |";
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::DisplayAdjacencyList()
{
	for (int i = 0; i < rows; i++)
	{
		for (auto i : vertex[i])
		{
			cout << i << " --> ";
		}
		cout << " NULL" << endl;
	}
}

int main()
{
	int Arr[array_rows][array_cols] =
	{ 
		{1, 2}, 
		{2, 3}, 
		{4, 5}, 
		{1, 5}, 
		{6, 1}, 
		{7, 4}, 
		{3, 8} 
	};

	Graph graph(N, M);
	cout << "================\nAdjacenty Matrix\n================" << endl << endl;
	graph.ConvertToAdjacencyMatrix(Arr);
	graph.DisplayAdjacencyMatrix();
	cout << endl;

	cout << "==============\nAdjacenty List\n==============" << endl << endl;
	graph.ConvertToAdjacencyList();
	graph.DisplayAdjacencyList();

	system("PAUSE");
	return 0;
}
