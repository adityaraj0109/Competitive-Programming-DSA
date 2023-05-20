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

bool solution(vector<int> v, int min, int c)
{
    int prev = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - prev >= min || prev==-1)
        {
            c--;
            prev = v[i];
        }
        if (c==0)
        {
            break;
        }
    }
    return c == 0;
}

int main()
{
    debugMode();
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int high = 1e9, low = 0, mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (solution(v, mid, c))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (solution(v, high, c))
        {
            cout << high << endl;
        }
        else
        {
            cout << low << endl;
        }
    }
    return 0;
}
