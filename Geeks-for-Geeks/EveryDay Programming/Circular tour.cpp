#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int tour(petrolPump p[], int n)
{
    int balance=0;
    int deficient=0;
    int start=0;
    for (int i = 0; i < n; i++)
    {
        balance+=p[i].petrol-p[i].distance;
        if (balance<0)
        {
            deficient+=balance;
            balance=0;
            start=i+1;
        }
    }
    if (balance+deficient>=0)
    {
        return start;
    }
    return -1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
