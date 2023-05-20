#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
int main()
{
    debugMode();
    int t;
    cin >> t;
    char arr[t];
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 0 && y % 2 == 0)
        {
            arr[i] = 'E';
        }
        else if (x % 2 == 0 && y % 2 != 0)
        {
            arr[i] = 'O';
        }
        else if (x % 2 != 0 && y % 2 != 0)
        {
            arr[i] = 'E';
        }
        else
        {
            arr[i] = 'O';
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (arr[i] == 'E')
        {
            cout << "Janmansh" << endl;
        }
        else
        {
            cout << "Jay" << endl;
        }
    }
    return 0;
}