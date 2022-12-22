#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int ProcessorID, Executiontime;
	Node* next;
};

class RoundRobin
{
private:
	Node* head = NULL;
public:
	void CreateProcess(int ProcessorID, int Executiontime);
	void DeleteProcess(int ProcessorID);
	void CurrentRunningProcess();
	void Process(int TimeSlice);
};

void RoundRobin::CreateProcess(int ProcessorID, int Executiontime)
{
	Node* node = new Node;
	node->ProcessorID = ProcessorID;
	node->Executiontime = Executiontime;
	if (head == NULL)
	{
		head = node;
		head->next = head;
	}
	else
	{
		Node* ptr = head;
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}
		ptr->next = node;
		node->next = head;
	}
}

void RoundRobin::DeleteProcess(int ProcessorID)
{
	if (head == NULL)
		return;

	if (head->ProcessorID == ProcessorID && head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}

	Node* last = head, * temp;
	if (head->ProcessorID == ProcessorID)
	{
		while (last->next != head)
			last = last->next;

		last->next = head->next;
		delete head;
		head = last->next;
		return;
	}

	while (last->next != head && last->next->ProcessorID != ProcessorID)
		last = last->next;

	if (last->next->ProcessorID == ProcessorID)
	{
		temp = last->next;
		last->next = temp->next;
		delete temp;
	}
}

void RoundRobin::CurrentRunningProcess()
{
	Node* ptr = head;
	cout << "Processes in Linked List: ";
	do
	{
		cout << ptr->ProcessorID << " ";
		ptr = ptr->next;
	} while (ptr != head);
}

void RoundRobin::Process(int TimeSlice)
{
	int ExecutionTime = 0;
	Node* ptr = head;
	while (head != NULL)
	{
		do
		{
			CurrentRunningProcess();
			if (ptr->Executiontime <= TimeSlice && (ptr->Executiontime - TimeSlice <= 0))
			{
				cout << "Process #" << ptr->ProcessorID << " executed for " << ptr->Executiontime << " seconds" << endl;
				ExecutionTime += ptr->Executiontime;
				cout << "Process #" << ptr->ProcessorID << " has been executed. Time Taken: " << ExecutionTime << endl;
				DeleteProcess(ptr->ProcessorID);
				ptr = head;
				continue;
			}
			else
			{
				cout << "Process #" << ptr->ProcessorID << " executed for " << TimeSlice << " seconds" << endl;
				ptr->Executiontime -= TimeSlice;
				ExecutionTime += TimeSlice;
			}

			ptr = ptr->next;
		} while (ptr != head);
	}
}

int main()
{
	RoundRobin round_robin;

	int TotalProcessors, ExecutionTime;
	cout << "Enter number of processes: ";
	cin >> TotalProcessors;

	for (int i = 1; i <= TotalProcessors; i++)
	{
		cout << "Enter Process #" << i << " Execution Time: ";
		cin >> ExecutionTime;
		round_robin.CreateProcess(i, ExecutionTime);
	}

	int TimeSlice;
	cout << "Enter Time Slice: ";
	cin >> TimeSlice;

	round_robin.Process(TimeSlice);
	cout << "Execution Completed" << endl;

	system("PAUSE");
	return 0;
}
