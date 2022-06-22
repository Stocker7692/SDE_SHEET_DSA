#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *flatten(Node *root)
{
   // Your code here
   vector<int>v;
   Node *curr=root;
   Node *nxt=root;
   while(nxt){
       while(curr){
           v.push_back(curr->data);
           curr=curr->bottom;
       }
       nxt=nxt->next;
       curr=nxt;
   }
   sort(v.begin(),v.end());
   Node *dummy=new Node(0);
   for(int i=0;i<v.size();i++){
    //   dummy->bottom =new Node(v[i]);
    //   dummy=dummy->bottom;
      cout<<v[i]<<" ";
   }
   return dummy->bottom;
 
}



    Node *solve(Node *a,Node *b){
        Node *temp= new Node(0);
        Node *res=temp;
        
        while(a && b){
            if(a->data<b->data){
                temp->bottom=a;
                temp=temp->bottom;
                a=a->bottom;
            }
            else{
                temp->bottom=b;
                temp=temp->bottom;
                b=b->bottom;
            }
        }
        if(a) temp->bottom=a;
        else temp->bottom=b;
        return res->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(!root || root->next==NULL) return root;
   
   root->next = flatten(root->next);
   
   root = solve(root,root->next);
   
   return root;
}