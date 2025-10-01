#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int getFourthLargest(int arr[], int n)
{
    // Write your code here.
    sort(arr, arr + n, greater<int>());

    if (n >= 4)
        return arr[3];
    return INT_MIN;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = getFourthLargest(arr, n);
    cout << ans << endl;

    return 0;
}