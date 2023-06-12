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

void dfs(vector<int> &discovery, vector<int> &low, vector<int> &visited, int &timer, int &ans, unordered_map<int, vector<int>> &graph, int vertex, int parent, int c, int d)
{
    visited[vertex] = 1;
    discovery[vertex] = low[vertex] = timer++;
    for (auto child : graph[vertex])
    {
        if (child == parent)
        {
            continue;
        }
        if (!visited[child])
        {
            dfs(discovery, low, visited, timer, ans, graph, child, vertex,c,d);
            low[vertex]=min(low[child],low[vertex]);
            if (low[child] > discovery[vertex]){
                if((child==c && vertex==d) || (child==d && vertex==c)){
                    ans=1;
                    return;
                }
            }
        }
        else{
            low[vertex] = min(low[vertex], discovery[child]);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < V; i++)
    {
        for (auto child : adj[i])
        {
            graph[i].push_back(child);
            graph[child].push_back(i);
        }
    }
    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<int> visited(V, 0);
    int timer = 0;
    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(discovery, low, visited, timer, ans, graph, i,-1,c,d);
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
