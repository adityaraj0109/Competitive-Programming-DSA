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

int solution(long long int low,long long int high, vector<int>&v,int h){
    long long int ans,mid,sum;
    while (high>=low)
    {
        sum=0;
        mid=(high+low)/2;
        for (int i = 0; i < v.size(); i++)
        {
            sum+=ceil((double)v[i]/(double)mid);
        }
        if(sum<=h){
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    debugMode();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        float h;
        cin>>n>>h;
        vector<int>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        long long int sum=accumulate(v.begin(),v.end(),0);
        long long int low=ceil(sum/h);
        long long int high=* max_element(v.begin(),v.end());
        cout<<solution(low,high,v,h)<<endl;
    }
    return 0;
}
