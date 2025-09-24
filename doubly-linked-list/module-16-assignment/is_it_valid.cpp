#include <bits/stdc++.h>
using namespace std;

void input_stack(stack<char> &st, int n)
{
    while (n--)
    {
        char val;
        cin >> val;
        st.push(val);
    }
}

void print_stack(stack<char> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

bool isValid(string s)
{
    stack<char> st;
    stack<char> st2;
    for (char c : s)
    {
        st.push(c);
    }
    while (!st.empty())
    {
        if (!st2.empty() && ((st.top() == '1' && st2.top() == '0') || (st.top() == '0' && st2.top() == '1')))
        {
            st.pop();
            st2.pop();
        }
        else
        {
            st2.push(st.top());
            st.pop();
        }
    }

    return st2.empty();
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        cout << (isValid(s) ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}