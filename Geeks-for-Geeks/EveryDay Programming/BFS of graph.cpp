#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int>ans;
    vector<bool>visited(V, false);
    queue<int>q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
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
