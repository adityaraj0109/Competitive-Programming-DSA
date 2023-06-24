#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int longestString(int x, int y, int z)
{
    int count=0;
    int mini=min(x,min(y,z));
    x=x-mini;
    y=y-mini;
    z=z-mini;
    count+=mini*6;
    if(x==0 || y==0){
        count+=z*2;
        if(x!=0){
            count+=2;
        }
        else if(y!=0){
            count+=2;
        }
    }
    else{
        mini=min(y,x);
        y=y-mini;
        x=x-mini;
        count+=mini*4;
        if(x!=0){
            count+=2;
        }
        else if(y!=0){
            count+=2;
        }
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
