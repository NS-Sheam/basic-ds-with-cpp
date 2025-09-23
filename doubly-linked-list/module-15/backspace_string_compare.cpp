#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push_pop(stack<char> &st, string s)
    {
        for (char c : s)
        {
            if (c == '#')
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(c);
            }
        }
    }

    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> st2;
        push_pop(st, s);
        push_pop(st2, t);

        return st == st2;
    }
};

int main()
{
    Solution s;

    cout << s.backspaceCompare("ab##", "c#d#");
    return 0;
}