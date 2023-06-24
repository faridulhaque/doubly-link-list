#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int v)
{

    Node *newNode = new Node(v);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;

        return;
    }
    tail->next = newNode;
    newNode->prev = tail;

    tail = newNode;
}

void print_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void insert_postion(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);

    Node *temp = head;

    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode -> next = temp-> next;
    newNode -> prev = temp;
    temp-> next = newNode;
}

void print_list_reverse(Node *tail)
{
    Node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int size = 0;

    while (true)
    {

        int v;
        cin >> v;

        if (v == -1)
        {
            break;
        }
        size++;
        insert_tail(head, tail, v);
    }

    print_list(head);

    int pos;
    int v;
    cin >> pos >> v;

    if (pos == 0)
    {
        cout << "it's for head" << endl;
    }
    else if (pos == size - 1)
    {
        insert_tail(head, tail, v);
    }

    else if (pos >= size)
    {
        cout << "wrong input" << endl;
    }

    else
    {
        insert_postion(head, pos, v);
    }

    print_list(head);
    cout << endl;
    print_list_reverse(tail);

    return 0;
}