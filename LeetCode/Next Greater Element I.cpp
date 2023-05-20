#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int>ans(nums1.size());
    vector<int>vec(nums2.size());
    stack<int>st;
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st.empty() && nums2[i]>nums2[st.top()])
        {
            vec[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        vec[st.top()]=-1;
        st.pop();
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        auto it=find(nums2.begin(),nums2.end(),nums1[i]);
        int index=it-nums2.begin();
        if (vec[index]==-1)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=nums2[vec[index]];
        }
    }
    return ans;
}

int main()
{
    vector<int>v1={2,4};
    vector<int>v2={1,2,3,4};
    vector<int>vec=nextGreaterElement(v1,v2);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}