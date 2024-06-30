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

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> distance(V, 100000000);
    distance[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto child : edges)
        {
            int u = child[0];
            int v = child[1];
            int wt = child[2];
            if (distance[u] != 100000000 && distance[u] + wt < distance[v])
            {
                distance[v] = distance[u] + wt;
            }
        }
    }

    // to check whether there is any -ve cycle
    int flag = 0;
    for (auto child : edges)
    {
        int u = child[0];
        int v = child[1];
        int wt = child[2];
        if (distance[u] != 100000000 && distance[u] + wt < distance[v])
        {
            flag = 1;
        }
    }
    if (!flag)
    {
        return distance;
    }
    return {-1};
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
