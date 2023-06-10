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

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < M; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> level(N, -1);
    vector<int> visited(N, 0);
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visited[src] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int child : graph[temp])
        {
            if (!visited[child])
            {
                level[child] = level[temp] + 1;
                q.push(child);
                visited[child] = 1;
            }
        }
    }
    return level;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
