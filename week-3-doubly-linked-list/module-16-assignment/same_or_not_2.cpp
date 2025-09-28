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
    bool isEmpty()
    {
        return head == NULL;
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
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
        delete deleted_node;
    }
    int front()
    {
        return head->val;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

void input_stack(myStack &st, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
}
void input_queue(myQueue &q, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
}

void print_stack(myStack st)
{
    myStack tmp = st;
    while (!st.isEmpty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void print_queue(myQueue q)
{
    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

bool isSame(myStack &st, myQueue &q)
{

    // cout << " st top " << st.top() << " q front " << q.front() << endl;
    if (st.size() != q.size())
        return false;

    while (!st.isEmpty())
    {

        if (st.top() != q.front())
            return false;
        st.pop();
        q.pop();
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    myStack st;
    myQueue q;

    input_stack(st, n);
    input_queue(q, m);
    // cout << " st top " << st.top() << " q front " << q.front() << endl;

    // print_stack(st);
    // print_queue(q);

    cout << ((isSame(st, q)) ? "YES" : "NO");

    return 0;
}