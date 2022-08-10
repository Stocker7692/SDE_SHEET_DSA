#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &st)
{
	// Write your code here
    stack<int>s1;
    while(!st.empty()){
        int item = st.top();
        st.pop();
        while(!s1.empty() && s1.top()<item){
            st.push(s1.top());
            s1.pop();
        } 
        s1.push(item);
    }
    while(!s1.empty()){
        st.push(s1.top());
        s1.pop();
    } 
}