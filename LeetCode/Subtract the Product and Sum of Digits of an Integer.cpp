#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n)
{
    int arr[6];
    int i = 0;
    while (n > 0)
    {
        arr[i] = n % 10;
        n = n / 10;
        i++;
    }
    long long int prod = 1, sum = 0;
    for (int j = 0; j < i; j++)
    {
        prod = prod * arr[j];
        sum += arr[j];
    }
    return (prod - sum);
}

int main()
{
    int res;
    res=subtractProductAndSum(4421);
    cout<<res<<endl;
    return 0;
}