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

void solution(vector<vector<int>>&ans,vector<int>&nums,int index){
    if (index==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        solution(ans,nums,index+1);
        swap(nums[i],nums[index]);
    }
}

//Shortcut way to find all distinct possible permutation

// vector<vector<int>> permute(vector<int> &nums)  
// {
//     vector<vector<int>>ans;
//     sort(nums.begin(),nums.end());
//     do
//     {
//         ans.push_back(nums);
//     } while (next_permutation(nums.begin(),nums.end()));
//     return ans;
// }

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>>ans;
    int index=0;
    solution(ans,nums,index);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>nums={1,2,3};
    vector<vector<int>>ans=permute(nums);
    for (auto it : ans)
    {
        for (int i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
