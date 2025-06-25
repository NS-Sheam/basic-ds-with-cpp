#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> word;
    // input the string
    string s;
    getline(cin, s);
    word.push_back(s);
    printf("The string is: %s\n", word[0].c_str());
    return 0;
}