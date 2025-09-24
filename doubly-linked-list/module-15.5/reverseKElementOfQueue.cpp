#include <bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.

    stack<int> st;
    queue<int> q2;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q2.push(st.top());
        st.pop();
    }
    while (!q.empty())
    {
        q2.push(q.front());
        q.pop();
    }

    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    return q;
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

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        queue<int> q;
        int m, k;
        cin >> m >> k;
        input_queue(q, m);
        reverseElements(q, k);
    }

    return 0;
}