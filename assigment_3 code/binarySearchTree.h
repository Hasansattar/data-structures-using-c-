#pragma once
#include <iostream>
template <class T>
struct Node
{
	T value;
	Node<T>* lhs, * rhs;
};

template <class T>
class BST
{
private:
	Node<T>* Tree;

    Node<T>* DeleteKey(Node<T>* n, T key)
    {
        if (n == NULL)
        {
            return NULL;
        }

        if (key < n->value)
        {
            n->lhs = DeleteKey(n->lhs, key);
        }
        else if (key > n->value)
        {
            n->rhs = DeleteKey(n->rhs, key);
        }
        else
        {
            if (!n->lhs && !n->rhs)
            {
                return NULL;
            }
            else if (n->lhs == NULL)
            {
                Node<T>* temp = n->rhs;
                delete n;
                return temp;
            }
            else if (n->rhs == NULL)
            {
                Node<T>* temp = n->lhs;
                delete n;
                return temp;
            }

            Node<T>* temp = n->rhs;
            while (temp->lhs != NULL)
            {
                temp = temp->lhs;
            }
            n->value = temp->value;
            n->rhs = DeleteKey(n->rhs, temp->value);
        }
        return n;
    }

    bool SearchKey(Node<T>* n, T key)
    {
        if (n == NULL)
        {
            return false;
        }

        if (key > n->value)
        {
            return SearchKey(n->rhs, key);
        }
        else if (key < n->value)
        {
            return SearchKey(n->lhs, key);
        }
        return true;
    }

    int findMax(Node<T>* n)
    {
        if (n->rhs == NULL)
            return n->value;
        return findMax(n->rhs);
    }

    int findMin(Node<T>* n)
    {
        if (n->lhs == NULL)
            return n->value;
        return findMin(n->lhs);
    }

	void preorderTraversal(Node<T>* n)
	{
		if (n == NULL)
			return;
        std::cout << n->value << ' ';
		preorderTraversal(n->lhs);
		preorderTraversal(n->rhs);
	}

    void inorderTraversal(Node<T>* n)
    {
        if (n == NULL)
            return;
        preorderTraversal(n->lhs);
        std::cout << n->value << ' ';
        preorderTraversal(n->rhs);
    }

    void postorderTraversal(Node<T>* n)
    {
        if (n == NULL)
            return;
        preorderTraversal(n->lhs);
        preorderTraversal(n->rhs);
        std::cout << n->n << ' ';
    }

    int treeHeight(Node<T>* n)
    {
        if (n == NULL)
        {
            return 0;
        }
        else 
        {
            int lhs_height = 
            intreeHeight(n->lhs);t rhs_height = treeHeight(n->rhs);

            if (lhs_height > rhs_height)
                return lhs_height + 1;
            else
                return rhs_height + 1;
        }
    }

    int treeNodeCount(Node<T>* n)
    {
        if (n == NULL) 
        {
            return 0;
        }
        return 1 + treeNodeCount(n->lhs) + treeNodeCount(n->rhs);
    }

    /*
        Code Taken from
        https://www.geeksforgeeks.org/print-level-order-traversal-line-line/
    */

    int treeLeavesCount(Node<T>* n)
    {
        if (n == NULL)
        {
            return 0;
        }

        if (!n->lhs && !n->rhs)
        {
            return 1;
        }
        else
        {
            return treeLeavesCount(n->lhs) + treeLeavesCount(n->rhs);
        }
    }

    void printGivenLevel(Node<T>* n, int lvl)
    {
        if (n == NULL)
        {
            return;
        }
        if (lvl == 1)
        {
            std::cout << " " << n->data;
        }
        else if (lvl > 1) {
            printGivenLevel(n->lhs, lvl - 1);
            printGivenLevel(n->rhs, lvl - 1);
        }
    }

    void printNodeLevel(Node<T>* n)
    {
        int height = treeHeight(n);
        int i;
        for (i = 1; i <= height; i++)
        {
            printGivenLevel(n, i);
            std::cout << std::endl;
        }
    }

    void ConvertIntoMirror(Node<T>* node)
    {
        if (node == NULL)
        {
            return;
        }
        else {
            Node<T>* temp;

            ConvertIntoMirror(node->lhs);
            ConvertIntoMirror(node->rhs);

            temp = node->lhs;
            node->lhs = node->rhs;
            node->rhs = temp;
        }
    }

