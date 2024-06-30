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

pair<bool,int>solution(Node* root){
    if (root==NULL)
    {
        return {true,0};
    }
    pair<bool,int> left=solution(root->left);
    pair<bool,int> right=solution(root->right);
    int sum=left.second+right.second+root->data;
    if (root->left== NULL && root->right==NULL)
    {
        return {true,sum};
    }
    bool value= left.second+right.second==root->data;
    if (left.first && right.first && value)
    {
        return {true,sum};
    }
    return {false,sum};
}

bool isSumTree(Node *root)
{
    pair<bool,int>ans=solution(root);
    return ans.first;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
