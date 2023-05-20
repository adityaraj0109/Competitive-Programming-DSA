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

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j == i + 1 || nums[j] != nums[j - 1]){
                    int k=j+1,l=n-1;
                    long long int num=(nums[i]+nums[j]);
                    long long int sum=(long long)target-num;
                    while(k<l){
                        if (nums[k]+nums[l]==sum)
                        {
                            vector<int>vec;
                            vec.push_back(nums[i]);
                            vec.push_back(nums[j]);
                            vec.push_back(nums[k]);
                            vec.push_back(nums[l]);
                            ans.push_back(vec);

                            while (k<l && nums[k]==nums[k+1])
                            {
                                k++;
                            }
                            while (k<l && nums[l]==nums[l-1])
                            {
                                l--;
                            }
                            k++;l--;
                        }
                        else if (nums[k]+nums[l]>sum)
                        {
                            l--;
                        }
                        else{
                            k++;
                        }
                    }
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
