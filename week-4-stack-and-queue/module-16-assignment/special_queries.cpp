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

int main()
{
    int n;
    cin >> n;

    queue<string> q;

    while (n--)
    {
        int btn;
        cin >> btn;
        if (btn == 0)
        {
            string name;
            cin >> name;
            q.push(name);
        }
        else
        {
            if (q.empty())
            {
                cout << "Invalid";
            }
            else
            {
                cout << q.front();
                q.pop();
            }
            cout << endl;
        }
    }

    return 0;
}