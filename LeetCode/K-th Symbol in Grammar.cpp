#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int kthGrammar(int n, int k)
{
    if (k==1 && n==1)
    {
        return 0;
    }
    int mid=pow(2,n-1)/2;
    if (k<=mid)
    {
        return kthGrammar(n-1,k);
    }
    else
    {
        return !kthGrammar(n-1,k-mid);
    }
}

int main()
{
    int ans=kthGrammar(4,5);
    cout<<ans<<endl;
    return 0;
}