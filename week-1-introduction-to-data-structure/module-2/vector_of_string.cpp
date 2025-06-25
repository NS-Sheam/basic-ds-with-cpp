#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // cin.ignore();
    // vector<string> v(n);
    // for(int i = 0; i < n; i++){
    //     getline(cin, v[i]);
    // }
    // for(string s : v){
    //     cout << s << " ";
    // }
    // cout << endl;
    //     int a[4] = {12,13,14,15};
    // vector<int> v(a, a+4);
    //     for(int x : v){
    //         cout << x << " ";
    //     }
    // vector<int> v = {1, 2, 3, 4};
    // v.resize(2);
    // v.resize(4);
    // for (int x : v)
    // {
    //     cout << x << " ";
    // }
    // Which is the right code for inserting 20 in index 3?

    // v.insert(v.begin() + 2, 20);

    vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 2, v.end());
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}