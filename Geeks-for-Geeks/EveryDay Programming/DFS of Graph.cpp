#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<int> &vis, vector<int> &ans, vector<int> adj[], int vertex){
    vis[vertex] = 1;
    ans.push_back(vertex);
    for(auto child : adj[vertex]){
        if(!vis[child]){
            dfs(vis, ans, adj, child);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;
    dfs(vis,ans,adj,0);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
