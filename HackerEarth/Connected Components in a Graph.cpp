#include <bits/stdc++.h>
using namespace std;

vector<int>graph[100005];
vector<bool>visited(100005,0);

void dfs(int vertex){
    visited[vertex]=true;
    for(int child:graph[vertex]){
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    for (int i = 0; i < edge; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int c=0;
    for (int i = 1; i <=node; i++)
    {
        if(!visited[i]){
            dfs(i);
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}