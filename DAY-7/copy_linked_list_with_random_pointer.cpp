#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;
        Node *curr = head;
        while (curr)
        {
            Node *temp = new Node(curr->val);
            m[curr] = temp;
            curr = curr->next;
        }
        Node *dummy = NULL;
        curr = head;
        for (auto i : m)
        {
            if (dummy == NULL)
                dummy = i.second;
            i.second->next = m[i.first->next];
            i.second->random = m[i.first->random];
        }
        return dummy;
    }
};
// OPTIMAL

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *curr = head;
        Node *nxt = head;
        Node *res = NULL;
        while (nxt)
        {
            Node *temp = new Node(curr->val);
            if (res == NULL)
                res = temp;
            nxt = curr->next;
            curr->next = temp;
            temp->next = nxt;
            curr = nxt;
        }
        curr = head;

        while (curr)
        {

            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        nxt = head;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;
        while (curr)
        {
            nxt = curr->next->next;
            copy->next = curr->next;
            curr->next = nxt;

            copy = copy->next;
            curr = nxt;
        }

        return pseudoHead->next;
    }
};