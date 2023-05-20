#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n,m;
int val[10005][10005];
int visited[10005][10005];
int level[10005][10005];

vector<pair<int,int>> movements={
    {-1,1},{0,1},{1,1},{1,0},{-1,0},{-1,-1},{0,-1},{1,-1}
};

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
            level[i][j]=INT_MAX;
        }
    }
}

bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(){
    int maxx=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxx=max(maxx,val[i][j]);
        }
    }
    queue<pair<int,int>>q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(maxx==val[i][j]){
                q.push({i,j});
                level[i][j]=0;
                visited[i][j]=1;
            }
        }
    }
    while (!q.empty())
    {
        auto vertex=q.front();
        int x=vertex.first;
        int y=vertex.second;
        q.pop();
        for (auto movement : movements)
        {
            int a=x+movement.first;
            int b=y+movement.second;
            if (!isValid(a,b))
            {
                continue;
            }
            if (visited[a][b])
            {
                continue;
            }
            q.push({a,b});
            level[a][b]=level[x][y]+1;
            visited[a][b]=1;
            ans=max(ans,level[a][b]);
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}