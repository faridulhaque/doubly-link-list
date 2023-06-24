#include <iostream>
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

void insert_tail(Node *&head, Node * & tail, int v)
{
    Node *newNode = new Node(v);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

   tail->next = newNode;  
   newNode-> prev = tail;  
   tail = newNode;
}

int comp_nodes(Node *head_1, Node *head_2, int c_head_1, int c_head_2)
{
    int flag = 1;

    if (c_head_1 != c_head_2)
    {
        return 0;
    }

    while (head_1 != NULL)
    {
        if (head_1->value != head_2->value)
        {
            flag = 0;
            break;
        }

        head_1 = head_1->next;
        head_2 = head_2->next;
    }

    return flag;
}

int main()
{
    Node *head_1 = NULL;
    Node *head_2 = NULL;


    Node *tail_1 = NULL;
    Node *tail_2 = NULL;

    int c_head_1 = 0;
    int c_head_2 = 0;

    while (true)
    {
        int v;
        cin >> v;
        c_head_1++;

        if (v == -1)
        {
            break;
        }

        insert_tail(head_1, tail_1, v);
    }

    while (true)
    {
        int v;
        cin >> v;
        c_head_2++;

        if (v == -1)
        {
            break;
        }

        insert_tail(head_2, tail_2, v);
    }

    int flag = comp_nodes(head_1, head_2, c_head_1, c_head_2);

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
