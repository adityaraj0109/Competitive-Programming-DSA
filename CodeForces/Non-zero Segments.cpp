#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0,sum=0;
    set<int>s;
    s.insert(0);
    for (int i = 1; i < n+1; i++)
    {
        int a;
        cin>>a;
        sum+=a;
        if(s.count(sum)){
            count++;
            s.clear();
            s.insert(0);
            s.insert(a);
            sum=a;
        }
        s.insert(sum);
    }
    cout<<count<<endl;
    return 0;
}