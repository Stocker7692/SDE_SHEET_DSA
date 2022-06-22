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
    bool isPalindrome(ListNode* head) {
         string s="";
       ListNode *curr=head;
        while(curr){
            s+=curr->val-'0';
            curr=curr->next;
        }
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t) return 1;
        return 0;
        
    }
};
// RECURSIVE

class Solution {
public:
    ListNode *start;
    int val=0;
    void solve(ListNode *head){
        if(!head) return;
        solve(head->next);
        if(start->val==head->val){
            val++;
        }
        start=start->next;
    }
    bool isPalindrome(ListNode* head) {    
       int size=0;
       ListNode *curr=head;
        while(curr){
            size++;
            curr=curr->next;
        }
        start=head;
        solve(head);
        if(size==val) return 1;
        return 0;
        
    }
};