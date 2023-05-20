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


bool dfs(int vertex, int par, vector<int>adj[],vector<bool>&visited){
    visited[vertex]=true;
    bool isCyclic=false;
    for(int child:adj[vertex]){
        if (visited[child] && child==par)
        {
            continue;
        }
        if (visited[child])
        {
            return true;
        }
        isCyclic|=dfs(child,vertex,adj,visited);
    }
    return isCyclic;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool>visited(100005,0);
    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            if(dfs(i,-1,adj,visited)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    debugMode();
    int v,e;
    cin>>v>>e;
    vector<int> adj[]={{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;
    bool ans=isCycle(v,adj);
    cout<<ans<<endl;
    return 0;
}
