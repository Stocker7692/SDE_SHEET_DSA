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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode *curr=head;
        while(curr){
            size++;
            curr=curr->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        curr=dummy;
        ListNode *next=dummy;
        ListNode *prev=dummy;
        while(size>=k){
            curr=prev->next;
            next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev=curr;
            size-=k;
        }
        return dummy->next;
        
    }
};
// RECURSIVE

class Solution {
public:
    ListNode *solve(ListNode *&head,int size,int k){
        if(size<k) return head;
        ListNode *curr=head;
        ListNode *next = head->next;
        ListNode *temp=NULL;
            for(int i=1;i<k;i++){
                temp=next->next;
                next->next=curr;
                curr=next;
                next=temp;
            }
         head->next=solve(next,size-k,k);
         head=curr;
        return head;
        
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        int size=0;
        ListNode *curr=head;
        while(curr){
            size++;
            curr=curr->next;
        }
        
        solve(head,size,k);
        return head;     
    }
};