#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{

    if (s.length() != t.length())
        return false;
    map<char, int> mpS;
    map<char, int> mpT;

    for (int i = 0; i < s.length(); i++)
    {
        mpS[s[i]]++;
        mpT[t[i]]++;
    }
    return mpS == mpT;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << (isAnagram(s, t) ? "Yes" : "No");

    return 0;
}