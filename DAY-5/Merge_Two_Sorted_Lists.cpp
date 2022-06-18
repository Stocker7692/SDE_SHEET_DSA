#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

// ITERATIVE 
// TC: O((len(l1)+len(l2))) 
// SC: O(1) 

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *res = NULL;
        ListNode *head;
        if (list1->val < list2->val)
        {
            res = list1;
            list1 = list1->next;
        }
        else
        {
            res = list2;
            list2 = list2->next;
        }
        head = res;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                res->next = list1;

                list1 = list1->next;
            }
            else
            {
                res->next = list2;

                list2 = list2->next;
            }
            res = res->next;
        }
        if (list1)
        {
            res->next = list1;
        }
        if (list2)
        {
            res->next = list2;
        }
        return head;
    }

    // ITERATIVE 
    // TC: O((len(l1)+len(l2))) 
    // SC: O(1) 

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val > list2->val)
            swap(list1, list2);
        ListNode *res = list1;
        while (list1 && list2)
        {
            ListNode *temp = NULL;
            while (list1 && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }

    // RECURSIVE 
    // TC: O(min(len(l1),len(l2))) 
    // SC: O(min(len(l1),len(l2))) 

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (!l1 && !l2)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};