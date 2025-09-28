#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print_forward(Node *head)
{
    Node *tmp = head;
    cout << "L -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
};

void print_backward(Node *tail)
{
    cout << "R -> ";
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

int sz(Node *head)
{
    Node *tmp = head;
    int listSize = 0;
    while (tmp != NULL)
    {
        listSize++;
        tmp = tmp->next;
    }

    return listSize;
};

void insert_at_index(Node *&head, Node *&tail, int idx, int val)
{
    int listSize = sz(head);
    if (idx > listSize)
    {
        cout << "Invalid" << endl;
        return;
    }
    Node *new_node = new Node(val);
    if (idx == 0)
    {
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    else if (idx == listSize)
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    else
    {
        Node *tmp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next->prev = new_node;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
    print_forward(head);
    print_backward(tail);
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    Node *tmp = head;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        insert_at_index(head, tail, x, v);
    }

    return 0;
}
