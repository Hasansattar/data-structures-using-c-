#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

struct Vertex
{
	int row, column;
	int cost;
};

class Graph
{
private:
	int** points;
	bool graph_initialized;
	int start_offset[2], goal_offset[2];
	int row, column;
	void GraphOutput(int** arr);
public:
	Graph();
	Graph(int** arr, int row, int column, int* start_offset, int* goal_offset);
	bool ValidState(int row, int column);
	void BFS();
	void DFS();
};

void Graph::GraphOutput(int **arr)
{
	int x;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			x = arr[i][j];
			if( x == 2 || x == 3 )
				std::cout << "* ";
			else 
				std::cout << x << " ";
		}
		std::cout << endl;
	}
}

Graph::Graph()
{
	this->graph_initialized = false;
}

Graph::Graph(int** points, int row, int column, int* start_offset, int* goal_offset)
{
	this->points = points;
	this->row = row;
	this->column = column;

	this->start_offset[0] = row - start_offset[0];
	this->start_offset[1] = start_offset[1] - 1;

	this->goal_offset[0] = row - goal_offset[0];
	this->goal_offset[1] = goal_offset[1] - 1;

	this->graph_initialized = true;
}

bool Graph::ValidState(int row, int column)
{
	if (!graph_initialized)
	{
		std::cout << "Graph is not initialized !!!" << endl;
		return false;
	}

	if (points[start_offset[0]][start_offset[1]] == 1)
	{
		std::cout << "Start State is Blocked !!!" << endl;
		return false;
	}

	if (points[goal_offset[0]][goal_offset[1]] == 1)
	{
		std::cout << "Goal State is Blocked !!!" << endl;
		return false;
	}
	return true;
}

void Graph::BFS()
{
	queue<Vertex> points_queue;
	bool goal_found = false;

	int** arr;
	arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = points[i][j];
		}
	}

	points_queue.push({ start_offset[0], start_offset[1], 0 });
	Vertex p;
	int total_count = 0;
	int total_cost = 0;

	std::cout << "Path: ";
	while (!points_queue.empty())
	{
		p = points_queue.front();
		total_cost += p.cost;

		std::cout << (row - p.row) << ":" << (p.column + 1) << " -> ";
		points_queue.pop();
		if (p.row == goal_offset[0] && p.column == goal_offset[1])
		{
			std::cout << "Goal Found !!!" << endl;
			goal_found = true;
			break;
		}

		//	Up
		if ((p.row - 1) >= 0)
		{
			if (arr[p.row - 1][p.column] == 0)
			{
				points_queue.push({ p.row - 1, p.column, p.cost + 2 });
				arr[p.row - 1][p.column] = 2;
			}
		}

		//	Diagonal
		if ((p.row - 1) >= 0 && (p.column + 1) < column)
		{
			if (arr[p.row - 1][p.column + 1] == 0)
			{
				points_queue.push({ p.row - 1, p.column + 1, p.cost + 3 });
				arr[p.row - 1][p.column + 1] = 3;
			}
		}

		//	Right
		if ((p.column + 1) < column)
		{
			if (arr[p.row][p.column + 1] == 0)
			{
				points_queue.push({ p.row, p.column + 1, p.cost + 2 });
				arr[p.row][p.column + 1] = 2;
			}
		}
		total_count++;
	}
	std::cout << "Total Iterations: " << total_count << endl;
	std::cout << "Total Cost: " << total_cost << endl;
	GraphOutput(arr);
}

void Graph::DFS()
{
	stack<Vertex> points_stack;
	bool goal_found = false;

	int** arr;
	arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = points[i][j];
		}
	}

	points_stack.push({ start_offset[0], start_offset[1], 0 });
	Vertex p;
	int total_count = 0;
	int total_cost = 0;

	std::cout << "Path: ";
	while (!points_stack.empty())
	{
		p = points_stack.top();
		total_cost += p.cost;

		std::cout << (row - p.row) << ":" << (p.column + 1) << " -> ";
		points_stack.pop();
		if (p.row == goal_offset[0] && p.column == goal_offset[1])
		{
			std::cout << "Goal Found !!!" << endl;
			goal_found = true;
			break;
		}

		//	Up
		if ((p.row - 1) >= 0)
		{
			if (arr[p.row - 1][p.column] == 0)
			{
				points_stack.push({ p.row - 1, p.column, p.cost + 2 });
				arr[p.row - 1][p.column] = 2;
			}
		}

		//	Diagonal
		if ((p.row - 1) >= 0 && (p.column + 1) < column)
		{
			if (arr[p.row - 1][p.column + 1] == 0)
			{
				points_stack.push({ p.row - 1, p.column + 1, p.cost + 3 });
				arr[p.row - 1][p.column + 1] = 3;
			}
		}

		//	Right
		if ((p.column + 1) < column)
		{
			if (arr[p.row][p.column + 1] == 0)
			{
				points_stack.push({ p.row, p.column + 1, p.cost + 2 });
				arr[p.row][p.column + 1] = 2;
			}
		}
		total_count++;
	}
	std::cout << "Total Iterations: " << total_count << endl;
	std::cout << "Total Cost: " << total_cost << endl;
	GraphOutput(arr);
}

int main()
{
	ifstream fileHandler;
	fileHandler.open("Grid.txt");
	int col, row;
	int start[2];
	int goal[2];
	
	if (!fileHandler.is_open())
	{
		std::cout << "File Not Found !!!" << endl;
	}
	else
	{
		fileHandler >> row;
		fileHandler >> col;

		fileHandler >> start[0];
		fileHandler >> start[1];

		fileHandler >> goal[0];
		fileHandler >> goal[1];

		int** arr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fileHandler >> arr[i][j];
			}
		}

		/*int data[row][col] =
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 },
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
			{ 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
			{ 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
			{ 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 }
		};

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				arr[i][j] = data[i][j];
		}*/

		Graph graph(arr, col, row, start, goal);

		std::cout << "====================\nBreadth-First Search\n====================" << endl;
		graph.BFS();
		std::cout << endl;

		std::cout << "==================\nDepth-First Search\n==================" << endl;
		graph.DFS();
		std::cout << endl;
	}

	system("PAUSE");
	return 0;
}
