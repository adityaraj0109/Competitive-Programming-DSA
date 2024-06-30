#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class compare{
    public:
        bool operator()(ListNode* a, ListNode*b){
            return a->val > b->val;
        }   
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode*, vector<ListNode*>,compare>pq;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    for(int i=0;i<lists.size();i++){
        if(lists[i]!=NULL){
            pq.push(lists[i]);
        }
    }
    while(!pq.empty()){
        ListNode *temp = pq.top();
        pq.pop();
        if(head==NULL){
            head = temp;
            tail = temp;
            if (temp->next!=NULL)
            {
                pq.push(temp->next);
            }
        }
        else{
            tail->next = temp;
            tail = temp;
            if (temp->next!=NULL){
                pq.push(temp->next);
            }
        }
    }
    return head;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
