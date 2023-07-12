#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> singleNumber(vector<int> nums)
{
    vector<int>ans;
    int XOR=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        XOR=XOR^nums[i];
    }
    int rightBit=XOR& (~(XOR-1));
    int x=0,y=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(rightBit&nums[i]){
            x=x^nums[i];
        }
        else{
            y=y^nums[i];
        }
    }
    if(x>y){
        swap(x,y);
    }
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
