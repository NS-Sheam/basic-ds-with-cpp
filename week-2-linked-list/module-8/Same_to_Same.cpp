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

int main()
{
    int val;
    Node *headA = NULL;
    Node *tailA = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Node *new_node = new Node(val);
        if (headA == NULL)
        {
            headA = new_node;
            tailA = new_node;
        }
        else
        {
            tailA->next = new_node;
            tailA = new_node;
        }
    }
    Node *headB = NULL;
    Node *tailB = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Node *new_node = new Node(val);
        if (headB == NULL)
        {
            headB = new_node;
            tailB = new_node;
        }
        else
        {
            tailB->next = new_node;
            tailB = new_node;
        }
    }
    Node *tmpA = headA;
    Node *tmpB = headB;
    bool same = true;
    while (tmpA != NULL && tmpB != NULL)
    {
        if (tmpA->val != tmpB->val)
        {
            same = false;
            break;
        }
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    if (same && tmpA == NULL && tmpB == NULL)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}