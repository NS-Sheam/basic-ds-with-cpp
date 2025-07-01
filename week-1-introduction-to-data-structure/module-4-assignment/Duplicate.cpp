#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int isDuplicate = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 1)
            break;
    }
    cout << ((isDuplicate == 1) ? "YES" : "NO") << endl;
    return 0;
}