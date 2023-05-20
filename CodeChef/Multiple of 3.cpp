#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(){
    long long int k;
    int d0,d1;
    cin>>k>>d0>>d1;
    long long int sum=d0+d1;
    long long int total=0;
    long long int segment=(2*sum)%10+(4*sum)%10+(8*sum)%10+(6*sum)%10;
    if (k==2)
    {
        total=sum;
    }
    else
    {
        long long int cycle=(k-3)/4;
        long long int left=(k-3)-(cycle*4);

        total=sum+(sum%10)+(segment*1LL*cycle);
        int y=2;
        for (int i = 1; i <=left; i++)
        {
            total=total+((y%10)*(sum%10))%10;
            y*=2;
        }
    }

    if (total%3==0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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
        solution();
    }
    return 0;
}