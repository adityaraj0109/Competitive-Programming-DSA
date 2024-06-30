#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int maxSum(vector<int> &nums)
{
    int n = nums.size();
    int maxx=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int maxx_a=INT_MIN;
            int maxx_b=INT_MIN;
            int temp1=nums[i],temp2=nums[j];
            while (temp1>0)
            {
                if(temp1%10>maxx_a) maxx_a=temp1%10;
                temp1=temp1/10;
            }
            while (temp2>0)
            {
                if(temp2%10>maxx_b) maxx_b=temp2%10;
                temp2=temp2/10;
            }
            if(maxx_a==maxx_b){
                int sum=nums[i]+nums[j];
                if(sum>maxx) maxx=sum;
            }
        }
    }
    if(maxx==INT_MIN) return -1;
    return maxx;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
