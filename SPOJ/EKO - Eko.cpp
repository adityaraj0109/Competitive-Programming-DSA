#include <bits/stdc++.h>
using namespace std;

bool solution(int h, vector<int>v, int m){
  long long int sum=0;
  for (int i = 0; i < v.size() ; ++i)
  {
    if (v[i]>h)
    {
      sum=sum+(v[i]-h);
    }
  }
  return sum>=m;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
      cin>>v[i];
    }
    int high=1e9,low=0,mid;
    while(high-low>1){
      mid=(high+low)/2;
      bool ans=solution(mid,v,m);
      if (ans)
      {
        low=mid;
      }
      else{
        high=mid-1;
      }
    }
    if (solution(high,v,m))
    {
      cout<<high<<endl;
    }
    else{
      cout<<low<<endl;
    }
    return 0;
}