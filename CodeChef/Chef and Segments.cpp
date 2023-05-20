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

int func(int a,int b, int m){
    int ans=1;
    while (b)
    {
        if (b&1)
        {
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b=b>>1;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    int prime[26] = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int arr[26][n+1];
    for (int j = 0; j <=n; j++)
    {
        for (int i = 0; i <=25 ; i++)
        {
            arr[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int j=1;
        while (v[i]!=1)
        {
            if (v[i]%prime[j]==0)
            {
                arr[j][i]+=1;
                v[i]=v[i]/prime[j];
            }
            else{
                j++;
            }
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <=25 ; i++)
        {
            arr[i][j]=arr[i][j]+arr[i][j-1];
        }
    }
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int l,r,m;
        cin>>l>>r>>m;
        int ans=1;
        for (int j = 1; j <= 25; j++)
        {
            int range=arr[j][r]-arr[j][l-1];
            ans=(ans*1LL*func(prime[j],range,m))%m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
