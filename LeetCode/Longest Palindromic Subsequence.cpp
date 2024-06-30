#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    vector<int>curr(n2+1,0);
    vector<int>next(n2+1,0);
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + next[j+1];
            }
            else
            {
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}

int longestPalindromeSubseq(string s)
{
    //solution is same as the longest common subsequence 
    //just reverse the string and find the lcs
    string str=s;
    reverse(str.begin(),str.end());
    return solution(s,str);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
