#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int longestAlternatingSubarray(vector<int> &nums, int threshold)
{
    int count=0;
    int ans=0;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        if(nums[i]%2==0 && nums[i]<=threshold){
            count=1;
            for (int j = i+1; j < n; j++)
            {
                if(count%2!=0){
                    if(nums[j]%2!=0 && nums[j]<=threshold){
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
                else{
                    if(nums[j]%2==0 && nums[j]<=threshold){
                        count++;
                    }
                    else break;
                }
            }
        }
        ans=max(ans,count);
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
