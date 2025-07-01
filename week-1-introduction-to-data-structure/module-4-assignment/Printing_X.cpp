
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (i == j && i == x / 2 && j == x / 2)
            {
                cout << "X";
            }
            else if (i == j)
            {
                cout << "\\";
            }
            else if (i + j == x - 1)
            {
                cout << "/";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}