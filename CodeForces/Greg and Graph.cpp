#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int distance[n+1][n+1];
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            cin>>distance[i][j];
        }
    }
    vector<int>removed(n);
    for (int i = 0; i < n; i++)
    {
        cin>>removed[i];
    }
    reverse(removed.begin(),removed.end());
    vector<long long int>ans;
    for (int k = 0; k <n; k++)
    {
        int elem=removed[k];
        for (int i = 1; i <=n; i++){
            for (int j = 1; j <=n; j++)
            {
                distance[i][j]=min(distance[i][j],distance[i][elem]+distance[elem][j]);
            }
        }
        long long int sum=0;
        for (int i = 0; i <=k; i++){
            for (int j = 0; j <=k; j++){
                sum+=distance[removed[i]][removed[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(int it:ans){
        cout<<it<<" ";
    }
    return 0;
}