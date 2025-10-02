#include <bits/stdc++.h>
using namespace std;
int main()
{
    // priority_queue<int> pq; // maximum priority queue
    priority_queue<int, vector<int>, greater<int>> pq; // minimum priority queue
    pq.push(10);
    pq.push(5);
    pq.push(30);
    pq.push(20);

    cout << pq.top() << endl;
    // pq.push(50);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    return 0;
}