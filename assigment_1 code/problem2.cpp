#include <iostream>
#include <string>

using namespace std;

int main()
{
	//	User Defined array pointer
	int* Array_List;

	//	Taking Array size as input from user
	int Array_Size;
	cout << "Enter Size of Array: ";
	cin >> Array_Size;

	//	Allocating User Defined array pointer with N-Size
	Array_List = new int[Array_Size];
	for (int i = 0; i < Array_Size; i++)
	{
		cout << "Enter value for ID[" << i << "] : ";
		cin >> Array_List[i];
	}

	for (int i = 0; i < Array_Size; i++)
	{
		cout << Array_List[i] << ": ";
		for (int j = 1; j < Array_List[i]; j++)
		{
			if (Array_List[i] % j == 0)
				cout << j << " ";
		}
		cout << endl;
	}
	cout << "Execution Completed..." << endl;

	system("PAUSE");	//	Prevent console from exiting.
	return 0;
}
