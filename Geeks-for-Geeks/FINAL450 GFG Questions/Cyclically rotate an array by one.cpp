#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for (int i = n-1; i >0 ; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

// void rotate(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         swap(arr[0],arr[i]);
//     }
// }

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
