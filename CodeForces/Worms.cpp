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
    vector<int>v(n);
    cin>>v[0];
    for (int i = 1; i <n; i++)
    {
        cin>>v[i];
        v[i]=v[i]+v[i-1];
    }
    int m;
    cin>>m;
    vector<int>vec(m);
    for (int i = 0; i < m; i++)
    {
        cin>>vec[i];
    }
    for (int i = 0; i < m; i++)
    {
        auto it=lower_bound(v.begin(),v.end(),vec[i]);
        cout<<(it-v.begin())+1<<endl;
    }
    return 0;
}
