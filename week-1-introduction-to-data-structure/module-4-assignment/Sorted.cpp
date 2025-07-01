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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int isSorted = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cout << "NO" << endl;
                isSorted = 0;
                break;
            }
        }
        if (isSorted)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}