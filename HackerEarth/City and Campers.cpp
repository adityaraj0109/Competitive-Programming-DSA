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
multiset<int>ms;

void make(int v){
    parent[v] = v;
    Size[v] = 1;
    ms.insert(Size[v]);
}

int find(int v){
    if(parent[v]==v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    ms.erase(ms.find(a));
    ms.erase(ms.find(b));
    ms.insert(a+b);
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
        merge(Size[a],Size[b]);
        Size[a] += Size[b];
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        make(i);
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin>>a>>b;
        Union(a, b);
        if (ms.size()==1)
        {
            cout<<0<<endl;
        }
        else
        {
            int minn=*ms.begin();
            int maxx=*(--ms.end());
            cout<<maxx-minn<<endl;
        }
    }
    return 0;
}