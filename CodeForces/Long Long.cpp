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
        int n;
        cin>>n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        long long int sum=0;
        long long int count=0;
        for (int i = 0; i < n; i++)
        {
            sum+=abs(arr[i]);
        }
        int i=0;
        while (i<n)
        {
            if (arr[i]<0)
            {
                count++;
                int j=i+1;
                while (arr[j]<=0 && j<n)
                {
                    j++;
                }
                i=j;
            }
            else{
                i++;
            }
        }
        cout<<sum<<" "<<count<<endl;
    }
    return 0;
}
