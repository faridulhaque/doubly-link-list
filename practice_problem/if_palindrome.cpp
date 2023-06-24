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

int palindrome(Node *&head, Node *&tail, int s)
{

    int flag = 1;

    for (int i = 1; i <= s / 2; i++)
    {
        

        if (head->value != tail->value)
        {
            flag = 0;
            break;
            head=head->next;
            tail = tail->prev;
        }
    }

    return flag;
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

    int flag = palindrome(head, tail, size);

    if (flag)
    {
        printf("YES");
    }

    else
    {
        printf("NO");
    }

    return 0;
}