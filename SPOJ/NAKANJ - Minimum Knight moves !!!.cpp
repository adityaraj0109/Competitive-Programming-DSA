#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int level[8][8];
int vis[8][8];

bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

int getX(string str){
    return (str[0]-'a');
}

int getY(string str){
    return (str[1]-'1');
}

vector<pair<int,int>>movements={
    {-1,2},{-2,1},
    {-1,-2},{-2,-1},
    {1,2},{2,1},
    {1,-2},{2,-1}
};

int bfs(string s1,string s2){
    int sourceX=getX(s1);
    int sourceY=getY(s1);
    int destX=getX(s2);
    int destY=getY(s2);
    queue<pair<int,int>>q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;
    level[sourceX][sourceY]=0;
    while (!q.empty())
    {
        pair<int,int>p=q.front();
        int x=p.first,y=p.second;
        q.pop();
        for(auto move:movements){
            int movex=move.first+x;
            int movey=move.second+y;
            if(isvalid(movex,movey)){
                if(vis[movex][movey]==0){
                    level[movex][movey]=level[x][y]+1;
                    q.push({movex,movey});
                    vis[movex][movey]=1;
                }
            }
        }
        if (level[destX][destY]!=-1)
        {
            break;
        }
    }
    return level[destX][destY];
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            level[i][j]=-1;
            vis[i][j]=0;
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        reset();        
        string s1,s2;
        cin>>s1>>s2;
        int ans=bfs(s1,s2);
        cout<<ans<<endl;
    }
    return 0;
}