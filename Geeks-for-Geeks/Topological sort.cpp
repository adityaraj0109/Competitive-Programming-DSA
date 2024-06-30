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

// 1st method using dfs

// void dfs(vector<int> graph[], int vertex, vector<int> &visited, stack<int> &s)
// {
//     visited[vertex] = 1;
//     for (auto child : graph[vertex])
//     {
//         if (!visited[child])
//         {
//             dfs(graph, child, visited, s);
//         }
//     }
//     s.push(vertex);
// }

// vector<int> topoSort(int V, vector<int> adj[])
// {
//     vector<int> visited(V, 0);
//     vector<int> ans;
//     stack<int> s;
//     for (int i = 0; i < V; i++)
//     {
//         if (!visited[i])
//         {
//             dfs(adj, i, visited, s);
//         }
//     }
//     while (!s.empty())
//     {
//         ans.push_back(s.top());
//         s.pop();
//     }
//     return ans;
// }

// 2nd method using bfs kahn algo

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto child:adj[i]){
            indegree[child]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto child:adj[temp]){
            indegree[child]--;
            if(indegree[child]==0){
                q.push(child);
            }
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
