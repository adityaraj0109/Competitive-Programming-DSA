#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    vector<int>v(1000,0);
    int max=0;
    for (int i = 0; i < answers.size(); i++)
    {
        v[answers[i]]++;
        if (max<answers[i])
        {
            max=answers[i];
        }
    }
    int div,rem,sum=0;
    for (int i = 0; i < max+1 ; i++)
    {
        if (v[i]!=0)
        {
            div=v[i]/(i+1);
            rem=v[i]%(i+1);
            if (rem!=0)
            {
                sum+=(div+1)*(i+1);
            }
            else
            {
                sum+=div*(i+1);
            }
        }
    }
    return sum;
}

int main()
{
    vector<int>answer;
    answer={10,10,10};
    int ans=numRabbits(answer);
    cout<<ans<<endl;
    return 0;
}