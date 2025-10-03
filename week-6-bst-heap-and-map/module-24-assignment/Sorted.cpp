#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        list<int> l;
        while (n--)
        {
            int val;
            cin >> val;
            l.push_back(val);
        }
        l.sort();
        l.unique();

        for (auto it = l.begin(); it != l.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}