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

long long findTheArrayConcVal(vector<int> &nums)
{
    long long int ans=0;
    int i=0,j=nums.size()-1;
    while (i<=j)
    {
        if (i==j)
        {
            ans+=nums[i];
            i++;
            j--;
            break;
        }
        string str=to_string(nums[i])+to_string(nums[j]);
        ans+=stoi(str);
        i++,j--;
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
