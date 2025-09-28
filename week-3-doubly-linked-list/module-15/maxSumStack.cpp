#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int sumOfStack(stack<int> st)
{
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}

int maxSum(stack<int> &st1, stack<int> &st2, stack<int> &st3)
{
    // Write your code here
    int sum1 = sumOfStack(st1);
    int sum2 = sumOfStack(st2);
    int sum3 = sumOfStack(st3);

    while (!(sum1 == sum2 && sum2 == sum3))
    {
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= st1.top();
            st1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= st2.top();
            st2.pop();
        }
        else if (sum3 >= sum1 && sum3 >= sum2)
        {
            sum3 -= st3.top();
            st3.pop();
        }
    }
    return sum1;
    return 0;
}

void input_stack(stack<int> &st, int n)
{
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
}

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    input_stack(st, n);
    stack<int> st2;
    cin >> n;
    input_stack(st2, n);
    stack<int> st3;
    cin >> n;
    input_stack(st3, n);
    cout << maxSum(st, st2, st3) << endl;

    // print_stack(st);

    return 0;
}