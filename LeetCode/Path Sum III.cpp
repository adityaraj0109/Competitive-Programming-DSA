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

void solution(TreeNode *root, int targetSum, int &count, vector<int> &vec){
    if(root == NULL){
        return;
    }
    vec.push_back(root->val);
    solution(root->left,targetSum,count,vec);
    solution(root->right,targetSum,count,vec);

    long long int sum=0;
    int n=vec.size();
    for (int i = n-1; i >= 0; i--)
    {
        sum+=(long long int)vec[i];
        if(sum==targetSum){
            count++;
        }
    }
    vec.pop_back();
}

int pathSum(TreeNode *root, int targetSum)
{
    int count=0;
    vector<int>vec;
    solution(root,targetSum,count,vec);
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
