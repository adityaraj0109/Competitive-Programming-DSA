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

class ListNode{
    public:
    int data;
    ListNode *next;
    ListNode(int x){
        this->data=x;
        this->next=NULL;
    }
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    int round=0;
    ListNode* flag=head;
    while (flag!=NULL)
    {
        flag=flag->next;
        round++;
    }
    int r=round/k;
    if (r==0)
    {
        return head;
    }
    ListNode* curr=head;
    ListNode* forward;
    ListNode* temp=head;
    int count=0;
    ListNode* prev=NULL;
    while(curr!=NULL && count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    head=prev;
    r--;
    if (r==0)
    {
        temp->next=curr;
        return head;
    }
    while(curr!=NULL && r--){
        count=0;
        prev=NULL;
        ListNode* temp2=curr;
        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        temp->next=prev;
        temp=temp2;
    }
    temp->next=curr;
    return head;
}

void InsertAtHead(ListNode* &head,int data){
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(ListNode* &tail,int data){
    ListNode *newNode = new ListNode(data);
    tail->next=newNode;
    tail = newNode;
}

void InsertAtMiddle(ListNode* &head, ListNode* &tail, int data, int index){
    if (index==0)   
    {
        InsertAtHead(head,data);
        return; 
    }
    ListNode *temp=head;
    int count=1;
    while (count<index)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==NULL)
    {
        InsertAtTail(tail,data);
        return;
    }
    ListNode *newNode = new ListNode(data);
    newNode->next=temp->next;
    temp->next=newNode;
}

void print(ListNode* &head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode *node1=new ListNode(10);
    ListNode *head=node1;
    ListNode *tail=node1;
    InsertAtHead(head,20);
    InsertAtHead(head,30);
    InsertAtHead(head,40);
    InsertAtMiddle(head,tail,50,3);
    InsertAtMiddle(head,tail,5,0);
    InsertAtMiddle(head,tail,15,0);
    InsertAtMiddle(head,tail,69,6);
    InsertAtTail(tail,80);
    InsertAtTail(tail,80);
    InsertAtTail(tail,90);
    InsertAtTail(tail,100);
    print(head);
    // Node* ans=reverseList(head);
    // print(ans);
    ListNode* ans1=reverseKGroup(head,3);
    print(ans1);
    return 0;
}
