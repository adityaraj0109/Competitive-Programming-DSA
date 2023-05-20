#include <bits/stdc++.h>
using namespace std;

int countWords(string list[], int n)
{
  unordered_map<string,int>m;
  for (int i = 0; i < n; ++i)
  {
    m[list[i]]++;
  }
  int count=0;
  for(auto i:m){
    if (i.second==2)
    {
      count++;
    }
  }
  return count;
}

int main()
{
    int n;
    cin>>n;
    string list[n];
    for (int i = 0; i < n; ++i)
    {
      cin>>list[i];
    }
    int ans=countWords(list,n);
    cout<<ans<<endl;
    return 0;
}