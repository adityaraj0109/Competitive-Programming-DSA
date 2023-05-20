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
    while (t--)
    {
        int n;
        cin>>n;
        int num=0;
        int count=ceil(log10(n))-1;
        while (n!=0)
        {
            num=num*10+n%10;
            n=n/10;
            count--;
        }
        cout<<num<<endl;
    }
    return 0;
}