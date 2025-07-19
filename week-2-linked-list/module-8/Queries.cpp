#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
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
    tail = tail->next;
}
int get_size(Node *head)
{
    int size = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}

void delete_at_head(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
    if (head == NULL)
    {
        tail = NULL;
    }
}
void delete_at_any(Node *&head, int idx)
{

    if (idx == 0)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        if (tmp == NULL)
            return;
        tmp = tmp->next;
    }
    if (tmp->next != NULL)
    {
        Node *toDelete = tmp->next;
        tmp->next = toDelete->next;
        delete toDelete;
    }
}
void delete_at_tail(Node *&head, Node *&tail)
{
    Node *tmp = head;
    if (tmp->next == NULL)
    {
        delete tmp;
        head = NULL;
        tail = NULL;
        return;
    }
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = NULL;
    tail = tmp;
}
int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *tail = NULL;
    while (n--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            int size = get_size(head);
            if (v == size - 1)
            {
                delete_at_tail(head, tail);
            }
            else if (v == 0)
            {
                delete_at_head(head, tail);
            }
            else if (v < size && v > 0)
            {
                delete_at_any(head, v);
            }
        }
        print_list(head);
    }
    return 0;
}