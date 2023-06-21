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

long long int merge(long long int *arr, long long start, long long end){
    long long mid=(start+end)/2;
    long long len1=mid-start+1;
    long long len2=end-mid;
    long long int *a1=new long long int[len1];
    long long int *a2=new long long int[len2];
    long long int len=start;
    for (int i = 0; i < len1; i++)
    {
        a1[i]=arr[len++];
    }
    len=mid+1;
    for (int i = 0; i < len2; i++)
    {
        a2[i]=arr[len++];
    }
    long long int l=0,r=0,count=0;
    len=start;
    while (l<len1 && r<len2)
    {
        if (a1[l]<=a2[r])
        {
            arr[len++]=a1[l++];
        }
        else
        {
            count+=(len1-l);
            arr[len++]=a2[r++];
        }
    }
    while (l<len1)
    {
        arr[len++]=a1[l++];
    }
    while (r<len2)
    {
        arr[len++]=a2[r++];
    }
    delete []a1;
    delete []a2;
    return count;
}

long long int merge_sort(long long int *arr, long long start, long long end){
    long long count=0;
    if (start<end)
    {
        long long mid=(start+end)/2;
        count+=merge_sort(arr,start,mid);
        count+=merge_sort(arr,mid+1,end);
        count+=merge(arr,start,end);
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    long long start=0,end=N-1;
    long long ans=merge_sort(arr,start,end);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
