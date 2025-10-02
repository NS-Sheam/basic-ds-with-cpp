#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    return s.size() != nums.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    cout << (containsDuplicate(v) ? "Contain Duplicate" : "Not Containingg");

    return 0;
}