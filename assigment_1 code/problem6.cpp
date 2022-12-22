#include <iostream>
#include <string>

using namespace std;

#define IS_VOWEL(c) ( \
		c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || \
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' )

struct Node
{
	char data;
	Node* next, * prev;
};

void Insert(Node*& head, char value)
{
    Node* node = new Node();
    node->data = value;

    if (head == NULL)
    {
        node->next = node;
        node->prev = node;
        head = node;
    }
    else
    {
        Node* last = head->prev;
        node->next = head;
        head->prev = node;
        node->prev = last;
        last->next = node;
    }
}

void Insert(Node*& head, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        Insert(head, str[i]);
    }
}

void DisplayList(Node*& head)
{
    Node* ptr = head;
    cout << "[ ";
    if (ptr != NULL)
    {
        do
        {
            cout << ptr->data;
            ptr = ptr->next;
        } while (ptr != head);
    }
    cout << " ]" << endl;
}

void PigLatin(Node*& head, string str)
{
    Insert(head, str);
    char c = head->data;
    if (IS_VOWEL(c))
    {
        Insert(head, "-way");
        return;
    }

    Node* ptr = head;
    bool has_vowel = false;
    do
    {
        c = ptr->data;
        if (IS_VOWEL(c))
        {
            has_vowel = true;
            break;
        }
        if (has_vowel)
            break;
        ptr = ptr->next;
    } while (ptr != head);

    if (!has_vowel) 
    {
        Insert(head, "-way");
        return;
    }

    Insert(head, '-');
    ptr = head;
    do
    {
        c = ptr->data;
        if (IS_VOWEL(c))
        {
            head = ptr;
            Insert(head, "ay");
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    Node* node = NULL;

    cout << "Running Test case for: eye\nResult: ";
    PigLatin(node, "eye");
    DisplayList(node);
    cout << endl;

    Node* node2 = NULL;
    cout << "Running Test case for: There\nResult: ";
    PigLatin(node2, "There");
    DisplayList(node2);
    cout << endl;

    Node* node3 = NULL;
    cout << "Running Test case for: 1234\nResult: ";
    PigLatin(node3, "1234");
    DisplayList(node3);
    cout << endl;

	system("PAUSE");
	return 0;
}
