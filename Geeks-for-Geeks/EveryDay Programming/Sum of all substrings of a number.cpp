#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long sumSubstrings(string s)
{
    int n=s.size();
    int mod=1e9+7;
    vector<long long>temp(n);
    temp[0]=s[0]-'0';
    long long sum=temp[0];
    for (int i = 1; i < n; i++)
    {
        temp[i]=(10*temp[i-1]+(i+1)*(s[i]-'0'))%mod;
        sum=(sum+temp[i])%mod;
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
