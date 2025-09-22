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
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
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
    void pop()
    {

        sz--;
        Node *deleted_node = head;
        // cout << "delted node " << deleted_node->val << " ";
        head = head->next;
        delete deleted_node;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }
    int front()
    {
        return head->val;
    }
    int back()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return head == NULL;
    }
};
int main()
{

    myQueue q;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    // cout << "front " << q.front() << " back " << q.back() << " size " << q.size() << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    // cout << "front " << q.front() << " back " << q.back() << " size " << q.size() << endl;

    return 0;
}