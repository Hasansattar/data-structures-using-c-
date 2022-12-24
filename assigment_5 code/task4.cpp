#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

//#define DEBUG		//	uncomment to check addEdge
template <class T>
class Graph
{
private:
	Vertex<T>* vertex;
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
	bool CanAddMoreVertex(T v)
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
	int GetVertexIndex(T v)
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
		size = unique_vertex = -1;
	}
	Graph(int s)
	{
		vertex = new Vertex<T>[s];
		size = s;
		unique_vertex = 0;
	}
	void SetVertexLimit(int s)
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

		vertex[GetVertexIndex(source)].list.push_back({ destination, cost });
		vertex[GetVertexIndex(destination)].list.push_back({ destination, cost });
	}
	void BFS(T source, T destination)
	{
		queue<VertexNode<T>> q;
		bool* visited = new bool[size];
		int total_cost = 0;
		int total_count = 0;
		bool goal_found = false;
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}

		int index = GetVertexIndex(source);
		if (index == -1)
		{
			cout << "Source doesn't Exist in List !!!" << endl;
			return;
		}
		visited[index] = true;
		q.push({ vertex[index].vertex, 0 });
		while (!q.empty())
		{
			VertexNode<T> last = q.front();
			q.pop();
			total_cost += last.cost;
			if (last.vertex == destination)
			{
				goal_found = true;
				break;
			}
			cout << last.vertex << " ---> ";
			for (auto i : vertex[GetVertexIndex(last.vertex)].list)
			{
				index = GetVertexIndex(i.vertex);
				if (!visited[index])
				{
					q.push({ i.vertex, i.cost });
					visited[index] = true;
				}
			}
			total_count++;
		}

		if (goal_found)
			cout << "Goal Reached !!!" << endl;
		else
			cout << "Goal not Reached !!!" << endl;

		std::cout << "Total Iterations: " << total_count << endl;
		std::cout << "Total Cost: " << total_cost << endl;
	}
	void DFS_util(T destination, int v, bool* visited, int& total_cost, int& total_count, bool& goal_found)
	{
		visited[v] = true;
		total_count++;
		int index;
		for (auto i : vertex[v].list)
		{
			index = GetVertexIndex(i.vertex);
			if (visited[index] == false)
			{
				total_cost += i.cost;
				if (i.vertex == destination)
				{
					goal_found = true;
					return;
				}
				cout << i.vertex << " ---> ";
				DFS_util(destination, GetVertexIndex(i.vertex), visited, total_cost, total_count, goal_found);
			}
			if (goal_found)
			{
				return;
			}
		}
	}
	void DFS(T source, T destination)
	{
		stack<VertexNode<T>> s;
		bool* visited = new bool[size];
		int total_cost = 0;
		int total_count = 0;
		bool goal_found = false;
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}

		int index = GetVertexIndex(source);
		if (index == -1)
		{
			cout << "Source doesn't Exist in List !!!" << endl;
			return;
		}

		for (int i = 0; i < unique_vertex; i++)
		{
			if (visited[i] == false && !goal_found)
			{
				cout << vertex[i].vertex << " ---> ";
				DFS_util(destination, i, visited, total_cost, total_count, goal_found);
			}
		}

		if (goal_found)
			cout << "Goal Reached !!!" << endl;
		else
			cout << "Goal not Reached !!!" << endl;

		std::cout << "Total Iterations: " << total_count << endl;
		std::cout << "Total Cost: " << total_cost << endl;
	}
	void displayEdge()
	{
		for (int i = 0; i < unique_vertex; i++)
		{
			cout << vertex[i].vertex << ": ";
			for (auto i : vertex[i].list)
			{
				cout << "--->" << i.vertex << "(" << i.cost << ")";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph<string> graph(20);

	graph.addEdge("Arad", "Zerind", 75);
	graph.addEdge("Arad", "Sibiu", 140);
	graph.addEdge("Arad", "Timisoara", 118);

	graph.addEdge("Bucharest", "Glurgiu", 90);
	graph.addEdge("Urziceni", "Glurgiu", 85);

	graph.addEdge("Cralova", "Pitesti", 138);

	graph.addEdge("Drobeta", "Cralova", 120);

	graph.addEdge("Fagaras", "Bucharest", 211);

	graph.addEdge("Hirsova", "Eforie", 86);

	graph.addEdge("Iasi", "Neamt", 87);

	graph.addEdge("Lugoj", "Mehadia", 70);

	graph.addEdge("Mehadia", "Drobeta", 75);

	graph.addEdge("Oradea", "Sibiu", 151);

	graph.addEdge("Pitesti", "Bucharest", 101);

	graph.addEdge("Rimnicu Vilcea", "Pitesti", 97);
	graph.addEdge("Rimnicu Vilcea", "Cralova", 146);

	graph.addEdge("Sibiu", "Fagaras", 99);
	graph.addEdge("Sibiu", "Rimnicu Vilcea", 80);

	graph.addEdge("Timisoara", "Lugoj", 111);

	graph.addEdge("Urziceni", "Hirsova", 98);
	graph.addEdge("Urziceni", "Vaslui", 142);

	graph.addEdge("Vaslui", "Iasi", 92);

	graph.addEdge("Zerind", "Oradea", 71);

	cout << "====================\nBreadth-First Search\n====================" << endl;
	graph.BFS("Arad", "Bucharest");
	cout << endl;

	cout << "==================\nDepth-First Search\n==================" << endl;
	graph.DFS("Arad", "Bucharest");
	cout << endl;

	cout << "=============\nDisplay Graph\n=============" << endl;
	graph.displayEdge();
	cout << endl;

	system("PAUSE");
	return 0;
}
