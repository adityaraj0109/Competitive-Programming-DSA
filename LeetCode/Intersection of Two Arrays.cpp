#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>m;
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        m[nums1[i]]++;
    }
    for(int i=0;i<nums2.size();i++){
        if(m[nums2[i]]!=0){
            ans.push_back(nums2[i]);
            m[nums2[i]]=0;
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
