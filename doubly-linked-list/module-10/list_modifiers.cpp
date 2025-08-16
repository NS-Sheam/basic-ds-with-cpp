#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l = {10, 20, 30, 40, 50};
    list<int> l2 = {80, 90, 100};
    // l2 = l;
    // l2.assign(l.begin(), l.end());

    l.push_back(60);    // Add an element to the end of the list
    l.push_front(5);    // Add an element to the front of the list
    l.pop_back();       // Remove the last element of the list
    l.pop_front();      // Remove the first element of the list
    next(l.begin(), 2); // Get an iterator to the third element of the list
    // cout << *next(l.begin(), 2) << endl; // Output the third element of the list
    // l.insert(next(l.begin(), 2), 35);
    // l.insert(next(l.begin(), 2), 35);
    l.insert(next(l.begin(), 2), l2.begin(), l2.end());
    // l.erase(next(l.begin(), 2), next(l.begin(), 4)); // Remove elements from the third to the fifth
    replace(l.begin(), l.end(), 30, 80); // Replace all occurrences of 30 with 80
    auto it = find(l.begin(), l.end(), 200);
    if (it != l.end())
    {
        cout << "Found 200" << endl;
    }
    else
    {
        cout << "200 not found" << endl;
    }
    for (int val : l)
    {
        cout << val << " ";
    }
    return 0;
}