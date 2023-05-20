#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    debugMode();
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n >> a;
        vector<int> v1(n + 1);
        vector<int> v2(n + 1);
        int maximum = 0;
        int minimum = INT_MAX;
        v1[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int c, d;
            cin >> c >> d;
            v1[i] = v1[i - 1] + c;
            v2[i] = d;
        }
        int l, r;
        for (int i = 1; i <= n; i++)
        {
            minimum = min(minimum, v2[i]);
            if (minimum == v2[i])
            {
                l = i;
            }
            maximum = max(maximum, v2[i]);
            if (maximum == v2[i])
            {
                r = i;
            }
        }
        long long int cost;
        if (l > r)
        {
            cost = ((l - r + 1) * a )- (v1[l] - v1[r - 1]) - ((maximum - minimum) * (maximum - minimum));
            cout<<(v1[l] - v1[r - 1])<<endl;
        }
        else{
            cost =( (r - l + 1) * a) - (v1[r] - v1[l - 1]) - ((maximum - minimum) * (maximum - minimum));
        }
        cout << minimum << " " << maximum << " " << l << " " << r << endl;
        cout << cost << endl;
    }
    return 0;
}
