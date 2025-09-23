#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    if (st.size() != q.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    while (!q.empty())
    {
        if (q.front() != st.top())
        {
            cout << "NO" << endl;
            return 0;
        }
        q.pop();
        st.pop();
    }
    cout << "YES" << endl;

    return 0;
}