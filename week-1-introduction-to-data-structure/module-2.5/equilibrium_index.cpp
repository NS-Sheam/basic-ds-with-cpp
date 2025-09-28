#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }
    int equilibrium_index = -1;
    for (int i = 0; i < n; i++)
    {
        int left_sum = (i == 0) ? 0 : prefix_sum[i - 1];
        int right_sum = prefix_sum[n - 1] - prefix_sum[i];
        if (left_sum == right_sum)
        {
            equilibrium_index = i;
            break;
        }
    }
    cout << equilibrium_index << endl;
    return 0;
}