    Node<T>* ConvertSortedArrayToTree(int* arr, int s_offset, int e_offset)
    {
        if (s_offset > e_offset)
        {
            return NULL;
        }

        int m_offset = (s_offset + e_offset) / 2;

        Node<T>* root = new Node<T>();
        root->value = arr[m_offset];
        root->lhs = ConvertSortedArrayToTree(arr, s_offset, m_offset - 1);
        root->rhs = ConvertSortedArrayToTree(arr, m_offset + 1, e_offset);
        return root;
    }

    int calculateSum(Node<T>* n)
    {
        int sum_left = 0, sum_right = 0;

        if (n == NULL)
        {
            return 0;
        }
        else
        {

            if (n->lhs)
            {
                sum_left = calculateSum(n->lhs);
            }

            if (n->rhs)
            {
                sum_right = calculateSum(n->rhs);
            }

            return n->value + sum_left + sum_right;
        }
    }

    void convertToGreaterTree(Node<T>* n, int* sum)
    {
        if (n == NULL)
        {
            return;
        }

        convertToGreaterTree(n->rhs, sum);
        *sum += n->value;
        n->value = *sum;
        convertToGreaterTree(n->lhs, sum);
    }
public:
	BST();
    void Insert(T value);
    void DeleteKey(T key);
	bool SearchKey(T key);
	int findMax();
	int findMin();
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();
	void printNodeLevel();
    //  Task2, Extra Function
    void ConvertIntoMirror();
    //  Task3, Extra Function
    void ConvertSortedArrayToTree(int* arr, int size);
    //  Task4, Extra Function
    int calculateSum();
    //  Task5, Extra Function
    void convertToGreaterTree();
};

template <class T>
BST<T>::BST()
{
    Tree = NULL;
}

template <class T>
void BST<T>::Insert(T value)
{
    Node<T>* node = new Node<T>();
    node->value = value;
    node->lhs = NULL;
    node->rhs = NULL;

    if (Tree == NULL)
    {
        Tree = node;
    }
    else
    {
        Node<T>* temp = Tree;
        Node<T>* prev = NULL;
        while (temp != NULL)
        {
            if (value < temp->value)
            {
                prev = temp;
                temp = temp->lhs;
            }
            else if (value > temp->value)
            {
                prev = temp;
                temp = temp->rhs;
            }
            else
            {
                printf("Duplicate not allowed...\n");
                return;
            }
        }
        if (value < prev->value)
            prev->lhs = node;
        else if (value > prev->value)
            prev->rhs = node;
    }
}

template <class T>
void BST<T>::DeleteKey(T key)
{
    DeleteKey(Tree, key);
}

template <class T>
bool BST<T>::SearchKey(T key)
{
    bool status = SearchKey(Tree, key);
/*    if (status)
    {
        std::cout << "BST<T>::SearchKey(" << key << "), exists..." << std::endl;
    }
    else
    {
        std::cout << "BST<T>::SearchKey(" << key << "), not exists..." << std::endl;
    }*/
    return status;
}

template <class T>
int BST<T>::findMax()
{
    return findMax(Tree);
}

template <class T>
int BST<T>::findMin()
{
    return findMin(Tree);
}

template <class T>
void BST<T>::inorderTraversal()
{
    inorderTraversal(Tree);
}

template <class T>
void BST<T>::preorderTraversal()
{
    preorderTraversal(Tree);
}

template <class T>
void BST<T>::postorderTraversal()
{
    postorderTraversal(Tree);
}

template <class T>
int BST<T>::treeHeight()
{
    return treeHeight(Tree);
}

template <class T>
int BST<T>::treeNodeCount()
{
    return treeNodeCount(Tree);
}

template <class T>
int BST<T>::treeLeavesCount()
{
    return treeLeavesCount(Tree);
}

template <class T>
void BST<T>::printNodeLevel()
{
    printNodeLevel();
}

template <class T>
void BST<T>::ConvertIntoMirror()
{
    ConvertIntoMirror(Tree);
}

template <class T>
void BST<T>::ConvertSortedArrayToTree(int* arr, int size)
{
    Tree = ConvertSortedArrayToTree(arr, 0, size - 1);
}

template <class T>
int BST<T>::calculateSum()
{
    return calculateSum(Tree);
}

template <class T>
void BST<T>::convertToGreaterTree()
{
    int dummy = 0;
    convertToGreaterTree(Tree, &dummy);
}

