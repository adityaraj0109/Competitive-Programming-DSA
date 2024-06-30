#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, INT_MAX);
    vector<int>visited(V,0);
    set<pair<int,int>>s;
    distance[S]=0;
    s.insert({0,S});
    while(!s.empty()){
        auto p=*s.begin();
        int wt=p.first;
        int vertex=p.second;
        s.erase(s.begin());
        if(visited[vertex]){
            continue;
        }
        visited[vertex]=1;
        for(auto child:adj[vertex]){
            int y=child[0];
            int w=child[1];
            if(distance[vertex]+w<distance[y]){
                distance[y]=distance[vertex]+w;
                s.insert({distance[y],y});
            }
        }
    }
    return distance;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
