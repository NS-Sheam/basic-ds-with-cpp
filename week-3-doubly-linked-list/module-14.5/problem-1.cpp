#include <bits/stdc++.h>
using namespace std;

void insert_into_stack(stack<int> &st, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        // cout << val << " n ";
        st.push(val);
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

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    insert_into_stack(st, n);
    print_stack(st);
    stack<int> st2;
    int m;
    cin >> m;
    insert_into_stack(st2, m);
    print_stack(st2);

    return 0;
}