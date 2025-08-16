#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l = {10, 20, 30, 40, 50, 10, 50, 60, 10, 20};
    // l.remove(10); // Remove all occurrences of 10 from the list
    l.sort(greater<int>()); // Sort the list
    l.unique();             // Remove consecutive duplicate elements
    l.reverse();            // Reverse the order of the list

    for (int val : l)
    {
        cout << val << " ";
    }
    return 0;
}