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

// BRUTE FORCE

    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode *curr = head;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        curr=head;
        for(int i=0;i<n/2;i++){
            curr=curr->next;
            
        }
        return curr;
        
    }


    // OPTIMIZED

    
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};