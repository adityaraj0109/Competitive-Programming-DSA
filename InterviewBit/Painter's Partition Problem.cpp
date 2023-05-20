#include <bits/stdc++.h>
using namespace std;

int solution(int A,int high,int low, vector<int>&C){
    int mid,count,a;
    int ans;
    while(high>=low){
      mid=(high+low)/2;
      count=1,a=0;
      for (int i = 0; i < C.size(); ++i)
      {
        a+=C[i];
        if (a>mid)
        {
          a=C[i];
          count++;
        }
      }
      if (count<=A)
      {
        ans=mid;
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return ans%10000003;
}

int paint(int A, int B, vector<int> &C) {
    int n=10000003;
    if(A>=C.size()){
        auto it=max_element(C.begin(),C.end());
        return ((B%n)*((*it)%n))%n;
    }
    int high=0;
    for (int i = 0; i < C.size(); ++i)
    {
      high=((high%n)+(C[i]%n))%n;
    }
    int low = * max_element(C.begin(), C.end());
    long long int ans;
    ans=solution(A,high,low,C);
    ans=((B%n)*(ans%n))%n;
    return ans;
}

int main()
{
  int A,B;
  cin>>A>>B;
  int n;
  cin>>n;
  vector<int>v(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
  }
  int ans=paint(A,B,v);
  cout<<ans<<endl;
  return 0;
}