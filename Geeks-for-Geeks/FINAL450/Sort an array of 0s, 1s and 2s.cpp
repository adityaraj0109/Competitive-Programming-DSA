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

// void sort012(int a[], int n)
// {
//     int c0=0,c1=0,c2=0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i]==0)
//         {
//             c0++;
//         }
//         if (a[i]==1)
//         {
//             c1++;
//         }
//         else
//         {
//             c2++;
//         }
//     }
//     for (int i = 0; i < c0; i++)
//     {
//         a[i]=0;
//     }
//     for (int i = c0; i < c0+c1; i++)
//     {
//         a[i]=1;
//     }
//     for (int i = c0+c1; i < n; i++)
//     {
//         a[i]=2;
//     }
// }

void sort012(int a[], int n)
{
    int low=0,mid=0,high=n-1;
    for (int i = 0; (i < n) && (mid<=high); i++)
    {
        if (a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if (a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a[high],a[mid]);
            high--;
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
