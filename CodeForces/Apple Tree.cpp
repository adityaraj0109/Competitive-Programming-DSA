#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>graph[n+1];
        for (int i = 1; i < n; i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
        int q;
        cin>>q;
        vector<pair<int,int>>nodes;
        for (int i = 0; i < q; i++)
        {
            int x,y;
            cin>>x>>y;
            nodes.push_back({x,y});
        }
        vector<int>leafnode(n+1,0);
        int count=0;
        for (int i = 1; i <=n; i++)
        {
            if(graph[i].size()==0){
                count++;
                leafnode[i]=1;
            }
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            int x=nodes[i].first;
            int y=nodes[i].second;
            int val1=1,val2=1;
            if(!leafnode[x]){
                val1=count;
            }
            if(!leafnode[y]){
                val2=count;
            }
            cout<<val1*val2<<endl;
        }
    }
    return 0;
}
