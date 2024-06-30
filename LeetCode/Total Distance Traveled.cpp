#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int distanceTraveled(int mainTank, int additionalTank)
{
    int ans=0;
    while (mainTank!=0)
    {
        int div=mainTank/5;
        if(div>0 && additionalTank!=0){
            mainTank+=1;
            mainTank-=5;
            additionalTank-=1;
            ans+=50;
        }
        else if (div>0 && additionalTank==0)
        {
            ans+=(mainTank)*10;
            mainTank=0;
        }
        else{
            ans+=(mainTank)*10;
            mainTank=0;
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
