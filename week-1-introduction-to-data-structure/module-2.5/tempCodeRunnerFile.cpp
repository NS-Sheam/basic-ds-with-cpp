#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
        int sum = 0;
        if (l == 1)
        {
            sum = prefix_sum[r - 1];
        }
        else
        {
            sum = prefix_sum[r - 1] - prefix_sum[l - 2];
        }
        cout << sum << endl;
    }
    return 0;
}