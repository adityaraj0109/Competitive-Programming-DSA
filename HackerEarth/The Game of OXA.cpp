#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n;
        cin>>n;
        vector<int>vec(n);
        for (int i = 0; i < n; i++)
        {
            cin>>vec[i];
        }
        int parity=-1;
        int size=1<<n;
        for (int i = 1; i < size; i++){
            vector<int>v;
            for (int j = 0; j < n; j++){
                if (i & (1<<j))
                {
                    v.push_back(vec[j]);
                }
            }
            int ans=v[0];
            for (int k = 1; k < v.size(); k++)
            {
                if (k%3==0)
                {
                    ans=ans+v[k];
                }
                else if (k%3==1)
                {
                    ans=ans|v[k];
                }
                else{
                    ans=ans^v[k];
                }
            }
            parity=max(parity,ans);
        }
        if (parity & 1)
        {
            if (s=="Odd")
            {
                cout<<"Monk"<<endl;
            }
            else{
                cout<<"Mariam"<<endl;
            }
        }
        else
        {
            if (s=="Even")
            {
                cout<<"Monk"<<endl;
            }
            else{
                cout<<"Mariam"<<endl;
            }
        }
    }
    return 0;
}