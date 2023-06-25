#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countBeautifulPairs(vector<int> &nums)
{
    int count=0;
    for (int i = 0; i < nums.size(); i++)
    {
        int num=nums[i];
        while (num/10!=0)
        {
            num=num/10;
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            int b = nums[j] % 10;
            if (__gcd(num, b) == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
