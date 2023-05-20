#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_subset(vector<int>v){
  int n=v.size();
  int size=1<<n;
  vector<vector<int>> vec;
  for (int i = 0; i < size; ++i)
  {
    vector<int>ans;
    for (int j = 0; j < n; ++j)
    {
      if ((1<<j)&i)
      {
        ans.push_back(v[j]);
      }
    }
    vec.push_back(ans);
  }
  return vec;
}

int main()
{
  vector<int> v={1,2,3,4};
  auto ans=generate_subset(v);
  for(auto it:ans){
    for(auto i:it){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}