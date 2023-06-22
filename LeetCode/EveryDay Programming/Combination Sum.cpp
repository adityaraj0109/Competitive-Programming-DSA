#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(vector<vector<int>> &ans, vector<int> &candidates, int target, vector<int> &temp, int start)
{
    if (target == 0)
        ans.push_back(temp);
    if (target < 0)
        return;

    for (int i = start; i < candidates.size(); i++)
    {
        if (candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            solution(ans, candidates, target - candidates[i], temp, i);
            temp.pop_back();
        }
        else
        {
            break;
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    solution(ans, candidates, target, temp, 0);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
