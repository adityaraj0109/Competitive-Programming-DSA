#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int returndiff(unordered_map<char,int> &m){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(auto it:m){
        if(it.second>maxi){
            maxi=it.second;
        }
        if(it.second<mini){
            mini=it.second;
        }
    }
    return (maxi-mini);
}

int beautySum(string s)
{
    int n=s.size();
    int sum=0;
    for (int i = 0; i <n ; i++)
    {
        unordered_map<char,int>m;
        for (int j = i; j <n ; j++)
        {
            m[s[j]]++;
            sum+=returndiff(m);
        }
    }
    return sum;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
