#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minChar(string str)
{
    int n=str.length();
    string temp=str;
    reverse(temp.begin(),temp.end());
    if(temp==str) return 0;
    str=str+temp;
    int num=2*n;
    vector<int>lps(num,0);
    int j=0,i=1;
    while (i<num)
    {
        if(str[i]==str[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j-1>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return n-lps[num-1];
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
