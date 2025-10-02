#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int total = 0;

        while (x > 0 || y > 0)
        {
            if (y >= 2)
            {
                y -= 2;
                x -= 7;
            }
            else if (y > 0)
            {
                y -= 1;
                x -= 11;
            }
            else
            {
                x -= 15;
            }
            total++;
        }

        cout << total << endl;
    }

    return 0;
}