#include "binarySearchTree.h"
using namespace std;

int main()
{
	/*
	// Sample Input: 65 55 22 44 61 19 90 10 78
	52
	BST<int> myIntBST;
	// test all functions here
	*/
	BST<int> myIntBST;

	int arr[] = { 65, 55, 22, 44, 61, 19, 90, 10, 78 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		cout << "BST<T>::Insert(" << arr[i] << ");" << endl;
		myIntBST.Insert(arr[i]);
	}
	cout << endl;

	cout << "BST<T>::calculateSum() = " << myIntBST.calculateSum() << endl;

	system("PAUSE");
	return 0;
}
