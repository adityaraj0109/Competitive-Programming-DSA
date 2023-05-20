#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        swap(arr[0],arr[i]);
    }
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int n=5;
    rotate(arr,5);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}