#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

// ITERATIVE


    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
        
    }

    // RECURSIVE
    
    ListNode* solve(ListNode *head,ListNode *prev){
        
        if(!head) return prev;
        ListNode *next = head->next;
        head->next=prev;
        return solve(next,head);
    }
    ListNode* reverseList(ListNode* head) {
        return solve(head,NULL);
        
        
    }
};