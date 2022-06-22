#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                ListNode *temp=head;
                while(slow!=temp){
                    slow=slow->next;
                    temp=temp->next;
                }
                return slow;
            } 
        }
        return NULL;
        
    }
};