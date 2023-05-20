#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    int n,m;
    unordered_set<int>s;
    for (int i = 0; i < q; ++i)
    {
      cin>>n;
      if (n==1)
      {
        cin>>m;
        s.insert(m);
      }
      else if (n==2)
      {
        cin>>m;
        s.erase(m);
      }
      else{
        cin>>m;
        if (s.count(m))
        {
          cout<<"Yes"<<endl;
        }
        else{
          cout<<"No"<<endl;
        }
      }
    }
    return 0;
}