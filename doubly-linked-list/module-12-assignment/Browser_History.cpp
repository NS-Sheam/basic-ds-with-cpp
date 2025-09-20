#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
};

void print_backward(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_at_tail(Node *&head, Node *&tail, string val)
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string val;
    while (true)
    {
        cin >> val;
        if (val == "end")
            break;
        insert_at_tail(head, tail, val);
    }
    int q;
    cin >> q;
    Node *tmp = head;
    while (q--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "visit")
        {
            string address;
            cin >> address;
            Node *tmp2 = head;
            while (tmp2 != NULL)
            {
                if (tmp2->val == address)
                {
                    cout << tmp2->val << endl;
                    tmp = tmp2;
                    break;
                }
                tmp2 = tmp2->next;
            }
            if (tmp2 == NULL)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (cmd == "next")
        {
            if (tmp->next == NULL)
                cout << "Not Available" << endl;
            else
            {
                tmp = tmp->next;
                cout << tmp->val << endl;
            }
        }
        else if (cmd == "prev")
        {
            if (tmp->prev == NULL)
                cout << "Not Available" << endl;
            else
            {
                tmp = tmp->prev;
                cout << tmp->val << endl;
            }
        }
    }

    // print_forward(head);
    return 0;
}
