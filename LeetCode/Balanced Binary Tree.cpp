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

pair<bool,int> isBalancedHeight(TreeNode *root){
    if(root == NULL){
        return {true, 0};
    }
    pair<bool,int> left = isBalancedHeight(root->left);
    pair<bool,int> right = isBalancedHeight(root->right);
    if(left.first && right.first && abs(left.second - right.second) <= 1){
        return {true,max(left.second,right.second)+1};
    }
    return {false,max(left.second,right.second)+1};
}

bool isBalanced(TreeNode *root)
{
    pair<bool,int>ans=isBalancedHeight(root);
    return ans.first;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
