#include <bits/stdc++.h>
using namespace std;

const long long int N=1e9+7;

long long int nthFibonacci(long long int n)
{
    long long int array[n+1];
    array[0]=0,array[1]=1;
    for (int i = 2; i <=n; i++)
    {
        array[i]=((array[i-1]%N)+(array[i-2]%N))%N;
    }
    return array[n];
}

int main()
{
    long long int n,ans;
    cin>>n;
    ans=nthFibonacci(n);
    cout<<ans<<endl;
    return 0;
}