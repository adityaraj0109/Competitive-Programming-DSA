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
    int c;
    cin >> c;
    int size=log2(c)+1;
    int a=0,b=0;
    vector<int>vec;
    for(int i=0;i<size;i++){
        if (c & (1<<i))
        {
            vec.push_back(i);
        }
        else{
            a=a|(1<<i);
            b=b|(1<<i);
        }
    }
    int s=1<<vec.size();
    long long int answer=-1;
    for (int i = 0; i < s; i++)
    {
        long long int dum_a=a,dum_b=b;
        for (int j = 0; j < vec.size(); j++)
        {
            if (i & (1<<j))
            {
                dum_a = dum_a | (1<<vec[j]);
            }
            else{
                dum_b = dum_b | (1<<vec[j]);
            }
        }
        answer=max(answer,(dum_a*dum_b));
    }
    cout<<answer<<endl;
    return 0;
}