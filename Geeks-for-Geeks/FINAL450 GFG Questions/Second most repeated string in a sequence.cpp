#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string secFrequent(string arr[], int n)
{
    unordered_map<string,int>m;
    string ans;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    pair<string,int> maxi={"",INT_MIN};
    int secondmaxi=INT_MIN;
    for(auto it:m){
        if(it.second>maxi.second){
            secondmaxi=maxi.second;
            ans=maxi.first;
            maxi=it;
        }
        else if(it.second>secondmaxi){
            secondmaxi=it.second;
            ans=it.first;
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
