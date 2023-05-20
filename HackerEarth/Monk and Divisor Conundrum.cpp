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

int num=2e5+10;
vector<int>v1(num,0);
vector<int>vec(num,0);

void divisor()
{
    for (int i = 1; i < num; i++)
    {
        for (int j = i; j < num; j = j + i)
        {
            vec[i]+=v1[j];
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        v1[v[i]]++;
    }
    divisor();
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int p,q;
        cin>>p>>q;
        long long int lcm=(p*1LL*q)/__gcd(p,q);
        long long int sum=vec[p]+vec[q];
        if(lcm<n){
            sum-=vec[lcm];
        }
        cout<<sum<<endl;
    }
    return 0;
}
