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
        int n;
        cin>>n;
        int arr[n];
        int count=1;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i-1]<arr[i])
            {
                arr[i]=arr[i-1];
            }
            else
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}