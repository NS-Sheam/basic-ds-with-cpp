#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
    tail = new_node;
}

void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val, pos;
        cin >> pos >> val;
        Node *new_node = new Node(val);
        if (pos == 0)
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
            print_forward(head);
        }
        else
        {
            Node *tmp = head;
            for (int j = 1; j < pos && tmp != NULL; j++)
            {
                tmp = tmp->next;
            }

            if (tmp == NULL)
            {
                cout << "Invalid position!" << endl;
                delete new_node;
                continue;
            }

            if (tmp->next == NULL)
            { // insert at tail
                tmp->next = new_node;
                new_node->prev = tmp;
                tail = new_node;
            }
            else
            { // insert in middle
                new_node->next = tmp->next;
                tmp->next->prev = new_node;
                new_node->prev = tmp;
                tmp->next = new_node;
            }
        }
        print_forward(head);
    }

    return 0;
}