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

vector<int> addToArrayForm(vector<int> &num, int k)
{
    int carry=0;
    vector<int>ans;
    for (int i = num.size()-1; i >=0; i--)
    {
        int sum=num[i]+k%10+carry;
        k=k/10;
        if (sum>=10)
        {
            sum=sum-10;
            carry=1;
        }
        else{
            carry=0;
        }
        ans.push_back(sum);
    }
    while (k)
    {
        int sum=k%10+carry;
        k=k/10;
        if (sum>=10)
        {
            sum=10-sum;
            carry=1;
        }
        else{
            carry=0;
        }
        ans.push_back(sum);
    }
    if (carry)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>num={2,7,4};
    int k=181;
    vector<int>ans=addToArrayForm(num,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
