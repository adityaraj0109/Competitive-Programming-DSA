#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int>s;
    int ans=INT_MIN;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }
    for(auto it:s){
        int count=0;
        if(s.find(it-1)==s.end()){
            count++;
            int x=it;
            while (s.find(x+1)!=s.end())
            {
                count++;
                x++;
            }
            ans=max(ans,count);
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
