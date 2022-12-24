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

	cout << "BST<T>::SearchKey(65) = " << (myIntBST.SearchKey(65) ? "Found" : "Not Found") << endl;
	cout << "BST<T>::SearchKey(100) = " << (myIntBST.SearchKey(100) ? "Found" : "Not Found") << endl;
	cout << "BST<T>::SearchKey(10) = " << (myIntBST.SearchKey(10) ? "Found" : "Not Found") << endl;

	cout << "BST<T>::DeleteKey(65)";
	myIntBST.DeleteKey(65);
	cout << endl;

	cout << "BST<T>::DeleteKey(100)";
	myIntBST.DeleteKey(100);
	cout << endl;

	cout << "BST<T>::DeleteKey(10)";
	myIntBST.DeleteKey(10);
	cout << endl;

	cout << "BST<T>::findMax() = ";
	cout << myIntBST.findMax() << endl;
	cout << endl;

	cout << "BST<T>::findMin() = ";
	cout << myIntBST.findMin() << endl;
	cout << endl;

	cout << "BST<T>::inorderTraversal() {\n  ";
	myIntBST.inorderTraversal();
	cout << "\n}\n" << endl;

	cout << "BST<T>::preorderTraversal() {\n  ";
	myIntBST.preorderTraversal();
	cout << "\n}\n" << endl;

	cout << "BST<T>::postorderTraversal() {\n  ";
	myIntBST.preorderTraversal();
	cout << "\n}\n" << endl;

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
