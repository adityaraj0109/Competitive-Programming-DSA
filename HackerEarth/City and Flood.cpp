#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int parent[100005];
int Size[100005];

void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(parent[v]==v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b) {
        if (Size[a]<Size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin>>a>>b;
        Union(a, b);
    }
    int connected_ct=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) connected_ct++;
    }
    cout<<connected_ct<<endl;
    return 0;
}