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
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Input: ";
	for (auto i : array)
	{
		cout << i << ' ';
	}
	cout << endl;
	cout << endl;

	myIntBST.ConvertSortedArrayToTree(array, size);

	cout << "BST<T>::treeHeight() = ";
	cout << myIntBST.treeHeight() << endl;
	cout << endl;

	cout << "BST<T>::treeNodeCount() = ";
	cout << myIntBST.treeNodeCount() << endl;
	cout << endl;

	cout << "BST<T>::treeLeavesCount() = ";
	cout << myIntBST.treeLeavesCount() << endl;
	cout << endl;

	cout << "BST<T>::printNodeLevel() {\n  ";
	myIntBST.preorderTraversal();
	cout << "\n}\n" << endl;


	system("PAUSE");
	return 0;
}
