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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    bool left2right=true;
    while (!q.empty())
    {
        int size=q.size();
        vector<int>temp(size);
        for (int i = 0; i < size; i++){
            TreeNode* tree=q.front();
            q.pop();
            int index=left2right? i:size-i-1;
            temp[index]=tree->val;

            if(tree->left!=NULL){
                q.push(tree->left);
            }
            if(tree->right!=NULL){
                q.push(tree->right);
            }
        }
        left2right=!left2right;
        ans.push_back(temp);
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
