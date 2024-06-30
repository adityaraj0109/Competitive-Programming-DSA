#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void threeWayPartition(vector<int> &array, int a, int b)
{
    int n=array.size();
    int i=0,low=0,high=n-1;
    while (i<=high && low<high)
    {
        if(array[i]<a){
            swap(array[i],array[low]);
            low++;
            i++;
        }
        else if(array[i]>b){
            swap(array[i],array[high]);
            high--;
        }
        else{
            i++;
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
