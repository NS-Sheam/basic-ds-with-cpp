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

void delete_at_index(Node *&head, Node *&tail, int idx)
{
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    int listSize = sz(head);
    // cout << idx << " idx " << endl;
    if (idx < 0 || idx >= listSize)
    {
        return;
    }
    if (idx == 0)
    {
        Node *toDelete = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete toDelete;
    }
    else if (idx == listSize - 1)
    {
        Node *toDelete = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        delete toDelete;
    }
    else
    {
        Node *tmp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            tmp = tmp->next;
        }
        Node *toDelete = tmp->next;
        tmp->next = toDelete->next;
        toDelete->next->prev = tmp;
        delete toDelete;
    }
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
        if (x == 0)
        {

            Node *new_node = new Node(v);
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
        else if (x == 1)
        {
            Node *new_node = new Node(v);
            if (tail == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }
        else if (x == 2)
            delete_at_index(head, tail, v);
        print_forward(head);
        print_backward(tail);
    }

    return 0;
}
