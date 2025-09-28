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
    // Node *head = new Node(5);
    // Node *a = new Node(4);
    // Node *b = new Node(8);
    // Node *c = new Node(6);
    // Node *d = new Node(2);
    // Node *e = new Node(1);
    Node *head = new Node(2);
    Node *a = new Node(4);
    Node *b = new Node(5);
    Node *c = new Node(6);
    Node *d = new Node(7);
    Node *e = new Node(4);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node *temp = head;
    bool is_duplicate = false;
    while (temp != NULL)
    {

        Node *check = head;
        while (check != temp)
        {
            if (check->val == temp->val)
            {
                is_duplicate = true;
                break;
            }
            check = check->next;
        }

        temp = temp->next;
    }

    cout << (is_duplicate ? "Duplicate found" : "No duplicates") << endl;

    return 0;
}

// 5 4 8 6 2 1
// 2 4 5 6 7 4