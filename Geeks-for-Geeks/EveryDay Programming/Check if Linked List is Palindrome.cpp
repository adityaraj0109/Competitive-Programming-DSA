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

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void InsertAtHead(Node* &head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(Node* &tail,int data){
    Node *newNode = new Node(data);
    tail->next=newNode;
    tail = newNode;
}

void InsertAtMiddle(Node* &head, Node* &tail, int data, int index){
    if (index==0)   
    {
        InsertAtHead(head,data);
        return; 
    }
    Node *temp=head;
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
    Node *newNode = new Node(data);
    newNode->next=temp->next;
    temp->next=newNode;
}

Node* findmiddle(Node* head){
    Node* slow = head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
        }
    }
    return slow;
}

bool isPalindrome(Node *head)
{
    if (head==NULL || head->next==NULL)
    {
        return true;
    }
    Node* middle=findmiddle(head);
    Node*curr=middle->next;
    Node* prev=NULL;
    Node* forward;
    while (curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    middle->next=prev;
    curr=head;
    forward=prev;
    while (forward!=NULL){
        if (curr->data!=forward->data){
            return false;
        }
        curr=curr->next;
        forward=forward->next;
    }
    return true;
}

void print(Node* &head){
    Node* temp = head;
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
    Node *node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    InsertAtHead(head,20);
    InsertAtHead(head,20);
    InsertAtHead(head,40);
    InsertAtTail(tail,20);
    InsertAtTail(tail,20);
    InsertAtTail(tail,40);
    print(head);
    int ans=isPalindrome(head);
    cout<<ans<<endl;
    return 0;
}
