#include <bits/stdc++.h>
using namespace std;

void input_stack(stack<int> &st, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
}
void input_queue(queue<int> &q, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
}
void print_stack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
    }
    cout << endl;
}

bool isSame(stack<int> st, queue<int> q)
{
    if (st.size() != q.size())
        return false;

    while (!st.empty())
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

    stack<int> st;
    queue<int> q;

    input_stack(st, n);
    input_queue(q, m);

    cout << ((isSame(st, q)) ? "YES" : "NO");

    return 0;
}