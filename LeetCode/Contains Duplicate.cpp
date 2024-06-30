#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int>s;
    for (auto i:nums)
    {
        s.insert(i);
    }
    int sz=s.size();
    int sz2=nums.size();
    if (sz==sz2)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int>v{1,3,2,2};
    bool ans=containsDuplicate(v);
    cout<<ans<<endl;
    return 0;
}