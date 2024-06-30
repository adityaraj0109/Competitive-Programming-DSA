#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long putMarbles(vector<int> &weights, int k)
{
    vector<long long>vec;
    int n=weights.size();
    for (int i = 0; i <=n-2; i++)
    {
        vec.push_back(weights[i]+weights[i+1]);
    }
    sort(vec.begin(),vec.end());
    long long mini=0,maxi=0;
    for(int i=0;i<k-1;i++){
        mini+=vec[i];
        maxi+=vec[vec.size()-1-i];
    }
    return maxi-mini;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
