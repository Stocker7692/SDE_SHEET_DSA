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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ) return head;
    
        int l=1;
        ListNode *curr=head;
        while(curr->next!=NULL){
            l++;
            curr=curr->next;
        }
        k=k%l;
        if(l==1 || k==0 || k==l) return head;
        ListNode *res=head;
        ListNode *prev=NULL;
        
        for(int i=0;i<l-k;i++){
            prev=res;
            res=res->next;
            
        }
        curr->next =head;
        prev->next=NULL;
        return res;
        
    }
};