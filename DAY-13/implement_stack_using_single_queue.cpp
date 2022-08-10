#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int>q;
    public:
    void push(int x){
        int s = q.size();
        q.push(x);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.size();
        q.pop();
        return n;
    }

    int top(){
        return q.front();
    }

    int size() {
        return q.size();
    }
};

int main(){

    Stack st;
    st.push(10);
    st.push(39);
    st.push(59);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

}