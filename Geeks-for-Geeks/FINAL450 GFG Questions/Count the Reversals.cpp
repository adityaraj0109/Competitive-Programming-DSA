#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countRev (string s)
{
    if(s.size()%2!=0) return -1;
    int open=0;
    int ans=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='{') open++;
        else{
            if(open==0){
                ans++;
                open++;
            }
            else open--;
        }
    }
    if(open!=0){
        ans=ans+(open/2);
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
