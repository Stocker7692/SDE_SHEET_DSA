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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *ans=NULL;
        int rem=0;
        while(l1 && l2){
            int x =l1->val+l2->val;
            x+=rem;
            if(x<10){
                res->next = new ListNode(x);
                rem=0;
            }
            else{
                res->next = new ListNode(x%10);
                rem = x/10;
            }
            res=res->next;
            if(ans==NULL) ans=res;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int x = l1->val+rem;
            if(x<10){
                res->next = new ListNode(x);
                rem=0;
            }
            else{
                res->next = new ListNode(x%10);
                rem = x/10;
            }
            res=res->next;
            l1=l1->next;
            
            
        }
        while(l2){
            int x = l2->val+rem;
            if(x<10){
                res->next = new ListNode(x);
                rem=0;
            }
            else{
                res->next = new ListNode(x%10);
                rem = x/10;
            }
            res=res->next;
            l2=l2->next;
            
            
        }
        if(rem){
            res->next = new ListNode(rem);
        }
        return ans;
        
    }
};