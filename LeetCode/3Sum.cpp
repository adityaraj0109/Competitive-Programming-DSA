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

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for (int i = 0; i < n-2; i++)
    {
        if (nums[i]!=nums[i-1])
        {
            int j=i+1;
            int k=n-1;
            int sum=-nums[i];
            while (j<k)
            {
                if (nums[j]+nums[k]==sum){
                    vector<int>vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[k]);
                    ans.push_back(vec);

                    while (j<k && nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    while (j<k && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (nums[j]+nums[k]<sum)
                {
                    j++;
                }
                else{
                    k--;
                }
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
