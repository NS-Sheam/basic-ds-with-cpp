#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int> l, pair<string, int> r)
{

    if (l.first == r.first)
        return l.second > r.second;
    return l.first < r.first;
}
int main()
{
    int n;
    cin >> n;
    list<pair<string, int>> l;
    while (n--)
    {
        string name;
        int num;
        cin >> name >> num;
        l.push_back({name, num});
    }
    l.sort(cmp);

    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}