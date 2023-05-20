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

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int>vec;
    for (int i = 0; i < nums.size(); i++)
    {
        int c=count(nums.begin()+i+1,nums.end(),(target-nums[i]));
        if (c)
        {
            auto it=find(nums.begin()+i+1,nums.end(),(target-nums[i]));
            vec.push_back(i);
            vec.push_back(it-nums.begin());
        }
    }
    return vec;  
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>ans;
    vector<int>v={3,2,4};
    ans=twoSum(v,6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
