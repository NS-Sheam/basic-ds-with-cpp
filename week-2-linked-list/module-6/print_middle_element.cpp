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
int main()
{
    Node *head = new Node(2);
    Node *a = new Node(4);
    Node *b = new Node(6);
    Node *c = new Node(8);
    Node *d = new Node(10);
    Node *e = new Node(12);
    Node *f = new Node(14);
    // Node *g = new Node(16);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    // f->next = g;

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        cout << fast << endl;
        // cout << "slow: " << slow->val << ", fast: " << fast->val << " " << fast->next->val << endl;
    }

    if (fast)
    {
        cout << "The middle element is " << slow->val << endl;
    }
    else
    {
        cout << "The middle element is " << prev->val << " and " << slow->val << endl;
    }

    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // }
}
// 2 4 6 8 10 // printing the middle element of a linked list
// The middle element is 6