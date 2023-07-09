#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class compare{
    public:
        bool operator()(pair<double,Item> a, pair<double,Item> b){
            return a.first>b.first;
        }
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double,Item>>vec;
    for (int i = 0; i < n; i++)
    {
        double val=arr[i].value/double(arr[i].weight);
        vec.push_back({val,arr[i]});
    }
    sort(vec.begin(),vec.end(),compare());
    double ans=0;
    for (int i = 0; i < n; i++)
    {
        if(vec[i].second.weight<=W){
            ans+=vec[i].second.value;
            W-=vec[i].second.weight;
        }
        else{
            ans+=W*vec[i].first;
            W=0;
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
