#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies,candies+N);
    int value=ceil(N/float(K+1));
    vector<int>ans;
    int mini=0,maxi=0;
    for (int i = 0; i < value; i++)
    {
        mini+=candies[i];
        maxi+=candies[N-1-i];
    }
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
