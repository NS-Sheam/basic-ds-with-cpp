#include <bits/stdc++.h>
using namespace std;

// int lastStoneWeight(vector<int> &stones)
// {
//     int totalSize = stones.size() - 1;

//     while (totalSize > 0)
//     {
//         sort(stones.begin(), stones.end());
//         if (stones[totalSize] == stones[totalSize - 1])
//         {
//             stones.pop_back();
//             stones.pop_back();
//             totalSize -= 2;
//         }
//         else if (stones[totalSize] > stones[totalSize - 1])
//         {
//             int substract = stones[totalSize] - stones[totalSize - 1];
//             stones.pop_back();
//             stones.pop_back();
//             stones.push_back(substract);
//             totalSize--;
//         }
//     }
//     if (!stones.size())
//         return 0;
//     else
//         return stones[0];
// }
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); i++)
    {
        pq.push(stones[i]);
    }

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (x != y)
            pq.push(y - x);
    }
    return pq.empty() ? 0 : pq.top();
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    int l = lastStoneWeight(v);
    cout << l << " ans";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    //     // cout << v[i] << " ";
    // }

    return 0;
}