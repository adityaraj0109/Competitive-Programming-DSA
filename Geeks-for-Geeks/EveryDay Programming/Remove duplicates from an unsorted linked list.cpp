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

Node *removeDuplicates(Node *head)
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        map<int,bool>visited;
        Node*curr=head;
        Node*prev=NULL;
        Node* temp;
        while (curr!=NULL){
            if (visited[curr->data]==false){
                visited[curr->data]=true;
                prev=curr;
                curr=curr->next;
            }
            else{
                prev->next=curr->next;
                temp=curr;
                temp->next=NULL;
                curr=prev->next;
                delete temp;
            }
        }
        return head;
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
    InsertAtMiddle(head,tail,50,3);
    InsertAtMiddle(head,tail,5,0);
    InsertAtMiddle(head,tail,5,6);
    InsertAtTail(tail,80);
    InsertAtTail(tail,5);
    InsertAtTail(tail,70);
    print(head);
    Node* ans=removeDuplicates(head);
    print(ans);
    return 0;
}
