#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        long long int n;
        cin>>n;
        long long int sum=0;
        while (n>0)
        {
            sum+=n;
            n=n/2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
