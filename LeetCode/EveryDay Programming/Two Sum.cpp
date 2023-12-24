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

// approach 1
//  vector<int> twoSum(vector<int>& nums, int target)
//  {
//      vector<int>vec;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          int c=count(nums.begin()+i+1,nums.end(),(target-nums[i]));
//          if (c)
//          {
//              auto it=find(nums.begin()+i+1,nums.end(),(target-nums[i]));
//              vec.push_back(i);
//              vec.push_back(it-nums.begin());
//          }
//      }
//      return vec;
//  }

// approach 2
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mp[nums[i]]=i;
//     }
//     vector<int>ans(2);
//     for (int i = 0; i < nums.size()-1; i++)
//     {
//         int temp=target-nums[i];
//         if((mp.find(temp)!=mp.end()) && mp[temp]!=i){
//             ans[0]=i;
//             ans[1]=mp[temp];
//             break;
//         }
//     }
//     if(ans[0]>ans[1]) swap(ans[0],ans[1]);
//     return ans;
// }

//approach 3  //ye work ni krega leetcode pr kyuki index change ho ja rhe hai isme
vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int left=0;
    int right=nums.size()-1;
    vector<int>ans(2);
    while (left<right)
    {
        int sum=nums[left]+nums[right];
        if(sum==target){
            ans[0]=left;
            ans[1]=right;
            break;
        }
        else if(sum<target) left++;
        else right--;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ans;
    vector<int> v = {3, 2, 4};
    ans = twoSum(v, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
