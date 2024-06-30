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

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};


Node* reverseDLL(Node * head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        curr->prev=forward;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtIndex(Node *&head, Node *&tail, int data, int index)
{
    Node *newNode = new Node(data);
    if (index == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
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
    Node *head = new Node(40);
    Node *tail = head;
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtIndex(head, tail, 100, 6);
    print(head);
    Node* ans=reverseDLL(head);
    print(ans);
    return 0;
}
