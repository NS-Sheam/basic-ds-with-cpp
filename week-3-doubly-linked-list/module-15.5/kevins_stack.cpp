#include <bits/stdc++.h>
using namespace std;

string kevinStackProblem(string &s)
{
    // Write your code here.

    stack<char> st;
    for (char c : s)
    {
        st.push(c);
    }
    string s2;
    while (!st.empty())
    {
        s2 += st.top();
        st.pop();
    }
    cout << s2 << endl;

    return s2;
}

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        kevinStackProblem(s);
    }

    return 0;
}