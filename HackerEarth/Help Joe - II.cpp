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
    int n,m;
    cin>>n>>m;
    set<long long int>s;
    for (int i = 0; i < n; i++)
    {
        long long int a;
        cin>>a;
        a=a%m;
        s.insert(a);
    }
    int q;
    cin>>q;
    vector<long long int>v(q);
    for (int i = 0; i < q; i++)
    {
        cin>>v[i];
        v[i]=v[i]%m;
        int d=m-v[i]-1;
        auto it=s.upper_bound(d);
        if (it!=s.begin())
        {
            it--;
        }
        else
        {
            it=s.upper_bound(m);
            it--;
        }
        auto t=s.end();
        t--;
        int ans=max(((*(it)+v[i])%m),((*(t)+v[i])%m));
        cout<<ans<<endl;
    } 
    return 0;
}
