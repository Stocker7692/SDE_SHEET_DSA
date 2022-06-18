#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// ITERATIVE
class Solution {
public:
// TC : O(2N)
//SC : O(1)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=0;
        ListNode *curr=head;
        while(curr){
            x++;
            curr=curr->next;
        }
        curr=head;
        x=x-n-1;
        if(x==-1) {
            curr = curr->next;
            return curr;
        }
        else{
            while(x--){
                curr=curr->next;
            }
        }
        curr->next = curr->next->next;
        return head;
        
    }
	
// OPTIMAL ITERATIVE
// TC: O(N)
// SC: O(1)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *slow,*fast;
        ListNode *dummy =new ListNode();
        dummy->next = head;
        slow=dummy;
        fast=dummy;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
        
    }
	
// RECURSIVE

// TC: O(N)
// SC: O(N)



int solve(ListNode *head,int n){
    if(!head) return 0;
    int x = solve(head->next,n);
    if(x==n){
        head->next=head->next->next;
    }
    return x+1;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
    ListNode *dummy=new ListNode(-1); // dummy pointer to handle deletion of first node
    dummy->next = head;
    solve(dummy,n);
    return dummy->next;

    
}
};