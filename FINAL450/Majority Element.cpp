#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int majorityElement(int a[], int size)
{
    int count=0,element;
    for (int i = 0; i < size; i++)
    {
        if(count==0){
            element=a[i];
            count++;
        }
        else if(a[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    if(count==0) return -1;
    count=0;
    for (int i = 0; i < size; i++)
    {
        if(a[i]==element) count++;
    }
    if(count>(size/2)) return element;
    return -1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
