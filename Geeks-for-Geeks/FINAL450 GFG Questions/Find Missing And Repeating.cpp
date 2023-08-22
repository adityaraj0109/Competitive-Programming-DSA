#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> findTwoElement(vector<int> arr, int n)
{
    long long int sum=accumulate(arr.begin(),arr.end(),0);
    int element;
    for (int i = 0; i < n; i++)
    {
        int index=abs(arr[i])-1;
        if(arr[index]<0){
            element=abs(arr[i]);
            break;
        }
        else{
            arr[index]=-1*arr[index];
        }
    }
    sum=sum-element;
    vector<int>ans;
    ans.push_back(element);
    long long int val=(n*1LL*(n+1)/2);
    ans.push_back(val-sum);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
