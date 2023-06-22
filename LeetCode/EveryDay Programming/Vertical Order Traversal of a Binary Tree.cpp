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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int,map<int,vector<int>>>nodes;
    queue<pair<TreeNode*,pair<int,int>>>q;
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    q.push({root,{0,0}});
    while(!q.empty()){
        pair<TreeNode*,pair<int,int>>temp=q.front();
        q.pop();
        TreeNode* frontNode=temp.first;
        int h=temp.second.first;
        int level=temp.second.second;
        nodes[h][level].push_back(frontNode->val);
        if(frontNode->left!=NULL){
            q.push({frontNode->left,{h-1,level+1}});
        }
        if(frontNode->right!=NULL){
            q.push({frontNode->right,{h+1,level+1}});
        }
    }
    for(auto x:nodes){
        vector<int>temp;
        for(auto it:x.second){
            vector<int>v=it.second;
            if(v.size()==1){
                temp.push_back(v[0]);
            }
            else{
                sort(v.begin(),v.end());
                for(int f:v){
                    temp.push_back(f);
                }
            }
        }
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
