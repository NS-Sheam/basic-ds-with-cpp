#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (q--)
    {
        int x;
        cin >> x;
        int left = 0, right = n - 1;
        bool found = false;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (v[mid] == x)
            {
                found = true;
                break;
            }
            else if (v[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << (found ? "found" : "not found") << endl;
    }
    return 0;
}