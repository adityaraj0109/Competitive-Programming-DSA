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
        vector<int>vec(n);
        for (int i = 0; i < n; i++)
        {
            cin>>vec[i];
        }
        if (n==1)
        {
            cout<<0<<endl;
        }
        else{
            int sum=0;
            sort(vec.begin(),vec.end());
            for (int i = 0; i < n/2; i++)
            {
                sum+=vec[n-1-i]-vec[i];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
