#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ITERATIVE

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = !a ? headA : a->next;
            b = !b ? headB : b->next;
        }
        return a;
    }
};
// RECURSIVE

class Solution
{
public:
    ListNode *solve(ListNode *headA, ListNode *headB, int sizeA, int sizeB)
    {
        if (sizeA == 0 || sizeB == 0)
            return NULL;
        if (sizeA > sizeB)
            return solve(headA->next, headB, sizeA - 1, sizeB);
        else if (sizeA < sizeB)
            return solve(headA, headB->next, sizeA, sizeB - 1);
        else if (sizeA == sizeB && headA == headB)
            return headA;
        else
            return solve(headA->next, headB->next, sizeA - 1, sizeB - 1);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = 0;
        int sizeB = 0;
        ListNode *curr = headA;
        while (curr)
        {
            sizeA++;
            curr = curr->next;
        }
        curr = headB;
        while (curr)
        {
            sizeB++;
            curr = curr->next;
        }
        return solve(headA, headB, sizeA, sizeB);
    }
};