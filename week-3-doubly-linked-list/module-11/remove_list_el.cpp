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
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

Node *removeElements(Node *head, int val)
{
    if (head == NULL)
        return head;
    while (head->val == val)
    {
        head = head->next;
    }
    Node *tmp = head;
    while (tmp != NULL && tmp->next != NULL)
    {
        if (tmp->next->val == val)
        {
            tmp->next = tmp->next->next;
        }
        else
            tmp = tmp->next;
    }
    return head;
};

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    cout << "Original Linked List: ";
    print_linked_list(head);
    removeElements(head, 6);
    cout << endl;
    cout << "After remove List: ";
    print_linked_list(head);

    return 0;
}