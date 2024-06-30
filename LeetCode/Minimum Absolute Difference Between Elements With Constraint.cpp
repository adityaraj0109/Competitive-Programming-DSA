#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int>& nums, int x){
    int num = nums.size();
    int temp = INT_MAX;
    set<int> sett;
    int maxi = INT_MIN;
    for(int i=num-1;i>=0;i--){
        sett.insert(nums[i]);
        maxi = max(maxi, nums[i]);
        if(i - x >= 0 && maxi >= nums[i - x]){
            int a = nums[i - x];
            auto b = sett.lower_bound(a);
            if(b != sett.end()) temp = min(temp, abs(*b - a));
        }
    }
    maxi = INT_MIN;
    sett.clear();
    for(int i=0;i<num;i++){
        sett.insert(nums[i]);
        maxi = max(maxi, nums[i]);
        if(i + x < num && maxi >= nums[i + x]){
            int a = nums[i + x];
            auto b = sett.lower_bound(a);
            if(b != sett.end()) temp = min(temp, abs(*b - a));
        }
    }
    return temp;
}

int minAbsoluteDifference(vector<int>& nums, int x) {
    return solution(nums,x);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
