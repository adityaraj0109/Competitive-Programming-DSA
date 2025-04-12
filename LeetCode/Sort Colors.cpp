#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void sortColors(vector<int>& nums) {
    int i=0, j=0;
    int k=nums.size()-1;
    while(j<=k){
        if(nums[j]==0){
            swap(nums[i],nums[j]);
            i++; j++;
        }
        else if(nums[j]==1) j++;
        else{
            swap(nums[j],nums[k]);
            k--;
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
