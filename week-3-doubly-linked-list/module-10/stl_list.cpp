#include <bits/stdc++.h>
using namespace std;
int main()
{
    // list<int> l;
    // list<int> l(10);
    // list<int> l(10, 3);
    list<int> l = {1, 2, 3, 4, 5};
    // list<int> l2(l);
    // int a[] = {10, 20, 30};
    // list<int> l2(a, a + 3);
    vector<int> v = {10, 20, 30};
    list<int> l2(v.begin(), v.end());
    // cout << l.max_size() << endl; // Output the maximum size of the list

    cout << l.size() << endl;   // Output the size of the list
    cout << *l.begin() << endl; // Output the first element of the list
    // for (auto it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    l.clear();
    if (l.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "List is not empty" << endl;
    }
    // l2.resize(2);
    l2.resize(5, 100); // Resize the list to 5 elements, filling with 100 if needed
    for (int val : l2)
    {
        cout << val << " ";
    }
    return 0;
}