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
		Array_List[i] = -1;
	}
	Array_Size -= 1;

	//	Counter for even & odd index
	int Even_Index = 0;
	int Odd_Index = 1;

	//	Variable to take input from user
	int User_Input;
	while (true)
	{
		if (Odd_Index > Array_Size && Even_Index > Array_Size)
		{
			cout << "There is no space left in array..." << endl;
			cout << "Terminating Program..." << endl;
			break;
		}
		cout << "Enter a Number: ";
		cin >> User_Input;
		if (!(User_Input % 2))	//	If even number
		{
			if (Even_Index > Array_Size)
			{
				cout << "\nEven Indexes are full" << endl;
				continue;
			}
			Array_List[Even_Index] = User_Input;
			Even_Index += 2;
		}
		else //	If odd number
		{
			if (Odd_Index > Array_Size)
			{
				cout << "\nOdd Indexes are full" << endl;
				continue;
			}
			Array_List[Odd_Index] = User_Input;
			Odd_Index += 2;
		}
	}

	cout << "[ ";
	Array_Size += 1;
	for (int i = 0; i < Array_Size; i++)
	{
		cout << Array_List[i] << " ";
	}
	cout << "]" << endl;
	cout << "Execution Completed..." << endl;

	system("PAUSE");	//	Prevent console from exiting.
	return 0;
}
