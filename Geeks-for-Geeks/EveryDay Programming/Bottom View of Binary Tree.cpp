#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *dummy = temp.first;
        q.pop();
        int col = temp.second;
        m[col]= dummy->data;
        if (dummy->left != NULL)
        {
            q.push({dummy->left, col - 1});
        }
        if (dummy->right != NULL)
        {
            q.push({dummy->right, col + 1});
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
