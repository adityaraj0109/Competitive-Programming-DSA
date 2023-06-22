#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> nextSmallest(vector<int>value){
    stack<int>s;
    s.push(-1);
    int n=value.size();
    vector<int> ans(n);
    for (int i = n-1; i >=0; i--)
    {
        while (s.top()!=-1 && value[s.top()]>=value[i])
        {
            s.pop();
        }
        if (s.top()==-1)
        {
            ans[i]=n;
        }
        else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallest(vector<int>value){
    stack<int>s;
    s.push(-1);
    int n=value.size();
    vector<int> ans(n);
    for (int i = 0; i <n; i++)
    {
        while (s.top()!=-1 && value[s.top()]>=value[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int solution(vector<int>value){
    int area=0;
    vector<int>next;
    vector<int>prev;
    int n=value.size();
    next=nextSmallest(value);
    prev=prevSmallest(value);
    for (int i = 0; i < n; i++)
    {
        int length=value[i];
        int breadth=next[i]-prev[i]-1;
        area=max(area,(length*breadth));
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int>value;
    for(char i:matrix[0]){
        value.push_back(i-'0');
    }
    int area=solution(value);
    int n = matrix.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j]=='0')
            {
                value[j]=0;
            }
            else{
                value[j]+=1;
            }
        }
        area=max(area,solution(value));
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
