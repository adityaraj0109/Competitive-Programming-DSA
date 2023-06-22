#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<int>ans(2);
    int n = nums.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        pq.push({nums[i][0],{i,0}});
        min=min>nums[i][0]?nums[i][0]:min;
        if (max<nums[i][0])
        {
            max=nums[i][0];
        }
    }
    ans[0]=min;ans[1]=max;
    while(pq.size()>=n){
        pair<int,pair<int,int>>temp=pq.top();
        pq.pop();
        int min=temp.first;
        int i=temp.second.first;
        int j=temp.second.second;
        int diffans=ans[1]-ans[0];
        int diffminmax=max-min;
        if(diffans>diffminmax){
            ans[0]=min;
            ans[1]=max;
        }
        if(j+1<nums[i].size()){
            pq.push({nums[i][j+1],{i,j+1}});
            if(max<nums[i][j+1]){
                max=nums[i][j+1];
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
