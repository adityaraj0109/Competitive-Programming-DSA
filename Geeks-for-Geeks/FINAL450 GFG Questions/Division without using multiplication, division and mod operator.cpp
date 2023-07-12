#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long divide(long long dividend, long long divisor)
{
    int sign=0;
    if(dividend*divisor<0){
        sign=1;
    }
    dividend=abs(dividend);
    divisor=abs(divisor);
    long long ans=0;
    while (dividend>=divisor)
    {
        long long val=divisor;
        int count=0;
        while (val<=dividend)
        {
            count++;
            val=val<<1;
        }
        val=val>>1;
        dividend-=val;
        ans=ans+(1<<(count-1));
    }
    if(sign) return -ans;
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
