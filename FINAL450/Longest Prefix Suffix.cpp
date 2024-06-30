#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lps(string s)
{
    int n=s.size();
    vector<int>temp(n,0);
    int i=0,j=1;
    while (j<n)
    {
        if(s[i]==s[j]){
            temp[j]=i+1;
            i++,j++;
        }
        else{
            if(i!=0){
                i=temp[i-1];
            }
            else j++;
        }
    }
    return temp[n-1];
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
