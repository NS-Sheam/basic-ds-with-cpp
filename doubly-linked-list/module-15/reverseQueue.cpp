#include <bits/stdc++.h>
using namespace std;

void input_queue(queue<int> &q, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
}
void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    print_queue(q);
    return q;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        queue<int> q;
        int m;
        cin >> m;
        input_queue(q, m);
        // print_queue(q);
        reverseQueue(q);
    }
    return 0;
}
