#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int s=nums.size();
    for (int i = 0; i < s; i++)
    {
        if (i==s-1)
        {
            return nums[i];
        }
        else if(i%2==0 && nums[i]!=nums[i+1]){
            return nums[i];
        }
    }
    assert(false);
}

int main()
{
    vector<int>v{4,1,2,1,2,5,4,8,8};
    int ans=singleNumber(v);
    cout<<ans<<endl;
    return 0;
}