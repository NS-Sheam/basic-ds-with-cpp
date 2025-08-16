#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l = {10, 20, 30, 40, 50, 10, 50, 60, 10, 20};
    cout << l.back() << endl;            // Access the last element
    cout << l.front() << endl;           // Access the first element
    cout << *next(l.begin(), 2) << endl; // Access the third element using an iterator
    cout << *l.begin() << endl;          // Access the first element using an iterator

    cout << *prev(l.end(), 1) << endl; // Access the last element using an iterator
    return 0;
}