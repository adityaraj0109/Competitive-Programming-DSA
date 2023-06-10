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

int spanningTree_Prim(int V, vector<vector<int>> adj[])
{
    vector<int>key(V,INT_MAX);
    vector<int>parent(V,-1);
    vector<int>visited(V,0);
    key[0]=0;
    parent[0]=-1;
    for (int i = 0; i < V; i++)
    {
        int mini=INT_MAX;
        int u;
        for (int j = 0; j < V; j++){
            if(!visited[j] && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }
        visited[u]=1;
        for (auto child : adj[u]){
            int x=child[0];
            int wt=child[1];
            if(!visited[x] && wt<key[x]){
                parent[x]=u;
                key[x]=wt;
            }
        }
    }
    int sum=0;
    for(int it:key){
        sum+=it;
    }
    return sum;
}

//with the kruskal algorithm

void make(int v,vector<int> &parent, vector<int> &size){
    parent[v]=v;
    size[v]=1;
}

int find(int v,vector<int> &parent){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v],parent);
}

void Union(int a, int b,vector<int> &parent, vector<int> &size){
    a=find(a,parent);
    b=find(b,parent);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int>parent(V,-1);
    vector<int>size(V,0);
    for(int i=0;i<V;i++){
        make(i,parent,size);
    }
    int sum=0;
    vector<pair<int,pair<int,int>>>graph;
    for(int i=0;i<V;i++){
        for(auto child:adj[i]){
            graph.push_back({child[1],{i,child[0]}});
        }
    }
    sort(graph.begin(),graph.end());
    for(auto child:graph){
        int a=child.second.first;
        int b=child.second.second;
        int wt=child.first;
        if(find(a,parent)!=find(b,parent)){
            Union(a,b,parent,size);
            sum+=wt;
        }
    }
    return sum;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
