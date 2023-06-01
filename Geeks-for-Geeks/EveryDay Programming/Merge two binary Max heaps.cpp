#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void heapify(vector<int> &ans, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < n && ans[left] > ans[largest])
    {
        largest = left;
    }
    if (right < n && ans[right] > ans[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(ans[index], ans[largest]);
        heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        ans.push_back(b[i]);
    }
    int size = ans.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(ans, i, size);
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
