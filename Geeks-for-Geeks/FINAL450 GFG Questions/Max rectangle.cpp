#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void prevsmallest(vector<int> &height, vector<int> &prev){
    stack<int>s;
    s.push(-1);
    for (int i = 0; i < height.size(); i++){
        while(s.top()!=-1 && height[s.top()]>=height[i]){
            s.pop();
        }
        prev[i]=s.top();
        s.push(i);
    }
}

void nextsmallest(vector<int> &height, vector<int> &next){
    int n=height.size();
    stack<int>s;
    s.push(-1);
    for (int i = n-1; i >=0 ; i--){
        while(s.top()!=-1 && height[s.top()]>=height[i]){
            s.pop();
        }
        next[i]=s.top();
        if(next[i]==-1) next[i]=n;
        s.push(i);
    }
}

int solution(vector<int> &height, int m){
    vector<int>prev(m);
    vector<int>next(m);
    prevsmallest(height,prev);
    nextsmallest(height,next);
    int area=INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int l=height[i];
        int b=next[i]-prev[i]-1;
        area=max(area,l*b);
    }
    return area;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    vector<int>height(m,0);
    int area=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(M[i][j]==0) height[j]=0;
            else height[j]+=1;
        }
        area=max(area,solution(height,m));
    }
    return area;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
