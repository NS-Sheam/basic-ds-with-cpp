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

void removeDuplicate(Node *head)
{
    for (Node *tmp1 = head; tmp1 != NULL; tmp1 = tmp1->next)
    {
        Node *tmp2 = tmp1;
        while (tmp2->next != NULL)
        {
            if (tmp1->val == tmp2->next->val)
            {
                Node *dup = tmp2->next;
                tmp2->next = tmp2->next->next;
            }
            else
            {
                tmp2 = tmp2->next;
            }
        }
    }
};

void orderList(Node *head)
{

    for (Node *tmp1 = head; tmp1 != NULL; tmp1 = tmp1->next)
    {
        for (Node *tmp2 = tmp1->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (tmp2->val < tmp1->val)
            {
                int tmp = tmp1->val;
                tmp1->val = tmp2->val;
                tmp2->val = tmp;
            }
        }
    }
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

    // cout << "Original Linked List : ";
    // print_linked_list(head);
    removeDuplicate(head);
    // cout << endl;
    orderList(head);
    // cout << "After delete : " << endl;
    print_linked_list(head);

    return 0;
}