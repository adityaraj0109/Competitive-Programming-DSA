#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    debugMode();
    int n;
    cin>>n;
    map<int,multiset<string>>m;
    for (int i = 0; i < n; i++)
    {
        int num;
        string s;
        cin>>s>>num;
        m[-num].insert(s);
    }
    for(auto &it:m){
        auto &f=it.first;
        auto &s=it.second;
        for(auto &i:s){
            cout<<i<<" "<<-f<<endl;
        }
    }
    return 0;
}
