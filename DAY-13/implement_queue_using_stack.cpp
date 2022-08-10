#include<bits/stdc++.h>
using namespace std;

class MyQueue {

    public:
    stack<int>input,output;

    MyQueue(){

    }

    void push(int x){
        cout<<"The element pushed is "<<x<<endl;
        input.push(x);
    }

    int pop(){
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int top(){
        if(output.top()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    int size(){
        return output.size()+input.size();
    }

};

struct Queue {
    stack<int> input,output;

    void push(int data){
        while(!input.empty()){
            output.push(input.top());
            input.pop();

        }

        cout<<"The element is pushed "<<data<<endl;
        input.push(data);

        while(!output.empty()){
            input.push(output.top());
            output.pop();
            
        }
    }

    int pop(){

        if(input.empty()){
            cout<<"stack is empty"<<endl;
            exit(0);
        }

        int val = input.top();
        input.pop();
        return val;
    }

    int top(){

        if(input.empty()){
            cout<<"Stack is Empty"<<endl;
            exit(0);
        }

        return input.top();
    }

    int size(){
        return input.size();
    }
};

int main(){

    MyQueue q;
    q.push(10);
    q.push(810);
    q.push(180);
    q.push(310);
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;

}