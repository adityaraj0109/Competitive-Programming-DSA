#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int>v(n);
      long long int sum=0;
      for (int i = 0; i < n; ++i)
      {
        cin>>v[i];
        sum+=v[i];
      }
      int count=0;
      for (int i = 1; i < n; ++i)
      {
        if (v[i]!=v[0])
        {
          break;
        }
        count++;
      }
      if (count==n-1)
      {
        cout<<0<<endl;
        continue;
      }
      int x=n-1;
      while(x>0){
        if (sum%x!=0)
        {
      x--;
          continue;
        }
        long long int val=sum/x;
        long long int sum2=0;
        count=0;
        for (int i = 0; i < n; ++i)
        {
          sum2+=v[i];
          if (sum2==val)
          {
            count++;
            sum2=0;
          }
          else if (sum2>val)
          {
            break;
          }
        }
        if (count==x)
        {
          cout<<n-count<<endl;
          break;
        }
        x--;
      }
    }
    return 0;
}