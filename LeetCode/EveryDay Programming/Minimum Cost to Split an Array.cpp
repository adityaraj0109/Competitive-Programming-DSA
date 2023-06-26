#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int> &nums, int k,vector<int> &dp,vector<vector<int>> &len, int index){
    if(index>=nums.size()) return 0;
    if(dp[index]!=-1) return dp[index];
    int ans=INT_MAX;
    for (int i = index; i < nums.size(); i++)
    {
        int part1=len[index][i]+k;
        int part2=solution(nums,k,dp,len,i+1);
        ans=min(ans,part1+part2);
    }
    return dp[index]=ans;
}

int minCost(vector<int> &nums, int k)
{
    int n=nums.size();
    vector<vector<int>>len(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        vector<int>m(1001,0);
        int count=0;
        for (int j = i; j < n; j++)
        {
            m[nums[j]]++;
            if(m[nums[j]]==2){
                count+=2;
            }
            else if(m[nums[j]]>2){
                count++;
            }
            len[i][j]=count;
        }
    }
    vector<int>dp(1001,-1);
    return solution(nums,k,dp,len,0);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
