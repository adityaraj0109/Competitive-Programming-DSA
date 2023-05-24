#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool solution(TreeNode* root,long long min,long long max){
    if (root==NULL)
    {
        return true;
    }
    if (root->val>min && root->val<max)
    {
        bool left=solution(root->left,min,root->val);
        bool right=solution(root->right,root->val,max);
        return left && right;
    }
    return false;
}

bool isValidBST(TreeNode *root)
{
    long long min=(long)INT_MIN-1;
    long long max=(long)INT_MAX+1;
    return solution(root,min,max);    
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
