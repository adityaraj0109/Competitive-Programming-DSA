#include <bits/stdc++.h>
using namespace std;

vector<long long> printFibb(int n) 
{
  vector<long long>v(n+1),v1(n);
  v[0]=0,v[1]=1;
  for (int i = 2; i <= n; ++i)
  {
    v[i]=v[i-1]+v[i-2];
  }
  for (int i = 0; i < n; ++i)
  {
    v1[i]=v[i+1];
  }
  return v1;
}

int main()
{
  vector<long long>v;
  int n;
  cin>>n;
  v=printFibb(n);
  for (int i = 1; i <= n; ++i)
  {
    cout<<v[i]<<" ";
  }
  return 0;
}