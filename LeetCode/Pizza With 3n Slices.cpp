#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//approach 1
int solution1(vector<int> &slices, int index, int endIndex, int n,vector<vector<int>> &dp){
    if(index>endIndex || n==0){
        return 0;
    }
    if(dp[index][n]!=-1) return dp[index][n];

    int ans=slices[index]+solution1(slices,index+2,endIndex,n--,dp);
    ans=max(ans,solution1(slices,index+1,endIndex,n,dp));
    return dp[index][n]=ans;
}

//approach 2
int solution2(vector<int> &slices){
    int k=slices.size();
    vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

    for (int index = k-2; index >=0; index--)
    {
        for (int n = 1; n <= k/3; n++)
        {
            int ans1=slices[index]+dp1[index+2][n-1];
            int ans2=dp1[index+1][n];
            dp1[index][n]=max(ans1,ans2);
        }
    }

    for (int index = k-1; index >=1; index--)
    {
        for (int n = 1; n <= k/3; n++)
        {
            int ans1=slices[index]+dp2[index+2][n-1];
            int ans2=dp2[index+1][n];
            dp2[index][n]=max(ans1,ans2);
        }
    }

    return max(dp1[0][k/3],dp2[1][k/3]);
}

//approach 3
int solution3(vector<int> &slices){
    int k=slices.size();
    vector<int>prev1(k+2,0);
    vector<int>curr1(k+2,0);
    vector<int>next1(k+2,0);
    vector<int>prev2(k+2,0);
    vector<int>curr2(k+2,0);
    vector<int>next2(k+2,0);

    for (int index = k-2; index >=0; index--)
    {
        for (int n = 1; n <= k/3; n++)
        {
            int ans1=slices[index]+next1[n-1];
            int ans2=curr1[n];
            prev1[n]=max(ans1,ans2);
        }
        next1=curr1;
        curr1=prev1;
    }

    for (int index = k-1; index >=1; index--)
    {
        for (int n = 1; n <= k/3; n++)
        {
            int ans1=slices[index]+next2[n-1];
            int ans2=curr2[n];
            prev2[n]=max(ans1,ans2);
        }
        next2=curr2;
        curr2=prev2;
    }

    return max(curr1[k/3],curr2[k/3]);
}

int maxSizeSlices(vector<int> &slices)
{
    //for approach 1
    // int n=slices.size();
    // vector<vector<int>>dp1(n,vector<int>(n,-1));
    // vector<vector<int>>dp2(n,vector<int>(n,-1));
    // int ans1=solution1(slices,0,n-2,n/3,dp1);
    // int ans2=solution1(slices,1,n-1,n/3,dp2);
    // return max(ans1,ans2);

    //for approach 2
    // return solution2(slices);

    //for approach 3
    return solution3(slices);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
