#include<bits/stdc++.h>
using namespace std;
int main(){
    // vector<int> v(5);
    // cout << v.size() << endl;
    // vector<int> v(10, -1);
    // vector<int> v1(v);
    // cout << v1.size() << endl;
    int a[5]= {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}