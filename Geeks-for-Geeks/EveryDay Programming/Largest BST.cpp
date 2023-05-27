#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

pair<pair<int,int>,pair<bool,int>> solution(Node* root, int &ans){
    if (root==NULL)
    {
        return {{INT_MIN,INT_MAX},{true,0}};
    }
    
    pair<pair<int,int>,pair<bool,int>> left=solution(root->left,ans);
    pair<pair<int,int>,pair<bool,int>> right=solution(root->right,ans);
    int size=left.second.second+right.second.second+1;
    int maxx=max(root->data,right.first.first);
    int minn=min(root->data,left.first.second);
    if (left.second.first==true && right.second.first==true && (root->data > left.first.first) && (root->data < right.first.second)){
        ans=max(ans,size);
        return {{maxx,minn},{true,size}};
    }
    return {{maxx,minn},{false,size}};
}

int largestBst(Node *root)
{
    int ans=0;
    pair<pair<int,int>,pair<int,int>>sol=solution(root,ans);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
