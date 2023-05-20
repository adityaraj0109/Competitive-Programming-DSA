#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<pair<int,int>>graph[100005];
vector<int>level(100005,INT_MAX);

int bfs(int n){
    deque<int>q;
    q.push_back(1);
    level[1] = 0;
    while(!q.empty()){
        int vertex = q.front();
        q.pop_front();
        for(auto child:graph[vertex]){
            int child_v=child.first;
            int wt=child.second;
            if(level[vertex]+wt<level[child_v]){
                level[child_v]=level[vertex]+wt;
                if (wt==1)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
    }
    if (level[n]==INT_MAX)
    {
        return -1;
    }
    return level[n];
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        if (x==y) continue;
        graph[x].push_back({y,0});
        graph[y].push_back({x,1});
    }
    int ans=bfs(n);
    cout<<ans<<endl;
    return 0;
}