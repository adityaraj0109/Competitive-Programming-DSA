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

int main()
{
    debugMode();
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=s+"b";
    int count1=0,count_a=0,ans=0;
    for (int i = 0; i < n+1; i++)
    {
        if (s[i]=='b')
        {
            if (count_a!=0)
            {
                ans=ans+count1;
                count1=0;
                count_a=0;
            }
            else{
                count1=0;
            }
        }
        else if (s[i]=='a')
        {
            count_a++;
            count1++;
        }
        else
        {
            count1++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
