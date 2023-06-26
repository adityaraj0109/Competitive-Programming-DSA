#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//TLE for this solution
// int solution(vector<vector<int>> &envelopes,vector<vector<int>>&dp, int currIndex, int prevIndex){
//     if(currIndex==envelopes.size()) return 0;
//     if(dp[currIndex][prevIndex+1]!=-1) return dp[currIndex][prevIndex+1];
    
//     int ans=0;
//     if(prevIndex==-1 || (envelopes[currIndex][0]>envelopes[prevIndex][0] && envelopes[currIndex][1]>envelopes[prevIndex][1])){
//         ans=1+solution(envelopes,dp,currIndex+1,currIndex);
//     }
//     ans=max(ans,solution(envelopes,dp,currIndex+1,prevIndex));
//     return dp[currIndex][prevIndex+1]=ans;
// }

// int maxEnvelopes(vector<vector<int>> &envelopes)
// {
//     int n=envelopes.size();
//     if(n==1) return 1;
//     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//     sort(envelopes.begin(),envelopes.end());
//     return solution(envelopes,dp,0,-1);
// }

//TLE for this solution also
// int maxEnvelopes(vector<vector<int>> &envelopes)
// {
//     int n=envelopes.size();
//     if(n==1) return 1;
//     vector<int>dp(n,1);
//     sort(envelopes.begin(),envelopes.end());
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
//                 dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//     }
//     return *max_element(dp.begin(),dp.end());
// }

//Solution in O(NlogN) dp with binary search
class compare{
    public:
        bool operator()(vector<int> &a, vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        }
};

// static bool compare(vector<int> &a, vector<int> &b){
//     if(a[0]==b[0]){
//         return a[1]>b[1];
//     }
//     return a[0]<b[0];
// }

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n=envelopes.size();
    if(n==1) return 1;
    vector<int>dp;
    sort(envelopes.begin(),envelopes.end(),compare());
    for (int i = 0; i < n; i++)
    {
        int height=envelopes[i][1];
        int index=lower_bound(dp.begin(),dp.end(),height)-dp.begin();
        if(index==dp.size()){
            dp.push_back(height);
        }
        dp[index]=height;
    }
    return dp.size();
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
