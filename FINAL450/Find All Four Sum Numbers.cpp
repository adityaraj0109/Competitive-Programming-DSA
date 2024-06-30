#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    vector<vector<int>>ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n-3; i++)
    {
        if(i!=0 && arr[i]==arr[i-1]) continue;
        for (int j = i+1; j < n-2; j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int target=k-arr[i]-arr[j];
            int high=n-1,low=j+1;
            while (low<high){
                int sum=arr[low]+arr[high];
                if(target==sum){
                    ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                    int prevlow=low;
                    low++;
                    while (low<high && arr[low]==arr[prevlow])
                    {
                        low++;
                    }
                }
                else if(target>sum){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
