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
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        int x, a,b,c;
        cin >> x >>a>>b>>c;
        int price;
        if (a<=b)
        {
            if (b<=c)
            {
                price=(x-1)*a+b;
                arr[i]=price;
            }
        }
        if (a<=c)
        {
            if (c<=b)
            {
                price=(x-1)*a+c;
                arr[i]=price;
            }
        }
        if (b<=a)
        {
            if (a<=c)
            {
                price=(x-1)*b+a;
                arr[i]=price;
            }
        }
        if (b<=c)
        {
            if (c<=a)
            {
                price=(x-1)*b+c;
                arr[i]=price;
            }
        }
        if (c<=a)
        {
            if (a<=b)
            {
                price=(x-1)*c+a;
                arr[i]=price;
            }
        }
        if (c<=b)
        {
            if (b<=a)
            {
                price=(x-1)*c+b;
                arr[i]=price;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}