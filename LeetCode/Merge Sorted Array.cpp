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

//approach 1
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     for (int i = m; i < nums1.size(); i++)
//     {
//         nums1[i]=nums2[i-m];
//     }
//     sort(nums1.begin(),nums1.end());
// }

//approach 2
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int j=nums2.size()-1;
    int k=m-1;
    for (int i = nums1.size()-1; i >=0 && j>=0 && k>=0; i--)
    {
        if (nums1[k]>nums2[j])
        {
            nums1[i]=nums1[k];
            k--;
        }
        else{
            nums1[i]=nums2[j];
            j--;
        }
    }
    while (j>=0){
        nums1[j]=nums2[j];
        j--;
    }
}

int main()
{
    debugMode();
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    merge(v1,3,v2,3);
    return 0;
}
