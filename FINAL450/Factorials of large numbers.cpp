#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data=data;
            next=NULL;
        }
};

vector<int> factorial(int N)
{
    vector<int>ans;
    Node* head=new Node(1);
    Node* tail=head;
    Node* root=head;
    for (int i = 2; i <= N; i++)
    {
        Node* temp=head;
        int carry=0;
        while (temp)
        {
            int s=carry+i*temp->data;
            carry=s/10;
            s=s%10;
            temp->data=s;
            temp=temp->next;
        }
        if(carry){
            while (carry>0)
            {
                Node* t=new Node(carry%10);
                tail->next=t;
                tail=tail->next;
                carry=carry/10;
            }
        }
    }
    while (root){
        ans.push_back(root->data);
        root=root->next;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
