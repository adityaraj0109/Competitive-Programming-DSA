#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int>ans(n);
    int pos=0,neg=1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]<0){
            ans[neg]=nums[i];
            neg=neg+2;
        }
        else{
            ans[pos]=nums[i];
            pos=pos+2;
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
