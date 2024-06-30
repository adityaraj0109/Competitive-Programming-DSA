#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void sieve(int n,vector<int> &primes,unordered_map<int,int> &m){
    vector<bool>prime(n,1);
    prime[0]=prime[1]=false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            for (int j= i*2; j < n; j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if(prime[i]){
            primes.push_back(i);
            m[i]=1;
        }
    }
}

vector<vector<int>> findPrimePairs(int n)
{
    vector<int>primes;
    unordered_map<int,int>m;
    vector<vector<int>>ans;
    if(n==2) return ans;
    sieve(n,primes,m);
    for(int i=0;i<primes.size();i++){
        if(primes[i]>n/2){
            break;
        }
        int target=n-primes[i];
        if(m[target]==1){
            ans.push_back({primes[i],target});
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
