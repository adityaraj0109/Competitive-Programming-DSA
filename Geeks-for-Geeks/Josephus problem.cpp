#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    int array[n] = {0};
    int count = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == n - 1)
        {
            break;
        }
        else
        {
            if (array[i]!=1)
            {
                count++;
            }
            if (array[i] == 0 && count % k == 0)
            {
                c++;
                array[i] = 1;
            }
        }
        if (i == n - 1)
        {
            i = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            return (i + 1);
        }
    }
}

int main()
{
    int ans = josephus(3,2);
    cout << ans << endl;
    return 0;
}