#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    char c;
    int sum=0;
    cin>>n>>s;
    map<char,int>m;
    int len=2*n-2;
    for (int i = 0; i < s.size(); i++)
    {
      if (i%2==0)
      {
        m[s[i]]++;
      }
     else{
      c=tolower(s[i]);
      auto it=m.count(c);
      if (!it)
      {
        sum++;
      }
      else{
        if (m[c]>0)
        {
          m[c]--;
        }
        else{
          sum++;
        }
      }
     }
    }
    cout<<sum<<endl;
    return 0;
}