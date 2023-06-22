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


    int dijkstra(int source,vector<vector<int>> &times, int n){
        vector<pair<int,int>>graph[n+1];
        for (auto it : times)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        vector<int>visited(n+1,0);
        vector<int>distance(n+1,INT_MAX);
        set<pair<int,int>>s;
        s.insert({0,source});
        distance[source]=0;
        int ans=0;
        while(!s.empty()){
            auto node=*s.begin();
            int x=node.first;
            int y=node.second;
            s.erase(node);
            if (visited[y])
            {
                continue;
            }
            visited[y]=1;
            for (auto child : graph[y]){
                int child_v=child.first;
                int wt=child.second;
                if (distance[y]+wt< distance[child_v])
                {
                    distance[child_v]=distance[y]+wt;
                    s.insert({distance[child_v],child_v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (distance[i]==INT_MAX)
            {
                return -1;
            }
            ans=max(ans,distance[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int ans=dijkstra(k,times,n);
        return ans;
    }

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
