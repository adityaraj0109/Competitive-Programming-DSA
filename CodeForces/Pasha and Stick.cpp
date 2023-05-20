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
    int t;
    cin >> t;
    if (t%2!=0)
    {
        cout<<0<<endl;
    }
    else
    {
        int count=0;
        for (int i = 1; i < ceil(t/4.0); i++)
        {
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}