#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    unordered_map<string,int>m;
    int y;
    string s;
    int type;
    for (int i = 0; i < q; ++i)
    {
      cin>>type;
      if (type==1)
      {
        cin>>s>>y;
        m[s]=m[s]+y;
      }
      else if (type==2)
      {
        cin>>s;
        m[s]=0;
      }
      else{
        cin>>s;
        cout<<m[s]<<endl;
      }
    }
    return 0;
}