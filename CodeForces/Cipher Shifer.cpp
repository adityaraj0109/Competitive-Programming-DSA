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
        string str;
        cin>>str;
        int i=0;
        string ans="";
        while (i<n)
        {
            int j=i+1;
            while (j<n && str[j]!=str[i]){
                j++;
            }
            ans+=str[i];
            i=j+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

