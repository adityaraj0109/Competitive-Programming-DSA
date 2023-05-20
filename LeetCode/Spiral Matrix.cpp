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

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int prod=m*n;
    int count=0;
    vector<int>ans;
    int rstart=0,rend=m-1,cstart=0,cend=n-1;
    while (count<prod)
    {
        for (int i = cstart;(count<prod)&& (i <=cend); i++)
        {
            ans.push_back(matrix[rstart][i]);
            count++;
        }
        rstart++;
        for (int i = rstart;(count<prod)&& (i <=rend); i++)
        {
            ans.push_back(matrix[i][cend]);
            count++;
        }
        cend--;
        for (int i = cend;(count<prod)&& (i >=cstart); i--)
        {
            ans.push_back(matrix[rend][i]);
            count++;
        }
        rend--;
        for (int i = rend;(count<prod)&& (i >=rstart); i--)
        {
            ans.push_back(matrix[i][cstart]);
            count++;
        }
        cstart++;
    }
    return ans;
}

int main()
{
    debugMode();
    vector<vector<int>>matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>ans=spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
