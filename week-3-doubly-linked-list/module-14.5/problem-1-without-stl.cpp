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

class myStack
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
            head = tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    void pop()
    {
        sz--;
        Node *deleted_node = tail;
        tail = tail->prev;
        delete deleted_node;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    int empty()
    {
        return head == NULL;
    }
};

void insert_into_stack(myStack &st, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        // cout << val << " n ";
        st.push(val);
    }
}

void print_stack(myStack &st)
{
    Node *tmp = st.tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

bool isSame(myStack st1, myStack st2)
{
    cout << " size " << st1.size() << " st " << st2.size() << endl;
    if (st1.size() != st2.size())
        return false;
    while (!st1.empty())
    {
        if (st1.top() != st2.top())
            return false;
        st1.pop();
        st2.pop();
    }

    return true;
}

int main()
{
    myStack st;
    int n;
    cin >> n;
    insert_into_stack(st, n);
    print_stack(st);
    myStack st2;
    int m;
    cin >> m;
    insert_into_stack(st2, m);
    print_stack(st2);
    cout << (isSame(st, st2) ? "YES" : "NO");

    return 0;
}