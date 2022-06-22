#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ITERATIVE

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return 1;
        } 
        
        return 0;
        
    }
};
// RECURSIVE

class Solution {
public:
    bool solve(ListNode *slow,ListNode *fast){
        if(!fast || fast->next==NULL) return false;
        if(slow==fast) return true;
        return solve(slow->next,fast->next->next);
    }
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        return solve(head->next,head->next->next);
        
    }
};