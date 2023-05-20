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

bool comparator(pair<pair<int,int>,int>x,pair<pair<int,int>,int>y){
    int sum1=x.first.first+x.first.second;
    int sum2=y.first.first+y.first.second;
    if (sum1==sum2)
    {
        return y.first.first>x.first.first;
    }
    return sum1<sum2;
}

int main()
{
    debugMode();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<pair<pair<int,int>,int>>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i].first.first>>v[i].first.second;
            v[i].second=i;
        }
        sort(v.begin(),v.end(),comparator);
        vector<int>vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[v[i].second]=i;
        }
        for (int i = 0; i < n; i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
