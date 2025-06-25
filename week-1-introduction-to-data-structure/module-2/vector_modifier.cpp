#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 2, 6, 2};
    vector<int> v2 = {100, 200, 300};
    // v2 = v;
    // v2.insert(v2.begin() + 2, 100);
    // v.insert(v.begin() + 2, v2.begin(), v2.end());
    // v.erase(v.begin()+1, v.begin()+5);
    // replace(v.begin(), v.end()-1, 2, 1000);
    auto it = find(v.begin(), v.end(), 6); // find the first occurrence of 6
    // if(it != v.end()){
    //     cout << "Element found at index: " << distance(v.begin(), it) << endl;
    // } else {
    //     cout << "Element not found" << endl;
    // }
    // for(int x: v){
    //     cout << x << " ";
    // }
    cout << *it << endl;
    return 0;
}