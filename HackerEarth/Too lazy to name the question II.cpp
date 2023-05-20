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
    vector<pair<int,int>>v(n);
    set<pair<int,int>>s;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].first>>v[i].second;
        s.insert(v[i]);
    }
    int area=-1,minimum=INT_MAX,maximum=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            if (v[i].first!=v[j].first && v[i].second!=v[j].second)
            {
                if (s.count({v[i].first,v[j].second}) && s.count({v[j].first,v[i].second}))
                {
                    area=abs((v[i].first-v[j].first)*(v[i].second-v[j].second));
                    minimum=min(minimum,area);
                    maximum=max(maximum,area);
                }
            }
        }
    }
    if(area==-1){
        cout<<-1<<endl;
    }
    else{
        cout<<maximum-minimum<<endl;
    }
    return 0;
}
