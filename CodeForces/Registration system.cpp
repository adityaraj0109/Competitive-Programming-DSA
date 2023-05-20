#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    unordered_map<string,int>m;
    for (int i = 0; i < n; ++i)
    {
      cin>>s;
      if (!m.count(s))
       {
         m[s]++;
         cout<<"OK"<<endl;
       } 
       else{
         m[s]++;
         string str=s+to_string(m[s]-1);
         cout<<str<<endl;
       }
    }
    return 0;
}