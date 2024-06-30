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

bool isCircular(Node *head)
{
    if (head == NULL || head->next == head)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        return false;
    }
    return true;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
