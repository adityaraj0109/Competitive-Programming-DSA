#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minSwaps(vector<int> &nums)
{
    vector<pair<int,int>>temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp.push_back({nums[i],i});
    }
    sort(temp.begin(),temp.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(temp[i].second==i) continue;
        else{
            count++;
            swap(temp[i],temp[temp[i].second]);
            i--;
        }
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
