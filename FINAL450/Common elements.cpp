#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i=0,j=0,k=0;
    vector<int>ans;
    while (i<n1 && j<n2 && k<n3)
    {
        if(A[i]==B[j] && A[i]==C[k]){
            if(i!=0 && j!=0 && k!=0){
                if(A[i]==A[i-1] && B[j]==B[j-1] && C[k]==C[k-1]){
                    i++;j++;k++;
                }
                else{
                    ans.push_back(A[i]);
                    i++;j++;k++;
                }
            }
            else{
                ans.push_back(A[i]);
                i++;j++;k++;
            }
        }
        else{
            if(A[i]>B[j]){
                if(B[j]>C[k]){
                    k++;
                }
                else{
                    j++;
                }
            }
            else{
                if(A[i]>C[k]){
                    k++;
                }
                else{
                    i++;
                }
            }
        }
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
