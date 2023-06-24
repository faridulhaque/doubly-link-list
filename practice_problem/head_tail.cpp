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

void insert_head(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insert_postion(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);

    Node *temp = head;

    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
}

void print_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
}

void print_reverse(Node *head)
{

    if (head == NULL)
    {

        return;
    }

    cout << head->value << " ";

    print_reverse(head->next);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    int size = 0;

    std::cin >> q;

    int p_ok = true;

    for (int i = 0; i < q; i++)
    {
        int pos;
        int v;
        cin >> pos >> v;

        // std::cout<<pos<<endl;

        if (pos == 0)
        {
            insert_head(head, tail, v);
            size++;
            p_ok = true;

        }
        else if (pos == size)
        {
            insert_tail(head, tail, v);
            size++;
            p_ok = true;

        }

        else if (pos > size)
        {
            std::cout << "invalid" << endl;
            p_ok = false;

        }

        else
        {
            insert_postion(head, pos, v);
            size++;
            p_ok = true;

        }

        if (p_ok)
        {
            print_list(head);
            std::cout << endl;
            print_reverse(head);
            std::cout << endl;
        }
    }

    return 0;
}