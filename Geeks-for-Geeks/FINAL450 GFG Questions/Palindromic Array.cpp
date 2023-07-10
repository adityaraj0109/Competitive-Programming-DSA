#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int num=a[i];
        int x=0;
        while (num>0)
        {
            x=x*10+(num%10);
            num=num/10;
        }
        if(x!=a[i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
