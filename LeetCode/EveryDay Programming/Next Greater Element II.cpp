#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int len=nums.size()-1;
    for (int i = 0; i < len; i++)
    {
        nums.push_back(nums[i]);
    }
    vector<int>vec(nums.size());
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            vec[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        vec[st.top()] = -1;
        st.pop();
    }
    vector<int>ans(len+1);
    for (int i = 0; i <=len; i++)
    {
        if (vec[i]==-1)
        {
            ans[i]=-1;
        }
        else{
            ans[i]=nums[vec[i]];
        }
    }
    return ans;
}

int main()
{
    vector<int> nums={1,2,1};
    vector<int> vec = nextGreaterElements(nums);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}