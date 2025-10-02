#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    mp["sakib"] = 7;
    mp["sania"] = 8;
    mp["rakib"] = 20;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    if (mp.count("akib"))
    {
        cout << "Ache" << endl;
    }
    else
        cout << "Nai" << endl;

    return 0;
}