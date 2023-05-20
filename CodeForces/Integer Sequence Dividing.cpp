#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}
int main()
{
    debugMode();
    ll t;
    cin >> t;
    ll sum;
    sum=t*(t+1)/2;
    if (sum%2==0)
    {
        cout<<0<<endl;
    }
    else
        cout<<1<<endl;
    return 0;
}