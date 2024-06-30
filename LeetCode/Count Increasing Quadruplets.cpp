#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long countQuadruplets(vector<int> &nums)
{
    int n=nums.size();
    vector<vector<int>>greaterthan(n,vector<int>(n,0));
    vector<vector<int>>lesserthan(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        int greater=0;
        for (int j = i+1; j <n; j++)
        {
            greater+=(nums[j]>nums[i]);
            greaterthan[i][j]=greater;
        }
    }

    for(int i=0;i<n;i++){
        int lesser=0;
        for (int j = 0; j <i; j++)
        {
            lesser+=(nums[j]<nums[i]);
            lesserthan[i][j]=lesser;
        }
    }

    long long ans=0;
    for (int j = 1; j < n-2; j++)
    {
        for (int k = j+1; k < n-1; k++)
        {
            if(nums[j]>nums[k]){
                int num_i=lesserthan[k][j];
                int num_l=greaterthan[j][n-1]-greaterthan[j][k];
                ans+=1LL*num_i*num_l;
            }
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
