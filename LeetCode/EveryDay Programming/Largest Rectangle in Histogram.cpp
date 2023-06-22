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

vector<int> nextSmallest(vector<int> &heights){
    vector<int> ans(heights.size());
    stack<int>s;
    s.push(-1);
    int n = heights.size();
    for(int i = n-1; i>=0; i--){
        while(s.top()!=-1 && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if (s.top()==-1)
        {
            ans[i]=n;
        }
        else
        {
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallest(vector<int> &heights){
    vector<int> ans(heights.size());
    stack<int>s;
    s.push(-1);
    int n = heights.size();
    for(int i = 0; i<n; i++){
        while(s.top()!=-1 && heights[s.top()]>=heights[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int>next;
    vector<int>prev;
    next=nextSmallest(heights);
    prev=prevSmallest(heights);
    int area=0;
    for(int i = 0; i<heights.size(); i++){
        int length=heights[i];
        int breadth=next[i]-prev[i]-1;
        area=max(area, (length*breadth));
    }
    return area;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
