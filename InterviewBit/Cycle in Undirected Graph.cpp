#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool dfs(vector<int> &vis,vector<int>graph[],int parent,int vertex){
    vis[vertex]=1;
    bool iscyclic=false;
    for(auto child:graph[vertex]){
        if (vis[child] && child==parent)
        {
            continue;
        }
        if (vis[child])
        {
            return true;
        }
        iscyclic|=dfs(vis,graph,vertex,child);
    }
    return iscyclic;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int>vis(A+1,0);
    vector<int>graph[A+1];
    for(auto edge:B){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vis[0]=1;
    for (int i = 1; i <=A; i++)
    {
        if (!vis[i])
        {
            if(dfs(vis,graph,0,i)){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
