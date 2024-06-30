#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool dfs(vector<int> &vis, vector<int> &dfsvis, vector<int> adj[], int vertex)
{
    vis[vertex] = 1;
    dfsvis[vertex] = 1;
    bool ans = false;
    for (auto child : adj[vertex])
    {
        if (vis[child] && dfsvis[child])
        {
            return true;
        }
        if (!vis[child])
        {
            ans |= dfs(vis, dfsvis, adj, child);
        }
    }
    dfsvis[vertex] = 0;
    return ans;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfsvis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(vis, dfsvis, adj, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
