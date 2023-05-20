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
    int t;
    cin >> t;
    while (t--)
    {
        int n,z;
        cin>>n>>z;
        int arr[n];
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            a[i]=arr[i]|z;
            int arrelm=arr[i];
            z=z& arrelm;
        }
        int am=arr[0]|z;
        if (am>a[0])
        {
            a[0]=am;
        }
        int m=*max_element(a,a+n);
        cout<<m<<endl;
    }
    return 0;
}