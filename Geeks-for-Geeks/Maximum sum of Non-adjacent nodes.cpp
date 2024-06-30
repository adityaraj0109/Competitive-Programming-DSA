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

pair<int,int> solution(Node* root){
    if(root==NULL){
        return {0,0};
    }
    pair<int,int>left=solution(root->left);
    pair<int,int>right=solution(root->right);

    pair<int,int>ans;
    ans.first=root->data+left.second+right.second;    //including the node value
    ans.second=max(left.first,left.second)+max(right.first,right.second);
    return ans;
}

int getMaxSum(Node *root)
{
    pair<int,int>ans=solution(root);
    return max(ans.first,ans.second);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
