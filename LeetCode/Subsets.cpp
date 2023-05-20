#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>vec;

void solution(vector<int>&subset,int i,vector<int>&nums){
    if (i==nums.size())
    {
        vec.push_back(subset);
        return;
    }
    solution(subset,i+1,nums);
    subset.push_back(nums[i]);
    solution(subset,i+1,nums);
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int>subset;
    solution(subset,0,nums);
    return vec;
}

int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>>ans=subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}