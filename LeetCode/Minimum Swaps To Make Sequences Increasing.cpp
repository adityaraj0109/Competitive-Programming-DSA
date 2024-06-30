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
int solution1(vector<int> &nums1, vector<int> &nums2, int swapped, int index,vector<vector<int>> &dp){
    if(index==nums1.size()) return 0;
    if(dp[index][swapped]!=-1) return dp[index][swapped];
    int ans=INT_MAX;
    int prev1=nums1[index-1];
    int prev2=nums2[index-1];

    if(swapped) swap(prev1,prev2);
    if(nums1[index]>prev1 && nums2[index]>prev2){
        ans=solution1(nums1,nums2,0,index+1,dp);
    }
    if(nums1[index]>prev2 && nums2[index]>prev1){
        ans=min(ans,1+solution1(nums1,nums2,1,index+1,dp));
    }
    return dp[index][swapped]=ans;
}

//approach 2
int solution2(vector<int> &nums1, vector<int> &nums2){
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    bool swapped=0;
    vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
    for (int index = nums1.size()-1; index>=1; index--)
    {
        for (int swapped = 1; swapped >=0; swapped--)
        {
            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];

            if(swapped) swap(prev1,prev2);
            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans=dp[index+1][0];
            }
            if(nums1[index]>prev2 && nums2[index]>prev1){
                ans=min(ans,1+dp[index+1][1]);
            }
            dp[index][swapped]=ans;
        }
    }
    return dp[1][0];
}

//approach 3
int solution3(vector<int> &nums1, vector<int> &nums2){
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    bool swapped=0;
    int currswap=0;
    int currnoswap=0;
    int nextswap=0;
    int nextnoswap=0;
    for (int index = nums1.size()-1; index>=1; index--)
    {
        for (int swapped = 1; swapped >=0; swapped--)
        {
            int ans=INT_MAX;
            int prev1=nums1[index-1];
            int prev2=nums2[index-1];

            if(swapped) swap(prev1,prev2);
            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans=nextnoswap;
            }
            if(nums1[index]>prev2 && nums2[index]>prev1){
                ans=min(ans,1+nextswap);
            }
            if(swapped) currswap=ans;
            else currnoswap=ans;
        }
        nextswap=currswap;
        nextnoswap=currnoswap;
    }
    return min(nextnoswap,nextswap);
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    //for approach 1
    // nums1.insert(nums1.begin(),-1);
    // nums2.insert(nums2.begin(),-1);
    // bool swapped=0;
    // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
    // return solution1(nums1,nums2,swapped,1,dp);

    //for approach 2
    return solution2(nums1,nums2);

    //for approach 3
    // return solution3(nums1,nums2);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
