#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> tmpStack;
    while (!myStack.empty())
    {
        tmpStack.push(myStack.top());
        myStack.pop();
    }
    tmpStack.push(x);
    while (!tmpStack.empty())
    {
        myStack.push(tmpStack.top());
        tmpStack.pop();
    }
    return myStack;
}

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    // print_stack(st);
    pushAtBottom(st, 9);
    return 0;
}