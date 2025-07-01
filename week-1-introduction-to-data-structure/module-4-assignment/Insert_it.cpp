#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    vector<int> insert(m);
    for (int i = 0; i < m; i++)
    {
        cin >> insert[i];
    }
    int insertIndex;
    cin >> insertIndex;
    arr.insert(arr.begin() + insertIndex, insert.begin(), insert.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}