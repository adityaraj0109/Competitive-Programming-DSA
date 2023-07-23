#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minimumNumberOfSwaps(string S)
{
    int n = S.size();
    int ans=0,open=0;
    for (int i = 0; i < n; i++)
    {
        if(S[i]=='['){
            open++;
        }
        else{
            if(open==0){
                int j=i+1;
                while (S[j]!='[')
                {
                    j++;
                }
                ans=ans+(j-i);
                swap(S[i],S[j]);
                open++;
            }
            else{
                open--;
            }
        }
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
