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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL){
        return true;
    }
    if (p==NULL && q!= NULL)
    {
        return false;
    }
    if (p!=NULL && q==NULL)
    {
        return false;
    }
    bool left=isSameTree(p->left,q->left);
    bool right=isSameTree(p->right,q->right);
    bool value= p->val==q->val;
    if (left && right && value)
    {
        return true;
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
