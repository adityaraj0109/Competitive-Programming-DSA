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

void dfs(int vertex, vector<int> &visited, stack<int> &s, unordered_map<int, vector<int>> &graph)
{
    visited[vertex] = 1;
    for (auto child : graph[vertex])
    {
        if (!visited[child])
        {
            dfs(child, visited, s, graph);
        }
    }
    s.push(vertex);
}

void dfsRev(int vertex, vector<int> &visited, unordered_map<int, vector<int>> &transposeGraph)
{
    visited[vertex] = 1;
    for (auto child : transposeGraph[vertex])
    {
        if (!visited[child])
        {
            dfsRev(child, visited, transposeGraph);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    unordered_map<int, vector<int>> graph;
    unordered_map<int, vector<int>> transposeGraph;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            graph[i].push_back(it);
            transposeGraph[it].push_back(i);
        }
    }

    // performing the topological sort
    vector<int> visited(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, graph);
        }
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // counting the no. of strongly connected components
    int count = 0;
    while (!s.empty())
    {
        int vertex = s.top();
        s.pop();
        if (!visited[vertex])
        {
            dfsRev(vertex, visited, transposeGraph);
            count++;
        }
    }

    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
