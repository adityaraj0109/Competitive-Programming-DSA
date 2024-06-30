#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode* temp=root;
    while (temp!=NULL)
    {
        if (temp->val==val)
        {
            return temp;
        }
        if (temp->val>val)
        {
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return NULL;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
