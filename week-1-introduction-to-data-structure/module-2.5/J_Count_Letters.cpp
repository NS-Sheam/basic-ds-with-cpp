#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for (char c : s)
    {
        count[tolower(c) - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << char('a' + i) << " : " << count[i] << endl;
        }
    }

    return 0;
}