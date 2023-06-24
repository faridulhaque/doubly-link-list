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

void delete_position(Node *&head, int pos)
{
    Node *dNode;
    Node *temp = head;

    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    dNode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete dNode;
}


void delete_head(Node *& head, Node * &tail) {
    Node * dNode = head;
    head = head->next;
    delete dNode;

    if(head == NULL){
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void delete_tail(Node *&head, Node *& tail){
    Node * dNode = tail;
    tail = tail->prev;
    delete dNode;
    if(tail == NULL){
        head = NULL; 
        return;
    }
    tail->next = NULL;
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

    int pos;
    cin >> pos;



    if (pos == 0)
    {
        delete_head(head, tail);
    }
    else if (pos == size -1)

    {
      
        delete_tail(head, tail);
    }

    else if (pos >= size)
    {
        cout << "wrong input" << endl;
    }

    else
    {
     delete_position(head, pos);  
    }

    print_list(head);
    cout << endl;

    return 0;
}