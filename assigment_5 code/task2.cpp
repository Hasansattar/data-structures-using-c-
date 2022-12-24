#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
struct VertexNode
{
	T vertex;
	int cost;
};

template <class T>
struct Vertex
{
	T vertex;
	vector<VertexNode<T>> list;
};

template <class T>
class Graph
{
private:
	Vertex<T> *vertex;
	int size, unique_vertex;
	bool IsNewVertex(T v)
	{
		bool flag = true;
		for (int i = 0; i < unique_vertex; i++)
		{
			if (vertex[i].vertex == v)
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	bool CanAddMoreVertex(char v)
	{
		if (IsNewVertex(v))
		{
			if (unique_vertex == size)
			{
				return false;
			}
			vertex[unique_vertex].vertex = v;
			unique_vertex++;
		}
		return true;
	}
	int GetVertex(T v)
	{
		int index = -1;
		for (int i = 0; i < unique_vertex; i++)
		{
			if (vertex[i].vertex == v)
			{
				index = i;
				break;
			}
		}
		return index;
	}
public:
	Graph()
	{
		vertex = NULL;
		size = unique_vertex = 0;
	}
	Graph(int s)
	{
		vertex = new Vertex<T>[s];
		size = s;
		unique_vertex = 0;
	}
	void SetGraphLimit(int s)
	{
		Graph(s);
	}
	void addEdge(T source, T destination, int cost)
	{
		if (!vertex)
		{
			cout << "Graph size is not initialized !!!" << endl;
			return;
		}

		if (!CanAddMoreVertex(source) || !CanAddMoreVertex(destination))
		{
			cout << "Limit Overflow !!! " << source << "--->" << destination << ", cannot create a link" << endl;
			return;
		}
				
#ifdef DEBUG
	cout << source << "--->" << destination << "(" << cost << ")" << endl;
#endif // DEBUG

		vertex[GetVertex(source)].list.push_back({ destination, cost });
		vertex[GetVertex(destination)].list.push_back({ source, cost });
	}
	void displayMatrix()
	{
		T* vertexNames = new T[unique_vertex];

		cout << "x ";
		for (int i = 0; i < unique_vertex; i++)
		{
			vertexNames[i] = vertex[i].vertex;
			cout << vertexNames[i] << " ";
		}
		cout << endl;

		int** matrix = new int* [unique_vertex];
		for (int i = 0; i < unique_vertex; i++)
		{
			matrix[i] = new int[unique_vertex];
		}
		for (int i = 0; i < unique_vertex; i++)
		{
			for (int j = 0; j < unique_vertex; j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < unique_vertex; i++)
		{
			cout << vertex[i].vertex << " ";
			for (int j = 0; j < unique_vertex; j++)
			{
				for (auto k : vertex[i].list)
				{
					if (k.vertex == vertexNames[j])
					{
						matrix[i][j] = 1;
						break;
					}
				}
			}
			for (int k = 0; k < unique_vertex; k++)
			{
				cout << matrix[i][k] << " ";
			}
			cout << endl;
		}
	}
	void displayEdge()
	{
		for (int i = 0; i < unique_vertex; i++)
		{
			cout << vertex[i].vertex << ": ";
			for (auto i : vertex[i].list)
			{
				cout << i.vertex << "(" << i.cost << "), ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph<char> graph(6);
	graph.addEdge('a', 'b', 7);
	graph.addEdge('a', 'c', 9);
	graph.addEdge('a', 'f', 14);

	graph.addEdge('b', 'd', 15);
	graph.addEdge('b', 'c', 10);
	
	graph.addEdge('c', 'd', 11);
	graph.addEdge('c', 'f', 2);

	graph.addEdge('d', 'e', 6);

	graph.addEdge('e', 'f', 9);

	cout << "Matrix: " << endl;
	graph.displayMatrix();
	cout << endl;

	cout << "Common Edges: " << endl;
	graph.displayEdge();

	system("PAUSE");
	return 0;
}
